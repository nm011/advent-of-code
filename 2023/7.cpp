#include <bits/stdc++.h>
using namespace std;

void part1() {
    string s;
    map<char, int> ranks = {{'A', 13}, {'K', 12}, {'Q', 11}, {'J', 10}, 
                            {'T', 9}, {'9', 8}, {'8', 7}, {'7', 6}, 
                            {'6', 5}, {'5', 4}, {'4', 3}, {'3', 2}, {'2', 1}};  
    map<string, int> bids;
    map<string, int> worths;
    vector<string> hands;
    while (getline(cin, s)) {
        string hand; hand = s.substr(0, 5);
        int bid; bid = stoi(s.substr(6));
        bids[hand] = bid;
        map<char, int> val; int worth = 0;
        for (char c:hand) {
            if (val[c]) {worth+=val[c]; val[c]++;}
            else {worth+=(-5); val[c]=(-4);}
        }
        worths[hand]=worth;
        hands.push_back(hand);
    }

    int ans = 0;
    for (string h:hands) {
        int rank = 1;
        for (string k:hands) {
            if (worths[h] > worths[k]) rank++;
            if (worths[h] == worths[k]) {
                for (int i=0; i<5; i++) {
                    if (ranks[h[i]] > ranks[k[i]]) {rank++; break;}
                    else if (ranks[h[i]] < ranks[k[i]]) break;
                }
            }
        }
        ans += rank*bids[h];
    }
    cout<<ans<<"\n";
}

void part2() {
    string s;
    map<char, int> ranks = {{'A', 13}, {'K', 12}, {'Q', 11}, 
                            {'T', 9}, {'9', 8}, {'8', 7}, {'7', 6}, 
                            {'6', 5}, {'5', 4}, {'4', 3}, {'3', 2}, {'2', 1}, {'J', 0}};  
    map<string, int> bids;
    map<string, int> worths;
    vector<string> hands;
    while (getline(cin, s)) {
        string hand; hand = s.substr(0, 5);
        int bid; bid = stoi(s.substr(6));
        bids[hand] = bid;
        map<char, int> val; int worth = 0;
        int cnt_j = 0, val_j = (-5);
        for (char c:hand) {
            if (c=='J') {cnt_j++; continue;}
            if (val[c]) {worth+=val[c]; val[c]++;}
            else {worth+=(-5); val[c]=(-4);}
            val_j = max(val_j, val[c]);
        }
        for (int i=0; i<cnt_j; i++) {
            worth += val_j; val_j++;
        }
        worths[hand]=worth;
        hands.push_back(hand);
    }

    int ans = 0;
    for (string h:hands) {
        int rank = 1;
        for (string k:hands) {
            if (worths[h] > worths[k]) rank++;
            if (worths[h] == worths[k]) {
                for (int i=0; i<5; i++) {
                    if (ranks[h[i]] > ranks[k[i]]) {rank++; break;}
                    else if (ranks[h[i]] < ranks[k[i]]) break;
                }
            }
        }
        ans += rank*bids[h];
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
