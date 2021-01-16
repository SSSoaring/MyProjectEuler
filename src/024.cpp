#include <iostream>

using namespace std;

int main()
{
    int p=1000000;
    int a[10];
    for(int i=0;i<10;++i) a[i]=i;
    int prod=1,k=1;
    int tmp,tmp_i;

    while(prod<p)
    {
        ++k;
        prod*=k;
    }

    while(k>1)
    {
        prod/=k;
        --k;
        tmp_i=(p-1)/prod;
        p=p-tmp_i*prod;
        if(tmp_i==0) continue;
        tmp=a[9-k+tmp_i];
        for(int i=9-k+tmp_i;i>9-k;--i) a[i]=a[i-1];
        a[9-k]=tmp;
    }
    for(int i=0;i<10;++i) cout<<a[i];
    return 0;
}
