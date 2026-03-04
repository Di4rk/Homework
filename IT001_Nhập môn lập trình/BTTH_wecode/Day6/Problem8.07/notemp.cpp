#include <bits/stdc++.h>
using namespace std;
#define MAX 3000

int main() {
    char s[MAX];
    s[0] = '\0';
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
    char *words[MAX];
    int count = 0;
    char *p = s;    
    while (*p != '\0') 
    {
        while (*p == ' ' || *p == '\t') p++;                
        if (*p == '\0') break;        
        words[count++] = p;
        while (*p != ' ' && *p != '\t' && *p != '\0') p++;
        if (*p == ' ' || *p == '\t') 
        {
            *p = '\0';
            p++;
        }
    }    
    if (count == 0) 
    {
        cout << "Chuoi rong." << endl;
    } 
    else 
    {
        for (int i = count - 1; i >= 0; i--) 
        {
            cout << words[i];
            if (i > 0) cout << " ";
        }
        cout << endl;
    }
    return 0;
}