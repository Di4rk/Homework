
#include <iostream>
#include <string.h>
using namespace std;
#define MAX 255

int myStrcmp(char s1[], char s2[]);

int main()
{
	char s1[MAX], s2[MAX];
	fgets(s1, MAX, stdin);
	fgets(s2, MAX, stdin);
	int kt = myStrcmp(s1, s2);
	cout << kt << endl;
	return 0;
}

int myStrcmp(char s1[], char s2[]) 
{
        int i=0,j=0;
        while(s1[i]!='\0') 
        {
            if(s1[i]=='\n' || s1[i]=='\r') break;
            i++;
        }
        while(s2[j]!='\0')
        {
            if(s2[j]=='\n' || s2[j]=='\r') break;
            j++;
        }
        if(i<j) return -1;
        else if(i>j) return 1;
        else
        {
            for(int k=0;k<i;k++)
            {
                if(s1[k]<s2[k]) return -1;
                else if(s1[k]>s2[k]) return 1;
            }
            return 0;
        }
}