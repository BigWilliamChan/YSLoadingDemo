# YSLoadingDemo
利用runtime动态增加属性来封装一个全局调用loading效果


> 在ios开发中，category和associative是objective-c的扩展机制的两个特性，category是类型，可以通过它来扩展方法，；不过可以利用associative，通过它来扩展属性。


在平常项目中，这个我们经常用，比如对NSString扩展方法。相对的associative，就用的比较少，要用它必须使用`<objc/runtime.h>`的头文件，然后使用`objc_getAssociatedObject`以及`objc_setAssociatedObject`，我们来看下这两个方法：

```
OBJC_EXPORT void objc_setAssociatedObject(id object, const void *key, id value, objc_AssociationPolicy policy)
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
```

```
OBJC_EXPORT id objc_getAssociatedObject(id object, const void *key)
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
```
另外还有一个方法：
```
OBJC_EXPORT void objc_removeAssociatedObjects(id object)
__OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_3_1);
```
`objc_getAssociatedObject`、`objc_setAssociatedObject`、`objc_removeAssociatedObjects`都是Obj-c中的外联方法，object 参数作为待扩展的对象实例，key作为该对象实例的属性的键，而value就是对象实例的属性的值，policy作为关联的策略，它的枚举包括：

```
typedef OBJC_ENUM(uintptr_t, objc_AssociationPolicy) {
    OBJC_ASSOCIATION_ASSIGN = 0,           /**< Specifies a weak reference to the associated object. */
    OBJC_ASSOCIATION_RETAIN_NONATOMIC = 1, /**< Specifies a strong reference to the associated object. 
                                            *   The association is not made atomically. */
    OBJC_ASSOCIATION_COPY_NONATOMIC = 3,   /**< Specifies that the associated object is copied. 
                                            *   The association is not made atomically. */
    OBJC_ASSOCIATION_RETAIN = 01401,       /**< Specifies a strong reference to the associated object.
                                            *   The association is made atomically. */
    OBJC_ASSOCIATION_COPY = 01403          /**< Specifies that the associated object is copied.
                                            *   The association is made atomically. */
};
```


----------

> 回到正题，我们app的loading需要在很多页面调用，如果每个页面都写创建方法，代码量就太大。放父类中呢，有的页面不需要loading，也不是很好。要是在UIView中加个扩展属性，那就随处可以调用了，并且只在当前UIView中显示loading。

首先，先封装个loading旋转动画，这里就不多阐述了，

```
#import "YSLoopView.h"
```
然后新建一个UIView扩展UIView+Extension.h

```
@interface UIView (Extension)
@property (strong, nonatomic) YSLoadingView *loadingView;
- (void)beginLoading;
- (void)endLoading;
@end

```
这里面loadingView是扩展属性，在.m文件中，我们对他set get方法：

```
@implementation UIView (Extension)
static char LoadingViewKey;
- (void)setLoadingView:(YSLoadingView *)loadingView{
    [self willChangeValueForKey:@"LoadingViewKey"];
    objc_setAssociatedObject(self, &LoadingViewKey,
                             loadingView,                       OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self didChangeValueForKey:@"LoadingViewKey"];
}
- (YSLoadingView*)loadingView{
    return objc_getAssociatedObject(self, &LoadingViewKey);
}
```
这样，我们就可以在扩展方法中调用开始加载方法

```
- (void)beginLoading{
    if (!self.loadingView) {
        self.loadingView = [[YSLoadingView alloc] initWithFrame:self.bounds];
        [self.loadingView.titleLabel setText:@"加载中..."];
    }
    [self addSubview:self.loadingView];
    [self.loadingView startAnimating];
}

```
和停止加载方法

```
- (void)endLoading{
    if (self.loadingView) {
        [self.loadingView stopAnimating];
    }
}
```
![运行截图](https://github.com/chenwei910101/YSLoadingDemo/blob/master/loading.gif?raw=true)
