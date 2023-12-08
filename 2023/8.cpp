#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void part1() {
    string inst; getline(cin, inst);
    string s;
    map<string, pair<string, string>> map;
    while (getline(cin, s)) {
        if (!s.size()) continue;
        map[s.substr(0,3)] = {s.substr(7,3), s.substr(12,3)};
    }
    int ans = 0;
    string curr = "AAA";
    int i=0;
    while (true) {
        if (curr == "ZZZ") break;
        if (inst[i]=='L') curr = map[curr].first;
        else curr = map[curr].second;
        ans++; i++; i=i%inst.length();
    }
    cout<<ans<<"\n";
}

void part2() {
    string inst; getline(cin, inst);
    string s;
    map<string, pair<string, string>> map;
    vector<string> starts;
    while (getline(cin, s)) {
        if (!s.size()) continue;
        map[s.substr(0,3)] = {s.substr(7,3), s.substr(12,3)};
        if (s[2]=='A') starts.push_back(s.substr(0,3));
    }
    ll ans = 1;
    for (string curr:starts) {
        int i=0; ll path=0;
        while (true) {
            if (curr[2]=='Z') break;
            if (inst[i]=='L') curr = map[curr].first;
            else curr = map[curr].second;
            path++; i++; i=i%inst.length();
        }
        ans = lcm(ans, path);
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
