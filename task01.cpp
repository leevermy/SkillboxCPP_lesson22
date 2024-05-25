#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::map<std::string, std::string> phone_to_surname;
    std::map<std::string, std::vector<std::string>> surname_to_phones;
    std::string command;

    while (getline(std::cin, command)) {
        std::string phone_number = "";
        std::string subscriber = "";

        if (isdigit(command[0])) {
            int space_pos = command.find(' ');
            if (space_pos != std::string::npos) {
                phone_number = command.substr(0, space_pos);
                subscriber = command.substr(space_pos + 1);
            } else {
                phone_number = command;
            }
        } else {
            subscriber = command;
        }

        if (!phone_number.empty() && !subscriber.empty()) {
            phone_to_surname.emplace(phone_number, subscriber);
            surname_to_phones[subscriber].push_back(phone_number);

        } else if (!phone_number.empty() && subscriber.empty()) {
            auto it = phone_to_surname.find(phone_number);
            if (it != phone_to_surname.end()) {
                std::cout << phone_to_surname.find(phone_number)->second << std::endl;
            } else {
                std::cout << "The phone is not found" << std::endl;
            }
            
        } else if (phone_number.empty() && !subscriber.empty()) {
            auto it = surname_to_phones.find(subscriber);
            if (it != surname_to_phones.end()) {
                for (const auto phones : it->second) {
                std::cout << phones <<std::endl;
                }
            } else {
                std::cout << "The subscriber is not found" << std::endl;
            }            
        } 
    }
    return 0;
}

