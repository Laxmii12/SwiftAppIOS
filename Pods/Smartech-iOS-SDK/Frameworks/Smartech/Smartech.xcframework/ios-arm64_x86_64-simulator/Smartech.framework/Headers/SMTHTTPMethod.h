//
//  SMTHTTPMethod.h
//  Smartech
//
//  Created by Netcore Solutions on 28/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief HTTPMethod is an enum for request HTTPMethod.
 */
typedef NS_ENUM(NSUInteger, SMTHTTPMethod) {
    SMTHTTPMethodGet, SMTHTTPMethodPost
};

/**
 @brief Parameters is simply just a typealias for a dictionary.
 */
typedef NSDictionary <NSString *, NSString *> URLParameters;

/**
 @brief Parameters is simply just a typealias for a dictionary.
 */
typedef NSDictionary <NSString *, id> BodyParameters;

/**
 @brief HTTPHeaders is simply just a typealias for a dictionary.
 */
typedef NSDictionary <NSString *, NSString *> HTTPHeaders;


/**
 @brief This defines the type of HTTP method used to perform the request.
 
 @discussion This method accepts a HTTPMethod value representing the HTTP protocol and it converts it to the corresponding string value.

 @param method - this is one of the HTTPMethod.
 
 @return NSString The HTTP method.
 */
extern NSString *SMTHTTPMethodString(SMTHTTPMethod method);

NS_ASSUME_NONNULL_END
