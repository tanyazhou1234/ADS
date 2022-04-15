#include<iostream>
#include<vector>
#include<string>
using namespace std;

int dfs(int cur,int n, int d, string &a, int &count, string &label)
{
	if(cur==n-1)
	{
	    return 1;
	}

    //cout<<"here:0"<<endl;
    int next_cur=cur+d;
    if(next_cur>=n)
    {
        next_cur=n-1;
    }
    for(int i=next_cur;i>cur;--i)
    {
		if (label[i]!='X')
		{
			if(a[i]=='1')
            {
				int sig=dfs(i,n,d,a,count,label);
                if(sig==1)
	                {
	                    ++count;
	                    return 1;
	                }
                else
	                {
	                    label[i]='X';
	                }
            }
		}
    }
    return -1;
}

int main()
{
    int n,d;
	cin>>n>>d;
	int ii;
	int count=0;

	string a;
	cin>>a;
	string label;
	int sig=dfs(0,n,d,a,count,label);
	if(sig==1)
	{
	    cout<<count<<endl;
	}
	else
	{
	    cout<<sig<<endl;
	}


}
