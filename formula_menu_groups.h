/* Split long categories into balanced alphabetical ranges without nesting. */
static void addFormulaMenuGroups(NSMenu *menu,NSArray<NSMenuItem *> *leaves,NSInteger category,NSString *name,NSString *hint){
    NSArray<NSMenuItem *> *sorted=[leaves sortedArrayUsingComparator:^NSComparisonResult(NSMenuItem *a,NSMenuItem *b){return [a.title localizedStandardCompare:b.title];}];
    NSUInteger parts=(category==0||category==4)?3:category==5?2:1;
    for(NSUInteger part=0;part<parts;part++){
        NSUInteger start=sorted.count*part/parts,end=sorted.count*(part+1)/parts;
        NSString *title=name;
        if(parts>1&&end>start)title=[NSString stringWithFormat:@"%@ (%@ – %@)",name,sorted[start].title,sorted[end-1].title];
        NSMenuItem *group=[[NSMenuItem alloc]initWithTitle:title action:nil keyEquivalent:@""];group.tag=category;group.toolTip=hint;
        NSMenu *children=[[NSMenu alloc]initWithTitle:title];children.autoenablesItems=NO;
        for(NSUInteger i=start;i<end;i++)[children addItem:sorted[i]];
        group.submenu=children;[menu addItem:group];
    }
}
