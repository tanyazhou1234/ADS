#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class UnionSet {
public:
    vector<int> boss;
    UnionSet(int n) {
        boss.resize(n);
        for (int i = 0; i < n; i++) {
            boss[i] = i;
        }
    }

    int find_big_boss(int person) {
        if (boss[person] == person) {
            return person;
        }
        int direct_boss = boss[person];
        int big_boss = find_big_boss(direct_boss);
        boss[person] = big_boss;
        return big_boss;
    }

    void merge(int a, int b) {
        int a_boss = find_big_boss(a);
        int b_boss = find_big_boss(b);
        boss[a_boss] = b_boss;
    }

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            boss[i] = i;
        }
    }
};

bool CompareWeight(vector<int> a, vector<int> b){
    return(a[2]<b[2]);
}
void show(vector<vector<int>> &gragh){
    
    cout<<"**********"<<endl;
    for(int i=0;i<gragh.size();i++){
        cout<<gragh[i][0]<<" "<<gragh[i][1]<<" "<<gragh[i][2]<<endl;
    }
}
int main(){
    int n,m;//number of vertices and edges
    cin>>n>>m;
    vector<vector<int>> gragh(m);
    for(int i=0;i<m;i++){
        int v1, v2, w;//vertice 1, vertice 2, weight
        cin>>v1>>v2>>w;
        gragh[i].push_back(v1);
        gragh[i].push_back(v2);
        gragh[i].push_back(w);
    }
    vector<vector<int>> sort_gragh=gragh;
    sort(sort_gragh.begin(), sort_gragh.end(),CompareWeight);
    
    show(gragh);
    show(sort_gragh);
    
    cout<<"here: "<<endl;
    for(int i=0;i<m;i++){
        //init union set
        UnionSet union_set(200000);
        union_set.init(n);
        set<int> flag;
        vector<int> start=gragh[i];
        union_set.merge(start[0], start[1]);
        flag.insert(start[0]);
        flag.insert(start[1]);
        long long cnt=start[2];
        for(int j=0;j<m;j++){
            if(union_set.find_big_boss(sort_gragh[j][0])==union_set.find_big_boss(sort_gragh[j][1])){
                if(flag.size()==n  ){
                    break;
                }else{
                continue;
                }
            }
            if(i==7){
                cout<<j<<": "<<sort_gragh[j][0]<<" "<<sort_gragh[j][1]<<endl;
            }
            union_set.merge(sort_gragh[j][0], sort_gragh[j][1]);
            flag.insert(sort_gragh[j][0]);
            flag.insert(sort_gragh[j][1]);
            cnt+=sort_gragh[j][2];
        }
       // cout<<cnt<<endl;
    }
    

    
    
}