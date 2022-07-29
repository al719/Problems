// We have populated the solutions for the 10 easiest problems for your support.
// Click on the SUBMIT button to make a submission to this problem.

#include <bits/stdc++.h>
using namespace std;

int main(){
int t;
	cin>>t;
	while(t--){
	    int a,b,c,d;
	    int count = 0;
	    cin>>a>>b>>c>>d;
        float sum = a+b+c;
	    if(a<=d && b<=d && c<=d)
        {if(sum<= d) count = 1;
	    else if(sum>d){
            count = ceil(sum/d);
        }}
	   cout<<count<<endl;
	}
	return 0;
}
/*
problem three boxes from codeChef link -->

https://www.codechef.com/submit/THREEBOX?tab=solution


*/
