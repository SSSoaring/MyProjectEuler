#include <iostream>

using namespace std;

int main()
{
    int first[101][12];
    const int gap[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int sum=0;
    first[0][11]=365-30;
    for(int i=1;i<101;++i)
    {
        first[i][0]=first[i-1][11]+gap[11];
        if(first[i][0]%7==0) ++sum;
        first[i][1]=first[i][0]+gap[0];
        if(first[i][1]%7==0) ++sum;
        first[i][2]=first[i][1]+gap[1];
        if(i%4==0) ++first[i][2];
        if(first[i][2]%7==0) ++sum;
        for(int j=3;j<12;++j)
        {
            first[i][j]=first[i][j-1]+gap[j-1];
            if(first[i][j]%7==0) ++sum;
        }
    }
//    for(int i=1;i<101;++i)
//    {
//        for(int j=0;j<12;++j)
//        {
//            cout<<first[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    cout<<sum<<endl;
    return 0;
}
