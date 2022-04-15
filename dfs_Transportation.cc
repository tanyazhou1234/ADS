#include<iostream>
#include<vector>

using namespace std;

int dfs(int cur,int goal,vector<int>& cell)
{
	if(cur==goal-1)
	{
		return 1;
	}
	if(cur>goal)
	{
		return 0;
	}
	for(int i=cur;i<goal;++i)
	{
		cur=cur+cell[i];
		int sig=(cur,goal,cell);
		if(sig==1)
		{
			return 1;
		}
	}
	return 0;
	
}
int main()
{
	int n,goal;
	cin>>n>>goal;
	vector<int> cell;
	while(n)
	{
		int value;
		cin>>value;
		cell.push_back(value);
	}
	for (int i=0;i<n-1;++i)
	{
	    cout<<cell[i];
	}
	cout<<endl;
	
	int sig=dfs(0,goal,cell);
	if(sig==1)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
	
}