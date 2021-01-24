#include <iostream>

using namespace std;

bool check(const int num[], const int len)
{
    for(int i=0;i<len/2;++i)
    {
        if(num[i]!=num[len-1-i]) return false;
    }
    return true;
}

int main()
{
    int num[6],len,bin[20],k;
    int sum=0;
    for(int i=1;i<1000000;i+=2)
    {
        if(i%10==0) continue;
        k=i;
        len=0;
        while(k!=0)
        {
            num[len]=k%10;
            k/=10;
            ++len;
        }
        if(!check(num,len)) continue;
        k=i;
        len=0;
        while(k!=0)
        {
            bin[len]=(k&2);
            k=k>>1;
            ++len;
        }
        if(check(bin,len)) sum+=i;
    }
    cout<<sum;
    return 0;
}
