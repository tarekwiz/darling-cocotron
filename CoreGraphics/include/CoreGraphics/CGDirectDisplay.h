
#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGError.h>

typedef uint32_t CGDirectDisplayID;
typedef uint32_t CGOpenGLDisplayMask;
typedef double CGRefreshRate;

COREGRAPHICS_EXPORT CGError CGReleaseAllDisplays(void);
