#include <bits/stdc++.h>
using namespace std;

void part1() {

    string input, line;
    while (getline(cin, line)) {
        input += line;
    }

    int ans = 0;
    regex pattern(R"(mul\((\d+),(\d+)\))");
    smatch matches;

    auto it = sregex_iterator(input.begin(), input.end(), pattern);
    auto end = sregex_iterator();

    vector<string> combinations;

    while (it != end) {
        int num1 = stoi(it->str(1));
        int num2 = stoi(it->str(2));
        ans += num1*num2;
        ++it;
    }

    cout<<ans<<"\n";
}

void part2() {
    string input, line;
    while (getline(cin, line)) {
        input += line;
    }

    int ans = 0;
    regex pattern(R"(mul\((\d+),(\d+)\)|do\(\)|don't\(\))");
    smatch matches;

    auto it = sregex_iterator(input.begin(), input.end(), pattern);
    auto end = sregex_iterator();

    int mult = 1;

    while (it != end) {

        if (it->str(0) == "do()") {mult = 1; ++it; continue;}
        if (it->str(0) == "don't()") {mult = 0; ++it; continue;}

        int num1 = stoi(it->str(1));
        int num2 = stoi(it->str(2));
        ans += mult*num1*num2;
        ++it;
    }

    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    
    // one at a time
    // part1();
    part2();
}
