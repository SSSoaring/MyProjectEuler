#include <iostream>
#include <cmath>

using namespace std;

int compute_d1(int n)
{
    int sum=1;
    for(int i=2;i<=sqrt(n);++i)
    {
        int k=1;
        while(n%i==0)
        {
            k=k*i+1;
            n/=i;
        }
        sum*=k;
    }
    if(n>1) sum*=(1+n);
    return sum;
}

int compute_d2(int n)
{
    int sum=n;
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0) sum+=i+n/i;
        if(i*i==n) sum-=i;
    }
    return sum;
}

int main()
{
    const int mlimit=28123;
    int a[mlimit+1];
    int num=0,tmp;
    bool b[mlimit+1];
    for(int i=1;i<=mlimit;++i)
    {
        b[i]=false;
        if(compute_d1(i)>2*i)
        {
            a[num]=i;
            ++num;
        }
    }
    for(int i=0;i<num;++i)
    {
        for(int j=i;j<num;++j)
        {
            tmp=a[i]+a[j];
            if(tmp<=mlimit) b[tmp]=true;
        }
    }
    int sum=0;
    for(int i=1;i<=mlimit;++i)
    {
        if(!b[i])
        {
            sum+=i;
        }
    }
    cout<<sum;
    return 0;
}
