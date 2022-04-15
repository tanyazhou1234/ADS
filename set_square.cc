#include<iostream>
#include<vector>
#include<stdio.h>
#include <math.h>

using namespace std;

const double pi = 3.14159265358979323846;
const int prime = 10007;
struct Dot {
    double x, y;
    Dot(double xx=0, double yy=0) : x(xx), y(yy) {}
    int hash() {
        int ix = fabs(x + 0.5);
        int iy = fabs(y + 0.5);
        return ix*ix+iy*iy;
    }
    bool operator==(const Dot& other) const {
        return fabs(x-other.x) < 1e-6 && fabs(y-other.y) < 1e-6;
    }
};
class Hash {
    std::vector<std::vector<Dot> > hash;
public:
    Hash() {
        for (int i = 0; i < prime; ++i) {
            std::vector<Dot> tmp;
            hash.push_back(tmp);
        }
    }
    void clear() {
        for (int i = 0; i < prime; ++i) {
            hash[i].clear();
        }
    }
    void insert(Dot& dot) {
        hash[dot.hash()%prime].push_back(dot);
    }
    bool exist(Dot& dot) {
        int idx = dot.hash()%prime;
        for(int i = 0; i < hash[idx].size(); ++i) {
            if(hash[idx][i] == dot) return true;
        }
        // cout << "not found " << dot.x << " " << dot.y << endl;
        return false;
    }
};

Dot find_dot(double x1, double h)
{
	double a;//dot3与x轴的夹角
	Dot dot;
	a=pi/2 - acos(fabs(x1)/h);
	dot.x=h*cos(a);
	dot.y=h*sin(a);
	
	return dot;
	
}

int main()
{
	int num;
	int xx, yy;
	vector<int> count;
	while(scanf("%d",&num))
	{
		if(num==0) break;
		else
		{
			Dot dot;
			int c=0;
			//cout<<"c="<<endl;
			Hash hash;
			vector<Dot> arr;
			for(int i=0;i<num;++i)
			{
				scanf("%d %d",&xx,&yy);
				dot.x=xx;
				dot.y=yy;
				arr.push_back(dot);
				hash.insert(dot);
			}
			
			for(int i=0; i<num; ++i)
			{
				for(int j=0; j<num;++j)
				{
					if(i!=j)
					{
						int x1,y1,x2,y2;
						
						vector<Dot> square_1, square_2;
						
						x1=arr[i].x;
						y1=arr[i].y;
						
						x2=arr[j].x;
						y2=arr[j].y;
						
						double h=sqrt(pow(x1-x2,2) + pow(y1-y2,2));//正方形边长
						
						//一个方向的点
						Dot dot_3;
						dot_3=find_dot(x1,h);
						cout<<"dot_3: "<<dot_3.x<<" "<<dot_3.y<<endl;
						
						
						Dot dot_4;
						dot_4=find_dot(x2,h);
						cout<<"dot_4: "<<dot_4.x<<" "<<dot_4.y<<endl;

						if(hash.exist(dot_3) && hash.exist(dot_4))
							{
								c++;
							}					
			
						//另一个方向的点
						Dot dot_3_opp,dot_4_opp;
						
						dot_3_opp.x=dot_3.x*(-1);
						dot_3_opp.y=dot_3.y*(-1);
						
						dot_4_opp.x=dot_4.x*(-1);
						dot_4_opp.y=dot_4.y*(-1);
						
						if(hash.exist(dot_3_opp) && hash.exist(dot_4_opp))
							{
								c++;
							}					
					}
				}
			}

			
			count.push_back(c);
			
	
			printf("c=%d\n",c);
		}
	}
}
