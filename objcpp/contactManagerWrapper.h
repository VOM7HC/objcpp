//
//  contactManagerWrapper.h
//  objcpp
//
//  Created by khoi on 11/10/24.
//

#import <Foundation/Foundation.h>

@interface contactManagerWrapper : NSObject

+ (instancetype)sharedManager;
- (NSInteger)createContact_name:(NSString *)name _email:(NSString *)email;
- (NSDictionary *)getContactById_id:(NSInteger)id;
- (BOOL)updateContactEmail_id:(NSInteger)id _email:(NSString *)email;
- (BOOL)deleteContact_id:(NSInteger)id;
- (NSArray *)getAllContacts;

@end
