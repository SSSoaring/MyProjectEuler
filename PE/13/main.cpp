#include <iostream>

using namespace std;

string s[100];


int main()
{
    for(int i=0;i<100;++i) cin>>s[i];
    int carry=0;
    int a[52];
    for(int i=49;i>=0;--i)
    {
        a[i+2]=carry;
        for(int j=0;j<100;++j)
        {
            a[i+2]+=s[j][i]-'0';
        }
        carry=a[i+2]/10;
        a[i+2]%=10;
    }
    a[1]=carry%10;
    carry/=10;
    a[0]=carry;

    int digit=0;
    for(int i=0;i<52;++i) cout<<a[digit+i];
    return 0;
}
