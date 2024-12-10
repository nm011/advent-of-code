#include <bits/stdc++.h>
using namespace std;

void part1() {

    string line;
    map<pair<int,int>, bool> order;

    int ans = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        string num;
        if (line.find('|') != string::npos) {
            getline(ss, num, '|');
            int num1 = stoi(num);
            getline(ss, num);
            int num2 = stoi(num);
            order[{num1, num2}] = 1;
        }
        else {
            vector<int> v;
            while (getline(ss, num, ',')) {
                v.push_back(stoi(num));
            }
            if (v.size() == 0) continue;
            bool f = 1;
            for (int i=1; i<v.size(); i++) {
                for (int j=0; j<i; j++) {
                    f = f & !order[{v[i], v[j]}];
                }
            }
            if (f) {
                ans += v[(v.size())/2];
            }
        }
    }
    cout<<ans<<"\n";
}

void part2() {
    string line;
    map<pair<int,int>, bool> order;

    int ans = 0;

    while (getline(cin, line)) {
        stringstream ss(line);
        string num;
        if (line.find('|') != string::npos) {
            getline(ss, num, '|');
            int num1 = stoi(num);
            getline(ss, num);
            int num2 = stoi(num);
            order[{num1, num2}] = 1;
        }
        else {
            vector<int> v;
            while (getline(ss, num, ',')) {
                v.push_back(stoi(num));
            }
            if (v.size() == 0) continue;
            bool f = 1;
            for (int i=1; i<v.size(); i++) {
                for (int j=0; j<i; j++) {
                    f = f & !order[{v[i], v[j]}];
                }
            }
            if (!f) {
                for (int i:v) {
                    int fwd = 0, bwd = 0;
                    for (int j:v) {
                        if (order[{i, j}]) fwd++;
                        if (order[{j, i}]) bwd++;
                    }
                    if ((fwd <= v.size()/2) && (bwd <= v.size()/2)) {
                        ans += i;
                        break;
                    }
                }
            }
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
