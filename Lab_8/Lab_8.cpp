#pragma warning(disable : 4996)

#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <map>
#include <queue>

using MyComparator = bool(*)(const std::string& string1, const std::string& string2);

bool compare1(const std::string& string1, const std::string& string2);
bool compare2(const std::string& string1, const std::string& string2);

std::string str, tmpStr;
std::map<std::string, int, MyComparator> tokens(compare1);
std::priority_queue<std::string, std::vector<std::string>, MyComparator> sorted_tokens(compare2);
std::ifstream fin("file.txt");

int main() {
    char inputStr[256];

    fin.getline(inputStr, 256);

    str.assign(inputStr);

    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        tmpStr = "";
        while ((*it) != ' ' && (*it) != ',' && (*it) != '.' && (*it) != '?' && (*it) != '!' && it != str.end()) {
            tmpStr += tolower((*it));
            ++it;
        }
        if(!tmpStr.empty())
            tokens[tmpStr] += 1;
    }

    std::map<std::string, int>::const_iterator mapIt = tokens.cbegin(); 

    while (mapIt != tokens.cend()) {
        sorted_tokens.push(mapIt->first);
        ++mapIt;
    }

    while (!sorted_tokens.empty()) {
        std::cout << sorted_tokens.top() << " => " << tokens[sorted_tokens.top()] << '\n'; 
        sorted_tokens.pop();
    }
}

bool compare1(const std::string& string1, const std::string& string2) {
    for (int i = 0; i < string1.size(); ++i) {
        if (string1[i] < string2[i]) {
            return true;
        }
        if (string1[i] > string2[i]) {
            return false;
        }
    }

    if (string1.size() != string2.size()) {
        return true;
    }
    return false;
}

bool compare2(const std::string& string1, const std::string& string2) {
    if (tokens[string1] < tokens[string2]) {
        return true;
    }
    if (tokens[string1] == tokens[string2]) {
        if (string1 > string2) {
            return true;
        }
        return false;
    }
    return false;
}