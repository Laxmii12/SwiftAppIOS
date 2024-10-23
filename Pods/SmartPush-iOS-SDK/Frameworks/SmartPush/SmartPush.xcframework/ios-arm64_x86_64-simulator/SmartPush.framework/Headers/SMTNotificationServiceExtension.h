//
//  SMTPayloadNotificationService.h
//  Smartech
//
//  Created by Netcore Solutions on 02/02/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>

NS_ASSUME_NONNULL_BEGIN

typedef void (^ModifiedContentCompletionBlock) (UNNotificationAttachment * _Nullable savedMediaAttachment);

/**
 @brief This class is for Smartech notification service extension that modifies the content of a remote notification before it's delivered to the user.
 */
@interface SMTNotificationServiceExtension : UNNotificationServiceExtension

/**
 @brief This method is useful for modifying the notification content before it is delivered.
 
 @param request The notification request to be handled.
 @param contentHandler Call contentHandler with the modified notification content to deliver. If the handler is not called before the service's time expires then the unmodified notification will be delivered.
 */
- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request
                   withContentHandler:(void (^)(UNNotificationContent *contentToDeliver))contentHandler;

/**
 @brief This method will be called just before this extension is terminated by the system. You may choose whether to override this method.
 */
- (void)serviceExtensionTimeWillExpire;

@end

NS_ASSUME_NONNULL_END
