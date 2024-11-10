//
//  contactManagerWrapper.mm
//  objcpp
//
//  Created by khoi on 11/10/24.
//

#import "contactManagerWrapper.h"
#import "contactManager.hpp"

@implementation contactManagerWrapper

+ (instancetype)sharedManager
{
    static contactManagerWrapper *instance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[self alloc] init];
    });
    return instance;
}

- (NSInteger)createContact_name:(NSString *)name _email:(NSString *)email
{
    contact &contact = contactManager::getInstance().createContact([name UTF8String], [email UTF8String]);
    return contact.getId();
}

- (BOOL)deleteContact_id:(NSInteger)id
{
    return contactManager::getInstance().deleteContact((int)id);
}

- (BOOL)updateContactEmail_id:(NSInteger)id _email:(NSString *)email
{
    return contactManager::getInstance().updateContactEmail((int)id, [email UTF8String]);
}

- (NSArray *)getAllContacts
{
    contactManager::getInstance().sortContactByName();
    NSMutableArray *contactsArray = [NSMutableArray array];
    for (const contact &contact : contactManager::getInstance().getAllContacts()) {
        [contactsArray addObject:@{
            @"id": @(contact.getId()),
            @"name": [NSString stringWithUTF8String:contact.getName().c_str()],
            @"email": [NSString stringWithUTF8String:contact.getEmail().c_str()]
        }];
    }
    return [contactsArray copy];
}

- (NSDictionary *)getContactById_id:(NSInteger)id
{
    auto contact = contactManager::getInstance().getContactById((int)id);
    if (contact) {
        return @{
            @"id": @(id),
            @"name": [NSString stringWithUTF8String:(*contact)->getName().c_str()],
            @"email": [NSString stringWithUTF8String:(*contact)->getEmail().c_str()]
        };
    }
    return nil;
}

@end
