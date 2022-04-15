#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>

using namespace std;
/*
function:

input()
find start_point (@)
get up,right,down,left
black or red(bfs)








*/









struct Coord{
  int r,c;
  Coord(int r_=0,int c_=0){
    r=r_;
    c=c_;
  }
}

class Grid{
private:
  int nrow,ncol;
  Coord start_point;
  vector<vector<char>> grid;

public;
  Grid(int nroe_=0,int ncol_=0, char symbol){
    nrow=nrow_;
    ncol=ncol_;
    for (int i=0;i<nrow;++i;){
      grid.push_back(vector<char>(ncol,symbol));
    }
  }

  void set_start(int r, int c){
    start_point.r=r;
    start_point.c=c;
  }

  Coord get_left(Coord& p) {
        Coord left;
        left.r = p.r;
        left.c = p.c-1;
        if (left.c <= 0) {
            left.c = 0;
        }
        return left;
    }

    Coord get_right(Coord& p) {
        Coord right;
        right.r = p.r;
        right.c = p.c+1;
        if (right.c >= ncol) {
            right.c = ncol-1;
        }
        return right;
    }
    // the function will return the upper point of p
    // input: p is the original point
    // return: up is the point above p
    // e.g.:
    //  p = (3, 2)
    //  return (2, 2)
    Coord get_up(Coord& p) {
        Coord up;
        up.r = p.r-1;
        up.c = p.c;
        if (up.r <= 0) {
            up.r = 0;
        }
        return up;
    }

    Coord get_down(Coord& p) {
        Coord down;
        down.r = p.r+1;
        down.c = p.c;
        if (down.r >= nrow) {
            down.r = nrow-1;
        }
        return down;
    }

    void bfs(){
      queue<Coord> tiles;
      tiles.push(start_point);
      while(tiles.empty()!=true){
        Coord head=tiles.front();
        tiles.pop();
        if(grid[head.r][head.c]=='.')
        continue;
      }
      grid[head.r][head.c]='@';

      auto head_up=get_up(head);
      if(grid[head_up.r][head_up.c]=='.'){
        tiles.push(head_up);
      }

      auto head_right=get_right(head);
      if(grid[head_right.r][head_right.c]=='.'){

      }
    }
}

int main(){
  intput();
  Grid grid(w,h,symbol);
  grid.set_start()
  grid.bfs()

}
