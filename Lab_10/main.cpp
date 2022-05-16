#include <iostream>
#include <fstream>
#include <algorithm>

#include "CommandManager.h"

using std::cout;
using std::ifstream; 
using std::ofstream;
using std::sort;
using std::for_each;

int main() {
    CommandManager manager;
    // number_of_errors represents the number of IO errors (eg. file errors) that happened in the commands
    // this is only relevant for the append and copy commands
    unsigned number_of_errors = 0;

    // prints pong!
    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    // prints the number of arguments it received
    // `count a b c` -> will print `counted 3 args`
    auto count = [](vector<string> args) { printf("%d\n", (int)args.size()); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [&number_of_errors](vector<string> args) { 
        ifstream fin(args[0]); 
        if (!fin.is_open()) {
            number_of_errors++;
        }
        else {
            string str;
            while (!fin.eof()) {
                char ch; 
                fin.get(ch); 
                str += ch;
            }
            fin.close(); 
            cout << str;
            for (auto it = args.begin() + 1; it != args.end(); ++it) {
                cout << (*it) << " ";
            }
            cout << "\n";
        }
    };
    manager.add("append", append);

    // will print the number of times the command was called
    // do not capture any reference for this lambda
    auto times = [count = 0](vector<string> args) mutable {
        count++;
        cout << count << "\n";
    };
    manager.add("times", times);

    // copy a file; args[0] will provide the source, and args[1] the destination
    // make sure it works with binary files (test it with an image)
    // remember to count the errors, if any
    auto copy = [&number_of_errors](vector<string> args) {
        ifstream fin(args[0]); 
        ofstream fout(args[1]);

        if (args.size() < 2) {
            number_of_errors++;
        }
        else if (!fin.is_open()) {
            number_of_errors++;
        }
        else {
            string tmpStr;
            while (getline(fin, tmpStr)) {
                fout << tmpStr << "\n";
            }
            fin.close(); 
            fout.close();
        }
    };
    manager.add("copy", copy);

    // will sort the arguments by size
    // `sort_size abc a 1234` -> will print `a abc 1234`
    // use std::sort with a lambda comparator to sort
    // and std::for_each with a lambda to print afterwards
    auto sort_size = [](vector<string> args) { 
        sort(args.begin(), args.end(), [](const string& str1, const string& str2) { return str1.size() < str2.size(); });
        for_each(args.begin(), args.end(), [](string str) { cout << str << " "; });
        cout << '\n';
    };
    manager.add("sort_size", sort_size);

    auto cat = [&number_of_errors](vector<string> args) {
        ifstream fin(args[0]);
        if (args.size() > 1) {
            number_of_errors++;
        }
        else if(!fin.is_open()) {
            number_of_errors++;
        }
        else {
            string str;
            while (!fin.eof()) {
                char ch;
                fin.get(ch);
                str += ch;
            }
            fin.close();
            cout << str << "\n";
        }
    };

    manager.add("cat", cat);

    manager.run();

    printf("number of errors: %u\ndone!\n", number_of_errors);
}
