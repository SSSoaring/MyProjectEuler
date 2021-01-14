#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a[]={2,3,5,7,11,13,17,19};
    int b[8];
    for(int j=0;j<8;++j)
    {
        int times=0,n=a[j];
        while(n<=20)
        {
            ++times;
            n=n*a[j];
        }
        b[j]=times;
    }
    int product=1;
    for(int j=0;j<8;++j)
    {
        for(int k=0;k<b[j];++k)
            product*=a[j];
    }
    cout<<product;
}
