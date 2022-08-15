#include <bits/stdc++.h>
using namespace std;
int fibonacci(int arr[],int n){
   arr[0] =1;
   arr[1] = 1;
   if(n == 0) return 0;
   fibonacci(arr,n-1);
   arr[n+1] = arr[n] + arr[n-1];
   return arr[n];
}

int fibonaccis(int n){
    if(n<=1) return 1;
    return fibonaccis(n-1) + fibonaccis(n-2);
}


int main(){
      
        int arr[7];
       
        cout<<fibonacci(arr,4)<<endl;
        cout<<fibonaccis(6)<<endl;
        return 0;
}
