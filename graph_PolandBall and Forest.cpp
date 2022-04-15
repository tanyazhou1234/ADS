#include<iostream>
#include<stack>

using namespace std;
int main(){
    int n,p;
    cin>>n;
    stack<int> ball;
    for(int i=0;i<n;i++){
        cin>>p;
        ball.push(p);       
    }

    int leaf=0;
    int start=ball.top();
    ball.pop();

    while(!ball.empty()){
        int a=ball.top();
        ball.pop();
        if(a<start){
            leaf++;
        }
        int b=ball.top
    }


    for(int i=0;i<ball.size()-1;i++){
        if(ball[i]<ball[i-1]){
            leaf++;
        }
        else if(ball[i+1]==ball[i]){
            i++;
            leaf++;
        }
    }
    int cnt=n-leaf;

    
    cout<<cnt<<endl;
}