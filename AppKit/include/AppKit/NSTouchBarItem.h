#import <AppKit/AppKitDefines.h>

#import <Foundation/Foundation.h>

typedef NSString * NSTouchBarItemIdentifier NS_EXTENSIBLE_STRING_ENUM;

@class NSTouchBar, NSViewController, NSView, NSImage, NSGestureRecognizer;
@class NSString;

NS_ASSUME_NONNULL_BEGIN

typedef float NSTouchBarItemPriority _NS_TYPED_EXTENSIBLE_ENUM NS_AVAILABLE_MAC(10_12_2);

static const NSTouchBarItemPriority NSTouchBarItemPriorityHigh NS_AVAILABLE_MAC(10_12_2) = 1000;
static const NSTouchBarItemPriority NSTouchBarItemPriorityNormal NS_AVAILABLE_MAC(10_12_2) = 0;
static const NSTouchBarItemPriority NSTouchBarItemPriorityLow NS_AVAILABLE_MAC(10_12_2) = -1000;


NS_CLASS_AVAILABLE_MAC(10_12_2)
@interface NSTouchBarItem : NSObject <NSCoding> {
@private
    NSTouchBarItemIdentifier _identifier;
    NSTouchBarItemPriority _visibilityPriority;
    NSInteger _visibilityCount;
    NSMapTable<NSTouchBar *, NSNumber *> *_touchBars;

#if !__OBJC2__
    void *_touchBarItemReserved[4] __unused;
#endif
}

- (instancetype)initWithIdentifier:(NSTouchBarItemIdentifier)identifier NS_DESIGNATED_INITIALIZER;

- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

@property (readonly, copy) NSTouchBarItemIdentifier identifier;

@property NSTouchBarItemPriority visibilityPriority;

@property (readonly, nullable) NSView *view;

@property (readonly, nullable) NSViewController *viewController;

@property (readonly, copy) NSString *customizationLabel;

@property (readonly, getter=isVisible) BOOL visible;

@end

APPKIT_EXTERN NSTouchBarItemIdentifier const NSTouchBarItemIdentifierFixedSpaceSmall NS_AVAILABLE_MAC(10_12_2);

APPKIT_EXTERN NSTouchBarItemIdentifier const NSTouchBarItemIdentifierFixedSpaceLarge NS_AVAILABLE_MAC(10_12_2);

APPKIT_EXTERN NSTouchBarItemIdentifier const NSTouchBarItemIdentifierFlexibleSpace NS_AVAILABLE_MAC(10_12_2);

APPKIT_EXTERN NSTouchBarItemIdentifier const NSTouchBarItemIdentifierOtherItemsProxy NS_AVAILABLE_MAC(10_12_2);

NS_ASSUME_NONNULL_END
