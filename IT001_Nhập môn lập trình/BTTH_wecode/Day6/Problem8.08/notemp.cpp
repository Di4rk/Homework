#include <bits/stdc++.h>
using namespace std;
#define MAX 300
#define RES_MAX 600 

int main() {
    char s[MAX];
    char s1[MAX];
    int k;
    if (fgets(s, MAX, stdin) != NULL) 
    {
        int len = strlen(s);
        while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) 
        {
            s[len - 1] = '\0';
            len--;
        }
    }
    if (fgets(s1, MAX, stdin) != NULL) 
    {
        int len = strlen(s1);
        while (len > 0 && (s1[len - 1] == '\n' || s1[len - 1] == '\r')) 
        {
            s1[len - 1] = '\0';
            len--;
        }
    }
    cin >> k;
    int lenS = strlen(s);
    if (k < 0 || k > lenS) {
        cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
    } 
    else 
    {
        char result[RES_MAX];
        strncpy(result, s, k);
        result[k] = '\0'; 
        strcat(result, s1);
        strcat(result, s + k);
        cout << result << endl;
    }
    return 0;
}