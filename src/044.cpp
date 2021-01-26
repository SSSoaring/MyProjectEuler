#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum,tmp,diff;
    for(int i=1;i<2000;++i)
    {
        for(int j=i+1;j<i+2000;++j)
        {
            sum=i*(3*i-1)+j*(3*j-1);
            tmp=sqrt(1+12*sum);
            if(tmp*tmp!=1+12*sum) continue;
            if((1+tmp)%6!=0) continue;

            diff=j*(3*j-1)-i*(3*i-1);
            tmp=sqrt(1+12*diff);
            if(tmp*tmp!=1+12*diff) continue;
            if((1+tmp)%6!=0) continue;
            cout<<i<<" "<<j<<" "<<diff/2<<endl;
        }
    }
}
