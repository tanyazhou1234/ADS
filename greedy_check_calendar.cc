#include<iostream>
#include<vector>
#include<string>

using namespace std;
vector<string> year2week(int start,vector<string> &week){
    vector<string> year;
    
    for(int j=0;j<12;j++){
        //1
        start=(start%7 + 3)%7;
        // cout<<start<<endl;
        year.push_back(week[start]);
        //2
        start=(start%7 + 3)%7;
        year.push_back(week[start]);
        //3
        start=start%7;
        year.push_back(week[start]);
        //4
        start=(start%7+3)%7;
        year.push_back(week[start]);
        //5
        start=(start%7+2)%7;
        year.push_back(week[start]);
        //6
        start=(start%7+3)%7;
        year.push_back(week[start]);
        //7
        start=(start%7+2)%7;
        year.push_back(week[start]);
        //8
        start=(start%7+3)%7;
        year.push_back(week[start]);
        //9
        start=(start%7+3)%7;
        year.push_back(week[start]);
        //10
        start=(start%7+2)%7;
        year.push_back(week[start]);
        //11
        start=(start%7+3)%7;
        year.push_back(week[start]);
        //12
        start=(start%7+2)%7;
        year.push_back(week[start]);
        
    }
    return year;
}

bool jduge(string str1, string str2, int i,vector<vector<string>> &calendar){
    for(int j=0;j<11;j++){
        if(calendar[i][j]==str1 &&calendar[i][j]==str2){
            return true;
        }
    }
    return false;
}


int main(){
    //vector<int> days={31,28,31,30,31,30,31,31,30,31,30,31};
    vector<string> week={"sunday","monday","tuesday","wednesday","thursday","friday","saturday"};
    vector<vector<string>> calendar;

    //暴力枚举所有可能，1~2022
    int start;
    for(int i=0;i<7;i++){
        //if(notleap(i)){
			start=i;
            vector<string> output=year2week(start,week);
            calendar.push_back(output);
        //}
    }

    string str1,str2;
    cin>>str1>>str2;
    bool flag = false;//
    for(int i=0;i<calendar.size() && flag== false;i++){
        for(int j=0;j<10 && flag== false;j++){
            if(calendar[i][j]==str1 && calendar[i][j+1]==str2){
                flag=true;
            }
        }
    }
    if(flag==true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    
}
