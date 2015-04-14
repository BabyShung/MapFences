//
//  DBMapSelectorGestureRecognizer.m
//  DBMapSelectorViewControllerExample
//
//  Created by Denis Bogatyrev on 28.03.15.
//  Copyright (c) 2015 Denis Bogatyrev. All rights reserved.
//

#import "GeoFencesGestureRecognizer.h"

@implementation GeoFencesGestureRecognizer

- (instancetype)init {
    if (self = [super init])
    {
        self.cancelsTouchesInView = NO;
    }
    return self;
}

#pragma mark - overriding

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (self.touchesBeganCallback) {
        self.touchesBeganCallback(touches, event);
    }
}

- (void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    if (self.touchesCanceledCallback) {
        self.touchesCanceledCallback(touches, event);
    }
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    if(self.touchesEndedCallback) {
        self.touchesEndedCallback(touches, event);
    }
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event {
    if(self.touchesMovedCallback) {
        self.touchesMovedCallback(touches, event);
    }
}

- (void)reset
{
}

- (void)ignoreTouch:(UITouch *)touch forEvent:(UIEvent *)event
{
}

- (BOOL)canBePreventedByGestureRecognizer:(UIGestureRecognizer *)preventingGestureRecognizer
{
    return NO;
}

- (BOOL)canPreventGestureRecognizer:(UIGestureRecognizer *)preventedGestureRecognizer
{
    return NO;
}

@end
