#include <iostream>

using namespace std;

bool check(int num)
{
    bool flag[7];
    for(int i=0;i<7;++i) flag[i]=false;
    int digit,tmp;
    tmp=num;
    while(tmp>0)
    {
        digit=tmp%10;
        tmp/=10;
        if(digit==0||flag[digit-1]) return false;
        flag[digit-1]=true;
    }
    for(int i=0;i<7;++i) if(!flag[i]) return false;
    return true;
}

bool  isPrime(int n)
{
    for(int i=5;i*i<=n;i+=6)
    {
        if(n%i==0) return false;
        if(n%(i+2)==0) return false;
    }
    return true;
}

int main()
{
    int maxp=0;
    for(int i=1234567;i<=7654321;i+=6)
    {
        if(check(i)&&isPrime(i)) maxp=i;
        if(check(i+4)&&isPrime(i+4)) maxp=i+4;
    }
    cout<<maxp;
    return 0;
}
