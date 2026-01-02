#include <bits/stdc++.h>
using namespace std;
#define MAX 300

int main() {
    char s1[MAX];
    char s2[MAX];
    if (fgets(s1, MAX, stdin) != NULL) 
    {
        int len = strlen(s1);
        while (len > 0 && (s1[len - 1] == '\n' || s1[len - 1] == '\r')) 
        {
            s1[len - 1] = '\0';
            len--;
        }
    }
    if (fgets(s2, MAX, stdin) != NULL) 
    {
        int len = strlen(s2);
        while (len > 0 && (s2[len - 1] == '\n' || s2[len - 1] == '\r')) 
        {
            s2[len - 1] = '\0';
            len--;
        }
    }
    char *p1 = s1;
    char *p2 = s2;
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) 
    {
        p1++;
        p2++;
    }
    if (*p1 > *p2) 
    {
        cout << 1 << endl;
    } 
    else if (*p1 < *p2) 
    {
        cout << -1 << endl;
    } 
    else 
    {
        cout << 0 << endl;
    }
    return 0;
}