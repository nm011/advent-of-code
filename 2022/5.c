#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    
    int y=3, x=3;
    deque<deque<char>> v{
        {'T','Q','V','C','D','S','N'},
        {'V','F','M'},
        {'M','H','N','P','D','W','Q','F'},
        {'F','T','R','Q','D'},
        {'B','V','H','Q','N','M','F','R'},
        {'Q','W','P','N','G','F','C'},
        {'T','C','L','R','F','W'},
        {'S','N','Z','T'},
        {'N','H','Q','R','J','D','S','M'}
    };
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        vector<string> out;
        string s="";
        for(auto x:line){
            if(x==' '){out.push_back(s);s="";}
            else{s=s+x;}
        }
        out.push_back(s);
        int a,b,c;
        a=stoi(out[1]);
        b=stoi(out[3])-1;
        c=stoi(out[5])-1;
        //part1
        for(int i=0;i<a;i++){
            v[c].push_front(v[b].front()); v[b].pop_front();
        }
        
        //part2
        deque<int> arr;
        for(int i=0;i<a;i++){arr.push_front(v[b].front());v[b].pop_front();}
        for(int i:arr){v[c].push_front(i);}
        
    }
    for(int i=0;i<9;i++){cout<<v[i].front();}
}