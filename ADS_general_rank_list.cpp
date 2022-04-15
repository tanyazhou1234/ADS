#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    //input
    int team_num, find_place;
    cin>>team_num>>find_place;
    int prob, tim;//solved problems, total time
    vector<pair<int,int>> contest;
    for(int i=0;i<team_num;i++){
        cin>>prob>>tim;
        contest.push_back(make_pair(prob,tim));
    }
    //sort
    sort(begin(contest),end(contest),[&](pair<int,int> a, pair<int,int> b){
        if(a.first != b.first){
            return a.first>b.first;//first decreasing
        }else{
            return a.second<b.second;//second increasing
        }

    });
    //cout<<"output:"<<endl;
    //for(int i=0;i<team_num;i++){
    //    cout<<contest[i].first<<" "<<contest[i].second<<endl;;
    //}

    //rank
    pair<int,int> cmp=contest[find_place-1];
    vector<pair<int,int>> same_level;
    //cout<<"find: "<<cmp.first<<", "<<cmp.second<<endl;
    //same_level.push_back(cmp);
    bool flag=true;
    for(int i=0;i<contest.size();i++){
        if(cmp==contest[i]){
            same_level.push_back(contest[i]);
            flag=false;
        }
        if(cmp!=contest[i]&&flag==false){
            break;
        }
    }

    cout<<same_level.size()<<endl;
}