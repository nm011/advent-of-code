#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    map<string,int> m={};
    vector<string> v;
    v.push_back("/");
    ifstream myfile("input.txt");
    getline(myfile,line);
    while(getline(myfile,line)){
        if(line[2]=='c'){
            if(line[5]=='.'){
                v.pop_back(); v.pop_back();
            }
            else{
                v.push_back(line.substr(4+line.find(" ")));
                v.push_back("/");
            }
        }
        if(line[0]>48&&line[0]<58){
            int size=stoi(line.substr(0,line.find(" ")));
            string s1;
            for(string s:v){s1.append(s);}
            m[s1]+=size;
            vector<string> w=v;
            while(w.size()!=1){
                w.pop_back(); w.pop_back();
                string s2;
                for(string s:w){s2.append(s);}
                m[s2]+=size;
            }
        }        
    }
    //part1
    int sum=0;
    for(auto [key,value]:m){
        if(value<=100000){sum+=value;}
    }
    cout<<sum<<"\n";

    //part2
    int used=m["/"];
    int minimum=INFINITY;
    for(auto [key,value]:m){
        if(value>=used-40000000){minimum=min(value,minimum);}
    }
    cout<<minimum<<"\n";

}