#include<iostream>
#include<vector>

using namespace std;

void show(vector<vector<int>> club){
    for(int i=0;i<club.size();i++){
        for(int j=0;j<club[i].size();j++){
            cout<<club[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> restore(vector<vector<int>> club){
    vector<int> group;
    for(int i=1;i<club.size();i++){
        if(club[i].size()==1){
            group.push_back(i);
        }
    }
    return group;
}

vector<vector<int>> kickout(vector<int> group, vector<vector<int>> club){
    //cout<<"kick out from:"<<endl;
    //show(club);
    
    for(int i=0;i<group.size();i++){
        club[group[i]].clear();
    }
    
    for(int i=0;i<group.size();i++){
        for(int j=1;j<club.size();j++){
            if(!club[j].empty()){
                for(int k=0;k<club[j].size();k++){
                    if(group[i]==club[j][k]){
                        club[j].erase(club[j].begin()+k);
                    }
                }
            }
        }
    }

    return club;
}

bool only(int a , vector<int> b){
    bool judge=true;
    for(int i=0;i<b.size();i++){
        if(a==b[i]){
            judge=false;
            break;
        }
    }
    return judge;     
}

int main(){
    int n, l;//number of students and laces
    cin>>n>>l;
    vector<vector<int>> club(n+1);
    //input
    for(int i=0;i<l;i++){
        int s1, s2;
        cin>>s1>>s2;
        if(only(s2,club[s1])){
            club[s1].push_back(s2);
        }
        if(only(s1,club[s2])){
            club[s2].push_back(s1);
        }
    }

    vector<int> group = restore(club);
    int cnt=0;
    vector<vector<int>>newclub;
    while(!group.empty()){
       
        //cout<<"punish:"<<endl;
        //for(int i=0;i<group.size();i++){
        //    cout<<group[i]<<" ";
        //}
        //cout<<endl;

        cnt++;
        club = kickout(group,club); 
        //cout<<"after kick out:"<<endl;
        //show(club);
        group = restore(club);
    }
   
    cout<<cnt<<endl;
    

}