#include <bits/stdc++.h>
using namespace std;

pair< int, pair<map<int,bool>, map<int,bool>> > calc(auto& grid, auto& hMap, auto& vMap, bool inv) {
    int r = grid.size(), c = grid[0].size();
    map<int, bool> newHMap;
    int mirrorsHorizontal = 0;
    for (int i=1; i<grid.size(); i++) {
        if (hMap[i]) continue;
        bool f = 1;
        for (int j=0; j<i; j++) {
            if ((2*i-1) -j < grid.size() ) {
                if (grid[j] != grid[(2*i-1) -j]) {f=0; break;}
            }
        }
        if (f) {mirrorsHorizontal+=i; newHMap[i] = 1;}
    }
    vector<string> gridT(c);
    for (string s:grid) {
        for (int i=0; i<c; i++) gridT[i].push_back(s[i]);
    }
    map<int, bool> newVMap;
    int mirrorsVertical = 0;
    for (int i=1; i<gridT.size(); i++) {
        if (vMap[i]) continue;
        bool f = 1;
        for (int j=0; j<i; j++) {
            if ((2*i-1) -j < gridT.size() ) {
                if (gridT[j] != gridT[(2*i-1) -j]) {f=0; break;}
            }
        }
        if (f) {mirrorsVertical+=i; newVMap[i]=1;}
    }
    int val = mirrorsHorizontal*100 + mirrorsVertical;
    if (inv) val = mirrorsVertical*100 + mirrorsHorizontal;
    return make_pair(val, make_pair(newHMap, newVMap));
}

void part1() {
    int ans = 0;
    string s;
    while(!(s.size())) {
        vector<string> grid;
        while(getline(cin,s) && (s.size())) {
            grid.push_back(s);
        }
        map<int, bool> hMap, vMap;
        ans += calc(grid, hMap, vMap, 0).first;
    }
    cout<<ans<<"\n"; 
}

void part2() {
    int ans = 0;
    string s;
    while(!(s.size())) {
        vector<string> grid;
        while(getline(cin,s) && (s.size())) {
            grid.push_back(s);
        }
        bool cont = 1;
        int r = grid.size(), c = grid[0].size();
        for (int i=1; i<grid.size(); i++) {
            int mistakes = 0;
            int x, y;
            for (int j=0; j<i; j++) {
                if ((2*i-1) -j < grid.size() ) {
                    if (grid[j] != grid[(2*i-1) -j]) {
                        for (int k=0; k<grid[j].size(); k++) 
                            if (grid[j][k] != grid[(2*i-1) -j][k]) 
                                {mistakes++; x=j; y=k;}
                    }
                }
            }

            if (mistakes == 1) {
                map<int, bool> hMap, vMap;
                auto res = calc(grid, hMap, vMap, 0);
                swap(hMap, res.second.first);
                swap(vMap, res.second.second);
                if (grid[x][y] == '.') grid[x][y] = '#';
                else grid[x][y] = '.';
                ans += calc(grid, hMap, vMap, 0).first;
                cont = 0;
                break;
            }
        }
        if (!cont) continue;
        vector<string> gridT(c);
        for (string s:grid) {
            for (int i=0; i<c; i++) gridT[i].push_back(s[i]);
        }
        swap(grid, gridT);
        for (int i=1; i<grid.size(); i++) {
            int mistakes = 0;
            int x, y;
            for (int j=0; j<i; j++) {
                if ((2*i-1) -j < grid.size() ) {
                    if (grid[j] != grid[(2*i-1) -j]) {
                        for (int k=0; k<grid[j].size(); k++) 
                            if (grid[j][k] != grid[(2*i-1) -j][k]) 
                                {mistakes++; x=j; y=k;}
                    }
                }
            }

            if (mistakes == 1) {
                map<int, bool> hMap, vMap;
                auto res = calc(grid, hMap, vMap, 1);
                swap(hMap, res.second.first);
                swap(vMap, res.second.second);
                if (grid[x][y] == '.') grid[x][y] = '#';
                else grid[x][y] = '.';
                ans += calc(grid, hMap, vMap, 1).first;
                cont = 0;
                break;
            }
        }
    }
    cout<<ans<<"\n"; 
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
