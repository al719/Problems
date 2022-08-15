#include <bits/stdc++.h>
using namespace std;

int menu(){
    cout<<"Enter your choice: \n";
    cout<<"1) Add new patien\n";
    cout<<"2) Print all patients\n";
    cout<<"3) Get Next patient\n";
    cout<<"4) Exit\n";
    int choice;
    cin>>choice;
    if(choice>4 || choice<1){
        cout<<"\nInvalid input,Please Try again!!\n"
        <<"----------------------------------\n";
        choice = menu();}
    return choice;
}

void add_New_Patient(string names[20][5],bool status[20][5],int freq[20],int freq2[20]){
    cout<<"Enter Specialization , name , status: ";
    int specialization;
    string name;
    bool statu;
    cin>>specialization>>name>>statu;
    if(freq[specialization-1]+freq2[specialization-1] == 5){
        cout<<"Sorry we can't add more patients for this specialization\n";
        return;
    }
    if(statu){
        //i do it through testing but actually it can't be happened with this final code
   //     if(names[specialization-1][freq2[specialization-1]] != ""){
   //         cout<<"this slot has already a patient!!"<<endl;
   //         return;
   //     }
   //if(freq2[specialization-1] > 0){
        for(int i=freq2[specialization-1];i>0;i--){
            names[specialization-1][i] = names[specialization-1][i-1];
            status[specialization-1][i] = status[specialization-1][i-1];  
        }
        names[specialization-1][0] = name;//freq2[specialization-1]-i
        status[specialization-1][0] = statu;//freq2[specialization-1]-i
        freq2[specialization-1]++;
        return;
   //}
        //names[specialization-1][freq2[specialization-1]] = name;
        //status[specialization-1][freq2[specialization-1]++] = statu;
    }
    else{
        //i do it through testing but actually it can't be happened with this final code
     //    if(names[specialization-1][4-freq[specialization-1]] != ""){
     //       cout<<"this slot has already a patient!!"<<endl;
     //       return;
     //   }
    for(int i=4-freq[specialization-1];i<=4;i++){
            names[specialization-1][i-1] = names[specialization-1][i];
            status[specialization-1][i-1] = status[specialization-1][i];  
        }
        names[specialization-1][4] = name;//freq2[specialization-1]-i
        status[specialization-1][4] = statu;//freq2[specialization-1]-i
        freq[specialization-1]++;
        return;
     //   names[specialization-1][4-freq[specialization-1]] = name;
     //   status[specialization-1][4-freq[specialization-1]++] = statu;
    }
   // freq[specialization-1]++;
}

void print_patients(string names[20][5],bool status[20][5],int freq[20],int freq2[20]){
    for(int i=0;i<20;i++){
        //if(freq[i] == 0)continue;
    //    if(freq[i] == 0 && freq2[i] == 0){
    //    cout<<"No Patient at the moment.Have rest Dr.\n";
    //    return;
    //}
        if(freq[i] != 0 || freq2[i] != 0){
            cout<<"There are "<<freq[i]+freq2[i]<<" patients in specialization "<<i+1<<endl;
            for(int j=0;j<5;j++){
                if(names[i][j] == "")continue;
                cout<<names[i][j]<<" ";
                if(status[i][j]) cout<<"Urgent\n";
                else cout<<"Regular\n";
            }
        }
    }
}

void get_next_patient(string names[20][5],bool status[20][5],int freq[20],int freq2[20]){
    int specialization;
    cout<<"Enter specialization: ";
    cin>>specialization;
    if(freq[specialization-1] == 0 && freq2[specialization-1] == 0){
        cout<<"No Patient at the moment.Have rest Dr.\n";
        return;
    }
    for(int i=0;i<5;i++){
        if(names[specialization-1][i] == "") continue;
        cout<<names[specialization-1][i]<<" ,Please go with the Dr.\n";
        names[specialization-1][i] = "";
        if(status[specialization-1][i])
            freq2[specialization-1]--;
        else freq[specialization-1]--;
        return;
    }
}

int main(){
    string names[20][5] {""};
    bool status[20][5];
    int freq_Arr[20] {0};
    int freq_Arr2[20] {0};
    while(1){
        int choice = menu();
        if(choice == 1) add_New_Patient(names,status,freq_Arr,freq_Arr2);
        else if(choice == 2) print_patients(names,status,freq_Arr,freq_Arr2);
        else if(choice == 3) get_next_patient(names,status,freq_Arr,freq_Arr2);
        else if(choice == 4)break;
        cout<<"\n----------------------------------\n";
    }
}