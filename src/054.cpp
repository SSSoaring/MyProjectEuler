#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

enum Rank {HighCard,OnePair,TwoPairs,ThreeofaKind,Straight,Flush,FullHouse,FourofaKind,StraightFlush,RoyalFlush};

/* find flush,strait flush, royal flush*/
bool findFlush(int card[13][4],Rank &r,int &value)
{
    int i,j,sum=1;
    bool flag=true;
    for(i=12;i>=4;--i)
    {
        for(j=0;j<4;++j)
        {
            if(card[i][j]==0) continue;
            if(card[i][j]==1) break;
        }
        if(j!=4) break;
    }
    for(int k=i-1;k>=0;--k)
    {
        if(card[k][j]==1) ++sum;
        else flag=false;
        if(sum==5) break;
    }
    if(sum!=5) return false;
    if(flag)
    {
        if(i==12)
        {
            r=RoyalFlush;
            value=i;
            return true;
        }
        r=StraightFlush;
        value=i;
        return true;
    }
    r=Flush;
    value=i;
    return true;
}

/* find OnePair,TwoPairs,Three of a Kind,Flush,FullHouse,Four of a Kind */
bool findSameValue(int card[13][4],Rank &r,int &value)
{
    int sum,i;
    bool flag=false;
    for(i=0;i<13;++i)
    {
        sum=card[i][0]+card[i][1]+card[i][2]+card[i][3];
        if(sum==3)
        {
            r=ThreeofaKind;
            value=i;
            flag=true;
            break;
        }
        if(sum==2)
        {
            r=OnePair;
            value=i;
            flag=true;
            break;
        }
        if(sum>=4)
        {
            r=FourofaKind;
            value=i;
            return true;
        }
    }
    if(!flag) return false;
    for(++i;i<13;++i)
    {
        sum=card[i][0]+card[i][1]+card[i][2]+card[i][3];
        if(sum==3)
        {
            r=FullHouse;
            value=i;
            return true;
        }
        if(sum==2)
        {
            if(r==OnePair)
            {

                r=TwoPairs;
                value=i;
                return true;
            }
            r=FullHouse;
            return true;
        }
    }
    return true;
}

/* find straight highcard */
bool findStraight(int card[13][4],Rank &r,int &value)
{
    int sum;
    int cnt=1;
    for(int i=12;i>=4;--i)
    {
        sum=card[i][0]+card[i][1]+card[i][2]+card[i][3];
        if(sum==0) continue;
        if(sum==1)
        {
            value=i;
            break;
        }
    }
    for(int i=value-1;i>=0;--i)
    {
        sum=card[i][0]+card[i][1]+card[i][2]+card[i][3];
        if(sum==0)
        {
            r=HighCard;
            return true;
        }
        ++cnt;
        if(cnt==5) break;
    }
    r=Straight;
    return true;
}

/* RankValue is used to break tie when 2 players have the same rank */
/* BreakTie is used to break tie when 2 players have the same rank and RankValue */
void highest(string cards[],Rank &r,int &RankValue,string &breaktie)
{
    int card[13][4],value;
    breaktie="0000000000000";
    for(int i=0;i<13;++i)
    {
        for(int j=0;j<4;++j)
        {
            card[i][j]=0;
        }
    }
    for(int i=0;i<5;++i)
    {
        if(cards[i][0]<='9'&&cards[i][0]>='2') value=cards[i][0]-'2';
        else
        {
            switch(cards[i][0])
            {
                case 'T':value=8;break;
                case 'J':value=9;break;
                case 'Q':value=10;break;
                case 'K':value=11;break;
                case 'A':value=12;break;
            }
        }
        switch(cards[i][1])
        {
            case 'C':++card[value][0];break;
            case 'D':++card[value][1];break;
            case 'H':++card[value][2];break;
            case 'S':++card[value][3];break;
        }
        breaktie[12-value]+=1;
    }
    r=HighCard;
    if(findFlush(card,r,RankValue)) return;
    if(findSameValue(card,r,RankValue)) return;
    if(findStraight(card,r,RankValue)) return;
}

bool compare(const string &str)
{
    string c1[10],b1,b2;
    int len=0,tmp=0,i=0;

    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            c1[len]=str.substr(tmp,2);
            ++len;
            while(str[i+1]==' ') ++i;
            tmp=i+1;
        }
        ++i;
    }
    c1[len]=str.substr(tmp,2);
    Rank r1,r2;
    int v1,v2;
    highest(c1,r1,v1,b1);
    highest(c1+5,r2,v2,b2);
    if(r1>r2||(r1==r2&&v1>v2)) return true;
    if(r1<r2||(r1==r2&&v1<v2)) return false;
    if(b1<b2) return false;
    else return true;
}

int main()
{
    string s;
    ifstream poker;
    int cnt=0;
    poker.open("./data/p054_poker.txt");
    char buf[100];
    if(poker.is_open())
    {
        while(poker.good()&&!poker.eof())
        {
            poker.getline(buf,100);
            s=buf;
            if(s.length()<20) break; //remove the final line
            if(compare(s)) ++cnt;
        }
    }
    poker.close();
    cout<<cnt;
    return 0;
}
