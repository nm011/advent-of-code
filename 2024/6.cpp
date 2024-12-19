#include <bits/stdc++.h>
using namespace std;

void part1() {
    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int x = grid[0].size();
    int y = grid.size();
    vector<vector<bool>> vis(y, vector<bool>(x)); 
    int sx, sy;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (grid[j][i] == '^') {
                sx = i; sy = j;
            }
        }
    }
    int ans = 0;
    char sym = '^';
    map<char, vector<int>> dir = {
        {'^', {0, -1}}, 
        {'>', {1, 0}}, 
        {'v', {0, 1}}, 
        {'<', {-1, 0}}
    };
    map<char, char> right_rotate = {
        {'^', '>'},
        {'>', 'v'},
        {'v', '<'},
        {'<', '^'}
    };
    while (true) {
        if (!vis[sy][sx]) {
            vis[sy][sx] = 1;
            ans++;
        }
        sx += dir[sym][0];
        sy += dir[sym][1];
        if (sx >= x || sx < 0 || sy >= y || sy < 0) {
            break;
        }
        else if (grid[sy][sx] == '#') {
            sx -= dir[sym][0];
            sy -= dir[sym][1];
            sym = right_rotate[sym];
        }
        else {
            continue;
        }
    }

    cout<<ans<<"\n";
}

void part2() {
    string line;
    vector<string> grid;
    while (getline(cin, line)) {
        grid.push_back(line);
    }
    int x = grid[0].size();
    int y = grid.size();
    vector<vector<bool>> vis(y, vector<bool>(x)); 
    int sx, sy;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (grid[j][i] == '^') {
                sx = i; sy = j;
            }
        }
    }
    int ans = 0;
    char sym = '^';
    map<char, vector<int>> dir = {
        {'^', {0, -1}}, 
        {'>', {1, 0}}, 
        {'v', {0, 1}}, 
        {'<', {-1, 0}}
    };
    map<char, char> right_rotate = {
        {'^', '>'},
        {'>', 'v'},
        {'v', '<'},
        {'<', '^'}
    };

    int SX = sx, SY = sy;

    vector<vector<bool>> obs(y, vector<bool>(x)); 
    map<vector<int>, vector<char>> prv;
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            // cout<<i<<" "<<j<<"\n";
            if ((i == SX && j == SY) || grid[j][i] == '#') continue;
            
            grid[j][i] = '#';
            sym = '^';
            vis = vector<vector<bool>>(y, vector<bool>(x, false));
            prv.clear();
            sx = SX; sy = SY;
            while (true) {
                prv[{sy,sx}].push_back(sym);
                vis[sy][sx] = 1;
                sx += dir[sym][0];
                sy += dir[sym][1];

                if (sx >= x || sx < 0 || sy >= y || sy < 0) {
                    break;
                }
                else if (grid[sy][sx] == '#') {
                    sx -= dir[sym][0];
                    sy -= dir[sym][1];
                    sym = right_rotate[sym];
                }
                else {
                    bool f = 0;
                    for (char c:prv[{sy,sx}]) {
                        if (c == sym) f=1;
                    }
                    if (f) {
                        ans++;
                        break;
                    }
                    continue;
                }
            }

            grid[j][i] = '.';
        }
    }

    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    
    // one at a time
    // part1();
    part2();
}
