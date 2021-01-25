#include <iostream>

using namespace std;

const int MAX=1000000;

bool p[MAX];

int main()
{
    for(int i=2; i<MAX; ++i)
        p[i]=i%2;
    p[2]=true;
    for(int i=3; i<MAX; ++i)
    {
        if(!p[i])
            continue;
        for(int j=i*3; j<MAX; j+=i*2)
        {
            p[j]=false;
        }
    }
    int sum=0;
    //1-digit:
    int p1[4]={2,3,5,7};
    //2-digit:
    for(int a=0; a<4; ++a)
    {
        for(int b=0; b<4; ++b)
        {
            if(p[10*p1[a]+p1[b]])
            {
                sum+=10*p1[a]+p1[b];
                cout<<p1[a]<<p1[b]<<endl;
            }
        }
    }
    //3-digit
    for(int a=0; a<4; ++a)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=0; c<4; ++c)
            {
                if(p[100*p1[a]+10*b+p1[c]]&&p[10*b+p1[c]]&&p[10*p1[a]+b])
                {
                    sum+=100*p1[a]+10*b+p1[c];
                    cout<<p1[a]<<b<<p1[c]<<endl;
                }
            }
        }
    }
    //4-digit
    for(int a=0; a<4; ++a)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=0; d<4; ++d)
                {
                    if(p[1000*p1[a]+100*b+10*c+p1[d]]&&p[100*b+10*c+p1[d]]
                       &&p[10*c+p1[d]]&&p[100*p1[a]+10*b+c]&&p[10*p1[a]+b])
                    {
                        sum+=1000*p1[a]+100*b+10*c+p1[d];
                        cout<<p1[a]<<b<<c<<p1[d]<<endl;
                    }
                }
            }
        }
    }
    //5-digit
    for(int a=0; a<4; ++a)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=1; d<=9; d+=2)
                {
                    for(int e=0; e<4; ++e)
                    {
                        if(p[10000*p1[a]+1000*b+100*c+10*d+p1[e]]&&p[1000*b+100*c+10*d+p1[e]]
                           &&p[100*c+10*d+p1[e]]&&p[10*d+p1[e]]
                           &&p[1000*p1[a]+100*b+10*c+d]&&p[100*p1[a]+10*b+c]&&p[10*p1[a]+b])
                        {
                            sum+=10000*p1[a]+1000*b+100*c+10*d+p1[e];
                            cout<<p1[a]<<b<<c<<d<<p1[e]<<endl;
                        }
                    }
                }
            }
        }
    }
    //6-digit
    for(int a=0; a<4; ++a)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=1; d<=9; d+=2)
                {
                    for(int e=1; e<=9; e+=2)
                    {
                        for(int f=0; f<4; ++f)
                        {
                            if(p[100000*p1[a]+10000*b+1000*c+100*d+10*e+p1[f]]&&p[10000*b+1000*c+100*d+10*e+p1[f]]
                                    &&p[1000*c+100*d+10*e+p1[f]]&&p[100*d+10*e+p1[f]]&&p[10*e+p1[f]]&&p[10*p1[a]+b]
                                    &&p[10000*p1[a]+1000*b+100*c+10*d+e]&&p[1000*p1[a]+100*b+10*c+d]&&p[100*p1[a]+10*b+c])
                            {
                                sum+=100000*p1[a]+10000*b+1000*c+100*d+10*e+p1[f];
                                cout<<p1[a]<<b<<c<<d<<e<<p1[f]<<endl;
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
