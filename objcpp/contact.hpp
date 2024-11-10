//
//  contact.hpp
//  objcpp
//
//  Created by khoi on 11/9/24.
//

#ifndef _CONTACT_HPP_
#define _CONTACT_HPP_

#include <string>

class contact {
private:
    int32_t m_id;
    std::string m_name;
    std::string m_email;
public:
    contact(int32_t id, const std::string& name, const std::string& email);
    int32_t getId() const;
    std::string getName() const;
    std::string getEmail() const;
    void updateEmail(const std::string& email);
};

#endif
