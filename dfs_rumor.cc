#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void show(vector<pair<int, int>> &cost, vector<vector<pair<int, int>>>  &friends){
    cout<<"cost:"<<endl;
    for(int i=1;i<cost.size();i++){
        cout<<i<<": ("<<cost[i].first<<","<<cost[i].second<<")"<<endl;
    }

    cout<<"frineds pair:"<<endl;
    for(int i=0;i<friends.size();i++){
        cout<<i<<": ";
        for(int j=0;j<friends[i].size();j++){
            cout<<"("<<friends[i][j].first<<","<<friends[i][j].second<<") ";
        }
        cout<<endl;
    }
}

void read_data(vector<pair<int, int>> &cost, vector<vector<pair<int, int>>>  &friends){
    int n, m;//number of charators and pair of friends
    int value;
    //rumor cost for everyone
    cin>>n>>m;
    cost.resize(n+1);
    friends.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>value;
        cost[i]=make_pair(i, value);
        friends[i].push_back(make_pair(i, value));
    }
    //rumors free for friends
    int f1,f2;
    for(int i=0;i<m;i++){
        cin>>f1>>f2;
        friends[f1].push_back(make_pair(f2, 0));
        friends[f2].push_back(make_pair(f1, 0));
    }
}

void dfs(vector<pair<int, int>> &cost,vector<vector<pair<int, int>>> &friends,vector<bool> &vst, int cur){
    if (!vst[cur]){
        return;
    }
    vst[cur]=false;
    for(int i=0;i<friends[cur].size();i++){
        int nxt = friends[cur][i].first;
        dfs(cost, friends, vst, nxt);
    }

}

int main(){
    vector<pair<int, int>> cost;
    vector<vector<pair<int, int>>> friends;
    read_data(cost, friends);

    sort(cost.begin(), cost.end(), [](auto &left, auto &right) {
        return left.second < right.second;
    });
    //cout<<"--------------"<<endl;
    //show(cost, friends);

    vector<bool> vst(cost.size(),true);
    long long int result=0;
    for(int i=1;i<cost.size();i++){
        if(vst[cost[i].first]){
            result+=cost[i].second;
        }
        dfs(cost, friends, vst, cost[i].first);
    }
    cout<<result<<endl;
}