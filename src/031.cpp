#include <iostream>

using namespace std;

int main()
{
    int coin[9]={0,1,2,5,10,20,50,100,200};
    int goal=200;
    int dp[201];

    for(int j=1;j<201;++j) dp[j]=0;
    dp[0]=1;
    for(int i=1;i<9;++i)
    {
        dp[0]=1;
        for(int j=coin[i];j<201;++j)
        {
            dp[j]+=dp[j-coin[i]];
        }
    }
    cout << dp[goal] << endl;
    return 0;
}
