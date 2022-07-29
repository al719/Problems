#include <bits/stdc++.h>
using namespace std;

int main(){
    	int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
//        int k=0;
//        int max=arr[0];
//        for (int j = 1; j < n; j++)
//        {
//            if(arr[j]>max)
//            {
//                max=arr[j];
//                k=j;
//            }
//        }
//        cout<<max<<" ";
//        arr[k] =0;
//        max = arr[0];
//        for (int j = 1; j < n; j++)
//        {
//            if(arr[j]>max)
//            {
//                max=arr[j];
//            }
//        }
//         cout<<max<<" \n";
//============================================================== mostafa saad solution
        int max1,max2;
        if(arr[0]>arr[1]){
            max1=arr[0];
            max2=arr[1];
        }
        else{
            max1=arr[1];
            max2=arr[0];
        }
        for(int i=2;i<n;i++){
            if(max1<arr[i]){
                max2=max1,max1=arr[i];
            }
            else if(max2<arr[i]){
                max2 =arr[i];
            }
        }
        cout<<max1<<" "<<max2<<endl;
    
}