#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void part1() {
    string s;
    vector<string> grid;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    int rowSize = grid[0].size(), colSize = grid.size();

    vector<int> rowAdd;
    int rAdd = 0;
    for (int c=0; c<rowSize; c++) {
        bool empty = 1;
        for (int r=0; r<colSize; r++) {
            if (grid[r][c] != '.') {empty=0; break;}
        }
        if (empty) {rAdd++;}
        rowAdd.push_back(rAdd);
    }
    vector<int> colAdd;
    int cAdd = 0;
    for (int r=0; r<colSize; r++) {
        bool empty = 1;
        for (int c=0; c<rowSize; c++) {
            if (grid[r][c] != '.') {empty=0; break;}
        }
        if (empty) {cAdd++;}
        colAdd.push_back(cAdd);
    }
    vector<pair<int,int>> map;
    for (int r=0; r<colSize; r++) {
        for (int c=0; c<rowSize; c++) {
            if (grid[r][c]=='#') map.push_back({r+colAdd[r], c+rowAdd[c]});
        }
    }
    int ans = 0;
    for (int i=0; i<map.size(); i++) {
        for (int j=i+1; j<map.size(); j++) {
            ans += (abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second));
        }
    }
    cout<<ans<<"\n";
}

void part2() {
    int expansionFactor = 1000000;
    expansionFactor--;
    string s;
    vector<string> grid;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    int rowSize = grid[0].size(), colSize = grid.size();

    vector<int> rowAdd;
    int rAdd = 0;
    for (int c=0; c<rowSize; c++) {
        bool empty = 1;
        for (int r=0; r<colSize; r++) {
            if (grid[r][c] != '.') {empty=0; break;}
        }
        if (empty) {rAdd+=expansionFactor;}
        rowAdd.push_back(rAdd);
    }
    vector<int> colAdd;
    int cAdd = 0;
    for (int r=0; r<colSize; r++) {
        bool empty = 1;
        for (int c=0; c<rowSize; c++) {
            if (grid[r][c] != '.') {empty=0; break;}
        }
        if (empty) {cAdd+=expansionFactor;}
        colAdd.push_back(cAdd);
    }
    vector<pair<int,int>> map;
    for (int r=0; r<colSize; r++) {
        for (int c=0; c<rowSize; c++) {
            if (grid[r][c]=='#') map.push_back({r+colAdd[r], c+rowAdd[c]});
        }
    }
    ll ans = 0;
    for (int i=0; i<map.size(); i++) {
        for (int j=i+1; j<map.size(); j++) {
            ans += (abs(map[i].first - map[j].first) + abs(map[i].second - map[j].second));
        }
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
