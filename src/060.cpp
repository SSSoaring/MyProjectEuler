#include <iostream>
#include <cmath>

using namespace std;

const int MAX=10000000;
bool p[MAX];

bool is_prime(long long int n)
{
    if(n<MAX) return p[n];
    if(n==3) return true;
    if(n%3==0) return false;
    long long int k=sqrt(n);
    for(int i=5;i<=k;i+=6)
    {
        if(n%i==0) return false;
        if(n%(i+2)==0) return false;
    }
    return true;
}

int next_prime(int n)
{
    int p=n+6;
    while(!is_prime(p))
    {
        p+=6;
    }
    return p;
}

int next_prime_by_2(int n)
{
    int p=n+2;
    while(!is_prime(p))
    {
        p+=2;
    }
    return p;
}


bool findpair(int num[],int len)
{
    bool flag=true;
    long long int n,tmp,p=num[len];

    for(int i=0;i<len;++i)
    {
        n=1;
        tmp=num[i];
        while(tmp!=0)
        {
            n*=10;
            tmp/=10;
        }
        if(!is_prime(p*n+num[i]))
        {
            flag=false;
            break;
        }
        n=1;
        tmp=p;
        while(tmp!=0)
        {
            n*=10;
            tmp/=10;
        }
        if(!is_prime(num[i]*n+p))
        {
            flag=false;
            break;
        }
    }
    return flag;
}


int main()
{
    int num[5];
    int sum,minsum=100000;

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

    num[0]=3;
    while(true)
    {
        if(num[0]*5>minsum) break;
        num[1]=num[0];
        while(true)
        {
            if(num[0]==3) num[1]=next_prime_by_2(num[1]);
            else num[1]=next_prime(num[1]);
            if(num[0]+num[1]*4>minsum) break;
            if(!findpair(num,1)) continue;
            num[2]=num[1];
            while(true)
            {
                num[2]=next_prime(num[2]);
                if(num[0]+num[1]+num[2]*3>minsum) break;
                if(!findpair(num,2)) continue;
                num[3]=num[2];
                while(true)
                {
                    num[3]=next_prime(num[3]);
                    if(num[0]+num[1]+num[2]+num[3]*2>minsum) break;
                    if(!findpair(num,3)) continue;
                    num[4]=num[3];
                    while(true)
                    {
                        num[4]=next_prime(num[4]);
                        sum=num[0]+num[1]+num[2]+num[3]+num[4];
                        if(sum>minsum) break;
                        if(findpair(num,4)) break;
                    }
                    if(sum>minsum) continue;
                    for(int i=0;i<5;++i)
                        cout<<num[i]<<" ";
                    cout<<sum<<endl;
                    if(sum<minsum) minsum=sum;
                }
            }
        }
        num[0]=next_prime_by_2(num[0]);
    }
    cout<<minsum;
    return 0;
}
