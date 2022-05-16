#pragma once
#include <map> 
#include <functional>
#include <string> 
#include <vector> 

using std::map; 
using std::function; 
using std::string;
using std::vector;

// the CommandManager class should implement a mini terminal that receive commands and dispatches them.
// example: copy a.jpg b.jpg
// this will search the map for a "copy" command, and if it finds it, it will invoke its callback with a vector made of {"a.jpg", "b.jpg"}
// no global variables allowed

class CommandManager {
private:
    map<string, function<void(vector<string>)>> commands;

public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};