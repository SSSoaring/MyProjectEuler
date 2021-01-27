#include <iostream>

using namespace std;

const int MAX=200000;

int CountFactor(int n)
{
    int cnt=0;
    if(n%2==0)
    {
        ++cnt;
        while(n%2==0)
        {
            n/=2;
        }
    }
    if(n%3==0)
    {
        ++cnt;
        while(n%3==0)
        {
            n/=3;
        }
    }
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0)
        {
            ++cnt;
            while(n%i==0)
            {
                n/=i;
            }
        }
        if(n%(i+2)==0)
        {
            ++cnt;
            while(n%(i+2)==0)
            {
                n/=(i+2);
            }
        }
    }
    if(n!=1) ++cnt;
    return cnt;
}

int main()
{
    int cnt=0;
    for(int i=646;i<MAX;++i)
    {
        if(CountFactor(i)==4) ++cnt;
        else cnt=0;
        if(cnt==4)
        {
            cout<<i-3;
            break;
        }
    }
    return 0;
}
