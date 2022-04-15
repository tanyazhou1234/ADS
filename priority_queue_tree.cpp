#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class PQ
{
    public:
	vector<int> arr;
	void push(int n)
	{
		arr.push_back(n);
		
	}
	
	int pop()
	{
		auto addr=max_element(arr.begin(),arr.end());
		int a=*addr;
		arr.erase(addr);
		return a;
	}
	
	void print(int i)
	{
		if(i>=arr.size())
		{
			return;
		}
		cout<<arr[i]<<endl;
		cout<<i<<" "<<"left:";
		print(2*i);
		cout<<i<<" "<<"right:";
		print(2*i+1);
	}
};

int main()
{
	PQ pq;
	pq.push(-1);
	pq.push(10);
	pq.push(30);
	pq.push(20);
	pq.print(1);
	
	cout<<pq.pop()<<endl;
	cout<<pq.pop()<<endl;
	
	
	
}