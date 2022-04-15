#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Coord
{
    int r,c;
    Coord(int r_=0, int c_=0)
    {
        r=r_;
        c=c_;
    }
};

class Grid
{
private:
    int nrow, mcol;

public:
    Grid(int nrow_=0, int mcol_=0, char symbol='*')
    {

        nrow=nrow_;
        mcol=mcol_;
        for(int i=0;i<nrow;++i)
        {
            grid.push_back(vector<char>(mcol,symbol));
        }
    }
	vector<vector<char>> grid;

    void input(int n,int m)
    {
        grid.clear();
        char value;
        for(int i=0;i<n;++i)
        {
            vector<char> irow;
            for(int j=0;j<m;++j)
            {
                cin>>value;
                irow.push_back(value);
            }
            grid.push_back(irow);
        }
        nrow=n;
        mcol=m;
    }

	bool out_of_box(int r_, int c_)
	{
		if(r_>=nrow || c_>=mcol || r_<0 || c_<0 || grid[r_][c_]==1)
		{
			return true;
		}
		else{
			return false;
		}
	}

	vector<Coord> get_around(int r_, int c_)
	{
		vector<Coord> around;
		for(int i=-1;i<=1;++i)
		{
		    for(int j=-1;j<=1;++j)
		    {
		        if(r_+i>=0 && c_+j>=0 && r_+i<nrow && c_+j<mcol)
		        {
		            around.push_back(Coord(r_+i,c_+j));
		            
		        }
		    }
		}
		
		return around;
	}

    int dfs(int r_, int c_, char value)
    {
        Coord cur;
		cur.r=r_;
		cur.c=c_;
        if(out_of_box(r_,c_))
		{
			return -1;
		}
        if(r_==nrow-1 && c_==mcol-1)
        {
            return 1;
        }

		if(grid[r_][c_]=='0')
		{
			grid[r_][c_]='#';

    		vector<Coord> next_8;
    		//int next_size=next_8.size();
    		//cout<<next_size<<endl;
    		next_8=get_around(cur.r,cur.c);
    		//cout<<next_8.size()<<endl;
    		for(int i=0;i<next_8.size();++i)
    		{
    			int sig=dfs(next_8[i].r, next_8[i].c, grid[r_][c_]);
                if(sig==1)
                {
                    return 1;
                }
    		}
		}

        return -1;

    }


    void show(int n, int m)
    {
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
            {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
};



int main()
{
    int n=2;//row
    int test_case,m;//test case and column
    cin>>test_case;
    Grid game;
    vector<int> label;
    for(int i=0;i<test_case;++i)
    {
        cin>>m;
        game.input(n,m);
        //cout<<"n:"<<n<<" m:"<<m<<endl;
        //cout<<"here is input:"<<endl;
        //game.show(n,m);
        int sig=game.dfs(0,0,'#');
        //cout<<"here is output:"<<sig<<endl;
        
        //game.show(n,m);
        label.push_back(sig);
    
    }
    
    for (int i=0;i<test_case;++i)
    {
        if (label[i]==1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

}
