#include <bits/stdc++.h>
using namespace std;

int main () {

  string line;
  int sum=0;
  ifstream myfile ("input.txt");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    
	    string a,b,s;
	    a=line[0];
	    b=line[2];
	    s=a+b;
      // part1
	    sum+=line[2]-87;
	    if(s=="AX"||s=="BY"||s=="CZ"){sum+=3;}
	    else if(s=="AY"||s=="BZ"||s=="CX"){sum+=6;}
    
    
      // part2
    	sum+=(line[2]-88)*3;
    	if(s=="AX"||s=="BZ"||s=="CY"){sum+=3;}
	    else if(s=="AZ"||s=="BY"||s=="CX"){sum+=2;}
	    else{sum+=1;}
    */
    }
    myfile.close();
  }
  cout<<sum<<"\n";
  return 0;
}