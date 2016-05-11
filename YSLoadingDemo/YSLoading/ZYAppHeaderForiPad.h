//
//  ZYAppHeaderForiPad.h
//  Cinema
//
//  Created by luzhiyong on 15/12/24.
//  Copyright © 2015年 tianqiwang. All rights reserved.
//

#ifndef ZYAppHeaderForiPad_h
#define ZYAppHeaderForiPad_h



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

#endif /* ZYAppHeaderForiPad_h */
