#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<sstream>
#include<cstring>
#include<map>

using namespace std;

class PQ
{
public:
        map<int,string> msg_priority;//priority at message
        priority_queue<int,vector<int>,greater<int>> WIN;//priority of message(greater)
       
        void put(vector<string> &split_string)
        {
            string msg=split_string[1]+' '+split_string[2];//message
            
            int pri=stoi(split_string[3]);//priority
            WIN.push(pri);
            
            msg_priority.insert(make_pair(pri,msg));
        }
        
        void get()
        {
            string output=msg_priority.at(WIN.top());
            cout<<output<<endl;
            WIN.pop();
        }
        
        int empty()
        {
            if(WIN.empty())
            {
                return 1;
            }
            else 
            {
                return 0;
            }
        }
};

vector<string> split(string win_command)
{
    vector<string> message;
    string s;
    stringstream ss{win_command};
    while(getline(ss,s,' '))
    {
        message.push_back(s);
    }

    return message;

}
int main()
{
    string win_command;
    PQ message_q;//input priotity & message
    int stop=0;
    while(1)
    {
        getline(cin,win_command);
        if(!win_command.compare("GET"))//top
        {
            if(message_q.empty())
            {
                cout<<"EMPTY QUEUE!"<<endl;
                if(stop!=0)// end-of-file
                {
                    break;
                }
            }
            else
            {
                message_q.get();        
            }
        }
        else//intput a message to message_q
        {
            vector<string> split_string=split(win_command);
            message_q.put(split_string);
            stop++; 
        }
    }
    
}
