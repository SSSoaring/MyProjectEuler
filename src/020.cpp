#include <iostream>

using namespace std;

int main()
{
    int a[200];
    for(int i=0;i<200;++i) a[i]=0;
    a[0]=1;
    int len=1;
    for(int i=2;i<=100;++i)
    {
        int carry=0;
        for(int j=0;j<len;++j)
        {
            a[j]=a[j]*i+carry;
            carry=a[j]/10;
            a[j]%=10;
        }
        while(carry!=0)
        {
            a[len]=carry;
            carry=a[len]/10;
            a[len]%=10;
            ++len;
        }
    }
    int sum=0;
    for(int i=0;i<len;++i) sum+=a[len-1-i];
    cout<<sum;
    return 0;
}
