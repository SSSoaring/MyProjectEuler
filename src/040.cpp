#include <iostream>

using namespace std;

int d(int n)
{
    int k=1,num, digit,t,b=1,m=10;
    while(k*m-b<n)
    {
        m=m*10;
        ++k;
        b=b*10+1;
    }
    num=(n+b-1)/k;
    t=k-n+num*k-b+1;
    while(t!=0)
    {
        digit=num%10;
        num/=10;
        --t;
    }
    return digit;
}

int main()
{
    cout<<d(1)*d(10)*d(100)*d(1000)*d(10000)*d(100000)*d(1000000);
    return 0;
}
