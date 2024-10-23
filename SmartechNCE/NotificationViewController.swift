import UIKit
import SmartPush

class NotificationViewController: SMTCustomNotificationViewController {
    
    @IBOutlet var customPNView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.customView = customPNView
    }
}

