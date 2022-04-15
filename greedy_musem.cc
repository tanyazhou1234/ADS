#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int main()
{
    string name;
    cin>>name;

    int step=0;
    char start='a';
    //make a~n to 0~13, make z~o to -1 ~ -12
    for(int i=0;i<name.size();++i)
    {
        if( fabs(name[i]-start) <= (26 - fabs(name[i]-start) ))
        {
            step += fabs(name[i]-start);
            //cout<<step<<endl;
        }
        else
        {
            step += 26 - fabs(name[i]-start);
            //cout<<step<<endl;
        }
        start=name[i];
    }

    cout<<step<<endl;
}
