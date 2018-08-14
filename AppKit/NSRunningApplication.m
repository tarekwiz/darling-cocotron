#import <Foundation/NSObject.h>

// DUMMY

@interface NSRunningApplication : NSObject
@end

@implementation NSRunningApplication
+ (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector
{
	return [NSMethodSignature signatureWithObjCTypes: "v@:"];
}

+ (void)forwardInvocation:(NSInvocation *)anInvocation
{
	NSLog(@"Stub called: %@ in %@", NSStringFromSelector([anInvocation selector]), self);
}
@end

