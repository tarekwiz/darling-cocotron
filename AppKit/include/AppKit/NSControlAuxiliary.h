#import <Foundation/Foundation.h>

@interface NSControlAuxiliary : NSObject {
    long long _tag;
    id _target;
    SEL _action;
}

- (id) target;
- (SEL) action;
- (long long) tag;

- (void) setTag: (long long) tag;
- (void) setAction: (SEL) action;
- (void) setTarget: (id) target;

@end
