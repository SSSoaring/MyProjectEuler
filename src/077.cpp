#include <iostream>

using namespace std;

int main()
{
    int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
    int num_of_p=20;

    const int N=100;
    const int limit=5000;

    int dp[N+1];

    for(int i=0;i<=N;++i) dp[i]=0;
    dp[0]=1;

    int i=0;
    bool flag=true;
    while(flag)
    {
        for(int j=prime[i];j<=N;++j)
        {
            dp[j]+=dp[j-prime[i]];
        }

        if(i==num_of_p-1) break;
        for(int j=prime[i]+1;j<=prime[i+1];++j)
        {
            if(dp[j]>limit)
            {
                cout<<j;
                flag=false;
                break;
            }
        }
        ++i;
    }
    return 0;
}
