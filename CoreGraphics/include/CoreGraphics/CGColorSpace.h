/* Copyright (c) 2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#include <CoreFoundation/CoreFoundation.h>

#import <CoreGraphics/CGGeometry.h>

@class O2ColorSpace;
typedef O2ColorSpace *CGColorSpaceRef;

extern const CFStringRef kCGColorSpaceGenericGray;
extern const CFStringRef kCGColorSpaceGenericRGB;
extern const CFStringRef kCGColorSpaceGenericCMYK;
extern const CFStringRef kCGColorSpaceDisplayP3;
extern const CFStringRef kCGColorSpaceGenericRGBLinear;
extern const CFStringRef kCGColorSpaceAdobeRGB1998;
extern const CFStringRef kCGColorSpaceSRGB;
extern const CFStringRef kCGColorSpaceGenericGrayGamma2_2;
extern const CFStringRef kCGColorSpaceGenericXYZ;
extern const CFStringRef kCGColorSpaceGenericLab;
extern const CFStringRef kCGColorSpaceACESCGLinear;
extern const CFStringRef kCGColorSpaceITUR_709;
extern const CFStringRef kCGColorSpaceITUR_2020;
extern const CFStringRef kCGColorSpaceROMMRGB;
extern const CFStringRef kCGColorSpaceDCIP3;
extern const CFStringRef kCGColorSpaceExtendedSRGB;
extern const CFStringRef kCGColorSpaceLinearSRGB;
extern const CFStringRef kCGColorSpaceExtendedLinearSRGB;
extern const CFStringRef kCGColorSpaceExtendedGray;
extern const CFStringRef kCGColorSpaceLinearGray;
extern const CFStringRef kCGColorSpaceExtendedLinearGray;

typedef enum {
    kCGRenderingIntentDefault,
    kCGRenderingIntentAbsoluteColorimetric,
    kCGRenderingIntentRelativeColorimetric,
    kCGRenderingIntentSaturation,
    kCGRenderingIntentPerceptual,
} CGColorRenderingIntent;

typedef enum {
    kCGColorSpaceModelUnknown = -1,
    kCGColorSpaceModelMonochrome,
    kCGColorSpaceModelRGB,
    kCGColorSpaceModelCMYK,
    kCGColorSpaceModelLab,
    kCGColorSpaceModelDeviceN,
    kCGColorSpaceModelIndexed,
    kCGColorSpaceModelPattern,
} CGColorSpaceModel;

COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceRetain(CGColorSpaceRef colorSpace);
COREGRAPHICS_EXPORT void CGColorSpaceRelease(CGColorSpaceRef colorSpace);

COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceRGB();
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceGray();
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreateDeviceCMYK();
COREGRAPHICS_EXPORT CGColorSpaceRef CGColorSpaceCreatePattern(CGColorSpaceRef baseSpace);

COREGRAPHICS_EXPORT CGColorSpaceModel CGColorSpaceGetModel(CGColorSpaceRef self);
COREGRAPHICS_EXPORT size_t CGColorSpaceGetNumberOfComponents(CGColorSpaceRef self);
