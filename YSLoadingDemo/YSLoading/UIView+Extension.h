
#import <UIKit/UIKit.h>
#import "YSLoopView.h"
@class YSLoadingView;

@interface UIView (Extension)

@property (strong, nonatomic) YSLoadingView *loadingView;


- (void)beginLoading;
- (void)endLoading;

@end


//loading加载效果
@interface YSLoadingView : UIView
@property (strong, nonatomic) YSLoopView *loopView;
@property (strong, nonatomic) UILabel *titleLabel;
@property (assign, nonatomic, readonly) BOOL isLoading;
- (void)startAnimating;
- (void)stopAnimating;
@end


