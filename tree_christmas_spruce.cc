#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dfs(int layer,int leaf,vector<vector<int>> spruce)
{
    if(layer==spruce.size()-1 && leaf>=3)
    {
        cout<<"Yes"<<endl;
        return;
    }
    leaf=spruce[layer].size();
    //cout<<"here: layer= "<<layer<<"leaf= "<<leaf<<endl;
    if(leaf!=0)
    {
        for(int i=0;i<spruce[layer].size();++i)
        {
            //cout<<"%%%% i= "<<i<<endl;
            if (spruce[layer][i]<spruce.size() && spruce[spruce[layer][i]].size()!=0)
                {
                    leaf=leaf-1;
                    //cout<<"////leaf: "<<leaf<<endl;
                    //cout<<"## i= "<<i<<"## leaf= "<<leaf<<endl;
                }
        }
        //cout<<"here leaf: "<<leaf<<endl;
        if(leaf<3)
        {
            cout<<"No"<<endl;
            return;
        }
    }    
    layer++;
    dfs(layer,spruce[layer].size(),spruce);
}

void show(int num, vector<pair<int,int>> all_vertex)
{
    for(int i=0;i<all_vertex.size();++i)
    {
        cout<<all_vertex[i].first<<" "<<all_vertex[i].second<<endl;
    }
}

void show_spruce(int layer, vector<vector<int>> spruce)
{
    for(int i=0;i<layer;++i)
    {
        for(int j=0;j<spruce[i].size();++j)
        {
            cout<<spruce[i][j]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int num;
    cin>>num;
    vector<pair<int,int>> all_vertex;
    
    int vertex;
    int c;
    for (int i=2;i<=num;++i)
    {
        cin>>vertex;
        all_vertex.push_back(make_pair(vertex,i));//layer and value
       
    }
   
    //show(num,all_vertex);
    //cout<<vertex<<endl;
    const auto max_l=max_element(all_vertex.begin(),all_vertex.end());
    auto layer=max_l->first;
    //cout<<"all layer:"<<layer<<endl;
    //make a tree
    vector<vector<int>> spruce(layer+1);//spruce has a size: layer+1

    spruce[0].push_back(1);

    vector<int> same_layer;
    for(int i=0;i<all_vertex.size();++i)
    {
        int a=all_vertex[i].first;
        int b=all_vertex[i].second;
        //cout<<"here i=: "<<i<<",a= "<<a<<",b="<<b<<endl;
        spruce[a].push_back(b);
    }
    //show_spruce(spruce.size(),spruce);
    
    dfs(1,spruce[spruce[0][0]].size(),spruce);

}
