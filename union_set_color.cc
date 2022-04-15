#include<iostream>
#include<vector>
#include<stack>


using namespace std;

struct Set{
    int x,y;
    Set(int x_=0, int y_=0){
        x=x_;
        y=y_;
    }
};

void show_tree(vector<vector<Set>> &tree)
{
    for(int i=0;i<tree.size();++i)
    {
        for(int j=0;j<tree[i].size();++j)
        {
            cout<<tree[i][j].x<<","<<tree[i][j].y<<" ";
        }
        cout<<"*"<<endl;
    }
}

int jduge(Set cur, int color, vector<vector<Set>> &tree)
{
	if(color==tree[cur.x][cur.y].y)
	{
	    //cout<<"Already painted, skip. "<<endl;
		return 0;
    }

    //cout<<"painting."<<endl;
    tree[cur.x][cur.y].y=color;
    return 1; 
}

void painting(stack<Set> paint_list, int color, vector<vector<Set>> &tree)
{
    if(paint_list.empty())
    {
        return;
    }
	Set cur=paint_list.top();
	//cout<<"cur: "<<cur.x<<" "<<cur.y<<endl;
	int k=tree[cur.x][cur.y].x;
	paint_list.pop();
	//cout<<"-----"<<paint_list.empty()<<"---"<<tree[k].empty()<<endl;
	if(tree[k].empty() && paint_list.empty())
	{
	    return;
	}
    for(int j=0;j<tree[k].size();++j)
    {
        tree[k][j].y=color;
        //cout<<"here "<<k<<" "<<j<<"= "<<tree[k][j].x<<endl;
		cur.x=k;
		cur.y=j;
		paint_list.push(cur);
    }
    painting(paint_list, color, tree);
//cout<<"////end"<<endl;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<Set>> tree(n+1);

    Set leaf;
    leaf.x=1;
    leaf.y=0;
    tree[0].push_back(leaf);
    
    int value;
    for(int i=2;i<=n;++i)
    {
        cin>>value;
        leaf.x=i;
        tree[value].push_back(leaf);
    }
    //show_tree(tree);
    //input color
    vector<int> color;
    color.push_back(0);
    int c;
    for(int i=0;i<n;++i)
    {
        cin>>c;
        color.push_back(c);
    }
 
    //calculate steps
    int steps=0;
    for (int i=1;i<color.size();++i)
    {
		Set cur;
		for (int i_=0;i_<tree.size();++i_)
		{
			for(int j_=0;j_<tree[i_].size();++j_)
			{
			        if(i==tree[i_][j_].x)
			        {
			            cur.x=i_;
				        cur.y=j_;
				        break;
				        break;
                    }
				
			}
		}
		stack <Set> paint_list;
        if(jduge(cur,color[i],tree))
        {
           steps++;
		   paint_list.push(cur);
		   //cout<<"steps= "<<steps<<endl;
		   
           painting(paint_list,color[i],tree);
	    }
		
      
       //show_tree(tree);
    }
    cout<<steps<<endl;
    
    
	//cout<<steps<<endl;

}
