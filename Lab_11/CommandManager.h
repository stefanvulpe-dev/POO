#pragma once
#include <map> 
#include <functional>
#include <string> 
#include <vector> 

using namespace std;

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    void run();
};