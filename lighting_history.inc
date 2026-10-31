- (void)syncLightingUndoButton {
    self.lightingUndoButton.enabled=!self.calculating&&(self.lightingUndoIndex>0||self.lightingUndoIndex+1<(NSInteger)self.lightingUndoHistory.count);
}
- (void)recordLightingRepaint:(RenderOptions)settings {
    if(self.lightingSliderTracking)return;
    if(self.lightingRestoringHistory){self.lightingRestoringHistory=NO;[self syncLightingUndoButton];return;}
    RenderOptions state=lightingHistoryState(settings);NSData *data=[NSData dataWithBytes:&state length:sizeof state];
    if(!self.lightingUndoHistory)self.lightingUndoHistory=[NSMutableArray array];
    if(self.lightingUndoHistory.count&&[self.lightingUndoHistory[self.lightingUndoIndex] isEqual:data]){[self syncLightingUndoButton];return;}
    if(self.lightingUndoHistory.count&&self.lightingUndoIndex+1<(NSInteger)self.lightingUndoHistory.count)[self.lightingUndoHistory removeObjectsInRange:NSMakeRange(self.lightingUndoIndex+1,self.lightingUndoHistory.count-self.lightingUndoIndex-1)];
    [self.lightingUndoHistory addObject:data];if(self.lightingUndoHistory.count>64)[self.lightingUndoHistory removeObjectAtIndex:0];self.lightingUndoIndex=self.lightingUndoHistory.count-1;[self syncLightingUndoButton];
}
- (void)undoLighting:(id)sender {(void)sender;[self restoreLightingRedo:NO];}
- (void)restoreLightingRedo:(BOOL)redo {
    if(self.calculating)return;NSInteger index=self.lightingUndoIndex+(redo?1:-1);if(index<0||index>=(NSInteger)self.lightingUndoHistory.count)return;
    RenderOptions state;[self.lightingUndoHistory[index] getBytes:&state length:sizeof state];self.lightingUndoIndex=index;self.lightingRestoringHistory=YES;
    [NSObject cancelPreviousPerformRequestsWithTarget:self selector:@selector(finishLightingSlider) object:nil];self.lightingPreviewGeneration++;self.lightingPreviewPending=NO;
    self.formulaSettings=lightingHistoryRestore(self.formulaSettings,state);[self populateObjectLighting];[self syncLightingUndoButton];[self finishLightingSlider];
}
