#include <bits/stdc++.h>
using namespace std;

void part1() {
    int a, b; cin>>a>>b;
    vector<int> l1, l2;
    while (a && b) {
        l1.push_back(a); l2.push_back(b);
        a = 0; b = 0;
        cin>>a>>b;
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    int ans = 0;
    for (int i=0; i<l1.size(); i++) {
        ans += abs(l1[i] - l2[i]);
    }
    cout<<ans<<"\n";
}

void part2() {
    int a, b; cin>>a>>b;
    vector<int> l1, l2;
    while (a && b) {
        l1.push_back(a); l2.push_back(b);
        a = 0; b = 0;
        cin>>a>>b;
    }
    
    map<int, int> cnt;
    for (int i:l2) cnt[i]++;

    int ans = 0;
    for (int i=0; i<l1.size(); i++) {
        ans += l1[i] * cnt[l1[i]];
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    
    // one at a time
    // part1();
    part2();
}
