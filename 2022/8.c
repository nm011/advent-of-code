#include<bits/stdc++.h>
using namespace std;

int main(){
    string line;
    int sum=0;
    int a[99][99];
    int x=0,y=0,i=0;
    ifstream myfile("input.txt");
    while(getline(myfile,line)){
        int j=0;
        for(char c:line){a[i][j]=stoi(&c);j++;}
        i++;
        y=j;
    }
    x=i;
    myfile.close();
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            //part1
            bool n=1,e=1,s=1,w=1;
            for(int l=i-1;l>-1;l--){if(a[l][j]>=a[i][j]){n=0;}}
            for(int l=i+1;l<x;l++){if(a[l][j]>=a[i][j]){s=0;}}
            for(int m=j-1;m>-1;m--){if(a[i][m]>=a[i][j]){w=0;}}
            for(int m=j+1;m<y;m++){if(a[i][m]>=a[i][j]){e=0;}}
            if(n||s||w||e){sum++;}
            
            //part2
            int n=0,e=0,s=0,w=0;
            for(int l=i-1;l>-1;l--){n++;if(a[l][j]<a[i][j]){continue;} else{break;}}
            for(int l=i+1;l<x;l++){s++; if(a[l][j]<a[i][j]){continue;} else{break;}}
            for(int m=j-1;m>-1;m--){e++;if(a[i][m]<a[i][j]){continue;} else{break;}}
            for(int m=j+1;m<y;m++){w++; if(a[i][m]<a[i][j]){continue;} else{break;}}
            sum=max(sum,n*s*e*w);   
        }
    }
    cout<<sum;
    return 0;
}