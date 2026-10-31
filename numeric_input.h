/* ASCII numeric entry without locale separators or exponent notation. */
static NSString *numericExpandedString(NSString *text){
    if(!text)return @"";
    NSRange e=[text rangeOfString:@"e" options:NSCaseInsensitiveSearch];if(e.location==NSNotFound)return text;
    static NSRegularExpression *expression;static dispatch_once_t once;dispatch_once(&once,^{expression=[NSRegularExpression regularExpressionWithPattern:@"^-?[0-9]+(?:\\.[0-9]*)?[eE][+-]?[0-9]+$" options:0 error:nil];});
    if(![expression firstMatchInString:text options:0 range:NSMakeRange(0,text.length)])return text;
    NSInteger exponent=[[text substringFromIndex:e.location+1] integerValue];if(labs(exponent)>400)return text;
    BOOL negative=[text hasPrefix:@"-"];NSString *mantissa=[text substringWithRange:NSMakeRange(negative?1:0,e.location-(negative?1:0))];NSRange dot=[mantissa rangeOfString:@"."];NSInteger point=(dot.location==NSNotFound?(NSInteger)mantissa.length:(NSInteger)dot.location)+exponent;
    NSString *digits=[mantissa stringByReplacingOccurrencesOfString:@"." withString:@""];NSMutableString *result=[NSMutableString stringWithString:negative?@"-":@""];
    if(point<=0){[result appendString:@"0."];for(NSInteger i=0;i< -point;i++)[result appendString:@"0"];[result appendString:digits];}
    else if(point>=(NSInteger)digits.length){[result appendString:digits];for(NSInteger i=digits.length;i<point;i++)[result appendString:@"0"];}
    else{[result appendString:[digits substringToIndex:point]];[result appendString:@"."];[result appendString:[digits substringFromIndex:point]];}
    return result;
}
/* Shortest decimal that round-trips to the stored binary value. Promoted
   float values use float precision; genuine double values keep double precision. */
static NSString *numericDisplayString(NSString *text){
    if(!text.length)return text?:@"";
    const char *bytes=text.UTF8String;char *end=NULL;double value=strtod(bytes,&end);
    if(end==bytes||*end||!isfinite(value))return numericExpandedString(text);
    float single=(float)value;BOOL isSingle=isfinite(single)&&(double)single==value;
    for(int digits=1;digits<=(isSingle?9:17);digits++){
        NSString *candidate=[NSString stringWithFormat:@"%.*g",digits,value];
        double parsed=strtod(candidate.UTF8String,NULL);
        if(isSingle?(float)parsed==single:parsed==value)return numericExpandedString(candidate);
    }
    return numericExpandedString(text);
}
static NSString *numericInputString(NSTextField *field);
@interface NumericInputFormatter : NSFormatter
@property(nonatomic) BOOL integerOnly,allowLast,singleDecimal;
@end
@implementation NumericInputFormatter
- (NSString *)stringForObjectValue:(id)object {if(self.singleDecimal)return [NSString stringWithFormat:@"%.1f",[object doubleValue]];return numericDisplayString([object isKindOfClass:NSString.class]?object:[object isKindOfClass:NSNumber.class]?[NSString stringWithFormat:@"%.17g",[object doubleValue]]:[object description]);}
- (BOOL)isPartialStringValid:(NSString *)text newEditingString:(NSString *__autoreleasing *)newString errorDescription:(NSString *__autoreleasing *)error {
    (void)newString;(void)error;if(self.allowLast&&text.length&&[@"last" hasPrefix:text.lowercaseString])return YES;
    BOOL dot=NO;for(NSUInteger i=0;i<text.length;i++){unichar c=[text characterAtIndex:i];if(c>='0'&&c<='9')continue;if(c=='-'&&i==0)continue;if(c=='.'&&!self.integerOnly&&!dot){dot=YES;continue;}return NO;}return YES;
}
- (BOOL)getObjectValue:(id __autoreleasing *)object forString:(NSString *)text errorDescription:(NSString *__autoreleasing *)error {
    if(self.allowLast&&[text.lowercaseString isEqual:@"last"]){if(object)*object=@"last";return YES;}
    BOOL digit=NO;for(NSUInteger i=0;i<text.length;i++)if([text characterAtIndex:i]>='0'&&[text characterAtIndex:i]<='9')digit=YES;
    if(!digit||![self isPartialStringValid:text newEditingString:NULL errorDescription:NULL]){if(error)*error=self.integerOnly?@"Enter an integer.":@"Enter a number using digits, a leading minus sign and one decimal point.";return NO;}
    if(object)*object=text;return YES;
}
@end
@interface NumericTextField : NSTextField
@property(nonatomic,copy) NSString *retainedNumericInput;
@end
@implementation NumericTextField
- (instancetype)initWithFrame:(NSRect)frame {if((self=[super initWithFrame:frame]))self.formatter=[NumericInputFormatter new];return self;}
- (void)setStringValue:(NSString *)value {NSString *raw=numericExpandedString(value);[super setStringValue:raw];self.retainedNumericInput=raw;}
- (void)setDoubleValue:(double)value {[super setDoubleValue:value];self.retainedNumericInput=[NSString stringWithFormat:@"%.17g",value];}
- (void)setIntegerValue:(NSInteger)value {[super setIntegerValue:value];self.retainedNumericInput=[NSString stringWithFormat:@"%ld",(long)value];}
- (void)setIntValue:(int)value {[super setIntValue:value];self.retainedNumericInput=[NSString stringWithFormat:@"%d",value];}
- (void)setFloatValue:(float)value {[super setFloatValue:value];self.retainedNumericInput=[NSString stringWithFormat:@"%.17g",(double)value];}
- (void)textDidChange:(NSNotification *)notification {self.retainedNumericInput=nil;[super textDidChange:notification];}
- (double)doubleValue {return numericInputString(self).doubleValue;}
@end
static void numericIntegerField(NSTextField *field,BOOL integerOnly){if([field.formatter isKindOfClass:NumericInputFormatter.class])((NumericInputFormatter*)field.formatter).integerOnly=integerOnly;}

/* The formatter changes presentation only. Read the original cell object so
   opening, rendering or saving without an edit never quantizes parameters. */
static NSString *numericInputString(NSTextField *field){
    if(![field.formatter isKindOfClass:NumericInputFormatter.class])return field.stringValue;
    if([field isKindOfClass:NumericTextField.class]&&((NumericTextField *)field).retainedNumericInput)return ((NumericTextField *)field).retainedNumericInput;
    id value=field.objectValue;
    return [value isKindOfClass:NSString.class]?value:[value isKindOfClass:NSNumber.class]?[NSString stringWithFormat:@"%.17g",[value doubleValue]]:field.stringValue;
}
