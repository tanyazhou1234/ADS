#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> topology(n+1);
    topology[0].push_back(0);
    int node,edge;
    for(int i=0;i<m;i++){
        cin>>node>>edge;
        topology[node].push_back(edge);
        topology[edge].push_back(node);
    }
    //jduge
    //a, b, c: number of no child, 1 child, more than 1 child
    int a=0;
    int b=0;
    int c=0;
    for(int i=1;i<=n;i++){
        if(topology[i].size()==1){
            a++;
        }else if(topology[i].size()==2){
            b++;
        }else if(topology[i].size()==n-1){
            c++;
        }
    }
    if(a==2&&b==n-2){
        cout<<"bus topology"<<endl;
    }else if(b==n){
        cout<<"ring topology"<<endl;
    }else if(c==1&&a==n-1){
        cout<<"star topology"<<endl;
    }else{
        cout<<"unknown topology"<<endl;
    }
    
}