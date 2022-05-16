#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "CommandManager.h" 

using std::cin; 
using std::getline;

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    this->commands[name] = fn;
}

void CommandManager::run() {
    vector<string> args;
    string str; 

    while (true) {
        getline(cin, str); 
        
        if (str == "stop") {
            return; 
        }

        args.clear();
        
        char* ptr = strtok(&str[0], " "); 

        while (ptr) {
            args.push_back(ptr); 
            ptr = strtok(nullptr, " "); 
        }

        if (args.empty()) {
            //empty command, continue
            continue;
        }

        auto it = this->commands.find(args[0]);

        if (it == this->commands.end()) {
            printf("Command doesn't exist\n"); 
            continue;
        }

        args.erase(args.begin()); 

        it->second(args);
    }
}