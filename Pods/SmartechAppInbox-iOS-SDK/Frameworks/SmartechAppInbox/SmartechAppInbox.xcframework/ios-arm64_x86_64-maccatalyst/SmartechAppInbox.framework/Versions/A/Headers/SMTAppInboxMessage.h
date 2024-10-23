//
//  SMTAppInboxMessage.h
//  SmartechAppInbox
//
//  Created by Netcore Solutions on 18/11/20.
//  Copyright © 2020 Netcore Solutions. All rights reserved.
//

#import "SMTAIBaseManagedObject.h"
#import "SMTAppInboxMessageModel.h"
#import "SMTAILogger.h"

NS_ASSUME_NONNULL_BEGIN

@interface SMTAppInboxMessage : SMTAIBaseManagedObject

@property (nullable, nonatomic, copy) NSString *trid;
@property (nullable, nonatomic, copy) NSString *status;
@property (nullable, nonatomic, copy) NSDate *publishedDate;
@property (nullable, nonatomic, retain) SMTAppInboxMessageModel *payload;
@property (nullable, nonatomic, retain) NSMutableDictionary *mediaDownloadInProgress;
@property (nullable, nonatomic, copy) NSDate *updatedDate;
@property (nullable, nonatomic, copy) NSDate *ttlDate;
@property (nullable, nonatomic, copy) NSString *categoryName;
@property (nullable, nonatomic, copy) NSString *timestamp;
@property (nullable, nonatomic, copy) NSString *userIdentity;

/**
 @brief This method is called to check if the media download is in progress.
 
 @param key The key against which download progress needs to be checked.
 
 @return BOOL Yes if the media download is in progress.
 */
- (BOOL)isMediaDownloadInProgressForKey:(NSString *)key;

/**
 @brief This method is called to check if the media download is in progress.

 @param isDownloadInProgress The boolean value to be set against the key.
 @param key The key against which download progress needs to be checked.
 */
- (void)setMediaDownloadInProgressValue:(BOOL)isDownloadInProgress forKey:(NSString *)key;

/**
 @brief This method is called to save the tranformable property payload into the database.
 
 @param mediaURLPath The updated inbox notification payload media URL path.
 
 @return NSError The error if not saved.
 */
- (NSError *)updatePayloadWithMediaURLPath:(NSString *)mediaURLPath;

/**
 @brief This method is called to save the tranformable property payload into the database.
 
 @param mediaURLPath The updated inbox notification payload media URL path.
 @param index The carousel index.

 @return NSError The error if not saved.
 */
- (NSError *)updatePayloadWithMediaURLPath:(NSString *)mediaURLPath forCarouselAtIndex:(int)index;

@end

NS_ASSUME_NONNULL_END
