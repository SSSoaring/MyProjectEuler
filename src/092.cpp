#include <iostream>

using namespace std;

const int MAX=10000000;
int arrive_at[MAX];

int check(const int i)
{
    int sum=0,tmp=i;

    if(arrive_at[i]!=0) return arrive_at[i];

    while(tmp!=0)
    {
        sum+=(tmp%10)*(tmp%10);
        tmp/=10;
    }
    if(sum==1||sum==89)
    {
        arrive_at[i]=sum;
        return sum;
    }
    if(arrive_at[sum]==0) arrive_at[sum]=check(sum);
    arrive_at[i]=arrive_at[sum];
    return arrive_at[i];
}

int main()
{
    int cnt=0;
    for(int i=1;i<MAX;++i) arrive_at[i]=0;
    for(int i=1;i<MAX;++i)
    {
        if(check(i)==89) ++cnt;
    }

    cout<<cnt;
    return 0;
}
