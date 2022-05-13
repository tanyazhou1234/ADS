#include<iostream>
#include<vector>

using namespace std;

int main(){
    int vertice, edge;
    while(cin>>vertice && vertice!=0){
        cin>>edge;
        vector<vector<int>> graph;
        ReadGraph(graph, vertice, edge);
    }

}