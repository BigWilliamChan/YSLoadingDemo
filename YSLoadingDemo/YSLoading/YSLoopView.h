//
//  YSLoopView.h
//  CinemaForiPad
//
//  Created by william on 16/4/1.
//  Copyright © 2016年 2345. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface YSLoopView : UIView

@property (nonatomic, strong) CAMediaTimingFunction *timingFunction;
@property (nonatomic, readonly) BOOL isAnimating;
@property (nonatomic) BOOL hideWhenStop;
@property (nonatomic, strong) UIBezierPath *mTrianglePath;

- (void)setProgressValue:(float)value;
- (void)startLoopAnimating;
- (void)stopLoopAnimating;


@end
