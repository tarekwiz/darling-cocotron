#import <QuartzCore/CABase.h>
#import <CoreFoundation/CoreFoundation.h>

@protocol CAMediaTiming

@property BOOL autoreverses;

@property CFTimeInterval beginTime;

@property CFTimeInterval duration;

@property(copy) NSString *fillMode;

@property CGFloat repeatCount;

@property CFTimeInterval repeatDuration;

@property CGFloat speed;

@property CFTimeInterval timeOffset;

@end
