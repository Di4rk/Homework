
#include <iostream>
#include <string>
using namespace std;
#define MAX 255

int myStrlen(char s[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1, MAX, stdin);
	fgets(s2, MAX, stdin);
	bool kt = myStrcat(s1, s2);
    if (kt)
        cout << s1 << endl;
    else
        cout << "Khong noi duoc. Khong du bo nho." << endl;
}

int myStrlen(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        if (s[i]=='\n' || s[i]=='\r') break;
        i++;
    }
    return i;
}
bool myStrcat(char s1[], char s2[])
{
    int len1 = myStrlen(s1);
    int len2 = myStrlen(s2);
    if (len1 + len2 >= MAX - 1) 
        return false;
    for (int i = 0; i < len2; i++)
    {
        s1[len1 + i] = s2[i];
    }
    s1[len1 + len2] = '\0';
    return true;
}
