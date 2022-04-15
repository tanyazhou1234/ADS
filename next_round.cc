#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

int main()
{
  int n,k;
  cin>>n>>k;
//  std::cout << n<<std::endl;

  vector<int> all_score;
  int score;



  while(1){
      cin>>score;
      all_score.push_back(score);
      if (cin.get()=='\n')
      break;
  }


 //sort(all_score.begin(),all_score.end());
 int score_len;
 score_len=all_score.size();

 vector<int> my_score;
 for (int i=0;i<score_len;i++){
     if ( (all_score[i] >= all_score[k-1]) && (all_score[i]>0) )
        my_score.push_back(all_score[i]);
 }

 int len_NextRound;
 len_NextRound=my_score.size();
 std::cout<<len_NextRound<<std::endl;

}
