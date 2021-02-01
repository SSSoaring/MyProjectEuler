#include <iostream>

using namespace std;

int main()
{
    int a[5],out[5],equal_sum,local_min_out,global_max_min_out=0,tmp;
    string result,result_max="";

    bool num[10];
    for(int i=1;i<10;++i) num[i]=0;

    out[0]=10;
    for(a[0]=1;a[0]<10;++a[0])
    {
        num[a[0]]=1;
        for(a[1]=1;a[1]<10;++a[1])
        {
            if(num[a[1]]) continue;
            num[a[1]]=1;
            equal_sum=a[0]+a[1]+out[0];

            for(a[2]=1;a[2]<10;++a[2])
            {
                if(num[a[2]]) continue;
                out[1]=equal_sum-(a[1]+a[2]);
                if(out[1]>9||out[1]<1||num[out[1]]||out[1]==a[2]) continue;
                num[a[2]]=1;
                num[out[1]]=1;

                for(a[3]=1;a[3]<10;++a[3])
                {
                    if(num[a[3]]) continue;
                    out[2]=equal_sum-(a[2]+a[3]);
                    if(out[2]>9||out[2]<1||num[out[2]]||out[2]==a[3]) continue;
                    num[a[3]]=1;
                    num[out[2]]=1;

                    for(a[4]=1;a[4]<10;++a[4])
                    {
                        if(num[a[4]]) continue;
                        out[3]=equal_sum-(a[3]+a[4]);
                        if(out[3]>9||out[3]<1||num[out[3]]||out[3]==a[4]) continue;
                        num[a[4]]=1;
                        num[out[3]]=1;

                        out[4]=equal_sum-(a[4]+a[0]);
                        if(!(out[4]>9||out[4]<1||num[out[4]]))
                        {
                            local_min_out=10;
                            for(int i=0;i<5;++i)
                            {
                                if(out[i]<local_min_out)
                                {
                                    local_min_out=out[i];
                                    tmp=i;
                                }
                            }
                            if(local_min_out>=global_max_min_out)
                            {
                                global_max_min_out=local_min_out;

                                result="";
                                for(int i=tmp;i<tmp+5;++i)
                                {
                                    if(out[i%5]==10) result+="10";
                                    else result+=out[i%5]+'0';
                                    result+=a[i%5]+'0';
                                    result+=a[(i+1)%5]+'0';
                                }
                                if(result>result_max) result_max=result;
                            }
                        }

                        num[a[4]]=0;
                        num[out[3]]=0;
                    }

                    num[a[3]]=0;
                    num[out[2]]=0;
                }
                num[a[2]]=0;
                num[out[1]]=0;
            }
            num[a[1]]=0;
        }
        num[a[0]]=0;
    }
    cout<<result_max;
    return 0;
}
