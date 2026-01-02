#include <bits/stdc++.h>
using namespace std;
#define MAX 300

int main() {
    char s[MAX];
    if (fgets(s, MAX, stdin) == NULL) {
        return 0;
    }
    int len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
    if (len == 0) {
        cout << "Chuoi rong." << endl;
        return 0;
    }
    char *words[MAX];
    int n = 0;
    char *p = s;
    while (*p != '\0') {
        while (*p == ' ') p++;        
        if (*p == '\0') break;
        words[n++] = p;
        while (*p != ' ' && *p != '\0') p++;
        if (*p == ' ') {
            *p = '\0';
            p++;
        }
    }
    if (n == 0) {
        cout << "Chuoi rong." << endl;
    } 
    else {
        bool isCounted[MAX];
        for (int i = 0; i < n; i++) isCounted[i] = false;
        for (int i = 0; i < n; i++) {
            if (!isCounted[i]) {
                int count = 1;
                for (int j = i + 1; j < n; j++) {
                    if (strcmp(words[i], words[j]) == 0) {
                        count++;
                        isCounted[j] = true;
                    }
                }
                cout << words[i] << ": " << count << endl;
            }
        }
    }
    return 0;
}