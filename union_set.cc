#include <vector>
#include <iostream>
using namespace std;

class UnionSet {
public:
    vector<int> boss;
    UnionSet(int n) {
        boss.resize(n);
        for (int i = 0; i < n; i++) {
            boss[i] = i;
        }
    }

    int find_big_boss(int person) {
        if (boss[person] == person) {
            return person;
        }
        int direct_boss = boss[person];
        int big_boss = find_big_boss(direct_boss);
        boss[person] = big_boss;
        return big_boss;
    }

    void merge(int a, int b) {
        int a_boss = find_big_boss(a);
        int b_boss = find_big_boss(b);
        boss[a_boss] = b_boss;
    }

    void init(int n) {
        for (int i = 0; i < n; ++i) {
            boss[i] = i;
        }
    }
};

int main() {
    int n, m;
    UnionSet union_set(30005);
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        // read data
        union_set.init(n);
        vector<vector<int> > clubs(m);
        for (int i = 0; i < m; i++) {
            int num_members;
            cin >> num_members;
            while (num_members-->0) {
                int stduent_id;
                cin >> stduent_id;
                clubs[i].push_back(stduent_id);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int k = 1; k < clubs[i].size(); ++k) {
                union_set.merge(clubs[i][0], clubs[i][k]);
            }
        }

        int zero_boss = union_set.find_big_boss(0);
        int num_q = 1;
        for (int i = 1; i < n; i++) {
            if (union_set.find_big_boss(i) == zero_boss) {
                num_q ++;
            }
        }
        cout << num_q << endl;
    }
}