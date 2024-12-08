#include <bits/stdc++.h>
using namespace std;

void num_xmas(int idx, int& num, int i, int j, int dx, int dy, auto& matrix) {
    string xmas = "XMAS";
    vector<vector<int>> dirs;

    if (dx == -2)
        dirs = {{1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}};
    else 
        dirs = {{dx, dy}};
    if (matrix[i][j] == xmas[idx]) {
        if (idx == 3) num++;
        else {
            for (auto dir:dirs)
                if (i+dir[0] >= 0 && i+dir[0] < matrix[0].size() &&
                    j+dir[1] >= 0 && j+dir[1] < matrix.size())
                    num_xmas(idx + 1, num, i+dir[0], j+dir[1], dir[0], dir[1], matrix);
        }
    }
}

void part1() {

    string line;
    vector<string> matrix;
    while (getline(cin, line)) {
        matrix.push_back(line);
    }

    int ans = 0;
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            int num = 0;
            num_xmas(0, num, i, j, -2, -2, matrix);
            ans += num;
        }
    }
    cout<<ans<<"\n";
}

void part2() {
    string line;
    vector<string> matrix;
    while (getline(cin, line)) {
        matrix.push_back(line);
    }

    vector<vector<int>> pos = {{0,0}, {0,2}, {1,1}, {2,0}, {2,2}};
    vector<string> x_mas = {"MSAMS", "MMASS", "SSAMM", "SMASM"};

    int ans = 0;
    for (int i=0; i+2<matrix.size(); i++) {
        for (int j=0; j+2<matrix[0].size(); j++) {
            bool f1 = 0;
            for (auto xmas:x_mas) {
                bool f2 = 1;
                for (auto posn:pos) {
                    int dx = posn[0], dy = posn[1];
                    f2 = f2 & (matrix[i+dx][j+dy] == xmas[dx + dy + (dx - dy) / 2]);
                }
                f1 = f1 | f2;
            }
            ans += f1;
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
