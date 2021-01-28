#include <iostream>
#include <string.h>

using namespace std;

const int MAX=1000000;
bool p[MAX];

int checkreplace(const int num,const int rep[],const int num_of_rep,string &re)
{
    string s=to_string(num);

    re="";
    int cnt=0;
    for(int i=0;i<num_of_rep;++i)
    {
        if(s[rep[i]]>'2') return 0;
    }

    if(rep[0]!=0)
    {
        for(int i=0;i<num_of_rep;++i) s[rep[i]]='0';
        if(!p[atoi(s.c_str())])
        {
            ++cnt;
        }
        else
        {
            if(re=="") re=s;
        }
    }
    else cnt=1;


    for(int i=1;i<10;++i)
    {
        for(int j=0;j<num_of_rep;++j) s[rep[j]]=i+'0';
        if(!p[atoi(s.c_str())])
        {
            ++cnt;
            if(cnt>2) return 0;
        }
        else
        {
            if(re=="") re=s;
        }
    }
    return 10-cnt;
}

bool next(int rep[],const int num_of_rep,const int digit)
{
    ++rep[num_of_rep-1];
    int tmp=num_of_rep-1;
    while(rep[tmp]==digit-num_of_rep+tmp+1)
    {
        if(tmp==0) return false;
        --tmp;
        ++rep[tmp];
    }
    while(tmp<num_of_rep-1)
    {
        ++tmp;
        rep[tmp]=rep[tmp-1]+1;
    }
    return true;
}

int main()
{
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

    int rep[6],num_of_rep=0,cnt,digit;
    string replaced="";

    digit=6;
    for(int i=100001;i<=999999;i+=6)
    {
        for(num_of_rep=3;num_of_rep<digit;num_of_rep+=3)
        {
            for(int j=0;j<num_of_rep;++j) rep[j]=j;
            --rep[num_of_rep-1];
            while(next(rep,num_of_rep,digit-1))
            {
                cnt=checkreplace(i,rep,num_of_rep,replaced);
                if(cnt<8) continue;
                cout<<replaced<<":"<<cnt<<" ";
                for(int j=0;j<num_of_rep;++j) cout<<rep[j]<<" ";
                cout<<endl;
                return 0;
            }
        }
        for(num_of_rep=3;num_of_rep<digit;num_of_rep+=3)
        {
            for(int j=0;j<num_of_rep;++j) rep[j]=j;
            --rep[num_of_rep-1];
            while(next(rep,num_of_rep,digit-1))
            {
                cnt=checkreplace(i+2,rep,num_of_rep,replaced);
                if(cnt<8) continue;
                cout<<replaced<<":"<<cnt<<" ";
                for(int j=0;j<num_of_rep;++j) cout<<rep[j]<<" ";
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}
