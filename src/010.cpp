#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int n)
{
    if(n%2==0) return false;
    if(n%3==0) return false;
    for(int i=5;i<=sqrt(n);i+=6)
    {
        if(n%i==0) return false;
        if(n%(i+2)==0) return false;
    }
    return true;
}

void method1(int n)
{
    long long sum=2+3;
    int i=5;
    while(i<n)
    {
        if(IsPrime(i)) sum+=i;
        if(IsPrime(i+2)) sum+=(i+2);
        i+=6;
    }
    cout << sum << endl;
}


int a[2000000];

void method2(int n)
{
    for(int i=0;i<n;++i) a[i]=i%2;
    a[0]=0;
    a[1]=0;
    for(int i=2;i<=(sqrt(n)-1)/2;++i)
    {
        if(a[i]==0) continue;
        for(int j=3*i;j<n;j+=2*i)
        {
            a[j]=0;
        }
    }

    long long sum=2+3;
    for(int i=5;i<n-2;i+=6)
    {
        if(a[i]) sum+=i;
        if(a[i+2]) sum+=(i+2);
    }
    cout << sum << endl;
}

int main()
{
    int MAX=2000000;
    method2(MAX);
    return 0;
}
