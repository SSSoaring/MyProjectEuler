#include <iostream>
#include <string.h>
#include<algorithm>

using namespace std;

bool check(int n)
{
    string s1=to_string(n);
    sort(s1.begin(), s1.end());
    string s2=to_string(2*n);
    sort(s2.begin(), s2.end());
    if(s1!=s2) return false;
    s2=to_string(3*n);
    sort(s2.begin(), s2.end());
    if(s1!=s2) return false;
    s2=to_string(4*n);
    sort(s2.begin(), s2.end());
    if(s1!=s2) return false;
    s2=to_string(5*n);
    sort(s2.begin(), s2.end());
    if(s1!=s2) return false;
    s2=to_string(6*n);
    sort(s2.begin(), s2.end());
    if(s1!=s2) return false;
    return true;
}

int main()
{
    for(int i=123456;i<=165432;++i)
    {
        if(check(i))
        {
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}
