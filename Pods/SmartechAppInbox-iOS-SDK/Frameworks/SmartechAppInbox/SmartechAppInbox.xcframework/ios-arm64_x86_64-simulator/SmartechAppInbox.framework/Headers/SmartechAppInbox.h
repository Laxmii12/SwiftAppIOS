//
//  SmartechAppInbox.h
//  SmartechAppInbox
//
//  Created by Netcore Solutions on 12/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for SmartechAppInbox.
FOUNDATION_EXPORT double SmartechAppInboxVersionNumber;

//! Project version string for SmartechAppInbox.
FOUNDATION_EXPORT const unsigned char SmartechAppInboxVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SmartechAppInbox/PublicHeader.h>

#import <SmartechAppInbox/SMTAppInboxViewController.h>
#import <Smartech/SMTAppInboxSettings.h>
#import <Smartech/Smartech.h>
#import <SmartechAppInbox/SMTAppInboxMessage.h>
#import <SmartechAppInbox/SMTAppInboxMessageModel.h>
#import <SmartechAppInbox/SMTAppInboxCategoryModel.h>
#import <SmartechAppInbox/SMTAppInboxFilter.h>


typedef NS_ENUM(NSUInteger, SMTAppInboxMessageType) {
    SMTAppInboxMessageTypeAll,
    SMTAppInboxMessageTypeDismiss,
    SMTAppInboxMessageTypeRead,
    SMTAppInboxMessageTypeUnread
};

#pragma mark - Event Name
/**
 @brief SMTAIEvent is an enum for request Smartech App Inbox Events.
 */
typedef NS_ENUM(NSUInteger, SMTAIEvent) {
    SMTAIEventInboxDelivered = 44,
    SMTAIEventInboxViewed = 45,
    SMTAIEventInboxClicked = 46,
    SMTAIEventInboxDismissed = 47,
};

@class SMTAppInboxMessage;
@class SMTAppInboxMessagePersistenceService;
@class SMTAppInboxFilter;
@class SMTAppInboxCategoryModel;

typedef void (^AppInboxCompletionBlock) (NSArray <SMTAppInboxMessage *> * _Nullable inboxMessages, NSError * _Nullable error);

typedef void (^AppInboxMediaDownloadAndSaveCompletionBlock) (NSString * _Nullable mediaPath, NSError * _Nullable error);

@interface SmartechAppInbox : NSObject

/**
 @brief This method returns the SmartechAppInbox instance.
 
 @return The SmartechAppInbox instance object.
 */
+ (instancetype _Nonnull )sharedInstance;

/**
@brief This method is for intialiazing the SmartechAppInbox SDK.

@discussion You need to call this method inside your app delegates didFinishLaunchingWithOptions: method immediately after initialising Smartech SDK.

You can use the below code.

@code
    [[SmartechAppInbox sharedInstance] initSDKWithDelegate:self withLaunchOptions:launchOptions];
@endcode

@param delegate The Smartech delegate.
@param launchOptions The launch option dictionary.
*/
- (void)initSDKWithDelegate:(id _Nullable )delegate withLaunchOptions:(NSDictionary * _Nullable)launchOptions;


#pragma mark - App Inbox Methods (Public)


- (void)initialiseAppInboxSDKFor:(SMTAppInboxSettings *_Nullable)appInboxSettings;

/**
 @brief This method is called to get default app inbox view controller
 @return SMTAppInboxViewController - instance of app inbox view controller
 */
- (SMTAppInboxViewController *_Nonnull)getAppInboxViewController;

/**
 @brief This method is called to get All app inbox message
 @param filter contains limit, direction, timesatmp
 */
- (void)getAppInboxMessage:(SMTAppInboxFilter *_Nullable)filter withCompletionHandler:(void(^_Nullable)(NSError *_Nullable,BOOL))handler;


/**
 @brief This method is called to get All app inbox category
 @return SMTAppInboxCategoryModel - array of category
 */
-(NSArray <SMTAppInboxCategoryModel *> *_Nullable)getAppInboxCategoryList;

/**
 @brief This method is called to get pull request param
 @return SMTAppInboxFilter - parameter for pull to refresh
 */
- (SMTAppInboxFilter *_Nonnull)getPullToRefreshParameter;

/**
 @brief This method is called to get old data and pagination request param
 @return SMTAppInboxFilter - parameter for old data and pagination
 */
- (SMTAppInboxFilter *_Nonnull)getPaginationParameter;

/**
 @brief This method is called to get app inbox data based on category
 @param categoryArray - category name array
 @return NSArray <SMTAppInboxMessage *> * - Array of app inbox messages.
 */
- (NSArray <SMTAppInboxMessage *> *_Nullable)getAppInboxMessageWithCategory:(NSMutableArray <SMTAppInboxCategoryModel *> *_Nullable)categoryArray;

/**
 @brief This method is called, when a message is viewed by the user
 */
- (void)markMessageAsViewed:(SMTAppInboxMessage *_Nullable)inboxMsg;

/**
 @brief This method is called, when a message is viewed by the user
 */
- (void)markMessageAsDismissed:(SMTAppInboxMessage *_Nullable)inboxMsg withCompletionHandler:(void(^_Nonnull)(NSError *_Nullable,BOOL))handler;

/**
 @brief This method is called, when a message is viewed by the user
 */
- (void)markMessageAsClicked:(SMTAppInboxMessage *_Nullable)inboxMsg withDeeplink:(NSString *_Nullable)actionDeeplink;

/**
 @brief This method is called to get all app inbox messages of a particular type
 @param statusType - type of app inbox message .
 @return NSArray <SMTAppInboxMessage *> * - Array of app inbox messages.
 */
- (NSArray <SMTAppInboxMessage *> *_Nonnull)getAppInboxMessages:(SMTAppInboxMessageType)statusType;

/**
 @brief This method is called to get count of app inbox messages of a particular type
 @param statusType - type of app inbox message .
 @return NSUInteger - count of app inbox messages.
 */
- (NSUInteger)getAppInboxMessageCount:(SMTAppInboxMessageType)statusType;

/**
 @brief This method is called to get  an app inbox messages with trid
 @param trid - trid of app inbox message .
 @return SMTAppInboxMessage - instance of app inbox message.
 */
- (SMTAppInboxMessage *_Nullable)getInboxMessageById:(NSString *_Nonnull)trid;

@end
