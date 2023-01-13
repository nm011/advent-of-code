#include<bits/stdc++.h>
using namespace std;

int func(string line){
    for(int i=0;i<line.length();i++){
        set<char> s;
        /*part1
        int k=4;
        */
       
        /*part2
        int k=14;
        */
        for(int j=0;j<k;j++){
            s.insert(line[i+j]);
        }
        if(s.size()==k){cout<<i+k<<"\n"; return 0;}
    }
    return 0;
}

int main(){
    string line;
    int sum=0;
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        func(line);
    }
    myfile.close();
    return 0;
}