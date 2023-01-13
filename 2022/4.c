#include<bits/stdc++.h>
using namespace std;

int func(string line){
    string s1,s2;
    s1 = line.substr(0,line.find(","));
    s2 = line.substr(1+line.find(","));
    int a1,a2,b1,b2;
    a1=stoi(s1.substr(0,s1.find("-")));
    a2=stoi(s1.substr(1+s1.find("-")));
    b1=stoi(s2.substr(0,s2.find("-")));
    b2=stoi(s2.substr(1+s2.find("-")));
    // part1
    if((a1>=b1&&a2<=b2)||(a1<=b1&&a2>=b2)){return 1;}
    else{return 0;}
    
    // part2
    if((a1>=b1&&a1<=b2)||(a2>=b1&&a2<=b2)||(a1>b1&&a2<b2)||(a1<b1&&a2>b2)){return 1;}
    else{return 0;}
    
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