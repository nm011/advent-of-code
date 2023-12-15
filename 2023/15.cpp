#include <bits/stdc++.h>
using namespace std;

int hashStep(string step) {
    int val = 0;
    for (char c:step) {
        val += c;
        val = (val*17)%256;
    }
    return val;
} 

void part1() {
    int ans = 0;
    string s;
    getline(cin,s); s=s+',';
    string step;
    for (int i=0; i<s.size()+1; i++) {
        if (s[i] == ',') {ans += hashStep(step); step.erase();}
        else step += s[i];
    }
    ans += hashStep(step); step.erase();

    cout<<ans<<"\n"; 
}

void part2() {
    // map < box, map<label, position*10+focalLength> >
    map<int, map<string, int>> boxMap;
    string s;
    getline(cin,s); s=s+',';
    string step; int sz = 0;
    for (int i=0; i<s.size()+1; i++) {
        if (s[i] == ',') {
            if (isdigit(step[step.size()-1])) {
                string label = step.substr(0,step.size()-2);
                if (boxMap[hashStep(label)][label]) 
                    boxMap[hashStep(label)][label] = 
                        (boxMap[hashStep(label)][label]/10)*10 + step[step.size()-1] - '0';
                else{
                    sz = boxMap[hashStep(label)].size();
                    boxMap[hashStep(label)][label] = 
                        (sz)*10 + step[step.size()-1] - '0';
                }
            }

            else {
                string label = step.substr(0,step.size()-1);
                if (boxMap[hashStep(label)][label])
                    for (auto p:boxMap[hashStep(label)])
                        if (p.second > boxMap[hashStep(label)][label]) boxMap[hashStep(label)][p.first] -= 10;
                    boxMap[hashStep(label)].erase(label);
            }

            step.erase();

        }
        else step += s[i];
    }
    int ans = 0;
    for (auto box:boxMap) {
        for (auto p:box.second) {
            ans += (box.first+1) * (p.second/10) * (p.second%10);
        }
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
