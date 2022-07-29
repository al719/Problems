#include <iostream>
#include <cmath>
using namespace std;

//just using 3-loops only
int main(){
  int count=0;
 for (int a = 1; a <= 200; ++a) {
		for (int b = 1; b <= 200; ++b) {
            int d=1;
			for (int c = 1; c <= 200;) {
				if(d<=200){
					count += (a + b == c + d);
                    d++;
                    continue;
                }
                c++;
                d=1;
			}
		}
	}
  
    cout<<count<<endl;
    
}