
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX 300

void DemKyTu(char s[]);
int myStrcmp(char s1[MAX], char s2[MAX]);
int myStrlen(char s[], int k);

int main()
{
	char s[MAX];
	fgets(s,MAX,stdin);	//Nhap chuoi s	
	if (myStrcmp(s, "") == 0)
		cout << "Chuoi rong." << endl;
	else
		DemKyTu(s);

	return 0;
}
int myStrcmp(char s1[MAX], char s2[MAX])
{
	if (s1[0] == '\n' || s1[0] == '\0' || s1[0] == '\r')
		return 0;
	return 1;
}
void DemKyTu(char s[])
{
	int len = myStrlen(s, MAX);
	s[len] = '\0';
	len--;
	int count[256] = {0};
	char *p = s;
	for(int i=0; i<len && s[i]!='\0';i++)
	{
		count[(unsigned char)*(p+i)]++;
	}
	p = s;
	for (;*p != '\0'; p++)
	{
		if (count[(unsigned char)*p] != 0)
		{
			cout << *p << ": " << count[(unsigned char)*p] << endl;
			count[(unsigned char)*p] = 0;
		}
	}
}
int myStrlen(char s[], int k)
{
	int i=0;
	for (; s[i] != '\0';i++);
	return i;
}