#include <bits/stdc++.h>
using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    if(k>n){
        cout<<" Error! please try again!\n";
    }
    //int s;
    int sum=0;
    int j=0,last=0;
    //int cnt=0;
    int count=0;
    //int arr[200]{0};
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int i=0;;i++){     
        if(count == k ){
            //if(i == k){cnt++;}
            //arr[j]=sum;
            if(last<sum){
                last = sum;
                j=i-k;
            }
            if(i == n)break;
            i = i-k+1;
            sum=0;
            count=0;
        }
        count++;
        //cin>>s;
        sum += arr[i];
        
    }
    cout<<j<<" "<<(j+k-1)<<" "<<last<<endl;
    
}


/*                  solution with nested loop            */

//    int k,n;
//    cin>>k>>n;
//    if(k>n){
//        cout<<" Error! please try again!\n";
//    }
//    int arr[n];
//    for(int i=0;i<n;i++){
//        cin>>arr[i];
//    }
//    int last = 0;
//    int sum=0;
//    int temp1,temp2;
//    for(int i=0;k<=n-i;i++){
//        sum=0;
//        for(int j=i;j<k+i;j++){
//            sum += arr[j];
//        }
//        if(last<sum){
//            last = sum;
//            temp1 =i;
//            temp2=i+k-1;
//        }
//    }
//    cout<<temp1<<" "<<temp2<<" "<<last<<endl;


//====================== second solution  =====================

/*

int k,n;
    cin>>k>>n;
    if(k>n){
        cout<<" Error! please try again!\n";
    }
    int sum=0;
    int j=0,last=0;
    int count=0;
    int arr[n];
    for(int x=0;x<n;x++){
        cin>>arr[x];
    }
    for(int i=0;;i++){     
        if(count == k ){
            if(last<sum){
                last = sum;
                j=i-k;
            }
            if(i == n)break;
            i = i-k+1;
            sum=0;
            count=0;
        }
        count++;
        sum += arr[i];   
    }
    cout<<j<<" "<<(j+k-1)<<" "<<last<<endl;

*/