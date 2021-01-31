#include <iostream>

using namespace std;

int SpecialNumber[6][100];
int len[6];
int num[6];


bool check(int n,int pos,int total)
{
    bool flag=false;
    num[pos]=n;
    if(total==6)
    {
        if(n%100==num[5]/100) return true;
        num[pos]=0;
        return false;
    }
    for(int i=0;i<5;++i)
    {
        if(num[i]!=0) continue;
        for(int j=0;j<len[i];++j)
        {
            if(SpecialNumber[i][j]/100==n%100)
            {
                flag=check(SpecialNumber[i][j],i,total+1);
                if(flag) break;
            }
        }
    }
    if(!flag)
    {
        num[pos]=0;
        return false;
    }
    return true;
}

int main()
{
    for(int i=0;i<6;++i) len[i]=0;
    for(int i=45;i<=140;++i)
    {
        SpecialNumber[0][len[0]]=i*(i+1)/2;
        ++len[0];
    }
    for(int i=32;i<100;++i)
    {
        SpecialNumber[1][len[1]]=i*i;
        ++len[1];
    }
    for(int i=26;i<82;++i)
    {
        SpecialNumber[2][len[2]]=i*(3*i-1)/2;
        ++len[2];
    }
    for(int i=23;i<71;++i)
    {
        SpecialNumber[3][len[3]]=i*(2*i-1);
        ++len[3];
    }
    for(int i=21;i<64;++i)
    {
        SpecialNumber[4][len[4]]=i*(5*i-3)/2;
        ++len[4];
    }
    for(int i=19;i<59;++i)
    {
        SpecialNumber[5][len[5]]=i*(3*i-2);
        ++len[5];
    }


    int sum=0;
    for(int i=0;i<6;++i)
    {
        num[i]=0;
    }
    for(int i=0;i<len[5];++i)
    {
        if(check(SpecialNumber[5][i],5,1))
        {
            for(int j=0;j<6;++j)
            {
                cout<<num[j]<<" ";
                sum+=num[j];
            }
            cout<<endl;
        }
    }
    cout<<sum;
    return 0;
}
