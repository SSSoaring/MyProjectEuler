#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int a,b;
    int digit;
    bool flag=false;
    for(b=101010103;b<138902662;b+=10)
    {
        a=b*b-10000000000000000;
        flag=true;
        for(int i=9;i>=2;--i)
        {
            digit=a%10;
            a/=100;
            if(digit!=i)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<b;
            break;
        }

        a=(b+4)*(b+4)-10000000000000000;
        flag=true;
        for(int i=9;i>=2;--i)
        {
            digit=a%10;
            a/=100;
            if(digit!=i)
            {
                flag=false;
                break;
            }
        }
        if(flag)
        {
            cout<<b+4;
            break;
        }
    }
    cout<<0;
    return 0;
}
