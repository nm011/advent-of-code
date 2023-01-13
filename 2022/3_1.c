#include<bits/stdc++.h>
using namespace std;

int func(string line){
    set<char> s;
    string line1,line2;
    int a=0;
    line1 = line.substr(0,line.length()/2);
    line2 = line.substr(line.length()/2);
    for(char i:line1){
        s.insert(i);
    }
    for(char i:line2){
        if(s.count(i)==1){
            if(i-96>0){a+=i-96;}
            else{a+=i-38;}
            return a;
        }
    }
    return 0;
}

int main(){
    string line;
    int sum=0;
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        sum+=func(line);
    }
    myfile.close();
    cout<<sum<<"\n";
    return 0;
}