#include<iostream>
#include<vector>
#include<limits>

using namespace std;
struct CityPrice{
	int city;
	float price;
};

int main(){
	int m, n;

	cin>>m>>n;
	vector<vector<CityPrice>> flights(n+1);
	for(int i=0;i<m;i++){
		int start, end;
		float cost;
		cin>>start>>end>>cost;
		CityPrice go, bk;
		go.city=end;
		go.price=cost;
		
		bk.city=start;
		bk.price=cost;
		
		flights[start].push_back(go);
		flights[end].push_back(bk);
		
	}
	
	vector<vector<float>> best(n+1);
	for(int i=1;i<n+1;i++){
		best[i]=vector<float> (n+1,numeric_limits<float>::infinity());		
	}
	
	for(int i=1;i<n+1;i++){
		for(int j=0;j<flights[i].size();j++){
			int ed=flights[i][j].city;
			float price=flights[i][j].price;
			best[i][ed]=price;
			//cout<<flights[i][j].city<<" "<<flights[i][j].price<<" ";
		}
		//cout<<endl;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<best[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"----------------"<<endl;
	for(int k=1;k<=n;k++){
		cout<<"transfer k"<<"-----"<<endl;
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(j==k || i==j)continue;
				
				float transfer=best[i][k]+best[k][j];
				if(transfer<best[i][j]){
					best[i][j]=transfer;
					//if(i==2 && j==4){
						cout<<i<<" "<<k<<" "<<j<<endl;
					//}
				}
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<best[i][j]<<"\t";
		}
		cout<<endl;
	}
}





