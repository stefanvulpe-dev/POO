#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "CommandManager.h" 
#include "MyException.h"

using namespace std;

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

        try {
            it->second(args);
        }
        catch (MyException& e) {
            fprintf(stderr, e.what());
            fprintf(stderr, "\n");
        }
        catch (bad_alloc& e) {
            fprintf(stderr, e.what());
            fprintf(stderr, "\n");
        }
    }
}