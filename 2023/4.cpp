#include <bits/stdc++.h>
using namespace std;

void part1() {
    int ans=0;
    string s;
    while (getline(cin, s)) {
        map<int, bool> win;
        bool h = 0, name = 1;
        string num;
        int matches = 0;
        int st = 0;
        while (s[st]!=':') st++;
        for (int i=st; i<s.length(); i++) {
            if (isdigit(s[i])) num.push_back(s[i]);
            else {
                if (s[i] == '|') h = 1;
                if (!num.size()) continue;
                if (!h) {win[stoi(num)]=1;}
                else {matches+=win[stoi(num)];}
                num.erase();
            }
        }
        if (num.size()) {matches+=win[stoi(num)]; num.erase();}
        if (matches) ans += (1<<(matches-1));
    }
    cout<<ans<<"\n";
}

void part2() {
    int ans=0;
    string s;
    vector<int> cards;
    vector<int> mat;
    while (getline(cin, s)) {
        map<int, bool> win;
        bool h = 0, name = 1;
        string num;
        int matches = 0;
        int st = 0;
        while (s[st]!=':') st++;
        for (int i=st; i<s.length(); i++) {
            if (isdigit(s[i])) num.push_back(s[i]);
            else {
                if (s[i] == '|') h = 1;
                if (!num.size()) continue;
                if (!h) {win[stoi(num)]=1;}
                else {matches+=win[stoi(num)];}
                num.erase();
            }
        }
        if (num.size()) {matches+=win[stoi(num)]; num.erase();}
        cards.push_back(1); mat.push_back(matches);
    }
    for (int i=0; i<cards.size(); i++) {
        for (int j=1; j<mat[i]+1; j++) {
            cards[i+j] += cards[i];
        }
    }
    for (int i:cards) ans+=i;
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
