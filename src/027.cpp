#include <iostream>

using namespace std;

const int Max=13000;
int p[Max];

void check()
{
    p[0]=0;
    p[1]=0;
    p[2]=1;
    for(int i=3;i<Max;++i) p[i]=i%2;
    for(int i=3;i*i<Max;i+=2)
    {
        if(p[i]==0) continue;
        for(int k=3;k*i<Max;k+=2)
            p[k*i]=0;
    }
}

bool check(int n)
{
    if(n<=1) return false;
    if(p[n]) return true;
    return false;
}

int main()
{
    int n,a,b,max_n=1,max_a,max_b;
    check();
    for(a=-999;a<=999;++a)
    {
        for(b=2;b<=1000;++b)
        {
            if(!p[b]) continue;
            n=1;
            while(check(n*(n+a)+b)) ++n;
            if(n>max_n)
            {
                max_n=n;
                max_a=a;
                max_b=b;
            }
        }
    }
    cout<<max_a*max_b<<" "<<max_n<<endl;
    return 0;
}
