#include <iostream>

using namespace std;

const int MAX=12000;

int count(int a,int b)
{
    int mid=a+b;
    if(mid>MAX) return 0;
    return count(a,mid)+count(mid,b)+1;
}


int main()
{
    cout << count(3,2) << endl;
    return 0;
}
