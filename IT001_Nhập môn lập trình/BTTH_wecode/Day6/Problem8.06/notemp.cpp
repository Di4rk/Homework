#include <bits/stdc++.h>
using namespace std;
#define MAX 300

void ReverseWord(char *start, char *end) {
    char temp;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main() {
    char s[MAX];
    if (fgets(s, MAX, stdin) == NULL) 
    {
        return 0;
    }
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) 
    {
        s[len - 1] = '\0';
        len--;
    }
    if (len == 0) 
    {
        cout << "Chuoi rong." << endl;
        return 0;
    }
    char *p = s;
    while (*p != '\0') 
    {
        if (*p != ' ') 
        {
            char *start = p;
            while (*p != ' ' && *p != '\0') p++;
            
            ReverseWord(start, p - 1);
            
            if (*p == '\0') break;
        } 
        else 
        {
            p++;
        }
    }
    cout << s << endl;
    return 0;
}