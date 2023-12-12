#include <bits/stdc++.h>
using namespace std;

pair<int,int> trv(auto v, auto& grid, auto& vis) {

    vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
    map<int, string> mp = {{1, "|7F"}, {0, "-FL"}, {3, "|JL"}, {2, "-7J"}};

    int x = v.first, y = v.second;
    char c = grid[x][y];
    vis[x][y] = 1;

    for (int i=0; i<4; i++) {
        char cNext = grid[x + dir[i][0]][y + dir[i][1]];
        pair<int,int> cNextCoords = {x + dir[i][0], y + dir[i][1]};
        if (vis[cNextCoords.first][cNextCoords.second]) continue;
        bool f = 0;

        if ((c=='S')
        ||  ((c == '|') && ((i==1) || (i==3)))
        ||  ((c == '-') && ((i==0) || (i==2)))
        ||  ((c == 'L') && ((i==1) || (i==2)))
        ||  ((c == 'J') && ((i==0) || (i==1)))
        ||  ((c == '7') && ((i==0) || (i==3)))
        ||  ((c == 'F') && ((i==2) || (i==3)))) {

            for (char cN:mp[i]) if (cNext == cN) f=1;
        }
        if (f) return cNextCoords;
    }
    return {0,0};
}

void part1() {
    int ans = 0;
    string s; getline(cin, s);
    vector<string> grid;
    grid.push_back(string(s.length()+2, '.'));
    grid.push_back('.'+s+'.');
    while (getline(cin, s)) {
        grid.push_back('.'+s+'.');
    }
    grid.push_back(string(s.length()+2, '.'));

    pair<int,int> start;
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j]=='S') {start.first = i; start.second = j; break;} 
        }
    }
    int len = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
    pair<int,int> curr = trv(start, grid, vis);
    while (curr.first || curr.second) {
        len++;
        curr = trv(curr, grid, vis);
    }

    cout<<(len+1)/2<<"\n";
}

void part2() {

    string s; getline(cin, s);
    vector<string> grid;
    grid.push_back(string(s.length()+2, '.'));
    grid.push_back('.'+s+'.');
    while (getline(cin, s)) {
        grid.push_back('.'+s+'.');
    }
    grid.push_back(string(s.length()+2, '.'));

    pair<int,int> start;
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j]=='S') {start.first = i; start.second = j; break;} 
        }
    }
    int len = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size()));
    pair<int,int> curr = trv(start, grid, vis);
    while (curr.first || curr.second) {
        len++;
        curr = trv(curr, grid, vis);
    }

    int ans = 0;
    for (int i=0; i<grid.size(); i++) {
        for (int j=0; j<grid[0].size(); j++) {
            if (vis[i][j]) continue;
            int i1=0, i2=0, i3=0, i4=0;
            // down
            for (int k=i+1; k<grid.size(); k++) 
                if (vis[k][j] && 
                    ((grid[k][j] == '-') || (grid[k][j] == 'F') || (grid[k][j] == 'L'))) {
                    i1++;
                }
            // up
            for (int k=i-1; k>=0; k--) 
                if (vis[k][j] && 
                    ((grid[k][j] == '-') || (grid[k][j] == 'F') || (grid[k][j] == 'L'))) {
                    i2++;
                }
            // right
            for (int k=j+1; k<grid[0].size(); k++) 
                if (vis[i][k] && 
                    ((grid[i][k] == '|') || (grid[i][k] == 'F') || (grid[i][k] == '7'))) {
                    i3++;
                }
            // left
            for (int k=j-1; k>=0; k--) 
                if (vis[i][k] && 
                    ((grid[i][k]== '|') || (grid[i][k] == 'F') || (grid[i][k] == '7'))) {
                    i4++;
                }
            
            // need to account for S being one of the tiles
            if (((i1%2)||(i2%2)) && ((i3%2)||(i4%2))) ans++;
        }
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
