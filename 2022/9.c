#include<bits/stdc++.h>
using namespace std;

pair<int, int> equalizer(int a1, int a2, int b1, int b2){
    if(abs(a1-b1)&&abs(a2-b2)){
        if(abs(a1-b1+1)<=1&&abs(a2-b2+1)<=1){return make_pair(-1,-1);}
        if(abs(a1-b1+1)<=1&&abs(a2-b2-1)<=1){return make_pair(-1,1);}
        if(abs(a1-b1-1)<=1&&abs(a2-b2+1)<=1){return make_pair(1,-1);}
        if(abs(a1-b1-1)<=1&&abs(a2-b2-1)<=1){return make_pair(1,1);}
    }
    else{
        if(abs(a1-b1+1)<=1&&abs(a2-b2)<=1){return make_pair(-1,0);}
        if(abs(a1-b1-1)<=1&&abs(a2-b2)<=1){return make_pair(1,0);}
        if(abs(a1-b1)<=1&&abs(a2-b2+1)<=1){return make_pair(0,-1);}
        if(abs(a1-b1)<=1&&abs(a2-b2-1)<=1){return make_pair(0,1);}
    }
    return make_pair(0,0);
}

int main(){
    string line;
    int sum=0;
    bool a[1000][1000]={};
    int h1=500,h2=500,t1=500,t2=500;
    int curr[18]; 
    for(int i=0;i<18;i++){curr[i]=500;}
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        char c; int n;
        c=line[0];
        n=stoi(line.substr(1+line.find(" ")));
        int p,q;
        if(c=='R'){p=1;q=0;}
        if(c=='L'){p=-1;q=0;}
        if(c=='U'){p=0;q=1;}
        if(c=='D'){p=0;q=-1;}
        for(int i=0;i<n;i++){
            //part1
            if(abs(h1+p-t1)>1||abs(h2+q-t2)>1){
                t1=h1; t2=h2;
                cout<<t1<<" "<<t2<<"\n";
                if(!a[t1][t2]){sum++;a[t1][t2]=1;}
            }
            
            //part2
            if(abs(h1+p-curr[0])>1||abs(h2+q-curr[1])>1){
                pair<int,int> k=equalizer(h1+p,h2+q,curr[0],curr[1]);
                curr[0]+=k.first; curr[1]+=k.second;
            }
            for(int j=1;j<9;j++){
                if(abs(curr[2*j-2]-curr[2*j])>1||abs(curr[2*j-1]-curr[2*j+1])>1){
                    pair<int,int> k=equalizer(curr[2*j-2],curr[2*j-1],curr[2*j],curr[2*j+1]);
                    curr[2*j]+=k.first; 
                    curr[2*j+1]+=k.second;
                    if(j==8){if(!a[curr[2*j]][curr[2*j+1]]){sum++; a[curr[2*j]][curr[2*j+1]]=1;}}
                }
            }
            h1+=p; h2+=q;
        }
    }
    myfile.close();
    cout<<sum+1<<"\n";
    return 0;
}