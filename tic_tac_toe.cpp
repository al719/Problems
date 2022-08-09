#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    char arr[n][n] ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j]='.';
        }
    }
    bool is_x_turn = true;
    int k=n*n;
    int freq_arr_x_row[n] {0};
    int freq_arr_x_col[n] {0};
    int freq_arr_o_row[n] {0};
    int freq_arr_o_col[n] {0};
    int diagonal_left_x = 0;
    int diagonal_right_x = 0;
    int diagonal_left_o = 0;
    int diagonal_right_o = 0;
    while(k--){
        int r,c;
        if(is_x_turn){
            cout<<"Player x turn. Enter empty location (r,c): ";
            cin>>r>>c;
            if(arr[r-1][c-1] == 'x' || arr[r-1][c-1] == 'o') {cout<<"Invalid input Try again!\n";continue;}
            if((r+c) == n+1) diagonal_right_x++;
            arr[--r][--c] = 'x';
            freq_arr_x_row[r]++;
            freq_arr_x_col[c]++;
            if(r == c) diagonal_left_x++;    
            is_x_turn = false;
        }
        else if(!is_x_turn){
            cout<<"Player o turn. Enter empty location (r,c): ";
            cin>>r>>c;
            if(arr[r-1][c-1] == 'x' || arr[r-1][c-1] == 'o') {cout<<"Invalid input Try again!\n";continue;}
            if((r+c) == n+1) diagonal_right_o++;
            arr[--r][--c]= 'o';
            freq_arr_o_row[r]++;
            freq_arr_o_col[c]++;
            if(r == c) diagonal_left_o++;
            is_x_turn = true;
        }
    for (int i = 0; i < n; i++)
        {       
        for (int j=0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        } 
        cout<<endl; 
        }
        if(diagonal_left_x == n || diagonal_right_x == n){cout<<"Player x is winner\n";break;}
        else if(diagonal_left_o == n || diagonal_right_o == n){cout<<"Player o is winner\n";break;}
        for(int x=0;x<n;x++){
            if(freq_arr_x_row[x] == n || freq_arr_x_col[x] == n){
                cout<<"Player x is winner\n";
                return 0;
            }
            else if(freq_arr_o_row[x] == n || freq_arr_o_col[x] == n){
                cout<<"Player o is winner\n";
                return 0;
            } 
        }  
    }
    if(k==-1) cout<<"Two Players are Tie!!"<<endl;
}