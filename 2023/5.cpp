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

void part1() {
    string s;
    vector<ll> seeds;
    while (getline(cin, s)) {
        if (s[5]==':') seeds = getNums(s);
        vector<bool> mapped(seeds.size()); 
        while (getline(cin, s) && s.size()) {
            vector<ll> map = getNums(s);
            for (int i=0; i<seeds.size(); i++) {
                if (mapped[i]) continue;
                if (seeds[i] >= map[1] && seeds[i] < map[1]+map[2]) {
                    seeds[i] = map[0] + seeds[i] - map[1];
                    mapped[i] = 1;
                }
            }
        }
    }
    cout<<*min_element(seeds.begin(), seeds.end());
}

void part2() {
    string s;
    vector<ll> ranges, seeds;
    vector<ll> r;
    while (getline(cin, s)) {
        if (s[5]==':') {
            seeds = getNums(s); 
            for (int i=0; i<seeds.size()/2; i++) seeds[2*i+1]+=seeds[2*i];
        }

        vector<vector<ll>> maps;
        while (getline(cin, s) && s.size()) {
            vector<ll> map = getNums(s);
            maps.push_back(map);
        }
        vector<ll> mappedSeeds;
        for (int i=0; i<seeds.size()/2; i++) {
            ll rl = seeds[2*i], rr = seeds[2*i+1];
            bool mapped = 0;
            for (auto map:maps){
                ll ml = map[1], mr = map[1]+map[2];
                ll fl = max(rl, ml), fr = min(rr, mr);
                if (fl < fr) {
                    mapped = 1;
                    mappedSeeds.push_back(fl - ml + map[0]);
                    mappedSeeds.push_back(fr - ml + map[0]);
                    if (fl > rl) {seeds.push_back(rl); seeds.push_back(fl);} 
                    if (fr < rr) {seeds.push_back(fr); seeds.push_back(rr);} 
                    break;
                }
            }
            if (!mapped) {mappedSeeds.push_back(rl); mappedSeeds.push_back(rr);}
        }
        swap(seeds, mappedSeeds);
    }
    cout<<*min_element(seeds.begin(), seeds.end());
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
