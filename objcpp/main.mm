//
//  main.m
//  objcpp
//
//  Created by khoi on 11/9/24.
//

#import <Foundation/Foundation.h>

#import "contactManagerWrapper.h"

NSString *getInputFromKeyboard(NSString *prompt)
{
    NSLog(@"%@", prompt);
    NSFileHandle *input = [NSFileHandle fileHandleWithStandardInput];
    NSData *inputData = [input availableData];
    NSString *inputString = [[NSString alloc] initWithData:inputData encoding:NSUTF8StringEncoding];
    return [inputString stringByTrimmingCharactersInSet:[NSCharacterSet newlineCharacterSet]];
}

int main(int argc, const char * argv[])
{
    @autoreleasepool
    {
        // insert code here...
        NSLog(@"Hello, World!");
        
        contactManagerWrapper *manager = [contactManagerWrapper sharedManager];
        
        // Create Contacts
        NSInteger id1 = [manager createContact_name:@"Khoi" _email:@"khoi@example.com"];
        NSInteger id2 = [manager createContact_name:@"Alex" _email:@"alex@example.com"];
        NSInteger id3 = [manager createContact_name:@"Zoe" _email:@"zoe@example.com"];
        
        // Display all contacts before sorting
        NSLog(@"All Contacts (Unsorted): %@", [manager getAllContacts]);
        
        // Update a contact
        [manager updateContactEmail_id:id2 _email:@"alexander@example.com"];
        
        // Sort and display all contacts
        NSLog(@"All Contacts (Sorted): %@", [manager getAllContacts]);
        
        // Retrieve a specific contact
        NSDictionary *contactInfo = [manager getContactById_id:id1];
        NSLog(@"Contact with ID %ld: %@", (long)id1, contactInfo);
        
        // Delete a contact and display remaining contacts
        [manager deleteContact_id:id3];
        NSLog(@"All Contacts after Deletion: %@", [manager getAllContacts]);
    }
    return 0;
}
