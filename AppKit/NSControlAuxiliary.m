#import "AppKit/NSControlAuxiliary.h"

@implementation NSControlAuxiliary

- (long long) tag {
    return _tag;
}

- (void) setTag: (long long) tag {
    _tag = tag;
}

- (id) target {
    return _target;
}

- (void) setTarget: (id) target {
    // weak
    _target = target;
}

- (SEL) action {
    return _action;
}

- (void) setAction: (SEL) action {
    _action = action;
}

@end
