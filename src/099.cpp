#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
    ifstream file("../data/p099_base_exp.txt");
    string one_line,single_data;
    const int N=1000;
    int pairs[N][2];
    double result[N],max=0,max_line;
    if(file.is_open())
    {
        for(int i=0;i<N;++i)
        {
            getline(file,one_line);
            istringstream _stream(one_line);
            for(int j=0;j<2;++j)
            {
                getline(_stream,single_data,',');
                pairs[i][j]=atoi(single_data.c_str());
            }
        }
    }

    for(int i=0;i<N;++i)
    {
        result[i]=pairs[i][1]*log(pairs[i][0]);
        if(result[i]>max)
        {
            max=result[i];
            max_line=i+1;
        }
    }
    cout<<max_line;
    return 0;
}
