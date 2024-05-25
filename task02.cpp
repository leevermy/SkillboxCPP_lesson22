#include <iostream>
#include <map>
#include <string>

int main() {
    std::string command;
    std::map<std::string, int> queue;

    while (getline(std::cin, command)) {
        if (command == "Next") {
            if (!queue.empty()) {
                auto it = queue.begin();
                std:: cout << it->first << std::endl;
                it->second--;
                if (it->second == 0) {
                    queue.erase(it);
                }
            } else {
                std::cout << "No patients in the queue" << std::endl;
            }
        } else {
            queue[command]++;
        }
    }
    return 0;
}