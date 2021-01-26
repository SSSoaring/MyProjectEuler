#include <iostream>

using namespace std;

bool check(int num[],int i)
{
    if(i!=5&&num[i]==5) return false;
    for(int j=i+1;j<10;++j)
    {
        if(num[j]==num[i]) return false;
    }
    return true;
}

int main()
{
    int num[10];
    long long int tmp,sum=0;
    for(num[9]=0;num[9]<10;++num[9])
    {
        for(num[8]=0;num[8]<10;++num[8])
        {
            if(!check(num,8)) continue;
            for(num[7]=0;num[7]<10;++num[7])
            {
                if(!check(num,7)) continue;
                if((num[7]*100+num[8]*10+num[9])%17!=0) continue;
                for(num[6]=0;num[6]<10;++num[6])
                {
                    if(!check(num,6)) continue;
                    if((num[6]*100+num[7]*10+num[8])%13!=0) continue;
                    num[5]=5;
                    if((num[5]*100+num[6]*10+num[7])%11!=0) continue;
                    for(num[4]=0;num[4]<10;++num[4])
                    {
                        if(!check(num,4)) continue;
                        if((num[4]*100+num[5]*10+num[6])%7!=0) continue;
                        for(num[3]=0;num[3]<10;num[3]+=2)
                        {
                            if(!check(num,3)) continue;
                            for(num[2]=0;num[2]<10;++num[2])
                            {
                                if(!check(num,2)) continue;
                                if((num[2]*100+num[3]*10+num[4])%3!=0) continue;
                                for(num[1]=0;num[1]<10;++num[1])
                                {
                                    if(!check(num,1)) continue;
                                    num[0]=45-num[1]-num[2]-num[3]-num[4]-num[5]-num[6]-num[7]-num[8]-num[9];
                                    tmp=num[0];
                                    for(int i=1;i<10;++i) tmp=tmp*10+num[i];
                                    sum+=tmp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<sum;
    return 0;
}
