#include <cstdio>
#include "Map.h"

int main() {
    Map<int, const char*> m;
    Map<int, const char*> m1;

    const char* valueType = nullptr;

    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    m.Set(0, "Linux");

    for (auto [key, value, index] : m) {
        printf("index:%d, key=%d, value=%s\n", index, key, value);
    }

    m[20] = "result";

    m.Set(40, "Some random text");

    m.Get(30, valueType);

    for (auto [key, value, index] : m) {
        printf("index:%d, key=%d, value=%s\n", index, key, value);
    }

    printf("Copied value from m[%d]: %s\n", 30, valueType);

    m.Delete(0);

    m.Delete(40);

    m1[10] = "C++";
    m1[20] = "result";
    m1[30] = "legit";

    printf("Map m is included in map m1?: %s", (m.Includes(m1) == 1 ? "Yes" : "No"));

    m.Clear(); 

    m1.Clear();

    return 0;
}