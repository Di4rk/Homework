
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemTieng(char s1[]);
int myStrcmp(char s1[], char s2[]);
int myStrlen(char s[], int k);
void myStrcpy(char s[], int vt, char s1[], int k);
void myMemmove(char s[], int vt, int k);
int myStrstr(char s[], char s1[]);
void mySubstr(char s[], int b, int count, char ss[]);
bool myStrcat(char s1[], char s2[]);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemTieng(s);
	return 0;
}

int myStrcmp(char s1[], char s2[])
{
    char *c=s1, *c2=s2;
    for(; ; c++, c2++)
    {
        char val1 = *c, val2 = *c2; 
        char p = (val1 == '\n' || val1 == '\r') ? '\0' : val1;
        char p2 = (val2 == '\n' || val2 == '\r') ? '\0' : val2;
        if (p != p2 || p2 == '\0')
            return p - p2;
    }
}
void mySubstr(char s[], int b, int count, char ss[])
{
    for (int i=0; i<count;i++)
    {
        ss[i]=s[b+i];
    }
    ss[count]='\0';
}
int myStrlen(char s[],int k)
{
    int i=0;
    while(s[i]!='\0') i++;
    return i;
}
void DemTieng(char s1[])
{
    int len = myStrlen(s1, MAX);
    char dsTu[100][MAX];
    int n=0;
    int i=0;
    while(i<len)
    {
        if (s1[i]== ' ' || s1[i] == '\n' || s1[i] == '\r')
        {
            i++;
            continue;
        }
        int start=i;
        while (i<len && s1[i]!=' ' && s1[i] != '\n' && s1[i] != '\r')
            i++;
        int count = i - start;
        mySubstr(s1, start, count, dsTu[n]);
        n++;        
    }
    int visited[100]={0};
    for(int i=0;i<n;i++)
        {
        if(visited[i]) continue;
        int count=1;
        for(int j=i+1;j<n;j++)
        {
            if(myStrcmp(dsTu[i], dsTu[j])==0)
            {
                count++;
                visited[j]=1;
            }
        }
        cout<<dsTu[i]<<": "<<count<<endl;
    }
}