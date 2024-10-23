//
//  SMTManagedObject.h
//  Smartech
//
//  Created by Netcore Solutions on 04/02/19.
//  Copyright © 2019 Netcore Solutions. All rights reserved.
//

#import <CoreData/CoreData.h>

NS_ASSUME_NONNULL_BEGIN

static NSString *const kSMTDatabaseObjectID = @"objectID";

@interface SMTManagedObject : NSManagedObject

/**
 @brief This method is called to make fetchRequest.
 
 @return NSFetchRequest return the fetch request.
 */
+ (NSFetchRequest <SMTManagedObject *> *)fetchRequest;

/**
 @brief This method is called to fetch all the objects from the database w.r.t. self - SMTManagedObject
 
 @param context The core data context.
 
 @return NSArray A list of objects.
 */
+ (NSArray *)fetchAllObjectsInContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to fetch the objects from the database by property name.
 
 @param propertyName The property name.
 @param context The core data context.
 
 @return NSArray A list of objects.
 */
+ (NSArray *)fetchAllObjectByProperty:(NSString *)propertyName
                            inContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to fetch the objects from the database after sorting.
 
 @param sortDescriptor the sort descriptor.
 @param context The core data context.
 
 @return NSArray A list of objects.
 */
+ (NSArray *)fetchAllObjectsWithSortDescriptor:(NSSortDescriptor * _Nullable)sortDescriptor
                                     inContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to fetch the objects from the database after sorting with predicate.
 
 @param predicate The where clause.
 @param sortDescriptor The sort descriptor.
 @param context The core data context.
 
 @return NSArray A list of objects.
 */
+ (NSArray *)findObjectsWithPredictate:(NSPredicate * _Nullable)predicate
                        sortDescriptor:(NSSortDescriptor * _Nullable)sortDescriptor
                             inContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to fetch the objects from the database with predicate.
 
 @param predicate The where clause.
 @param context The core data context.

 @return NSArray A list of objects.
 */
+ (NSArray *)findObjectsWithPredictate:(NSPredicate * _Nullable)predicate inContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to insert a new object.
 
 @param context The core data context.
 
 @return id The newly created object.
 */
+ (id)insertNewObjectForEntityWithManagedContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to delete the objects in a batch based on predicate.
 
 @param predicate The where clause.
 @param context The core data context.
 
 @return BOOL If deletion is successful.
 */
+ (BOOL)batchDeleteRequestWithPredictate:(NSPredicate * _Nullable)predicate
                               inContext:(NSManagedObjectContext *)context;

/**
 @brief This method is called to update the objects in a batch based on predicate.
 
 @param propertiesToUpdate The properties to update.
 @param predicate The where clause.
 @param context The core data context.
 
 @return id The updated object/objects.
 */
+ (id)batchUpdateRequestForProperties:(NSDictionary *)propertiesToUpdate
                       withPredictate:(NSPredicate * _Nullable)predicate
                            inContext:(NSManagedObjectContext *)context;
/**
 @brief This method is called to get the count of rows from the database after sorting with predicate.
 
 @param predicate The where clause.
 @param sortDescriptor The sort descriptor.
 @param context The core data context.
 
 @return NSUInteger A count of objects.
 */
+ (NSUInteger)countForObjectsWithPredictate:(NSPredicate * _Nullable)predicate
                             sortDescriptor:(NSSortDescriptor * _Nullable)sortDescriptor
                                  inContext:(NSManagedObjectContext *)context;


/**
 @brief This method is called to save the objets into the database.
 
 @return NSError return error if not saved.
 */
- (NSError * _Nullable)save;


/**
@brief This method is called to fetch the objects from the database with record limit

@param predicate The where clause.
@param recordLimit record limit
@param context The core data context.

@return NSArray A list of objects.
 */
+ (NSArray *)findObjectsWithPredictate:(NSPredicate * _Nullable)predicate
                             withLimit:(NSInteger)recordLimit
                             inContext:(NSManagedObjectContext *)context;

+ (NSArray *)findObjectsWithDistinct:(NSManagedObjectContext *)context;

/**
@brief This method is called to fetch the objects from the database with record limit

@param predicate The where clause.
@param sortDescriptor The sort descriptor.
@param recordLimit record limit
@param context The core data context.

@return NSArray A list of objects.
 */
+ (NSArray *)findObjectsWithPredictate:(NSPredicate * _Nullable)predicate
                        sortDescriptor:(NSSortDescriptor * _Nullable)sortDescriptor
                             withLimit:(NSInteger)recordLimit
                             inContext:(NSManagedObjectContext *)context;

@end

NS_ASSUME_NONNULL_END
