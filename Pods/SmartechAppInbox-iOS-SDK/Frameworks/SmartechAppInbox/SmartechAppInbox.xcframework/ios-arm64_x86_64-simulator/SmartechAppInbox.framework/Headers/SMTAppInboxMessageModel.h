//
//  SMTAppInboxMessageModel.h
//  SmartechAppInbox
//
//  Created by Netcore Solutions on 20/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SMTInboxMessageStatus) {
    SMTInboxMessageUnread = 1,
    SMTInboxMessageViewed = 2,
    SMTInboxMessageClicked = 3,
    SMTInboxMessageDeleted = 4
};

@class SMTAppInboxMessageModel;
@class SMTAIAps;
@class SMTAIAlert;
@class SMTCustomPayload;
@class SMTAIPayload;
@class SMTAIAttributionParameter;
@class SMTAIActionButton;
@class SMTAICarousel;
@class SMTAIActionButtonConfiguration;
@class SMTNotificationConstants;

#pragma mark - Object interfaces

/**
 @brief This is base model class of Push Notification.
 */
@interface SMTAIBase : NSObject

/**
 @brief This method gives back the dictionary object of self object.
 
 @return NSMutableDictionary The key value pair for self parameters.
 */
- (NSMutableDictionary *)toNSDictionary;

/**
 @brief This method gives back the array object of self object.
 
 @param SMTAIBaseArray - array of self object.
 
 @return NSArray The array of dictionary.
 */
- (NSArray *)SMTAIBaseDictionaryArray :(NSArray <SMTAIBase *> *) SMTAIBaseArray;

@end

API_AVAILABLE(ios(12.0))
/**
 @brief The SMTAppInboxMessageModelValueTransformer class is used to custom object of coredata which is SMTAppInboxMessageModel. It contains full notification payload.
 */
@interface SMTAppInboxMessageModelValueTransformer : NSSecureUnarchiveFromDataTransformer

+ (void)register;
+ (id)transformedValue:(id)value;
+ (id)reverseTransformedValue:(id)value;

@end

/**
 @brief This model class contains complete payload of Push Notification.
 */
@interface SMTAppInboxMessageModel : SMTAIBase <NSSecureCoding>

@property (nonatomic, strong) SMTAIAps *aps;
@property (nonatomic, copy) NSString *source;
@property (nonatomic, strong) SMTAIPayload *smtPayload;
@property (nonatomic, strong) NSDictionary *smtCustomPayload;

@end

/**
 @brief This model class contains APS.
 */
@interface SMTAIAps : SMTAIBase <NSSecureCoding>

@property (nonatomic, strong) SMTAIAlert *alert;
@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *sound;

@end

/**
 @brief This model class contains Alert.
 */
@interface SMTAIAlert : SMTAIBase <NSSecureCoding>

@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, copy) NSString *body;

@end

/**
 @brief This model class contains the actual payload.
 */
@interface SMTAIPayload : SMTAIBase <NSSecureCoding>

@property (nonatomic, copy) NSString *category;
@property (nonatomic, copy) NSString *type;
@property (nonatomic, copy) NSString *trid;
@property (nonatomic, copy) NSString *mediaURL;
@property (nonatomic, copy) NSString *mediaURLPath;
@property (nonatomic, copy) NSString *deeplink;
@property (nonatomic, copy) NSArray <SMTAIActionButton *> *actionButton;
@property (nonatomic, copy) NSArray <SMTAICarousel *> *carousel;
@property (nonatomic, strong) SMTAIAttributionParameter *smtAttribution;
@property (nonatomic, copy) NSDictionary *pnMeta;
@property (nonatomic, copy) NSString *publishedDate;
@property (nonatomic, copy) NSString *status;
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *subtitle;
@property (nonatomic, copy) NSString *body;
@property (nonatomic, copy) NSString *sound;
@property (nonatomic, copy) NSString *collapseKey;
@property (nonatomic, copy) NSString *modifiedDate;
@property (nonatomic, copy) NSString *appInBoxCategory;
@property (nonatomic, copy) NSString *appInBoxTimestamp;
@property (nonatomic, copy) NSString *aappInBoxTtl;
@property (nonatomic, copy) NSString *htTitle;
@property (nonatomic, copy) NSString *htSubtitle;
@property (nonatomic, copy) NSString *htBody;


- (void)deleteStoredMedia;

@end

/**
 @brief This model class contains the attribution parameters.
 */
@interface SMTAIAttributionParameter : SMTAIBase <NSSecureCoding>

// This is used to store the complete attrParams which is used by the smartech server for PN attribution.
@property (nonatomic, copy) NSDictionary *attrParams;

// This variable get value when we break down __sta parameter comming in attrParams.
@property (nonatomic, copy) NSString *attrIdentity;

@end

/**
 @brief This model class contains the action buttons.
 */
@interface SMTAIActionButton : SMTAIBase <NSSecureCoding>

typedef NS_ENUM(NSUInteger, SMTActionType) {
    SMTActionTypeNone = 1,
    SMTActionTypeCopyCode = 2,
    SMTActionTypeDismiss = 3,
    SMTActionTypeSnooze = 4,
    SMTActionTypeReply = 5
};

@property (nonatomic, copy) NSString *actionName;
@property (nonatomic, copy) NSString *actionDeeplink;
@property (nonatomic, copy) NSNumber *actionType;
@property (nonatomic, copy) NSDictionary *actionConfig;

@end

/**
 @brief This model class contains the action buttons configurations.
 */
@interface SMTAIActionButtonConfiguration : SMTAIBase <NSSecureCoding>

@property (nonatomic, copy) NSString *promoCode;
@property (nonatomic, copy) NSString *snoozeInterval;

@end

/**
 @brief This model class contains the carousel.
 */
@interface SMTAICarousel : SMTAIBase <NSSecureCoding>

@property (nonatomic, copy) NSString *imgUrl;
@property (nonatomic, copy) NSString *imgUrlPath;
@property (nonatomic, copy) NSString *imgTitle;
@property (nonatomic, copy) NSString *imgMsg;
@property (nonatomic, copy) NSString *imgDeeplink;

@end

NS_ASSUME_NONNULL_END

