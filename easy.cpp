#include <iostream>
using namespace std;

int main(){
          
          int n;
          cin>>n;
          int i = n-1;
          int m=1;
          while(i>=0){
            int j=0;
            int k=0;
            while (j<i)
            {
                 cout<<" ";
                 j++;
            }
             while (k<m)
            {
                 cout<<"*";
                 k++;
            }
            cout<<endl;
            i--;
            m+=2;
          }
//====================================================
            int x=1;
            m+=1;
            while(x<n){
            int j=0;
            int k=n;
            while (j<x)
            {
                 cout<<" ";
                 j++;
            }
             while (k<m)
            {
                 cout<<"*";
                 k++;
            }
            cout<<endl;
            x++;
            m-=2;
          }


}
/*
int n;
          cin>>n;
          while(n>0){
            int j=0;
            while (j<n)
            {
                 cout<<"*";
                 j++;
            }
            cout<<endl;
            n--;
          }
*/