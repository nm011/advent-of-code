#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> getNums(string s) {
    s = s + '.';
    string num;
    vector<int> nums;
    for (int i=0; i<s.length()+1; i++) {
        if (isdigit(s[i]) || (s[i]=='-')) num.push_back(s[i]);
        else {
            if (!num.size()) continue;
            nums.push_back(stoll(num));
            num.erase();
        }
    }
    return nums;
}

int nextNum(vector<int> nums){
    bool zeros = 1;
    for (int num:nums) if (num) zeros = 0;
    if (zeros) return 0;
    int n = nums.size();
    vector<int> diff;
    for (int i=0; i<n-1; i++) diff.push_back(nums[i+1]-nums[i]);
    return nums[n-1]+nextNum(diff);
}

void part1() {
    ll ans = 0;
    string s;
    while (getline(cin, s)) {
        int next = nextNum(getNums(s));
        ans += next;
    }
    cout<<ans<<"\n";
}

void part2() {
    ll ans = 0;
    string s;
    while (getline(cin, s)) {
        vector<int> nums = getNums(s);
        reverse(nums.begin(), nums.end());
        int next = nextNum(nums);
        ans += next;
    }
    cout<<ans<<"\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    // part1();                         // one at a time
    part2();
}
