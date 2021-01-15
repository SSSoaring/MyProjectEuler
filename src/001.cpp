#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int sum=0, max_num;
    scanf("%d",&max_num);
    for(int i=1;i<max_num;++i)
    {
        if (i%3==0||i%5==0)
            sum+=i;
    }
    printf("%d\n",sum);
    return 0;
}
