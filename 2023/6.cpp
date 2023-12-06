#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> getNums(string s) {
    s = s + '.';
    string num;
    vector<ll> nums;
    for (int i=0; i<s.length()+1; i++) {
        if (isdigit(s[i])) num.push_back(s[i]);
        else {
            if (!num.size()) continue;
            nums.push_back(stoll(num));
            num.erase();
        }
    }
    return nums;
}

vector<ll> getNumsPart2(string s) {
    s = s + '.';
    string num;
    vector<ll> nums;
    for (int i=0; i<s.length()+1; i++) {
        if (isdigit(s[i])) num.push_back(s[i]);
    }
    nums.push_back(stoll(num));
    return nums;
}

void part1() {
    string s;
    vector<ll> time, distance;
    while (getline(cin, s)) {
        if (s[0]=='T') time = getNums(s);
        if (s[0]=='D') distance = getNums(s);
    }
    ll ans = 1;
    for (int i=0; i<time.size(); i++) {
        ll wins = 0;
        for (int j=0; j<time[i]+1; j++) {
            if (j*(time[i]-j) > distance[i]) wins++;
        }
        ans *= wins;
    }
    cout<<ans<<"\n";
}

void part2() {
    string s;
    vector<ll> time, distance;
    while (getline(cin, s)) {
        if (s[0]=='T') time = getNumsPart2(s);
        if (s[0]=='D') distance = getNumsPart2(s);
    }
    ll ans = 1;
    for (int i=0; i<time.size(); i++) {
        ll wins = 0;
        for (int j=0; j<time[i]+1; j++) {
            if (j*(time[i]-j) > distance[i]) wins++;
        }
        ans *= wins;
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    part1();                         // one at a time
    // part2();
}
