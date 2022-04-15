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
    vector<vector<char>> grid;
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

    void input(int n,int m)
    {
        char symbol;
        for(int i=0;i<n;++i)
        {
            vector<char> irow;
            for(int j=0;j<m;++j)
            {
                cin>>symbol;
                irow.push_back(symbol);
            }
            grid.push_back(irow);
        }
        nrow=n;
        mcol=m;
    }

    void dfs(int r_, int c_, int n, int m)
    {
        Coord cur;

        if(r_==n-1 && c_==m-1)
        {
            if(n!=1 && m!=1)
            {
                return;
            }
            else
            {
                grid[r_][c_]='B';
                cout<<grid[r_][c_];
                return;
            }
        }


        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cur.r=i;
                cur.c=j;
                if(grid[cur.r][cur.c]!='-')
                {

                    Coord cur_up;
                    if (i-1>=0)
                    {
                        cur_up.r=i-1;
                        cur_up.c=j;
                    }
                    else
                    {
                        cur_up.r=i;
                        cur_up.c=j;
                    }

                    Coord cur_left;
                    if (j-1>=0)
                    {
                        cur_left.r=i;
                        cur_left.c=j-1;
                    }
                    else
                    {
                        cur_left.r=i;
                        cur_left.c=j;
                    }
                    if(grid[cur_up.r][cur_up.c]!='B' && grid[cur_left.r][cur_left.c]!='B')
                    {
                        grid[cur.r][cur.c]='B';
                    }
                    else
                    {
                        grid[cur.r][cur.c]='W';
                    }

                    //dfs(i,j,n,m);
                }
                cout<<grid[i][j];
            }
            cout<<endl;
        }

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
    int n,m;
    vector<string> irow;
    cin>>n>>m;
    Grid grid;
    grid.input(n,m);
    grid.dfs(0,0,n,m);
    //grid.show(n,m);
}
