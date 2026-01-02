#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);
void ChenChuoiTaiVitriK(char s[], char s1[], int k);

int main()
{
	char s[MAX], s1[MAX];
	fgets(s, MAX, stdin);
	fgets(s1, MAX, stdin);
	int k;
	cin >> k;
	if (k < 0 || k>myStrlen(s, 0))
		cout << "Vi tri " << k << " khong thoa dieu kien." << endl;
	else
	{
        ChenChuoiTaiVitriK(s, s1, k);
    }
}
int myStrlen(char s[], int l)
{
    int i=0;
    while(s[i]!='\0')
    {
        if (s[i]=='\n' || s[i]=='\r') break;
        i++;
    }
    return i;
}
void myStrcpy(char s[], int vt, char s1[], int k)
{
    int i=0;
    while(s1[k+i]!='\0')
    {
        s[vt+i]=s1[k+i];
        i++;
    }
    s[vt+i]='\0';
}
void mySubstr(char s[], int b, int count, char ss[])
{
    int i;
    for(i=0; i <count && s[b+i]!='\0';i++)
    {
        ss[i]=s[b+i];
    }
    ss[i]='\0';
}
bool myStrcat(char s1[], char s2[])
{
    int i=0,j=0;
    while(s1[i]!='\0') i++;
    while(s2[j]!='\0')
    {
        if (s2[j]=='\n' || s2[j]=='\r') break;
        s1[i]=s2[j];
        i++; j++;
    }
    s1[i]='\0';
    return true;
}
void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
    char ss[MAX];
    mySubstr(s, k, myStrlen(s,0)-k, ss);
    s[k]='\0';
    myStrcat(s, s1);
    myStrcat(s, ss);
    cout << s << endl;
}