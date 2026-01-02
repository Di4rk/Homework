
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void ChenChuoiTaiVitriK(char s[], char s1[], int k);
void Chuanhoa(char s[]);
int myStrlen(char s[], int k);
bool myStrcat(char s[], char s1[], char s2[]);
void myStrcpy(char s[], int vt, char s1[], int k);
int myStrstr(char s[], char s1[]);

int main()
{
	char s[MAX];

	fflush(stdin);
	fgets(s,MAX,stdin);

	char s1[MAX];
	myStrcpy(s1, 0, s, 0);
	Chuanhoa(s1);
	cout << s << endl << s1 << endl;
	return 0;
}

int myStrlen(char s[], int k)
{
    int len = 0;
    for (; s[k]!= '\0'; k++)
    {
        len++;
    }
    return len;
}
void myStrcpy(char s[], int vt, char s1[], int k)
{
    for (; s1[k] != '\0';k++,vt++)
    {
        s[vt] = s1[k];
    }
    s[vt] = '\0';
}
void ChenChuoiTaiVitriK(char s[], char s1[], int k)
{
    int len1 = myStrlen(s, 0);
    int len2 = myStrlen(s1, 0);
    for (int i=len1-1; i>=k; i--)
    {
        s[i+len2] = s[i];
    }
    for (int i=0; i<len2; i++)
    {
        s[k+i] = s1[i];
    }
    s[len1+len2] = '\0';
}
void Chuanhoa(char s[])
{
    int len = myStrlen(s, 0);
    while (len > 0 && s[len-1]==' ' && s[len-1]!='\n' && s[len-1]!='\r')
    {
        s[--len]='\0';
    }
    for (int i=0; i<len;i++)
    {
        if (s[i]== '.' && s[i-1]==' ')
        {
            myStrcpy(s,i-1,s,i);
            len--;
            i-=2;
            continue;
        }
        if (s[i]=='.')
        {
            if (s[i+1]!= '\0')
                if (s[i+1]!=' ')
                {
                    for(int j=len;j>i+1;j--) s[j]=s[j-1];
                    s[i+1]=' ';
                    len++; 
                    s[len]='\0';
                }
                else if (s[i+2]==' ')
                {
                    myStrcpy(s,i+1,s,i+2);
                    len--;
                    i--;
                }
        }
    }
        
}
