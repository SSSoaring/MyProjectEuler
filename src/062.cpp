#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

struct Count_Struct
{
    long long int small_num;
    int cnt;
    Count_Struct(const long long int &cube,int n)
    {
        small_num=cube;
        cnt=n;
    }
};

map<string,Count_Struct> cnt;

bool insert(int i)
{
    long long int cube=i,tmp;
    cube=cube*cube*cube;
    tmp=cube;
    string str="";
    char ch;
    while(tmp!=0)
    {
        ch=tmp%10+'0';
        str=ch+str;
        tmp/=10;
    }
    sort(str.begin(),str.end());
    map<string,Count_Struct>::iterator iter = cnt.find(str);
    if(iter==cnt.end())
    {
        cnt.insert(pair<string,Count_Struct>(str,Count_Struct(cube,1)));
    }
    else
    {
        ++(iter->second).cnt;
        if((iter->second).cnt==5)
        {
            cout<<(iter->second).small_num;
            return true;
        }
    }
    return false;
}

int main()
{
    int i=464;
    while(!insert(i)) ++i;
    return 0;
}
