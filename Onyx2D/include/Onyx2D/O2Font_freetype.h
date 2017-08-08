#import <Onyx2D/O2Font.h>
#import "O2Defines_FreeType.h"

#ifdef FREETYPE_PRESENT

#ifdef DARLING
#define __linux__
#endif

#include <ft2build.h>
#include FT_FREETYPE_H

#ifdef DARLING
#undef __linux__
#endif

@interface O2Font_freetype : O2Font {
    FT_Face _face;
    FT_Encoding _ftEncoding;
    O2Encoding *_macRomanEncoding;
    O2Encoding *_macExpertEncoding;
    O2Encoding *_winAnsiEncoding;
}

- initWithDataProvider:(O2DataProviderRef)provider;

FT_Face O2FontFreeTypeFace(O2Font_freetype *self);

@end

#endif
