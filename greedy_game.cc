#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int game_level, p1, p2;    
    //full level
    cin>>game_level;

    cin>>p1;
    vector<int> player1;
    int level;
    for(int i=0;i<p1;++i)
    {
        cin>>level;
        player1.push_back(level);
    }

    cin>>p2;
    vector<int> player2;
    for (int i=0;i<p2;++i)
    {
        cin>>level;
        player2.push_back(level);
    }

    // greddy
    player1.insert(player1.end(), player2.begin(), player2.end());//put player2 into player1
    sort(player1.begin(),player1.end());
    player1.erase(unique(player1.begin(),player1.end()), player1.end());
    int c=player1.size();
    if(game_level==c)
    {
        cout<<"I become the guy."<<endl;
    }
    else
    {
        cout<<"Oh, my keyboard!"<<endl;
    }
    
    

}