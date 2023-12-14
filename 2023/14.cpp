#include <bits/stdc++.h>
using namespace std;

void spin(vector<string>& grid) {
    // north
    for (int j=0; j<grid[0].size(); j++) {
        int curr = 0;
        for (int i=0; i<grid.size(); i++) {
            if (grid[i][j] == 'O') {
                grid[curr][j] = 'O'; 
                if (curr - i) grid[i][j] = '.'; 
                curr++;
            }
            else if (grid[i][j] == '#') curr = (i+1);
        }
    }
    // west
    for (int i=0; i<grid.size(); i++) {
        int curr = 0;
        for (int j=0; j<grid[0].size(); j++) {
            if (grid[i][j] == 'O') {
                grid[i][curr] = 'O'; 
                if (curr - j) grid[i][j] = '.'; 
                curr++;
            }
            else if (grid[i][j] == '#') curr = (j+1);
        }
    }
    // south
    for (int j=0; j<grid[0].size(); j++) {
        int curr = grid.size()-1;
        for (int i=grid.size()-1; i>=0; i--) {
            if (grid[i][j] == 'O') {
                grid[curr][j] = 'O'; 
                if (curr - i) grid[i][j] = '.'; 
                curr--;
            }
            else if (grid[i][j] == '#') curr = (i-1);
        }
    }
    // east
    for (int i=0; i<grid.size(); i++) {
        int curr = grid[0].size()-1;
        for (int j=grid[0].size()-1; j>=0; j--) {
            if (grid[i][j] == 'O') {
                grid[i][curr] = 'O'; 
                if (curr - j) grid[i][j] = '.'; 
                curr--;
            }
            else if (grid[i][j] == '#') curr = (j-1);
        }
    }
}

void part1() {
    int ans = 0;
    string s;
    vector<string> grid;
    while(getline(cin,s)) {
        grid.push_back(s);
    }
    for (int j=0; j<s.size(); j++) {
        int curr = 0;
        for (int i=0; i<grid.size(); i++) {
            if (grid[i][j] == 'O') {ans+= (grid.size() - curr); curr++; }
            else if (grid[i][j] == '#') curr = (i+1);
        }
    }
    cout<<ans<<"\n"; 
}

void part2() {
    int cycles = 1000000000;
    string s;
    vector<string> grid;
    while(getline(cin,s)) {
        grid.push_back(s);
    }

    map<vector<string>, int> mp;  
    mp[grid] = 0;
    spin(grid);
    int  i=1;
    while (!mp[grid]){
        mp[grid] = i;
        i++;
        spin(grid);
    }

    int spins = (cycles - i) % (mp[grid] - i);
    for (int j=0; j<spins; j++) spin(grid);

    int ans = 0;
    for (int j=0; j<s.size(); j++) {
        for (int i=0; i<grid.size(); i++) {
            if (grid[i][j] == 'O') ans+= (grid.size() - i);
        }
    }
    cout<<ans<<"\n"; 
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
