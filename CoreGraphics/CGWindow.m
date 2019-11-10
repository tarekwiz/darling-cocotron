/* Copyright (c) 2006-2007 Christopher J. W. Lloyd <cjwl@objc.net>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
#import <CoreGraphics/CGWindow.h>
#import <Onyx2D/O2Exceptions.h>

const CFStringRef kCGWindowAlpha = CFSTR("kCGWindowAlpha");
const CFStringRef kCGWindowBounds = CFSTR("kCGWindowBounds");
const CFStringRef kCGWindowLayer = CFSTR("kCGWindowLayer");
const CFStringRef kCGWindowOwnerPID = CFSTR("kCGWindowOwnerPID");

@implementation CGWindow

-(void)setDelegate:delegate {
}

-delegate {
   return nil;
}

-(void)invalidate {
}

- (void) syncDelegateProperties {
}


-(O2Context *)cgContext {
   return nil;
}

-(NSUInteger)styleMask {
   return 0;
}

-(void)setLevel:(int)value {
}

-(void)setStyleMask:(NSUInteger)mask {
}

-(void)setTitle:(NSString *)title {
}

-(void)setFrame:(CGRect)frame {
}

-(void)setOpaque:(BOOL)value {
}

-(void)setAlphaValue:(CGFloat)value {
}

-(void)setHasShadow:(BOOL)value {
}

-(void)sheetOrderFrontFromFrame:(NSRect)frame aboveWindow:(CGWindow *)aboveWindow {
}

-(void)sheetOrderOutToFrame:(NSRect)frame {
}

-(void)showWindowForAppActivation:(NSRect)frame {
}

-(void)hideWindowForAppDeactivation:(NSRect)frame {
}

-(void)showWindowWithoutActivation {
}

-(void)hideWindow {
}

// these suck
+windowWithWindowNumber:(NSInteger)windowNumber {
   return (id)windowNumber;
}

-(NSInteger)windowNumber {
   return (NSInteger)self;
}

-(void)placeAboveWindow:(NSInteger)other {
}

-(void)placeBelowWindow:(NSInteger)other {
}


-(void)makeKey {
}

-(void)makeMain {
}

-(void)captureEvents {
}

-(void)miniaturize {
}

-(void)deminiaturize {
}

-(BOOL)isMiniaturized {
   return NO;
}

-(void)disableFlushWindow {
}

-(void)enableFlushWindow {
}

-(void)flushBuffer {
}


-(void)dirtyRect:(CGRect)rect
{
    // Default does nothing - that can be used for optimized redraws
}

-(NSPoint)mouseLocationOutsideOfEventStream {
   return NSZeroPoint;
}


-(void)sendEvent:(CGEvent *)event {
}

-(void)addEntriesToDeviceDictionary:(NSDictionary *)entries {
}

-(void)flashWindow {
}

-(void)addCGLContext:(CGLContextObj)cglContext {
}

-(void)removeCGLContext:(CGLContextObj)cglContext {
}

-(void)flushCGLContext:(CGLContextObj)cglContext {
}

- (CGSubWindow *) createSubWindowWithFrame: (CGRect) frame {
    return nil;
}

@end
