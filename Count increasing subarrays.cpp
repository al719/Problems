#include <bits/stdc++.h>
using namespace std;
// just a hint: use count decrease as flag
int main(){
    int n;
    cin>>n;
    int last=INT_MIN;
    int s;
    int count_increase=0,count_decrease=0;
    bool is_decrease=false;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s>last && i>=1){
            count_increase++;
            is_decrease = false;
        }
        else
        { 
            count_decrease++;
            is_decrease =true;
        }
        last =s;
        if(is_decrease == true &&i>=1){
            sum += (count_increase+1)* (count_increase+2)/2;
            count_increase =0;
        }
        else if(i == n-1 && is_decrease == false){
            sum+=(count_increase+1)* (count_increase+2)/2;
        }
    }
    if(count_increase == n-1) cout<<n*(n+1)/2<<endl;
    else if(count_decrease == n) cout<<n<<endl;
    else cout<<sum<<endl;
}