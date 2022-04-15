#include<iostream>
#include<algorithm>
#include<vector>

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

struct stops{
    int price;
    int last;
    int next;
};
bool ComparePrice(stops a, stops b){
    return (a.price < b.price);
}
int main(){
    
    while(1){
        int n;//number of total stations
        cin>>n;
        if(n==0){
            break;
        }
        vector<stops> roads;
        for(int i=0;i<n-1;i++){
            char from;
            int st_num;
            cin>>from>>st_num;
            stops each;
            for(int j=0;j<st_num;j++){
                char to;
                int cost;
                cin>>to>>cost;
                each.price=cost;
                each.last=int(from)-65;
                each.next=int(to)-65;
                roads.push_back(each);
            }
        }
        sort(roads.begin(),roads.end(), ComparePrice);
        //init
        UnionSet union_set(100);
        union_set.init(n);

        int min_cost=0;
        for(int i=0;i<roads.size();i++){
            int a=roads[i].last;
            int b=roads[i].next;
            if(union_set.find_big_boss(a)==union_set.find_big_boss(b)){
                continue;
            }else{
                union_set.merge(a,b);
                min_cost+=roads[i].price;
            }
            
        }
        cout<<min_cost<<endl;
    }
}
