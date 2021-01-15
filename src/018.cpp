#include <iostream>

using namespace std;

int main()
{
    const int MAX=15;
    int a[MAX][MAX];
    for(int i=0;i<MAX;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cin>>a[i][j];
        }
    }
    int output=0;
    for(int i=1;i<MAX;++i)
    {
        a[i][0]+=a[i-1][0];
        a[i][i]+=a[i-1][i-1];
        for(int j=1;j<=i-1;++j)
        {
            if(a[i-1][j-1]>a[i-1][j]) a[i][j]+=a[i-1][j-1];
            else a[i][j]+=a[i-1][j];
        }
    }
    for(int j=0;j<=MAX;++j)
    {
        if(a[MAX-1][j]>output) output=a[MAX-1][j];
    }
    cout<<output<<endl;
    return 0;
}
