#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
   if(n<500 && n>0 && n!=1){
   for(int i =2;i<n;i++){
       if((n%i)!=0)continue;
       else {
           cout<<"NO\n";
           return 0;    
   }
   }
    cout<<"YES\n";
   }
   else cout<<"NO\n";                         
     }
    