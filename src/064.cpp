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
    fraction(int n)
    {
        N=n;
        k=1;
        b=0;
        den=1;
    }
    bool iter()
    {
        int a=(k*sqrt(N)+b)/den;
        int k_new=den*k;
        int b_new=den*(a*den-b);
        int den_new=k*k*N-(a*den-b)*(a*den-b);
        int factor=gcd(gcd(k_new,den_new),b_new);
        k=k_new/factor;
        b=b_new/factor;
        den=den_new/factor;
        return den==0;
    }
    bool operator==(const fraction &f)
    {
        return (k==f.k)&&(N==f.N)&&(b==f.b)&&(den==f.den);
    }
};

bool check(int n)
{
    fraction f(n),tmp(n);
    if(f.iter()) return false;
    tmp=f;
    int i=1;
    while(true)
    {
        f.iter();
        if(f==tmp) break;
        ++i;
    }
    return (i%2==1);
}


int main()
{
    int cnt=0;
    for(int i=1;i<10000;++i)
    {
        if(check(i)) ++cnt;;
    }
    cout<<cnt;
    return 0;
}
