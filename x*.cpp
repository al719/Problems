#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int n;
    cin>>n;
     int k=0;
    int m=n-1;
    for(int i=0;i<n;i++){
       
        for(int j=0;j<n;j++){
            if(j == i){cout<<"*";continue;}
            if(j == k) cout<<"*";
            else if(j == m) cout<<"*";
            else cout<<" ";
        }
        k++;
        m--;
        cout<<endl;
    }
}