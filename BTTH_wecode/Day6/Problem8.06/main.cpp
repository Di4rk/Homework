/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
strlen
strcat
string
strcmp
strcpy
memmove
strstr
###End banned keyword*/

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

int myStrcmp(char s1[], char s2[])
{
    char *c=s1, *c2=s2;
    for(; ; c++,c2++)
    {
        char p = (*c == '\n' || *c == '\r') ? '\0' : *c;
        char p2 = (*c2 == '\n' || *c2 == '\r') ? '\0' : *c2;
        if (p!=p2 || p2=='\0') return p - p2;
    }
}
void mySubstr(char s[], int b, int count, char ss[])
{
    for(int i=0; i <count/2;i++)
    {
        char temp = s[b+i];
        s[b+i] = s[b+count -1 -i];
        s[b+count -1 -i] = temp;
    }
}
int myStrlen(char s[],int k)
{
    int i=0;
    while(s[i]!='\0') i++;
    return i;
}
void StringReverse(char st[])
{
    int len = myStrlen(st, MAX);
    int i=0;
    if (len>0 && (st[len-1]=='\n' || st[len-1]=='\r'))
    {
        st[len]='\0';
        len--;
    }
    while(i<len)
    {
        while (i<len && st[i]==' ') i++;
        int start = i;
        while (i<len && st[i]!=' ') i++;
        int coutn = i - start;
        mySubstr(st, start, coutn, st);
    }
}