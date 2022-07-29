#include <iostream>
#include <cmath>
using namespace std;


int main() {
              int n;
              cin>>n;
              int tri=n;
              for (int i = 1, m=1; i <= n; i++,m++)
              {
                for(int j=0;j<i;j++){
                  cout<<" ";
                }
                for(int k=0;k<m;k++){
                  if(k==0)cout<<"*";  
                }
//=====================================================
                
                
               
                cout<<endl;
              }
              
  
	return 0;         
}
/*
int num1,num2,num3,temp=0;
   cin>>num1>>num2>>num3;
    temp = num2;
    num2 = num3;
    num3 = num1;
    num1 = temp;
    cout<<num1<<" "<<num2<<" "<<num3<<endl;

    //        int num;
             // cin>>num;
             // bool is_even = ((num%2)==0);
             // bool is_odd = 1 - is_even;
             // cout<<(is_even * 100 + is_odd * 7)<<endl;
             int total_num;
             cin>>total_num;
             int no_year = total_num/360;
             total_num = total_num - (no_year*360);
             int no_month = total_num/30;
             int remain_days = total_num%30;
             cout<<no_year<<"  "<<no_month<<"  "<<remain_days<<endl;

*/