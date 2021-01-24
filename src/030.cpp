#include <iostream>

using namespace std;

int main()
{
    int power[10];
    for(int i=0;i<10;++i)
    {
        power[i]=i*i*i*i*i;
    }
    int sum=0;
    int num;
    //no 2-digit number
    //no 3-digit
    //4-digit:1000-5555
    for(int a=1;a<=5;++a)
    {
        for(int b=0;b<=5;++b)
        {
            for(int c=0;c<=5;++c)
            {
                for(int d=0;d<=5;++d)
                {
                    num=a*1000+b*100+c*10+d;
                    if(num==power[a]+power[b]+power[c]+power[d])
                    {
                        sum+=num;
                    }
                }
            }
        }
    }
    //5-digit
    for(int a=1;a<=9;++a)
    {
        for(int b=0;b<=9;++b)
        {
            for(int c=0;c<=9;++c)
            {
                for(int d=0;d<=9;++d)
                {
                    for(int e=0;e<=9;++e)
                    {
                        num=a*10000+b*1000+c*100+d*10+e;
                        if(num==power[a]+power[b]+power[c]+power[d]+power[e])
                        {
                            sum+=num;
                        }
                    }
                }
            }
        }
    }
    //6-digit:100000-354294
    for(int a=1;a<=3;++a)
    {
        for(int b=0;b<=9;++b)
        {
            for(int c=0;c<=9;++c)
            {
                for(int d=0;d<=9;++d)
                {
                    for(int e=0;e<=9;++e)
                    {
                        for(int f=0;f<=9;++f)
                        {
                            num=a*100000+b*10000+c*1000+d*100+e*10+f;
                            if(num==power[a]+power[b]+power[c]+power[d]+power[e]+power[f])
                            {
                                sum+=num;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}
