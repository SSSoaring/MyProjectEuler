#include <iostream>

using namespace std;

int gcd(int n,int d)
{
    int k;
    while(n!=0)
    {
        k=d%n;
        d=n;
        n=k;
    }
    return d;
}


int main()
{
    int k,n=1,d=1;
    for(int i=1;i<=9;++i)
    {
        for(int j=i+1;j<=9;++j)
        {
            if(10*i*j%(9*i+j)==0)
            {
                k=10*i*j/(9*i+j);
                n*=i;
                d*=k;
            }
        }
    }
    cout<<d/gcd(n,d);
    return 0;
}
