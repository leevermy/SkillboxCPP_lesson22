#include <iostream>
#include <map>
#include <string>

bool areAnagrams(std::string str1, std::string str2) {
    if (str1.length() != str2.length()) return false;

    std::map<char, int> char_count;
    for (char ch : str1) {
        char_count[ch]++;
    }

    for (char ch : str2) {
        char_count[ch]--;
        if (char_count[ch] < 0) return false;
    }

    for (auto it : char_count) {
        if (it.second != 0) return false;
    }

    return true;
}

int main() {
    std::string str1 = "qwertycvbgfd";
    std::string str2 = "dfgvbcqweytr";

    if (areAnagrams(str1, str2)) {
        std::cout << "The strings are anagrams." << std::endl;
    } else {
        std::cout << "The strings are not anagrams." << std::endl;
    }
    
    return 0;
}