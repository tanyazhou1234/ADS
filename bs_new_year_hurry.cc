#include<iostream>
using namespace std;
void contest(int n, int k, int c)
{
    int left=0;
    int right=n;
    //cout<<right<<endl;
    int mid;
    int time_max;
    time_max=240-k;//maximum time for solving problems
    //cout<<"n="<<right<<" "<<"time_left="<<time_max<<endl;

    while(right>left)
	{
        mid=(right+left)/2;
        //cout<<"mid="<<mid<<endl;
        int time_need=0;
        
        for(int i=0;i<=mid;++i)
		{
            time_need=time_need+5*i;//time needed
        }
        //cout<<"time need:"<<time_need<<endl;
        
        //cout<<"left="<<left<<" right="<<right<<" time_need="<<time_need<<endl;
        if (time_need==time_max)
		{
			c=mid;
			break;
		}
		else if(time_need>time_max)
		{
			right=mid;
		}
		else if (time_need<time_max && right-left>1)
		{
            left=mid;;
			//cout<<"here left="<<left<<endl;
        }
		else
		{
		    int time_right=0;
            for (int i=0;i<=right;++i)
            {
                time_right=time_need+5*i;//time needed
            }
            if(time_right<=time_max)
            {
                c=right;
                break;
            }
            else
            {
                c=mid;
                break;
            }
            
        }

    }
     cout<<c<<endl;
}
int main()
{
    int n,k;
	int c=0;//number of probelms solved
    while(cin>>n>>k)
	{
		contest(n,k,c);
	}


}