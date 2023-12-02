#include <bits/stdc++.h>
using namespace std;

bool is_digit(char c) {
    return (c>='0' && c<='9');
}

void part1() {
    int ans = 0;
    string s;
    map<char, int> limit = {{'r',12}, {'g', 13}, {'b', 14}};
    int k = 0;
    while (getline(cin, s)) {
        k++; ans+=k;
        for (int i=0; i<s.length()-2; i++) {
            if ((s[i+2]=='r' || s[i+2]=='g' || s[i+2]=='b') && is_digit(s[i])) {
                int num = s[i]-'0';
                if (is_digit(s[i-1])) num += 10*(s[i-1]-'0');
                if (num > limit[s[i+2]]) {ans-=k; break;}
            }  
        }
    }
    cout<<ans<<"\n";
}

void part2() {
    int ans = 0;
    string s;
    while (getline(cin, s)) {
        map<char, int> minm = {{'r', 0}, {'g', 0}, {'b', 0}};
        for (int i=0; i<s.length()-2; i++) {
            if ((s[i+2]=='r' || s[i+2]=='g' || s[i+2]=='b') && is_digit(s[i])) {
                int num = s[i]-'0';
                if (is_digit(s[i-1])) num += 10*(s[i-1]-'0');
                minm[s[i+2]] = max(minm[s[i+2]], num);
            }  
        }
        ans += minm['r']*minm['g']*minm['b'];
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    part1();                         // one at a time
    // part2();
}
