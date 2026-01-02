#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void StringReverse(char st[]);

int main()
{
	char s[MAX];
	fgets(s, MAX, stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
	{
		StringReverse(s);
		cout << s << endl;
	}
	return 0;
}

int myStrlen(char s[], int k) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

int myStrcmp(char s1[], char s2[]) {
    int i = 0;
    while (1) {
        char c1 = s1[i];
        char c2 = s2[i];
        
        if (c1 == '\n' || c1 == '\r') c1 = '\0';
        if (c2 == '\n' || c2 == '\r') c2 = '\0';
        
        if (c1 != c2) return c1 - c2;
        if (c1 == '\0') return 0;
        i++;
    }
}

void myStrcpy(char s[], int vt, char s1[], int k) {
    int i = 0;
    while (s1[k + i] != '\0') {
        s[vt + i] = s1[k + i];
        i++;
    }
    s[vt + i] = '\0';
}

void mySubstr(char s[], int b, int count, char ss[]) {
    int i;
    for (i = 0; i < count && s[b + i] != '\0'; i++) {
        ss[i] = s[b + i];
    }
    ss[i] = '\0';
}

bool myStrcat(char s1[], char s2[]) {
    int len = myStrlen(s1, 0);
    int i = 0;
    while (s2[i] != '\0') {
        s1[len + i] = s2[i];
        i++;
    }
    s1[len + i] = '\0';
    return true;
}

void StringReverse(char st[]) {
    int len = myStrlen(st, 0);
    for(int i = 0; i < len; i++) {
        if(st[i] == '\n' || st[i] == '\r') {
            st[i] = '\0';
            break;
        }
    }

    char *words[MAX];
    int count = 0;
    char *p = st;
    
    while (*p != '\0') {
        while (*p == ' ') p++;
        
        if (*p == '\0') break;
        
        words[count++] = p;
        
        while (*p != ' ' && *p != '\0') p++;
        
        if (*p == ' ') {
            *p = '\0';
            p++;
        }
    }
    
    char buffer[MAX];
    buffer[0] = '\0';
    
    if (count > 0) {
        for (int i = count - 1; i >= 0; i--) {
            myStrcat(buffer, words[i]);
            if (i > 0) myStrcat(buffer, " ");
        }
        myStrcpy(st, 0, buffer, 0);
    } else {
        st[0] = '\0';
    }
}