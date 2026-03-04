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
    bool isCounted[MAX];
    for (int i = 0; i < len; i++) isCounted[i] = false;
    for (int i = 0; i < len; i++) {
        if (!isCounted[i]) {
            int count = 0;
            for (int j = i; j < len; j++) {
                if (s[j] == s[i]) {
                    count++;
                    isCounted[j] = true;
                }
            }
            cout << s[i] << ": " << count << endl;
        }
    }
    return 0;
}