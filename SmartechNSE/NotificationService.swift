import UserNotifications
import SmartPush

class NotificationService: UNNotificationServiceExtension {
  
  let smartechServiceExtension = SMTNotificationServiceExtension()
  
  override func didReceive(_ request: UNNotificationRequest, withContentHandler contentHandler: @escaping (UNNotificationContent) -> Void) {
      print("Notification Service Extension triggered")
    //...
  if SmartPush.sharedInstance().isNotification(fromSmartech:request.content.userInfo){
      smartechServiceExtension.didReceive(request, withContentHandler: contentHandler)
    }
    //...
  }
  
  override func serviceExtensionTimeWillExpire() {
    //...
    smartechServiceExtension.serviceExtensionTimeWillExpire()
    //...
  }
}
