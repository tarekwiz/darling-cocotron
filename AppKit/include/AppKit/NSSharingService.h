#import <AppKit/AppKitDefines.h>
#import <AppKit/NSPasteboard.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSItemProvider.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSArray.h>

#define NS_SHARING_SERVICE_DELEGATE_TRANSITION_IMAGE_FOR_SHARE_ITEM_DECLARES_NULLABILITY (1)

@class NSString, NSImage, NSView, NSError, NSWindow;
@class CKShare, CKContainer;

NS_ASSUME_NONNULL_BEGIN

APPKIT_EXTERN NSString * const NSSharingServiceNamePostOnFacebook NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostOnTwitter NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostOnSinaWeibo NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostOnTencentWeibo NS_AVAILABLE_MAC(10_9);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostOnLinkedIn NS_AVAILABLE_MAC(10_9);
APPKIT_EXTERN NSString * const NSSharingServiceNameComposeEmail NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameComposeMessage NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameSendViaAirDrop NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameAddToSafariReadingList NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameAddToIPhoto NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameAddToAperture NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameUseAsTwitterProfileImage NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNameUseAsFacebookProfileImage NS_AVAILABLE_MAC(10_9);
APPKIT_EXTERN NSString * const NSSharingServiceNameUseAsLinkedInProfileImage NS_AVAILABLE_MAC(10_9);
APPKIT_EXTERN NSString * const NSSharingServiceNameUseAsDesktopPicture NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostImageOnFlickr NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostVideoOnVimeo NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostVideoOnYouku NS_AVAILABLE_MAC(10_8);
APPKIT_EXTERN NSString * const NSSharingServiceNamePostVideoOnTudou NS_AVAILABLE_MAC(10_8);

APPKIT_EXTERN NSString * const NSSharingServiceNameCloudSharing NS_AVAILABLE_MAC(10_12);


@protocol NSSharingServiceDelegate;

NS_CLASS_AVAILABLE(10_8, NA)
@interface NSSharingService : NSObject {
@private
    id _reserved;
}
@property (nullable, assign) id <NSSharingServiceDelegate> delegate;
@property (readonly, copy) NSString *title;
@property (readonly, strong) NSImage *image;
@property (nullable, readonly, strong) NSImage *alternateImage;

@property (copy) NSString *menuItemTitle NS_AVAILABLE_MAC(10_9);

@property (nullable, copy) NSArray<NSString *> *recipients NS_AVAILABLE_MAC(10_9);

@property (nullable, copy) NSString *subject NS_AVAILABLE_MAC(10_9);

@property (nullable, readonly, copy) NSString *messageBody NS_AVAILABLE_MAC(10_9);

@property (nullable, readonly, copy) NSURL *permanentLink NS_AVAILABLE_MAC(10_9);

@property (nullable, readonly, copy) NSString *accountName NS_AVAILABLE_MAC(10_9);

@property (nullable, readonly, copy) NSArray<NSURL *> *attachmentFileURLs NS_AVAILABLE_MAC(10_9);

+ (NSArray<NSSharingService *> *)sharingServicesForItems:(NSArray *)items;

+ (nullable NSSharingService *)sharingServiceNamed:(NSString *)serviceName;

- (instancetype)initWithTitle:(NSString *)title image:(NSImage *)image alternateImage:(nullable NSImage *)alternateImage handler:(void (^)(void))block NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (BOOL)canPerformWithItems:(nullable NSArray *)items;

- (void)performWithItems:(NSArray *)items;

@end

typedef NS_ENUM(NSInteger, NSSharingContentScope) {
    NSSharingContentScopeItem,
    NSSharingContentScopePartial,
    NSSharingContentScopeFull
}  NS_ENUM_AVAILABLE_MAC(10_8);

@protocol NSSharingServiceDelegate <NSObject>
@optional
- (void)sharingService:(NSSharingService *)sharingService willShareItems:(NSArray *)items;
- (void)sharingService:(NSSharingService *)sharingService didFailToShareItems:(NSArray *)items error:(NSError *)error;
- (void)sharingService:(NSSharingService *)sharingService didShareItems:(NSArray *)items;

- (NSRect)sharingService:(NSSharingService *)sharingService sourceFrameOnScreenForShareItem:(id)item;
#if NS_SHARING_SERVICE_DELEGATE_TRANSITION_IMAGE_FOR_SHARE_ITEM_DECLARES_NULLABILITY

- (nullable NSImage *)sharingService:(NSSharingService *)sharingService transitionImageForShareItem:(id)item contentRect:(NSRect *)contentRect;
#else
- (NSImage *)sharingService:(NSSharingService *)sharingService transitionImageForShareItem:(id)item contentRect:(NSRect *)contentRect;
#endif
- (nullable NSWindow *)sharingService:(NSSharingService *)sharingService sourceWindowForShareItems:(NSArray *)items sharingContentScope:(NSSharingContentScope *)sharingContentScope;

- (nullable NSView *)anchoringViewForSharingService:(NSSharingService *)sharingService showRelativeToRect:(NSRect *)positioningRect preferredEdge:(NSRectEdge *)preferredEdge;

@end


typedef NS_OPTIONS(NSUInteger, NSCloudKitSharingServiceOptions) {
    NSCloudKitSharingServiceStandard = 0,
    NSCloudKitSharingServiceAllowPublic = 1 << 0,
    NSCloudKitSharingServiceAllowPrivate = 1 << 1,
    NSCloudKitSharingServiceAllowReadOnly = 1 << 4,
    NSCloudKitSharingServiceAllowReadWrite = 1 << 5,
} NS_ENUM_AVAILABLE_MAC(10_12);

@protocol NSCloudSharingServiceDelegate <NSSharingServiceDelegate>
@optional

- (void)sharingService:(NSSharingService *)sharingService didCompleteForItems:(NSArray *)items error:(nullable NSError *)error;

#if __OBJC2__

- (NSCloudKitSharingServiceOptions)optionsForSharingService:(NSSharingService *)cloudKitSharingService shareProvider:(NSItemProvider *)provider;

#endif

- (void)sharingService:(NSSharingService *)sharingService didSaveShare:(CKShare *)share;

- (void)sharingService:(NSSharingService *)sharingService didStopSharing:(CKShare *)share;

@end

#if __OBJC2__

@interface NSItemProvider (NSCloudKitSharing)

- (void)registerCloudKitShareWithPreparationHandler:(void (^_Nonnull)(void (^ _Nonnull preparationCompletionHandler)(CKShare * _Nullable, CKContainer * _Nullable, NSError * _Nullable)))preparationHandler NS_AVAILABLE_MAC(10_12);

- (void)registerCloudKitShare:(CKShare *)share container:(CKContainer *)container NS_AVAILABLE_MAC(10_12);

@end

#endif



@protocol NSSharingServicePickerDelegate;

NS_CLASS_AVAILABLE(10_8, NA)
@interface NSSharingServicePicker : NSObject 
{
@private
    id _reserved;
}

@property (nullable, assign) id <NSSharingServicePickerDelegate> delegate;

- (instancetype)initWithItems:(NSArray *)items NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

- (void)showRelativeToRect:(NSRect)rect ofView:(NSView *)view preferredEdge:(NSRectEdge)preferredEdge;

@end


@protocol NSSharingServicePickerDelegate <NSObject>
@optional

- (NSArray<NSSharingService *> *)sharingServicePicker:(NSSharingServicePicker *)sharingServicePicker sharingServicesForItems:(NSArray *)items proposedSharingServices:(NSArray<NSSharingService *> *)proposedServices;

- (nullable id <NSSharingServiceDelegate>)sharingServicePicker:(NSSharingServicePicker *)sharingServicePicker delegateForSharingService:(NSSharingService *)sharingService;

- (void)sharingServicePicker:(NSSharingServicePicker *)sharingServicePicker didChooseSharingService:(nullable NSSharingService *)service;

@end

NS_ASSUME_NONNULL_END
