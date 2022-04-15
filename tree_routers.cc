#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void show(vector<pair<int,int>> &bmail_router )
{
	for(int i=0;i<bmail_router.size();++i)
	{
		cout<<bmail_router[i].first<<" "<<bmail_router[i].second<<endl;
	}
}

void dfs(int cur,vector<pair<int,int>> &bmail_router, stack<int> &output)
{
	if(cur==0)
	{
	    output.push(bmail_router[cur].first);
	    //cout<<bmail_router[cur].first<<endl;
	    //cout<<"stack size:"<<output.size()<<endl;
	    while(output.size()!=0)
    	{
    	    cout<<output.top()<<" ";
    	    output.pop();
    	}
		
		return;
	}
	for(int i=cur;i>0;--i)
	{
	    
		int next=bmail_router[cur].second;
		if(next==bmail_router[i-1].first)
		{
		    
		    output.push(bmail_router[cur].first);
			//cout<<bmail_router[cur].first<<" ";
			dfs(i-1,bmail_router,output);
			break;
		}
	}
}

int main()
{
	int n,path;//router number
	cin>>n;
	vector<pair<int,int>> bmail_router;
	bmail_router.push_back(make_pair(1,1));
	for(int i=2;i<=n;++i)
	{
		cin>>path;
		bmail_router.push_back(make_pair(i,path));
	}
	//show(bmail_router);
	
	stack<int> output;
	dfs(n-1,bmail_router,output);
}