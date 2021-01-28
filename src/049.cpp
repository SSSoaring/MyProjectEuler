#include <iostream>

using namespace std;

const int MAX=10000;
bool p[MAX];

bool check(int a,int b,int c)
{
    int flag1[10],flag2[10],tmp;
    for(int i=0;i<10;++i)
    {
        flag1[i]=0;
        flag2[i]=0;
    }
    while(a!=0)
    {
        ++flag1[a%10];
        a/=10;
    }
    while(b!=0)
    {
        ++flag2[b%10];
        b/=10;
    }
    while(c!=0)
    {
        tmp=c%10;
        if(flag1[tmp]==0||flag2[tmp]==0||flag1[tmp]!=flag2[tmp]) return false;
        --flag1[tmp];
        --flag2[tmp];
        c/=10;
    }
    return true;
}

int main()
{
    for(int i=3; i<MAX; ++i)
        p[i]=i%2;
    p[1]=false;
    p[2]=true;
    for(int i=3;i<MAX;++i)
    {
        if(!p[i])
            continue;
        for(int j=i*3;j<MAX;j+=i*2)
        {
            p[j]=false;
        }
    }
    for(int i=1001;i<=3339;i+=6)
    {
        if(p[i]&&p[i+3330]&&p[i+6660]&&check(i,i+3330,i+6660))
        {
            cout<<i<<i+3330<<i+6660<<endl;
        }
        if(p[i+2]&&p[i+3332]&&p[i+6662]&&check(i+2,i+3332,i+6662))
        {
            cout<<i+2<<i+3332<<i+6662<<endl;
        }

    }
    return 0;
}
