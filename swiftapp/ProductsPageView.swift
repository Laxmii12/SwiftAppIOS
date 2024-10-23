//
//  ProductsPageView.swift
//  swiftapp
//
//  Created by Laxmee Medli on 19/10/24.
//

import SwiftUI
import Smartech

struct ProductsPageView: View {
    var body: some View {
        VStack {
            Text("Products Page")
                .font(.largeTitle)
                .padding()
                .onAppear(){
                    // Example
                    let payloadDictionary = [
                                    "product_id" : "10",
                                    "screen_name" : "ProductsPageView",
                                    "brand" : "Polo"]

                    Smartech.sharedInstance().trackEvent("Product Viewed", andPayload:payloadDictionary)
                }
        }
    }
}
