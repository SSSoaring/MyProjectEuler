#include <iostream>

using namespace std;

int main()
{
    int f[10];
    f[0]=1;
    for(int i=1;i<10;++i)
    {
        f[i]=f[i-1]*i;
    }

    const int MAX=1000000;
    int tmp,last_sum,sum,cnt=0,length_of_chain;
    for(int i=1;i<MAX;++i)
    {
        tmp=i;
        length_of_chain=1;
        last_sum=i;

        while(true)
        {
            sum=0;
            while(tmp!=0)
            {
                sum+=f[tmp%10];
                tmp/=10;
            }
            if(sum==last_sum)
            {
                break;
            }
            if(sum==169||sum==363601||sum==1454)
            {
                length_of_chain+=3;
                break;
            }
            if(sum==871||sum==45361)
            {
                length_of_chain+=2;
                break;
            }
            if(sum==872||sum==45362)
            {
                length_of_chain+=2;
                break;
            }
            tmp=sum;
            last_sum=sum;
            ++length_of_chain;
        }
        if(length_of_chain==60) ++cnt;
    }
    cout<<cnt;
    return 0;
}
