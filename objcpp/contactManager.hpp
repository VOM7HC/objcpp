//
//  contactManager.hpp
//  objcpp
//
//  Created by khoi on 11/10/24.
//

#ifndef _CONTACTMANAGER_HPP_
#define _CONTACTMANAGER_HPP_

#include <algorithm>
#include <mutex>
#include <optional>
#include <vector>

#include "contact.hpp"

class contactManager {
private:
    static contactManager* contactManager_;
    static std::mutex mutex_;
    std::vector<contact> contacts;
    contactManager(int32_t start);
    int32_t m_id;

public:
    static contactManager& getInstance();
    contact& createContact(const std::string& name, const std::string& email);
    std::optional<contact*> getContactById(int32_t id);
    bool updateContactEmail(int32_t id, const std::string& email);
    bool deleteContact(int32_t id);
    void sortContactByName();
    const std::vector<contact>& getAllContacts() const;
};

#endif
