//
//  SMTCustomNotificationViewController.h
//  SmartPush
//
//  Created by Netcore Solutions on 12/12/22.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SMTCustomNotificationViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIView *customView;

//- (void)didReceiveNotification:(nonnull UNNotification *)notification;
//
//- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption option))completion;

@end

NS_ASSUME_NONNULL_END
