#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int read_data(vector<vector<pair<int, int>>> &tree){
    int n, u, v, w;
    cin>>n;
    tree.resize(n);
    for(int i=0; i<n-1; i++){
        cin>>u>>v>>w;
        tree[u].push_back(make_pair(v,w));
        tree[v].push_back(make_pair(u,w));
    }
    return n;
}

void show(vector<vector<pair<int, int>>> &tree){
    cout<<"####"<<endl;
    for(int i=0;i<tree.size();i++){
        cout<<i<<": ";
        for(int j=0;j<tree[i].size();j++){
            cout<<tree[i][j].first<<"-"<<tree[i][j].second<<" ";
        }
        cout<<endl;
    }
    cout<<"####"<<endl;
}

void show_vst(vector<bool> &vst){
    cout<<"show vst: ";
    for(int i=0;i<vst.size();i++){
        cout<<vst[i]<<" ";
    }
    cout<<endl;
}

void find_max(vector<vector<pair<int, int>>> &tree,vector<bool> &vst,int cur,  int result, int sum){
    cout<<"****** cur: "<<cur<<" result: "<<result<<" sum: "<<sum<<endl;
    if(vst[cur]){
        return;
    }
    vst[cur]=true;
    show_vst(vst);
    for(int i=0;i<tree[cur].size();i++){

        if(vst[tree[cur][i].first]){

            result=max(result,sum);
            cout<<"cur: "<<cur<<" i: "<<i<<" result: "<<result<<" sum: "<<sum<<endl;
            continue;

        }
        find_max(tree,vst,tree[cur][i].first,result,sum+tree[cur][i].second);
    }
    cout<<"------- "<<"cur: "<<cur<<" result: "<<result<<" sum: "<<sum<<endl;
    return;

}



int main(){
    vector<vector<pair<int, int>>> tree;
    int n=read_data(tree);
    int result;
    show(tree);
    vector<bool> vst(n,false);

    //int sum=0;
    find_max(tree,vst,0,0,0);

    cout<<"output: "<<result<<endl;


}