#include<bits/stdc++.h>
using namespace std;

int func(string line1,string line2,string line3){
    int a=0;
    set<char> s1,s2;
    for(char i:line1){s1.insert(i);}
    for(char i:line2){if(s1.count(i)){s2.insert(i);}}
    for(char i:line3){if(s2.count(i)){
        if(i-96>0){a+=i-96;}
        else{a+=i-38;}
        return a;
    }}
    return 0;
}

int main(){
    string line;
    int sum=0;
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        string line1,line2;
        getline(myfile,line1);
        getline(myfile,line2);
        sum+=func(line,line1,line2);
    }
    myfile.close();
    cout<<sum<<"\n";
    return 0;
}