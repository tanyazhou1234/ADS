#include<iostream>
#include<queue>
#include<string>
#include<vector>


using namespace std;

struct PQ
{
    public:
    string msg;
    int value;
    int pri;

    PQ(string msg, int value, int pri)
	:msg(msg),value(value),pri(pri)
	{
	}
};

struct ComparePri
{
    bool operator()(PQ const& p1, PQ const& p2)
    {
        return p1.pri > p2.pri;
    }

};
int main()
{
    priority_queue<PQ,vector<PQ>,ComparePri> win_msg;
    string command{4};//PUT or GET
    //int stop=0;
    while(cin>>command)
    {
        
        if(!command.compare("GET"))
        {
            
            if(win_msg.empty())
            {
                cout<<"EMPTY QUEUE!"<<endl;
        
            }
            else
            {
                PQ output=win_msg.top();
                win_msg.pop();
                cout<<output.msg<<" "<<output.value<<endl;
            }
        }
        else
        {
            string msg_name;
            int msg_value;
            int msg_pri;
            cin>>msg_name>>msg_value>>msg_pri;
            win_msg.push(PQ(msg_name,msg_value,msg_pri));
            //stop++;
            //cout<<"here"<<endl;       
        }
        
    }  
    return 0;
} 


