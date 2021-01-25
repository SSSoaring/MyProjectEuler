#include <iostream>

using namespace std;

bool check(int num[],int len)
{
    bool flag[9];
    for(int i=0;i<9;++i) flag[i]=false;
    int digit,tmp;
    for(int i=0;i<len;++i)
    {
        tmp=num[i];
        while(tmp>0)
        {
            digit=tmp%10;
            tmp/=10;
            if(digit==0||flag[digit-1]) return false;
            flag[digit-1]=true;
        }
    }
    for(int i=0;i<9;++i) if(!flag[i]) return false;
    return true;
}

int main()
{
    int num[5];
    int maxp=0,p;
    for(int i=9;i<=9;++i)
    {
        for(int j=1;j<=5;++j)
        {
            num[j-1]=i*j;
        }
        if(check(num,5))
        {
            p=num[0];
            for(int j=2;j<=5;++j)
            {
                p=p*100+num[j-1];
            }
            if(p>maxp) maxp=p;
        }
    }
    for(int i=9123;i<=9876;++i)
    {
        for(int j=1;j<=2;++j)
        {
            num[j-1]=i*j;
        }
        if(check(num,2))
        {
            p=num[0]*100000+num[1];
            if(p>maxp) maxp=p;
        }
    }
    cout<<maxp;
    return 0;
}
