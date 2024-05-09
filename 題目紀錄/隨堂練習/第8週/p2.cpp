#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t a[6];
    string s[6] = 
    {
        "second(LS)",
        "minute(LM)",
        "hour(LH)",
        "day(LD)",
        "week(LW)",
        "year(LY)"
    };
    a[0]=299792458;
    a[1]=a[0]*60;
    a[2]=a[1]*60;
    a[3]=a[2]*24;
    a[4]=a[3]*7;
    a[5]=a[3]*365;
    for(int i=0;i<6;i++)
        cout << "1 Light-" << s[i] << " is " << a[i] << " metres.\n";
}