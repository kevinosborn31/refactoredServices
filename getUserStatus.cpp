#include "fakeAPI.h"

#include <iostream>
#include <map>
#include <string>
#include <future>

std::map<std::string, bool> getAllUsers() {
    try {
        std::map<std::string, bool> response = api.getUserData();
        return response;
    } catch(const std::exception& err) {
        std::cerr << "Sorry, there was an error: " << err.what() << std::endl;
        return std::map<std::string, bool>();
    }
}

std::string getUserStatus(const std::string& username) {
    std::map<std::string, bool> users = getAllUsers();

    if (users.find(username) != users.end()) {
        bool isEnabled = users[username];
        return isEnabled ? "Enabled" : "Disabled";
    } else {
        return "This user does not exist";
    }
}

int main() {
    std::string status = getUserStatus("kevinosborn");
    std::cout << "User Status: " << status << std::endl;
    return 0;
}
