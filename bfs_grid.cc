#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Grid {
private:
    vector< vector<char> > grid;
    
    void set(int row, int col) {
        for (int r = 0; r < row; r++) {
            grid.push_back(vector<char>(col, 'x'));
        }
        // vector<char> (size, 'x')
    }
public:
    Grid(int row=3, int col=4, char symbol='*') {
        set(row, col);
        set_symbol(symbol);
    }

    void set_symbol(char s) {
        for (int r = 0; r < grid.size(); ++r) {
            //for (int c = 0; c < grid[r].size(); ++c) {
            //    grid[r][c] = s;
            //}
            fill(grid[r].begin(), grid[r].end(), s);
        }
    }

    void show() {
        std::cout << "hi" << std::endl;
        for (int r = 0; r <grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                cout << grid[r][c] << ' ';
            }
            cout << endl;
        }
    }

};

int main() {
    Grid grid(7);
    //grid.set(4, 4);
    //grid.set_symbol('.');
    grid.show();

    //Grid default_grid(7);
    //default_grid.show();
}
