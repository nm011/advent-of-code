#include <bits/stdc++.h>
using namespace std;

void part1() {
    int ans = 0;
    string s;
    while (cin>>s) {
        string nums;
        for (char c:s) {
            if (c>='1' && c<='9') nums.push_back(c);
        }
        ans += (nums[0]-'0')*10 + (nums.back()-'0');
    }
    cout<<ans<<"\n";
}

void part2() {
    int ans = 0;
    string s;
    vector<string> digits = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    while (cin>>s) {
        for (int pos=0; pos<s.length(); pos++) {
            for (int i=0; i<9; i++) {
                if (digits[i] == s.substr( pos, digits[i].length() ))
                    s.replace(pos, digits[i].length(), to_string(i+1) + digits[i].back());
            }
        }
        string nums;
        for (char c:s) {
            if (c>='1' && c<='9') nums.push_back(c);
        }
        ans += (nums[0]-'0')*10 + (nums.back()-'0');
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
