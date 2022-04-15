#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

//judge a test case is queue or stack

int main(){
    int case_num,case_len;
    cin>>case_num;

    while (case_num){
        cin>>case_len; //case length
        int case_ele; //contents of test cases
        vector<int> test_case_1st;
        vector<int> test_case_2nd;
        queue<int> q_case;
        stack<int> s_case;
        //the 1st input case
        while (1) {
            cin>>case_ele;
            q_case.push(case_ele); //make it a queue
            s_case.push(case_ele); //make it a stack
            test_case_1st.push_back(case_ele);
            if (cin.get()=='\n')
            break;
        }
        //the 2nd input case
        while(1){
            cin>>case_ele;
            test_case_2nd.push_back(case_ele);
            if (cin.get()=='\n')
            break;
        }

        vector<int> test_case_queue;
        vector<int> test_case_stack;
        for (int j=0;j<case_len;++j){
          test_case_queue[j]=q_case.front();
          q_case.pop();

          test_case_stack[j]=s_case.top();
          s_case.pop();
        }

        //queue or stack


        case_num=case_num - 1;
    }
}
