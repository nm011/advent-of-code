#include<bits/stdc++.h>
using namespace std;

int func(int c){
    if(c==20||c==60||c==100||c==140||c==180||c==220){return c;}
    return 0;
}

void print(int c, int x){
    c=c%40;
    if(c==x||c==x-1||c==x+1){cout<<"#";}
    if(c!=x&&c!=x-1&&c!=x+1){cout<<".";}
    if(c==39){cout<<"\n";}
    
}

int main(){
    string line;
    int sum=0;
    int x=1;
    int cycle=0;
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        if(line[0]=='n'){
            print(cycle,x);
            cycle+=1;
            sum+=func(cycle)*x;
            
        }
        else{
            int n=stoi(line.substr(1+line.find(" ")));
            print(cycle,x);
            cycle+=1; 
            sum+=func(cycle)*x;
            print(cycle,x);
            cycle+=1;
            sum+=func(cycle)*x;
            x+=n;
        }
        
    }
    myfile.close();
    cout<<sum<<"\n";
    return 0;
}