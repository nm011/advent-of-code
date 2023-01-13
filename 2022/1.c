#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main () {
  string line;
  vector<int> a;
  int sum=0;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
	    if(line.length()){
	      stringstream ss;
	      ss << line;
	      int i; ss>>i;
	      sum+=i;
	    }
	    else{a.push_back(sum); sum=0;}
    }
    myfile.close();
  }
  a.push_back(sum);
  // part1 
  cout<<*max_element(a.begin(),a.end())<<"\n";
  
  //part2
  sort(a.begin(),a.end());
  int k=size(a);
  cout<<a[k-1]+a[k-2]+a[k-3];
  
  return 0;
}