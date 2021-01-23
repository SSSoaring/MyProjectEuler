#include <iostream>

using namespace std;

const int MAX=9999;
bool product[MAX+1];

bool check(int a,int b,int p)
{
    bool flag[9];
    for(int i=0;i<9;++i) flag[i]=false;
    int digit;
    while(a>0)
    {
        digit=a%10;
        a/=10;
        if(digit==0||flag[digit-1]) return false;
        flag[digit-1]=true;
    }
    while(b>0)
    {
        digit=b%10;
        b/=10;
        if(digit==0||flag[digit-1]) return false;
        flag[digit-1]=true;
    }
    while(p>0)
    {
        digit=p%10;
        p/=10;
        if(digit==0||flag[digit-1]) return false;
        flag[digit-1]=true;
    }
    for(int i=0;i<9;++i) if(!flag[i]) return false;
    return true;
}

int main()
{
    int p,sum=0;
    for(int i=0;i<=MAX;++i) product[i]=false;
    for(int a=1;a<=99;++a)
    {
        for(int b=a;b<=9999/a;++b)
        {
            p=a*b;
            if(product[p]) continue;
            if(check(a,b,p))
            {
                product[p]=true;
                sum+=p;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
