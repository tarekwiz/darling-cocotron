#ifndef _CGDirectDisplay_H_
#define _CGDirectDisplay_H_

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFAvailability.h>
#include <stdint.h>

#include <CoreGraphics/CGContext.h>
#include <CoreGraphics/CGError.h>
#include <CoreGraphics/CGGeometry.h>
#include <CoreGraphics/CGWindow.h>
#include <CoreGraphics/CGWindowLevel.h>
#include <mach/boolean.h>

typedef uint32_t CGDirectDisplayID;
typedef uint32_t CGOpenGLDisplayMask;
typedef double CGRefreshRate;

typedef struct CF_BRIDGED_TYPE(id) CGDisplayMode *CGDisplayModeRef;

#define kCGNullDirectDisplay ((CGDirectDisplayID)0)
#define kCGDirectMainDisplay CGMainDisplayID()

CF_IMPLICIT_BRIDGING_ENABLED

CF_ASSUME_NONNULL_BEGIN

COREGRAPHICS_EXPORT CGError CGReleaseAllDisplays(void);

#define kCGDisplayWidth                     CFSTR("Width")
#define kCGDisplayHeight                    CFSTR("Height")
#define kCGDisplayMode                      CFSTR("Mode")
#define kCGDisplayBitsPerPixel              CFSTR("BitsPerPixel")
#define kCGDisplayBitsPerSample             CFSTR("BitsPerSample")
#define kCGDisplaySamplesPerPixel           CFSTR("SamplesPerPixel")
#define kCGDisplayRefreshRate               CFSTR("RefreshRate")
#define kCGDisplayModeUsableForDesktopGUI	CFSTR("UsableForDesktopGUI")
#define kCGDisplayIOFlags                   CFSTR("IOFlags")
#define kCGDisplayBytesPerRow               CFSTR("kCGDisplayBytesPerRow")
#define kCGIODisplayModeID                  CFSTR("IODisplayModeID")

#define kCGDisplayModeIsSafeForHardware             \
  CFSTR("kCGDisplayModeIsSafeForHardware")
#define kCGDisplayModeIsInterlaced					\
  CFSTR("kCGDisplayModeIsInterlaced") 
#define kCGDisplayModeIsStretched					\
  CFSTR("kCGDisplayModeIsStretched")
#define kCGDisplayModeIsTelevisionOutput            \
  CFSTR("kCGDisplayModeIsTelevisionOutput")

CF_ASSUME_NONNULL_END
CF_IMPLICIT_BRIDGING_DISABLED

#endif