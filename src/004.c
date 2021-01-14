#include <iostream>

using namespace std;

bool check(int p)
{
    int a[6],len=0;
    while(p!=0)
    {
        a[len]=p%10;
        p=p/10;
        ++len;
    }
    for(int i=0;i<len/2;++i)
    {
        if(a[i]!=a[len-1-i]) return false;
    }
    return true;
}



int main()
{
    int product;
    int max_p=0;
    for(int i=999;i>99;--i)
    {
        for(int j=i;j>99;--j)
        {
            product=i*j;
            if(check(product))
            {
                if(product>max_p)
                {
                    max_p=product;
                    cout<<product<<" "<<i<<" "<<j<<endl;
                }
            }
        }
    }
    cout<<max_p;
    return 0;
}
