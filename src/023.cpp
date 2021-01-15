#include <iostream>
#include <cmath>

using namespace std;

int compute_d(int n)
{
    int sum=1;
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
    int num=0;
    bool b[mlimit+1];
    for(int i=1;i<=mlimit;++i)
    {
        b[i]=false;
        if(compute_d(i)>i)
        {
            a[num]=i;
            ++num;
        }
    }
    for(int i=0;i<num;++i)
    {
        for(int j=i;j<num;++j)
        {
            if(a[i]+a[j]<=mlimit) b[a[i]+a[j]]=true;
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
