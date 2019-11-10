/*
 This file is part of Darling.

 Copyright (C) 2019 Lubos Dolezel

 Darling is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 Darling is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with Darling.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <IOKit/graphics/IOGraphicsLib.h>
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CGDirectDisplay.h>
#include <CoreGraphics/CGGeometry.h>

typedef float CGGammaValue;
typedef int32_t CGWindowLevel;

static int verbose = 0;

__attribute__((constructor))
static void initme(void) {
    verbose = getenv("STUB_VERBOSE") != NULL;
}

CGError CGDisplayShowCursor(CGDirectDisplayID display)
{
    if (verbose) puts("STUB: CGDisplayShowCursor called");
	return (CGError)0;
}

boolean_t CGCursorIsVisible(void)
{
    if (verbose) puts("STUB: CGCursorIsVisible called");
	return true;
}

CFArrayRef CGDisplayAvailableModes(CGDirectDisplayID a)
{
	// Usual keys: Width, Height, Mode, BitsPerPixel, SamplesPerPixel, RefreshRate, UsableForDesktopGUI, IOFlags, kCGDisplayBytesPerRow, IODisplayModeID

    if (verbose) puts("STUB: CGDisplayAvailableModes called");

    CFTypeRef arrayValues[ 1 ];

    CFTypeRef dummyDisplayKeys[ 3 ];
    CFTypeRef dummyDisplayValues[ 3 ];

    dummyDisplayKeys[0] = CFSTR("Width");
    dummyDisplayKeys[1] = CFSTR("Height");
    dummyDisplayKeys[2] = CFSTR("BitsPerPixel");

    // TODO: put some real values here
    int val = 640;
    dummyDisplayValues[0] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &val);
    val = 480;
    dummyDisplayValues[1] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &val);
    val = 32;
    dummyDisplayValues[2] = CFNumberCreate(kCFAllocatorDefault, kCFNumberSInt32Type, &val);

    CFDictionaryRef dictionary = CFDictionaryCreate(
        kCFAllocatorDefault,
        (const void **)&dummyDisplayKeys,
        (const void **)&dummyDisplayValues,
        3,
        &kCFTypeDictionaryKeyCallBacks,
        &kCFTypeDictionaryValueCallBacks
    );

    arrayValues[0] = dictionary;

    CFArrayRef ret = CFArrayCreate(kCFAllocatorDefault, 
    	                      &arrayValues, 
    	                      1, 
    	                      &kCFTypeArrayCallBacks);

    CFRelease(dummyDisplayValues[0]);
    CFRelease(dummyDisplayValues[1]);
    CFRelease(dummyDisplayValues[2]);

    // TODO: autorelease ret?
	return ret;
}

CGRect CGDisplayBounds(CGDirectDisplayID a)
{
    if (verbose) puts("STUB: CGDisplayBounds called");
	return CGRectMake(0,0,640,480);
}

CGError CGDisplayHideCursor(CGDirectDisplayID a)
{
    if (verbose) puts("STUB: CGDisplayHideCursor called");
	return (CGError)0;
}

CGOpenGLDisplayMask CGDisplayIDToOpenGLDisplayMask(CGDirectDisplayID a)
{
    if (verbose) puts("STUB: CGDisplayIDToOpenGLDisplayMask called");
	return 0;
}

CGError CGDisplayMoveCursorToPoint(CGDirectDisplayID a, CGPoint b)
{
    if (verbose) puts("STUB: CGDisplayMoveCursorToPoint called");
	return (CGError)0;
}

void CGDisplayRestoreColorSyncSettings(void)
{
    if (verbose) puts("STUB: CGDisplayRestoreColorSyncSettings called");
	
}

CGError CGGetActiveDisplayList(uint32_t maxDisplays, CGDirectDisplayID *activeDspys, uint32_t *dspyCnt)
{
    if (verbose) puts("STUB: CGGetActiveDisplayList called");
    
    if(dspyCnt)
        *dspyCnt = 1;

    if(activeDspys)
        *activeDspys = 1;
    
	return (CGError)0;
}

CGError CGGetDisplayTransferByFormula(CGDirectDisplayID a, CGGammaValue *b, CGGammaValue *c, CGGammaValue *d, CGGammaValue *e, CGGammaValue *f, CGGammaValue *g, CGGammaValue *h, CGGammaValue *i, CGGammaValue *j)
{
    if (verbose) puts("STUB: CGGetDisplayTransferByFormula called");
	return (CGError)0;
}

CGError CGGetDisplayTransferByTable(CGDirectDisplayID a, uint32_t b, CGGammaValue *c, CGGammaValue *d, CGGammaValue *e, uint32_t *f)
{
    if (verbose) puts("STUB: CGGetDisplayTransferByTable called");
	return (CGError)0;
}

void CGGetLastMouseDelta(int32_t *a, int32_t *b)
{
    if (verbose) puts("STUB: CGGetLastMouseDelta called");
	
}

CGDirectDisplayID CGMainDisplayID(void)
{
    if (verbose) puts("STUB: CGMainDisplayID called");
	return (CGDirectDisplayID)1;
}

CGError CGSetDisplayTransferByFormula(CGDirectDisplayID a, CGGammaValue b, CGGammaValue c, CGGammaValue d, CGGammaValue e, CGGammaValue f, CGGammaValue g, CGGammaValue h, CGGammaValue i, CGGammaValue j)
{
    if (verbose) puts("STUB: CGSetDisplayTransferByFormula called");
	return (CGError)0;
}

CGError CGSetDisplayTransferByTable(CGDirectDisplayID a, uint32_t b, const CGGammaValue *c, const CGGammaValue *d, const CGGammaValue *e)
{
    if (verbose) puts("STUB: CGSetDisplayTransferByTable called");
	return (CGError)0;
}

CGError CGSetLocalEventsSuppressionInterval(CFTimeInterval a)
{
    if (verbose) puts("STUB: CGSetLocalEventsSuppressionInterval called");
	return (CGError)0;
}

CGWindowLevel CGShieldingWindowLevel(void)
{
    if (verbose) puts("STUB: CGShieldingWindowLevel called");
	return 0;
}

io_service_t IOServicePortFromCGDisplayID(CGDirectDisplayID displayID)
{
    io_iterator_t iter;
    io_service_t serv, servicePort = 0;
    
    CFMutableDictionaryRef matching = IOServiceMatching("IODisplayConnect");
    
    // releases matching for us
    kern_return_t err = IOServiceGetMatchingServices(kIOMasterPortDefault,
                                                     matching,
                                                     &iter);
    if (err)
        return 0;
    
    while ((serv = IOIteratorNext(iter)) != 0)
    {
        CFDictionaryRef info;
        CFIndex vendorID, productID, serialNumber;
        CFNumberRef vendorIDRef, productIDRef, serialNumberRef;
        Boolean success;
        
        info = IODisplayCreateInfoDictionary(serv,
                                             kIODisplayOnlyPreferredName);
        
        vendorIDRef = CFDictionaryGetValue(info,
                                           CFSTR(kDisplayVendorID));
        productIDRef = CFDictionaryGetValue(info,
                                            CFSTR(kDisplayProductID));
        serialNumberRef = CFDictionaryGetValue(info,
                                               CFSTR(kDisplaySerialNumber));
        
        success = CFNumberGetValue(vendorIDRef, kCFNumberCFIndexType,
                                   &vendorID);
        success &= CFNumberGetValue(productIDRef, kCFNumberCFIndexType,
                                    &productID);
        success &= CFNumberGetValue(serialNumberRef, kCFNumberCFIndexType,
                                    &serialNumber);
        
        if (!success)
        {
            CFRelease(info);
            continue;
        }
        
        // If the vendor and product id along with the serial don't match
        // then we are not looking at the correct monitor.
        // NOTE: The serial number is important in cases where two monitors
        //       are the exact same.
        // if (CGDisplayVendorNumber(displayID) != vendorID  ||
        //     CGDisplayModelNumber(displayID) != productID  ||
        //     CGDisplaySerialNumber(displayID) != serialNumber)
        // {
        //     CFRelease(info);
        //     continue;
        // }
        
        // The VendorID, Product ID, and the Serial Number all Match Up!
        // Therefore we have found the appropriate display io_service
        servicePort = serv;
        CFRelease(info);
        break;
    }
    
    IOObjectRelease(iter);
    return servicePort;
}