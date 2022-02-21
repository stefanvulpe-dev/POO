#include <cstdio> 
#include <cstring> 

#define _CRT_SECURE_NO_WARNINGS

FILE * fptr; 

int string_to_number(char s[], int cnt)
{
    int nr = 0, p = 1;
    for(int i = cnt - 1; i >= 0; -- i)
    {
        nr = nr + (s[i] - '0') * p; 
        p *= 10;
    }
    return nr;
}

int main()
{
    fptr = fopen("in.txt", "r");

    int cnt = 0, sum = 0;;
    char ch, s[105];
    
    s[0] = '\0';  
    ch = getc(fptr);

    while(ch != EOF)
    {
        if(ch == '\n')
        {
            s[cnt] = '\0';
            sum += string_to_number(s, cnt);
            cnt = 0;
        }
        else 
            s[cnt ++] = ch; 
        ch = getc(fptr); 
    } 

    printf("%d", sum);

    return 0;
}