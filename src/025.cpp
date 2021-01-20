#include <iostream>

using namespace std;

const int num=1000;
int a[num],b[num];
int len=1;

void add(int a[],int b[])
{
    int carry=0;
    for(int i=0;i<len;++i)
    {
        a[i]=a[i]+b[i]+carry;
        carry=a[i]/10;
        a[i]%=10;
    }
    if(carry==0) return;
    a[len]=carry;
    ++len;
}

int main()
{
    for(int i=0;i<num;++i)
    {
        a[i]=0;
        b[i]=0;
    }
    int n=2;
    a[0]=1;
    b[0]=1;
    while(true)
    {
        ++n;
        if(n%2==0) add(a,b);
        else add(b,a);
        if(len==num) break;
    }
    cout << n << endl;
    return 0;
}
