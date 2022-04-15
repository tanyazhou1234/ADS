#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int steps;
    int half;
    if(n%2==0){
        half=n/2;
    }else{
        half=n/2+1;
    }
    if( m > n ){
        steps=-1;
    }else{
        int c;
        if(half%m==0){
            c=half/m;
        }else{
            c=half/m +1;
        }
        //cout<<c<<endl;
        if(c*m <= n){
            steps=c*m;
        }else{
            steps=-1;
        }
    }
    
    cout<<steps<<endl;
}