#include <bits/stdc++.h>
using namespace std;

void part1() {
    string line;
    int ans = 0; bool f = 0;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        vector<int> numbers, diffs;
        int number;
        f = 1;
        while (ss >> number) {
            if (numbers.size()) {
                int diff = number - numbers.back();
                if (diffs.size()) {
                    if (diffs.back() * diff <= 0) f = 0;
                }
                diffs.push_back(diff);
                if (abs(diff) > 3) f = 0; 
            }
            numbers.push_back(number);
            if (ss.peek() == ' ') ss.ignore();
        }
        if (f) ans++;
    }
    cout<<ans<<"\n";
}

void part2() {
    string line;
    int ans = 0; bool f = 0;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        vector<int> numbers, diffs;
        int number;
        f = 1;
        while (ss >> number) {
            if (numbers.size()) {
                int diff = number - numbers.back();
                if (diffs.size()) {
                    if (diffs.back() * diff <= 0) f = 0;
                }
                diffs.push_back(diff);
                if (abs(diff) > 3) f = 0; 
            }
            numbers.push_back(number);
            if (ss.peek() == ' ') ss.ignore();
        }


        if (!f) {
            bool g = 1;
            vector<vector<int>> all_numbers;

            for (int i=0; i<numbers.size(); i++) {
                vector<int> new_numbers;
                for (int j=0; j<numbers.size(); j++) {
                    if (j != i) new_numbers.push_back(numbers[j]);
                }
                all_numbers.push_back(new_numbers);
            }    

            for (auto& new_numbers:all_numbers) {
                g = 1;
                vector<int> diffs;
                for (int i=0; i<new_numbers.size()-1; i++) {
                    int diff = new_numbers[i+1] - new_numbers[i];
                    if (diffs.size()) {
                        if (diffs.back() * diff <= 0) g = 0;
                    }
                    diffs.push_back(diff);
                    if (abs(diff) > 3) g = 0; 
                }
                f = f || g;
            }
        }

        if (f) ans++;
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    
    // one at a time
    // part1();
    part2();
}
