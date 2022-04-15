#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

int main(){
    char col;
    int row;
    pair<char,int> start;
    pair<char,int> end;
    //start
    cin>>col>>row;
    start.first=col;
    start.second=row;
    //end
    cin>>col>>row;
    end.first=col;
    end.second=row;

    pair<int,int> dis;
    dis.first=end.first-start.first;
    dis.second=end.second-start.second;
    string lr,ud;//left,right,up,down
    if (dis.first>=0){
        lr="R";
    }else{
        lr="L";
    }
    if(dis.second>=0){
        ud="U";
    }
    else{
        ud="D";
    }
    vector<string> steps;
    for(int i=0;i<min(abs(dis.first),abs(dis.second));i++){
        steps.push_back(lr+ud);
    }
    for(int i=0;i<abs(abs(dis.first)-abs(dis.second));i++){
        if(abs(dis.first)>abs(dis.second)){
            steps.push_back(lr);
        }else{
            steps.push_back(ud);
        }
    }
    cout<<steps.size()<<endl;
    for(int i=0;i<steps.size();i++){
        cout<<steps[i]<<endl;
    }



}