#include <iostream>
#include <cmath>

using namespace std;

int gcd(int m,int n)
{
    if(n==0) return m;
    return gcd(n,m%n);
}

class fraction
{
private:
    int k;
    int N;
    int b;
    int den;
public:
    void set(int n,int a0)
    {
        N=n;
        k=1;
        b=a0;
        den=n-a0*a0;
    }
    int iter()
    {
        int a=(k*sqrt(N)+b)/den;
        int k_new=den*k;
        int b_new=den*(a*den-b);
        int den_new=k*k*N-(a*den-b)*(a*den-b);
        int factor=gcd(gcd(k_new,den_new),b_new);
        k=k_new/factor;
        b=b_new/factor;
        den=den_new/factor;
        return a;
    }
};

int main()
{
    int cnt=0,period,a0,ai;
    fraction f;
    for(int i=1;i<10000;++i)
    {
        a0=sqrt(i);
        if(a0*a0==i) continue;
        f.set(i,a0);
        period=1;
        while(true)
        {
            ai=f.iter();
            if(ai==2*a0) break;
            ++period;
        }
        if (period%2==1) ++cnt;
    }
    cout<<cnt;
    return 0;
}
