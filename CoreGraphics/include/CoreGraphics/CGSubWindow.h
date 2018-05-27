#import <Foundation/Foundation.h>
#import <CoreGraphics/CGGeometry.h>

@interface CGSubWindow : NSObject

- (void *) nativeWindow;

- (void) show;
- (void) hide;

- (void) setFrame: (CGRect) frame;

@end
