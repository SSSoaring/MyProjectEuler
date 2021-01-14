#include <iostream>

using namespace std;

int main()
{
    int MAX=302;
    int a[MAX];
    a[0]=1;
    int carry=0;
    int len=1;
    for(int i=0;i<1000;++i)
    {
        carry=0;
        for(int j=0;j<len;++j)
        {
            a[j]=a[j]*2+carry;
            carry=a[j]/10;
            a[j]=a[j]%10;
        }
        a[len]=carry;
        len+=carry;
    }
    int sum=0;
    int i=len-1;
    while(a[i]==0)
    {
        --i;
    }
    for(;i>=0;--i)
    {
        sum+=a[i];
        cout<<a[i];
    }
    cout<<endl<<sum<<endl;
    return 0;
}
