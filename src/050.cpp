#include <iostream>

using namespace std;

const int MAX=1000000;
bool p[MAX];

long long int sum[1000];

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

    int len;
    sum[0]=2;
    sum[1]=5;
    len=2;
    for(int i=5;i<5000;i+=6)
    {
        if(p[i])
        {
            sum[len]=sum[len-1]+i;
            ++len;
        }
        if(p[i+2])
        {
            sum[len]=sum[len-1]+i+2;
            ++len;
        }
    }

    int maxlen=0,maxp=0;
    for(int i=len;i>0;--i)
    {
        if(sum[i]<MAX&&p[sum[i]])
        {
            maxlen=i;
            maxp=sum[i];
            break;
        }
    }

    int tmp;
    while(len>maxlen)
    {
        tmp=sum[0];
        for(int i=0;i<len-1;++i)
        {
            sum[i]=sum[i+1]-tmp;
            if(i>maxlen&&sum[i]<MAX&&p[sum[i]])
            {
                maxlen=i;
                maxp=sum[i];
            }
        }
        --len;
    }

    cout<<maxlen+1<<" "<<maxp<<endl;
    return 0;
}
