#include <iostream>

using namespace std;


struct vec
{
    int x;
    int y;
};

bool is_right(const vec &v1,const vec &v2)
{
    if(v1.x==0&&v1.y==0) return false;
    if(v2.x==0&&v2.y==0) return false;
    return (v1.x*v2.x+v1.y*v2.y)==0;
}

int main()
{
    const int N=50;
    vec v1,v2,v3;
    int cnt=N*N,l;

    for(int x1=0;x1<=N;++x1)
    {
        for(int y1=1;y1<=N;++y1)
        {
            v1.x=x1;
            v1.y=y1;
            for(int x2=1;x2<=N;++x2)
            {
                if(x1==0) l=N;
                else l=y1*x2/x1;
                for(int y2=0;y2<=l;++y2)
                {
                    v2.x=x2;
                    v2.y=y2;

                    v3.x=x1-x2;
                    v3.y=y1-y2;

                    cnt+=is_right(v1,v3);
                    cnt+=is_right(v2,v3);
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
