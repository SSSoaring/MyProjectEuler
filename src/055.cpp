#include <iostream>

using namespace std;

bool reverse_add_isPalindromic(int num[],int &len)
{
    int carry=0;

    for(int i=0;i<len/2;++i)
    {
        num[i]=num[i]+num[len-1-i];
        num[len-1-i]=num[i];
    }
    if(len%2==1) num[len/2]*=2;

    for(int i=0;i<len;++i)
    {
        num[i]+=carry;
        carry=num[i]/10;
        num[i]%=10;
    }
    if(carry)
    {
        num[len]=carry;
        ++len;
    }

    for(int i=0;i<len/2;++i)
    {
        if(num[i]!=num[len-1-i]) return false;
    }
    return true;
}

bool isLychrel(int n)
{
    int num[100];
    int len=0;
    bool flag;

    while(n!=0)
    {
        num[len]=n%10;
        ++len;
        n/=10;
    }

    for(int i=1;i<50;++i)
    {
        flag=reverse_add_isPalindromic(num,len);
        if(flag) return false;
    }
    return true;
}

int main()
{
    int cnt=0;
    for(int i=1;i<10000;++i)
    {
        if(isLychrel(i)) ++cnt;
    }
    cout<<cnt;
    return 0;
}
