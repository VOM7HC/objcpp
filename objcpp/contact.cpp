//
//  contact.cpp
//  objcpp
//
//  Created by khoi on 11/9/24.
//

#include "contact.hpp"

contact::contact(int32_t id,const std::string& name, const std::string& email)
: m_id(id),
  m_name(name),
  m_email(email)
{
    
}

int32_t contact::getId() const
{
    return m_id;
}

std::string contact::getName() const
{
    return m_name;
}

std::string contact::getEmail() const
{
    return m_email;
}

void contact::updateEmail(const std::string& email)
{
    m_email = email;
}
