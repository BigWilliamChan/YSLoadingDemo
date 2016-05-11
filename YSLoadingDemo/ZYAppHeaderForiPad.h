//
//  ZYAppHeaderForiPad.h
//  Cinema
//
//  Created by luzhiyong on 15/12/24.
//  Copyright © 2015年 tianqiwang. All rights reserved.
//

#ifndef ZYAppHeaderForiPad_h
#define ZYAppHeaderForiPad_h

#pragma mark - 默认参数

#define QI_YE_BAN     0
#define APP_CHANNEL @"App Store"  //企业版的发布渠道，APP Store版不需要传

#define RELEASE_VERSION     1
#define APP_GLOBAL_SEARCH @"global_search_version_1.0.2"

#if QI_YE_BAN
#define KAPI_CHANNEL    @"2345ysm1"//渠道
#else
#define KAPI_CHANNEL    @"appstore"//渠道
#endif

#pragma mark - Keys

#define UMENG_KEY    @"567a72fa67e58e3ea5000f81"
#define BUGLY_KEY    @"900016050"

#define qqID         @"1101359651"
#define qqKey        @"oTjq42ANdV69NNs6"

#define wechatKey    @"wxfadc5846b0cb1fdc"
#define wechatSecret @"1a43f92707ce9e90a932933c1c7fff67"

#define qqURL @"http://sailfish.io/api/v1/apps/death-clock-website/5437b58e31302d36e5300000/smart_link?p=ios"

#define projectId   @"ipadys"

/** 百度广告Tag */
#define BaiDuAdUnitTag  @"2414069"
#define BaiDuPublisherId @"f4f691b6"

#if RELEASE_VERSION

//留言板
static NSString *const APP_ID = @"10";
static NSString *const APP_KEY = @"5c40973d08f049541cb602f48976364a";

//移动武林榜
#define k50Bang_KEY   @"19188aa93dd64015f2ac567bd5d672d6" //加密的key
#define kProjectName  @"movie_os_pad" //项目名

#else

//留言板
static NSString *const APP_ID  = @"8";
static NSString *const APP_KEY = @"b32073438dc032d9b04a161e167e04dc";

//移动武林榜
#define k50Bang_KEY   @"471a61bba9792ae138ece4c69668e90a" //测试的加密的key
#define kProjectName  @"test" //测试的项目名

#endif

// APP_STORE_ID
#define APP_STORE_ID [[[NSBundle mainBundle] objectForInfoDictionaryKey:@"APP_STORE_ID"] longValue]

// 播放器播放地址失败统计

static NSString *const FromServerCatchType = @"0"; //来源服务器入库地址
static NSString *const FromPhpCatchType = @"1"; //PHP接口抓取
static NSString *const FromPluginCatchType = @"2"; //插件架包抓取
static NSString *const FromJSCatchType = @"3"; //js抓取
static NSString *const NetworkTimeout = @"1"; //请求网络超时
static NSString *const PluginCatchRuleChanged = @"3"; //插件架包抓取规则变化
static NSString *const UrlError = @"4"; //抓取到的地址不能播放
static NSString *const PluginWebParamError = @"6"; //网页不能提供插件抓取所需的参数
static NSString *const GetUrlFailed = @"7"; //获取到的数据404或者403等 没有数据
static NSString *const UrlPlaySuccess = @"8"; //获取到的地址成功播放
static NSString *const UserClickToPlay = @"9"; //用户点击播放按钮
static NSString *const DefaultErrorCode = @"-2345"; //未打开播放器的情况下的错误统计，默认值为-2345

//通知
#define NETWORK_NOT_REACH @"NetworkNotReachNotification"
#define NETWORK_WAAN_REACH @"NetworkWaanReachNotification"
#define NETWORK_WIFI_REACH @"NetworkWifiReachNotification"
#define DOWNLOAD_FINSHED_NOTIFICATION @"DownloadFinishedNotification"
#define DOWNLOAD_STATE_CHANGE_NOTIFICATION @"DownloadStateChangeNotification"
#define DOWNLOAD_STATE_NOSPACE_NOTIFICATION @"DownloadStateNoSpaceNotification"
#define PushDetails @"pushDetailsNotification"
#define PushShortVideo @"pushShortVideoNotification"

// 宏方法
#define SetUserDefault(x,y) [[NSUserDefaults standardUserDefaults] setObject:x forKey:y];\
[[NSUserDefaults standardUserDefaults] synchronize]
#define GetUserDefault(x) [[NSUserDefaults standardUserDefaults] objectForKey:x]

#define WS(weakSelf)    __weak __typeof(&*self)weakSelf = self;

//屏幕尺寸

#define ThreeInch ([UIScreen mainScreen].bounds.size.height == 480.0)
#define FourInch ([UIScreen mainScreen].bounds.size.height == 568.0)
#define FourSevenInch ([UIScreen mainScreen].bounds.size.height == 667.0)
#define FiveInch ([UIScreen mainScreen].bounds.size.height == 736.0)
#define IpadInch (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

//版本
#define IOS_VERSION_9_OR_ABOVE (([[[UIDevice currentDevice] systemVersion] floatValue] >= 9.0)? (YES):(NO))
#define IOS_VERSION_8_OR_ABOVE (([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)? (YES):(NO))
#define IOS_VERSION_7_OR_ABOVE (([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0)? (YES):(NO))
#define IOS_VERSION_6_OR_ABOVE (([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0)? (YES):(NO))


#define TICK   NSDate *startTime = [NSDate date]
#define TOCK   NSLog(@"执行时间⌚️Time: %f", -[startTime timeIntervalSinceNow])
//颜色
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define APP_BG_COLOR [UIColor colorWithRed:245/255.f green:245/255.f blue:245/255.f alpha:1.f]
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue &0xFF00) >>8))/255.0 blue:((float)(rgbValue &0xFF))/255.0 alpha:1.0]
#define RGBCOLORV(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:1.0]
#define RGBCOLORVA(rgbValue, alphaValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0x00FF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0x0000FF))/255.0 \
alpha:alphaValue]

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
#define MB_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
boundingRectWithSize:maxSize options:(NSStringDrawingUsesLineFragmentOrigin) \
attributes:@{NSFontAttributeName:font} context:nil].size : CGSizeZero;
#else
#define MB_MULTILINE_TEXTSIZE(text, font, maxSize, mode) [text length] > 0 ? [text \
sizeWithFont:font constrainedToSize:maxSize lineBreakMode:mode] : CGSizeZero;
#endif


#define SCREEN_WIDTH  CGRectGetWidth([UIScreen mainScreen].bounds)
#define SCREEN_HEIGHT CGRectGetHeight([UIScreen mainScreen].bounds)

#define VIDEO_WIDTH  MAX(CGRectGetWidth([UIScreen mainScreen].bounds),CGRectGetHeight([UIScreen mainScreen].bounds))
#define VIDEO_HEIGHT MIN(CGRectGetWidth([UIScreen mainScreen].bounds),CGRectGetHeight([UIScreen mainScreen].bounds))

#define kCOLOR(ColorName)           [UIColor ColorName]
#define kRGBCOLOR(r,g,b)            [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define kRGBACOLOR(r,g,b,a)         [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]
#define kIMAGE(ImageName)           [UIImage imageNamed:ImageName]
#define kFONT(FontSize)             [UIFont systemFontOfSize:FontSize]
#define kBOLDFONT(FontSize)         [UIFont boldSystemFontOfSize:FontSize]
#define kSEL(SELName)               @selector(SELName)
#define kPoint(x,y)                 CGPointMake(x,y)

#define kFrame(x,y,width,height)    CGRectMake(x, y, width, height)
#define kSize(width,height)         CGSizeMake(width,height)
#define kBOUNDS                     self.view.bounds


//频道channel类型
#define CHANNEL_TYPE_NEWS   @"xw"   //新闻
#define CHANNEL_TYPE_TV     @"tv"   //电视剧
#define CHANNEL_TYPE_DY     @"dy"   //电影
#define CHANNEL_TYPE_ZY     @"zy"   //综艺
#define CHANNEL_TYPE_DM     @"dm"   //动漫
#define CHANNEL_TYPE_QT     @"qt"   //其他
#define CHANNEL_TYPE_XZ     @"dlRecommend"   //下载专区
#define CHANNEL_TYPE_CT     @"custom"   //自定义频道
#define CHANNEL_TYPE_MZT     @"customList"   //更多专题
#define CHANNEL_TYPE_SVW     @"shortVideo_wasu"   //短视频
#define CHANNEL_TYPE_AD		@"ad"	//广告
#define CHANNEL_TYPE_ZB     @"zb"   //直播

//视频类型
#define VIDEO_TYPE_RB       @"rb" //热播
#define VIDEO_TYPE_GQ       @"gq" //高清
#define VIDEO_TYPE_YG       @"yg" //预告
#define VIDEO_TYPE_ZT       @"zt" //专题
#define VIDEO_TYPE_DM       @"dm" //动漫
#define VIDEO_TYPE_ZB       @"zb" //直播
#define VIDEO_TYPE_DY       @"dy" //电影
#define VIDEO_TYPE_TV       @"tv" //电视剧
#define VIDEO_TYPE_ZY       @"zy" //综艺
#define VIDEO_TYPE_DB       @"db" //独播
#define VIDEO_TYPE_RF       @"rf" //新番
#define VIDEO_TYPE_XJ       @"xj" //新剧
#define VIDEO_TYPE_SB       @"sb" //首播
#define VIDEO_TYPE_RQ       @"rq" //人气
#define VIDEO_TYPE_DSJ      @"dsj" //电视剧

//图片模板的类型
#define CHANNEL_PICTYPE_ONE   @"1"//三分之一
#define CHANNEL_PICTYPE_TWO   @"2"//二分之一
#define CHANNEL_PICTYPE_THREE @"3"//三分之二
#define CHANNEL_PICTYPE_FOUR  @"4"//通栏

//焦点图的比率   高/宽
#define RECOMMEND_TOP_FOCUS_RATE   150.0/320.0

//图片模板的比率  高/宽
#define CHANNEL_PICTYPE_RATE_ONE   126.0/93.0 //三分之一的比率
#define CHANNEL_PICTYPE_RATE_TWO   82.0/145.0//首页 二分之一的比率
#define CHANNEL_PICTYPE_RATE_THREE 126.0/197.0//三分之二的比率
#define CHANNEL_PICTYPE_RATE_FOUR  126.0/300.0//全屏的比率

#define CHANNEL_PICTYPE_RATE_TWO_RECOMMEND   84.0/145.0//首页 二分之一的比率
#define CHANNEL_PICTYPE_RATE_FOUR_ZT 107.0/300.0 //专题图片

#define kWidthCollectionViewSpacing 10.0 //两个cell上下左右之间的间距  cell和边框的间距

//每页显示的数量
#define LIST_PERPAGE 18


//频道详情Ctl类型
#define Ctl_TYPE_TV @"tvDetail"   //电视剧
#define Ctl_TYPE_DY @"dyDetail"   //电影
#define Ctl_TYPE_ZY @"zyDetail"   //综艺
#define Ctl_TYPE_DM @"dmDetail"   //动漫
#define Ctl_TYPE_QT @"qtDetail"   //其他

//清晰度
#define NORMAL_DEFINITION      @"标清" //标清
#define HEIGHT_DEFINITION      @"高清" //高清
#define SUPER_DEFINITION       @"超清" //超清

#define kTipAlert(_S_, ...)     [[[UIAlertView alloc] initWithTitle:@"提示" message:[NSString stringWithFormat:(_S_), ##__VA_ARGS__] delegate:nil cancelButtonTitle:@"知道了" otherButtonTitles:nil] show]

//6Plus适配宏定义
#define NavigationTitleFont [UIFont systemFontOfSize:20.0f] //导航栏标题字体
#define SelectionTitleFont ([UIScreen mainScreen].bounds.size.height == 736.0)?[UIFont systemFontOfSize:15.0f]:[UIFont systemFontOfSize:13.0f] //左右滑动tab字体
#define ChannelSelectionTitleFont ([UIScreen mainScreen].bounds.size.height == 736.0)?[UIFont systemFontOfSize:16.0f]:[UIFont systemFontOfSize:14.0f] //频道左右滑动tab字体

//lua文件存储路径
#define YSLuaResponseObjectFile [[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingPathComponent:@"luaResponseObject.data"]


/** 影视CellID */
static NSString * const StyleOneCellReuseIdentify =		@"StyleOneCollectionViewCell";
static NSString * const StyleTwoCellReuseIdentify =		@"StyleTwoCollectionViewCell";
static NSString * const StyleThreeCellReuseIdentify =	@"StyleThreeCollectionViewCell";
static NSString * const RanListCellReuseIdentify =	@"RanListCollectionViewCell";

static NSString * const HeaderReuseIdentify = @"HeaderCollectionReusableView";
static NSString * const BannerReusableIdentify = @"BannerCollectionReusableView";

static NSString * const downloadingCollectionCell = @"DownloadingCollectionCell";
static NSString * const downloadedCollectionCell = @"DownloadedCollectionCell";

static NSString * const downloadingTableViewCell = @"DownloadingTableViewCell";
static NSString * const downloadedTableViewCell = @"DownloadedTableViewCell";

static NSString * const specialTopicCell = @"specialTopicCell";

/** 详情页的CellID */
static NSString * const VideoDetailsFloorOneIdentify = @"cell1";
static NSString * const VideoDetailsFloorTwoIdentify = @"cell2";
static NSString * const VideoDetailsFloorThreeIdentify = @"cell3";
static NSString * const VideoDetailsFloorFourIdentify = @"cell4";
static NSString * const VideoDetailsFloorFiveIdentify = @"cell5";


#endif /* ZYAppHeaderForiPad_h */
