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
    //1-digit: 4
    //2-digit: 9
    int cnt=13;
    //3-digit
    for(int a=1; a<=9; a+=2)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                if(p[100*a+10*b+c]&&p[100*b+10*c+a]&&p[100*c+10*a+b])
                {
                    ++cnt;
                }
            }
        }
    }
    //4-digit
    for(int a=1; a<=9; a+=2)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=1; d<=9; d+=2)
                {
                    if(p[1000*a+100*b+10*c+d]&&p[1000*b+100*c+10*d+a]
                       &&p[1000*c+100*d+10*a+b]&&p[1000*d+100*a+10*b+c])
                    {
                        ++cnt;
                    }
                }
            }
        }
    }
    //5-digit
    for(int a=1; a<=9; a+=2)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=1; d<=9; d+=2)
                {
                    for(int e=1; e<=9; e+=2)
                    {
                        if(p[10000*a+1000*b+100*c+10*d+e]&&p[10000*b+1000*c+100*d+10*e+a]
                           &&p[10000*c+1000*d+100*e+10*a+b]&&p[10000*d+1000*e+100*a+10*b+c]
                           &&p[10000*e+1000*a+100*b+10*c+d])
                        {
                            ++cnt;
                        }
                    }
                }
            }
        }
    }
    //6-digit
    for(int a=1; a<=9; a+=2)
    {
        for(int b=1; b<=9; b+=2)
        {
            for(int c=1; c<=9; c+=2)
            {
                for(int d=1; d<=9; d+=2)
                {
                    for(int e=1; e<=9; e+=2)
                    {
                        for(int f=1; f<=9; f+=2)
                        {
                            if(p[100000*a+10000*b+1000*c+100*d+10*e+f]&&p[100000*b+10000*c+1000*d+100*e+10*f+a]
                               &&p[100000*c+10000*d+1000*e+100*f+10*a+b]&&p[100000*d+10000*e+1000*f+100*a+10*b+c]
                               &&p[100000*e+10000*f+1000*a+100*b+10*c+d]&&p[100000*f+10000*a+1000*b+100*c+10*d+e])
                            {
                                ++cnt;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
