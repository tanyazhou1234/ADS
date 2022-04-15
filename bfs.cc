#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include <thread>
using namespace std;
struct Coord {
    int r, c;

    Coord(int r_=0, int c_=0) {
        r = r_;
        c = c_;
    }
};

class Grid {
private:
    int nrow, ncol;
    Coord start_point;
    vector<vector<char>> grid;
    
public:
    Grid(int nrow_=0, int ncol_=0, char symbol='.') {
        nrow = nrow_;
        ncol = ncol_;
        for (int i = 0; i < nrow; ++i) {
            grid.push_back(vector<char>(ncol, symbol));
        }
    }

    void show() {
        for (int r = 0; r < nrow; ++r) {
            for (int c = 0; c < ncol; ++c) {
                std::cout << grid[r][c] << " ";
            }
            std::cout << std::endl;
        }
    }

    void set_start(int r, int c) {
        start_point.r = r; 
        start_point.c = c; 
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
};

int main() {
    Grid grid(15, 15, '.');
    grid.set_start(3, 5); 
    Coord cur(7, 9);
    auto up_point = grid.get_up(cur);
}
