#include<iostream>
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
