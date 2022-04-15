#include<iostream>
#include<vector>

using namespace std;
struct fridge{
	int No,Weight;
};
void main(){	
	//input
	int t;//test case number
	cin<<t;
	for(int i=0;i<t;i++){
		int n, s;//number of fridges and steel chains
		cin<<n<<s;
		int w;
		vector<vector<fridge>> apart;
		for(int j=1;j<=n;j++){
			fridge room;
			cin<<w;
			room.No=j;
			room.Weight=w;
			apart.push_back(room);
		}
	}
	//output
	vector<int> output;
	for (int i=0;i<t;i++){
		if(s<f){
			output.push_back(-1);
		}
	}
	
	
}