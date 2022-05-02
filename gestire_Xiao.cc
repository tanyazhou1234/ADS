#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int gesture_to_int(char g) {
    if (g == 'r') return 0;
    if (g == 's') return 1;
    if (g == 'p') return 2;
}

int find_winner(vector<int>& gestures, vector<int>& cnt) {
    for (int i = 0; i < 3; ++i) {
        if(cnt[gestures[i]] == 2) return i;
    }
    return -1;
}

int main() {
    string gesture;
    vector<int> wins(3, 0);
    vector<int> gestures;
    for (int i = 0; i < 3; ++i) {
        cin >> gesture;
        int g = gesture_to_int(gesture[0]);
        wins[(g-1+3)%3] ++;
        gestures.push_back(g);
    }

    string player = "FMS";
    int winner = find_winner(gestures, wins);
    if (winner == -1) {
        cout << "?" << endl;
    } else {
        cout << player[winner] << endl;
    }
}
