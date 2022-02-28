#include <cstdio> 
#include <cstring> 

#define _CRT_SECURE_NO_WARNINGS

char s[105], arr[105][105]; 

void sort_strings(char arr[][105], int size)
{
    bool ok; 
    char aux[105];

    do {
        ok = true; 
        for(int i = 0; i < size; ++ i)
        {
            if((strlen(arr[i]) < strlen(arr[i + 1])) || ((strlen(arr[i]) == strlen(arr[i + 1])) && strcmp(arr[i], arr[i + 1]) > 0))
            {
                strcpy(aux, arr[i]); 
                strcpy(arr[i], arr[i + 1]); 
                strcpy(arr[i + 1], aux); 
                ok = false;
            }
        }
    } while(!ok);
}

int main()
{
    char * p; 
    int cnt = 0;

    fgets(s, sizeof(s), stdin);
    
    s[strlen(s) - 1] = '\0';
    
    p = strtok(s, " "); 

    while(p)
    {
        strcpy(arr[cnt ++], p);
        p = strtok(NULL, " ");
    }
    
    sort_strings(arr, cnt); 

    for(int i = 0; i < cnt; ++ i)
    {
        printf("%s\n", arr[i]);
    }

    return 0;
}