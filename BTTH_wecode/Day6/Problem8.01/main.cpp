#include <iostream>
#include <string.h>
using namespace std;
#define MAX 300

bool kiemtraSo(char* ptr)
{
    for (; *ptr!='\0'; ptr++)
    {
        if (*ptr >= '0' && *ptr <= '9')
            return true;
    }
    return false;
}

int main()
{
    char str[MAX];
    cin.getline(str, MAX);
    if (kiemtraSo(str))
    {
        cout << "CHUOI KHONG HOP LE.";
        return 0;
    }
    char* p=str;
    for (; *p != '\0'; p++)
    {
        cout << *p;
    }
    return 0;
}
