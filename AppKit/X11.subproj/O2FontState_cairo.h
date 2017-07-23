#import <Onyx2D/O2Geometry.h>

#ifdef DARLING
#define __linux__
#endif

#import <cairo/cairo-ft.h>

#ifdef DARLING
#undef __linux__
#endif

@class O2Font_FT;

@interface O2FontState_cairo : NSObject {
    O2Font_FT *_font;
    O2Float _size;
    cairo_font_face_t *_cairo_font_face;
}

- initWithFreeTypeFont:(O2Font_FT *)font size:(O2Float)size;

- (cairo_font_face_t *)cairo_font_face;

@end
