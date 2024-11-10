//
//  contactManager.cpp
//  objcpp
//
//  Created by khoi on 11/10/24.
//

#include <format>
#include <iostream>

#include "contactManager.hpp"

// Initialize static members outside the class definition
contactManager* contactManager::contactManager_ = nullptr;
std::mutex contactManager::mutex_;

contactManager::contactManager(int32_t start)
: m_id(start)
{
    std::string message = std::format("hello cpp");
    std::cout << message;
}

contactManager& contactManager::getInstance()
{
    std::lock_guard<std::mutex> lock(mutex_);
    if (contactManager_ == nullptr)
    {
        contactManager_ = new contactManager(0);
    }
    return *contactManager_;
}

std::optional<contact*> contactManager::getContactById(int32_t id)
{
    for (auto& contact: contacts)
    {
        if (contact.getId() == id)
        {
            return &contact;
        }
    }
    return std::nullopt;
}

contact &contactManager::createContact(const std::string &name, const std::string &email)
{
    contacts.emplace_back(m_id++, name, email);
    return contacts.back();
}

void contactManager::sortContactByName()
{
    std::sort(contacts.begin(), contacts.end(), [](const contact &a, const contact &b) {
        return a.getName() < b.getName();
    });
}


bool contactManager::deleteContact(int32_t id) { 
    auto it = std::remove_if(contacts.begin(), contacts.end(), [id](const contact& contact) {
        return contact.getId() == id;
    });
    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        return true;
    }
    return false;
}

bool contactManager::updateContactEmail(int32_t id, const std::string &email) { 
    auto contact = getContactById(id);
    if (contact) {
        (*contact)->updateEmail(email);
        return true;
    }
    return false;
}

const std::vector<contact> &contactManager::getAllContacts() const
{
    return contacts;
}
