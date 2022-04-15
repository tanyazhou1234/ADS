#include<iostream>
#include<vector>

using namespace std;

int Dijkstra(vector<vector<pair<int,int>>> &road, int n){
    vector<int> best(n+1,1<<30);
    vector<bool> vis(n+1,false);

    for(int i=0;i<road[n].size();i++){
        pair<int,int> nxt=road[n][i];
        if(best[nxt.first]>nxt.second){
            best[nxt.first]=nxt.second;
        }
    }
    vis[n]=true;

    for(int z=1;z<n;z++){
        pair<int,int> min_value(0,1<<30);
        for(int i=1;i<n;i++){
            if(vis[i]==false && best[i]<min_value.second){
                min_value.first=i;
                min_value.second=best[i];
            }
        }
        if(min_value.first==0){
            break;
        }
        vis[min_value.first]=true;

        for(int i=0;i<road[min_value.first].size();i++){
            pair<int,int> arr = road[min_value.first][i];
            if(best[arr.first]>best[min_value.first]+arr.second){
                best[arr.first] = best[min_value.first]+arr.second;
            }
        }
    }
    return best[1];

}

int main(){
    int t,n;
    cin>>t>>n;
    int a,b,price;
    vector<vector<pair<int,int>>> road(n+1);
    for(int i=0;i<t;i++){
        cin>>a>>b>>price;
        road[a].push_back(make_pair(b,price));
        road[b].push_back(make_pair(a,price));
    }

    int ret=Dijkstra(road,n);
    cout<<ret<<endl;
}