#include <bits/stdc++.h>
using namespace std;

bool is_digit(char c) {
    return (c>='0' && c<='9');
}

void markSymbol(auto& f, int r, int c){
    for (int i=-1; i<2; i++) {
        for (int j=-1; j<2; j++) {
            f[r+i][c+j] = 1;
        }
    }
}

vector<int> findMarkedNumbers(auto& e, auto& f) {
    vector<int> nums; string num; bool add = 0;
    for (int r=1; r<e.size()-1; r++) {
        if (add) nums.push_back(stoi(num));
        num.erase(); add = 0;
        for (int c=1; c<e[0].length()-1; c++) {
            if (is_digit(e[r][c])) {
                num.push_back(e[r][c]);
                if (f[r][c]) add=1;
            }
            else {
                if (add) nums.push_back(stoi(num));
                add=0;
                num.erase();
            }
        }
    }
    return nums;
} 

void part1() {
    vector<string> e;
    string s; cin>>s; 
    string m = string(s.size()+2, '#'); 
    e.push_back(m); e.push_back('#'+s+'#');
    while (cin>>s) e.push_back('#'+s+'#');
    e.push_back(m);
    vector<vector<bool>> f(e.size(), vector<bool>(e[0].size()));
    for (int r=1; r<e.size()-1; r++) {
        for (int c=1; c<e[0].length()-1; c++) {
            if (!is_digit(e[r][c]) && (e[r][c]!='.')) {
                markSymbol(f, r, c);
            }
        }
    }
    vector<int> nums = findMarkedNumbers(e, f);

    int ans=0;
    for (int i:nums) ans+=i;
    cout<<ans<<"\n";
}

void part2() {
    vector<string> e;
    string s; cin>>s; 
    string m = string(s.size()+2, '#'); 
    e.push_back(m); e.push_back('#'+s+'#');
    while (cin>>s) e.push_back('#'+s+'#');
    e.push_back(m);

    int ans = 0;
    for (int r=1; r<e.size()-1; r++) {
        for (int c=1; c<e[0].length()-1; c++) {
            if (e[r][c]=='*') {
                vector<vector<bool>> f(e.size(), vector<bool>(e[0].size()));
                markSymbol(f, r, c);
                vector<int> nums = findMarkedNumbers(e, f);
                if (nums.size() == 2) ans+=nums[0]*nums[1];
            }
        }
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    part1();                         // one at a time
    // part2();
}
