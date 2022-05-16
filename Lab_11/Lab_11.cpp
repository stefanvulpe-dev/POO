#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include "CommandManager.h"
#include "MyException.h"
#include "OpenFileException.h" 
#include "ReadFileException.h"
#include "WriteFileException.h"

using namespace std;

int main() {
    CommandManager manager;

    auto ping = [](vector<string> args) { printf("pong!\n"); };
    manager.add("ping", ping);

    auto count = [](vector<string> args) { printf("%d\n", (int)args.size()); };
    manager.add("count", count);

    // the first argument will be treated as a file name
    // the rest of the arguments will be appended to that file with a space as delimiter
    // remember to count the errors, if any
    auto append = [](vector<string> args) {
        FILE* fptr = fopen(args[0].c_str(), "rb+");

        if (fptr == nullptr) {
            throw OpenFileException(args[0]);
        }
        else {
            //go to the end of file
            fseek(fptr, 0L, SEEK_END);
            fwrite(" ", 1, 1, fptr);

            for (auto it = args.begin() + 1; it != args.end(); ++it) {
                size_t bytes = fwrite(it->c_str(), it->length(), 1, fptr);
                fwrite(" ", 1, 1, fptr);
                if (bytes == 0) {
                    fclose(fptr);
                    throw WriteFileException(args[0]);
                }
            }

            fclose(fptr);
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
    auto copy = [](vector<string> args) {
        FILE* fptr1 =  fopen(args[0].c_str(), "rb");
        if (fptr1 == nullptr) {
            throw OpenFileException(args[0]);
        }

        FILE* fptr2 = fopen(args[1].c_str(), "wb");
        if (fptr2 == nullptr) {
            throw OpenFileException(args[1]);
        }

        char* buff = new char;
        while (true) {
            size_t bytes_read = fread(buff, 1, 1, fptr1);

            if (bytes_read == 0 && !feof(fptr1)) {
                fclose(fptr1);
                throw ReadFileException(args[0]); 
            }
            else if (bytes_read == 0) {
                break;
            }

            size_t bytes_written = fwrite(buff, 1, 1, fptr2); 

            if (bytes_written < 1) {
                fclose(fptr2); 
                throw WriteFileException(args[1]);
            }
        }

        fclose(fptr1);
        fclose(fptr2);
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

    auto cat = [](vector<string> args) {
        FILE* fptr = fopen(args[0].c_str(), "rb");
        
        if (fptr == nullptr) {
            throw OpenFileException(args[0]);
        }
        
        char* buff = new char;
        while (true) {
            size_t bytes = fread(buff, 1, 1, fptr); 
            if (bytes == 0 && !feof(fptr)) {
                fclose(fptr);
                throw ReadFileException(args[0]); 
            }
            else if (bytes == 0) {
                break;
            }
            fprintf(stdout, "%c", *buff);
        }
        fprintf(stdout, "\n");
        fclose(fptr);
    };

    manager.add("cat", cat);

    auto new_command = [](vector<string> args) {
        char* arr = nullptr;
        int size = 0;
        if (args.size() == 0) {
            size = -1;
            arr = new char[size];
        }
        else {
            size = 1.2676506e+30;
            arr = new char[size];
        }
    };

    manager.add("new", new_command);

    manager.run();
}
