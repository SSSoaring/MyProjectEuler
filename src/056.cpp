#include <iostream>

using namespace std;

int multiply(int num[],int &len,int a)
{
    int carry=0,sum=0;
    for(int i=0;i<len;++i)
    {
        num[i]=num[i]*a+carry;
        carry=num[i]/10;
        num[i]%=10;
        sum+=num[i];
    }
    while(carry!=0)
    {
        num[len]=carry%10;
        sum+=num[len];
        carry/=10;
        ++len;
    }
    return sum;
}

int test(int a)
{
    int num[200];
    int len=0,tmp=a,sum=0,maxsum=0;
    while(tmp!=0)
    {
        num[len]=tmp%10;
        sum+=num[len];
        tmp/=10;
        ++len;
    }
    maxsum=sum;
    for(int i=2;i<100;++i)
    {
        sum=multiply(num,len,a);
        if(sum>maxsum) maxsum=sum;
    }
    return maxsum;
}

int main()
{
    int maxsum=0,sum;
    for(int i=2;i<100;++i)
    {
        if(i%10==0) continue;
        sum=test(i);
        if(sum>maxsum) maxsum=sum;
    }
    cout<<maxsum;
    return 0;
}
