#include<iostream>
#include<vector>
#include<string>

using namespace std;
int main(){
	int t;//number of test case
	vector<int> output;//vector of result
	cin>>t;
	for(int i=0;i<t;i++){
	    int n;
		cin>>n;
		char s;
		int a=0;//number of ">"
		int b=0;//number of "<"
		int c=0;//number of "-"
		vector<char> input;
		for(int j=0;j<n;j++){
			cin>>s;
			input.push_back(s);
			if(s=='>'){
				a++;
			}
			if(s=='<'){
				b++;
			}
			if(s=='-'){
				c++;
			}
		}
		
		//judge
		int count=0;
		if( (a+c)==n || (b+c)==n){
			output.push_back(n);
		}
		else{
			for(int i=0;i<n;i++){
				if(i==0){
					if(input[i]=='-' || input[n-1]=='-'){
						count++;
					}
				}
				else if(input[i-1]=='-' || input[i]=='-'){
						count++;
					}
			}
			output.push_back(count);
		}	
	
	}
	for(int i=0;i<t;i++){
		cout<<output[i]<<endl;
	}
}