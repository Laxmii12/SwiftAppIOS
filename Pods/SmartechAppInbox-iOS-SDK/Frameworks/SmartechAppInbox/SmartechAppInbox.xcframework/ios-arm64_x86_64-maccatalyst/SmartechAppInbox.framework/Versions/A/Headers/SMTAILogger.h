//
//  SMTAILogger.h
//  Smartech
//
//  Created by Netcore Solutions on 31/01/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM(NSUInteger, SMTAILogLevel) {
    SMTAILogLevelVerbose = 1,
    SMTAILogLevelDebug = 2,
    SMTAILogLevelInfo = 3,
    SMTAILogLevelWarn = 4,
    SMTAILogLevelError = 5,
    SMTAILogLevelFatal = 6,
    SMTAILogLevelNone = 7,
};

#define SMTAILogVerbose( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelVerbose func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogDebug( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelDebug func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogInfo( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelInfo func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogWarn( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelWarn func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogError( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelError func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogFatal( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelFatal func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define SMTAILogInternal( s, ... ) [SMTAILogger print:[self class] logLevel:SMTAILogLevelInternal func:[NSString stringWithFormat: @"%s", __PRETTY_FUNCTION__] lineNumber:__LINE__ str:[NSString stringWithFormat:(s), ##__VA_ARGS__]]

extern const int SMTAILogLevelInternal;
extern const int SMTEnableInternalLog;



/**
 @brief This class enables logging at SDK level.
 */
@interface SMTAILogger : NSObject

/**
 @brief
 Set the debug logging level
 
 @discussion
 Set using SMTAILogLevel enum values or the corresponding int values.
 
 SMTAILogLevelVerbose     - enables all logging.
 SMTAILogLevelDebug       - enables verbose debug logging.
 SMTAILogLevelInfo        - enables minimal information related to SDK integration.
 SMTAILogLevelWarn        - enables warning information related to SDK integration.
 SMTAILogLevelError       - enables errorn information related to SDK integration.
 SMTAILogLevelFatal       - enables crash information related to SDK integration.
 SMTAILogLevelNone        - turns off all SDK logging.
 
 @param level  the level to set
 */
+ (void)setDebugLevel:(SMTAILogLevel)level;

/**
 @brief
 Get the debug logging level
 
 @discussion
 Returns the currently set debug logging level.
 */
+ (SMTAILogLevel)getDebugLevel;

/**
 @brief
 Prints the log at the console
 
 @param theClassName  the classname where the log statement has been put
 @param logLevel  the debug log level
 @param func  the function name
 @param line  the line number
 @param message  the message information
 */
+ (void)print:(Class)theClassName logLevel:(SMTAILogLevel)logLevel func:(NSString *)func lineNumber:(int)line str:(NSString *)message;

+ (NSString *)logLevelString:(SMTAILogLevel)level;

@end

NS_ASSUME_NONNULL_END
