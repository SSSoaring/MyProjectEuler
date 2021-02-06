#include <iostream>

using namespace std;

const int Limit=50000000;
bool num[Limit+1];

int main()
{
    const int MAX=7071;
    bool p[MAX];
    int tmp,cnt=0;

    for(int i=3; i<MAX; ++i)
        p[i]=i%2;
    p[1]=false;
    p[2]=true;
    for(int i=3;i<MAX;++i)
    {
        if(!p[i])
            continue;
        for(int j=i*3;j<MAX;j+=i*2)
        {
            p[j]=false;
        }
    }

    num[4+8+16]=1;

    int max_j=369,max_k=84;

    for(int i=3;i<max_k;i+=2)
    {
        if(!p[i]) continue;
        tmp=4+8+i*i*i*i;
        if(tmp<=Limit) num[tmp]=1;
        else break;
    }

    for(int i=3;i<max_j;i+=2)
    {
        if(!p[i]) continue;
        tmp=4+i*i*i+16;
        if(tmp<=Limit) num[tmp]=1;
        else break;
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(!p[i]) continue;
        tmp=i*i+8+16;
        if(tmp<=Limit) num[tmp]=1;
        else break;
    }

    for(int i=3;i<max_j;i+=2)
    {
        if(!p[i]) continue;
        if(4+i*i*i>Limit) break;
        for(int j=3;j<max_k;j+=2)
        {
            if(!p[j]) continue;
            tmp=4+i*i*i+j*j*j*j;
            if(tmp<=Limit) num[tmp]=1;
            else break;
        }
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(!p[i]) continue;
        for(int j=3;j<max_k;j+=2)
        {
            if(!p[j]) continue;
            tmp=i*i+8+j*j*j*j;
            if(tmp<=Limit) num[tmp]=1;
            else break;
        }
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(!p[i]) continue;
        for(int j=3;j<max_j;j+=2)
        {
            if(!p[j]) continue;
            tmp=i*i+j*j*j+16;
            if(tmp<=Limit) num[tmp]=1;
            else break;
        }
    }

    for(int i=3;i<MAX;i+=2)
    {
        if(!p[i]) continue;
        for(int j=3;j<max_j;j+=2)
        {
            if(!p[j]) continue;
            tmp=i*i+j*j*j;
            if(tmp>Limit) break;
            for(int k=3;k<max_k;k+=2)
            {
                if(!p[k]) continue;
                tmp=i*i+j*j*j+k*k*k*k;
                if(tmp>Limit) break;
                num[tmp]=1;
            }
        }
    }

    for(int i=1;i<=Limit;++i)
    {
        if(num[i]) ++cnt;
    }


    cout<<cnt<<endl;
    return 0;
}
