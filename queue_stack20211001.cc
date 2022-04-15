#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void input(){
    vector<int> test_case_1st;
    vector <int> test_case_2nd;
    int case_length;
    std::cin>>case_length;
    int case_ele;
    //input the first test case 
    for(int i=0; i<case_length; ++i){
        cin>>case_ele;
        test_case_1st.push_back(case_ele);
        //cout<<test_case_1st<<endl;
        //cout<< test_case_1st.top();
    }
    for (const auto&item: test_case_1st){
        cout<<item<<" ";
    }
    cout<<endl;
 
    //input the second test case
     for(int i=0; i<case_length; ++i){
        std::cin>>case_ele;
        test_case_2nd.push_back(case_ele);
    }

    for (const auto&item: test_case_2nd){
        cout<<item<<" ";
    }
    cout<<endl;
}

void make_queue(){
    
}

int main(){
    input();
    make_queue();
    //test_case._make_stack();
    //test_case.queue_or_stack():
}