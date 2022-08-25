#include <bits/stdc++.h>

#include <fstream>
using namespace std;





struct AskFm{
    int menu(){
        int choice = -1;
        while(choice == -1){
        cout<<"\nMenu:\n";
        cout<<"\t\t1: Print Questions To Me.\n";
        cout<<"\t\t2: Print Questions From Me.\n";
        cout<<"\t\t3: Answer Question.\n";
        cout<<"\t\t4: Delete Question.\n";
        cout<<"\t\t5: Ask Question.\n";
        cout<<"\t\t6: List System Users.\n";
        cout<<"\t\t7: Feed.\n";
        cout<<"\t\t8: Logout.\n";
        cout<<"\n\n\t\tEnter number in range 1 - 8: ";
        cin>>choice;
        if(choice > 8 || choice < 1){
            cout<<"\n\t\tInvalid choice please try again\n";
            cout<<"\t\t********************************\n";
            choice = -1;
        }
        }
        return choice;
    }
    void runner(){
        while(1){
            int choice = menu();
           // if(choice == 1)
           // else if(choice == 2)
           // else if(choice == 3)
           // else if(choice == 4)
           // else if(choice == 5)
           // else if(choice == 6)
           // else if(choice == 7)
            if(choice == 8) registeration_process();
            cout<<"\n*************************\n";
        }
    }
    bool signUp(){
        //static int id =1;
        int id = rand()%100 +1;
        string user_name,email;
        string password;
        bool anonymous;
        ofstream fout("users.text",fstream::app);
        if(fout.fail()){
            cout<<"Cant't open this file!!\n";
            return 0;
        }
        cout<<"Enter user name. (No spaces): ";cin>>user_name;
        cout<<"Enter password: ";cin>>password;
        cout<<"Enter name: ";
        string fullname;
        cin.ignore();
        getline(cin,fullname);
        while(1){
        cout<<"Enter Email: ";cin>>email;
        if(email.find('@') == -1) cout<<"Wrong email,please try again\n";
        else break; 
        }
        cout<<"Allow anonymous questions?: (0 or 1) ";cin>>anonymous;
        fout<<id<<","<<user_name<<","<<password<<","<<fullname<<","<<email<<","<<anonymous;//<<"\n";
        fout.close();
        cout<<"\nYour Registeration is completed :)\n";
        return true;
    }
    bool login(string filename){
        string userName,password,valname;
        bool password_correct,name_correct;
        cout<<"Enter user name & password: ";
        cin>>userName>>password;
        ifstream fin(filename);
        if(fin.fail()){
            cout<<"Cant't open this file!!\n";
            return 0;
        }
        while(getline(fin,valname,',')){
            if(userName == valname) {
                password_correct =true;
                name_correct = true;}
            else if(password_correct){
                password_correct =false;
                if(valname == password){
                    cout<<"Login successfuly :)\n";
                    fin.close();
                    return true;
                }
            }
        }
        if(name_correct){
            cout<<"Wrong password!!\n";
            fin.close();
            return false;
        }
        cout<<"you should sign up first!!\n";
        fin.close();
        return false;
    }
    int registeration_choice(){
        int choice = -1;
        while(choice == -1){
            cout<<"Welcome, Join AskFm Community: \n";
            cout<<"1: Login\t\t2:Sign Up\n";
            cout<<"Enter number in range 1 - 2: ";
            cin>>choice;
            if(choice != 1 && choice!=2){
                cout<<"ERROR --> Invalid number Try again!!\n";
                cout<<"\n******************************\n";
                choice =-1;
            }
        }
        return choice;    
    }
    void registeration_process(){
        while(1){
            int choice = registeration_choice();
            if(choice == 1){
                bool x = login("users.text");
                if(x) runner();
                else if(!x) cout<<"Login failed :(\n";}
            else if(choice == 2){   
                bool z =signUp(); 
                if(z) runner();
                else cout<<"\nyour sign up faild Try again\n";
            }
            cout<<"\n*************************\n";
        }
    }
};

int main(){
    AskFm tst ;
    tst.registeration_process();
}

/*
bool login(string filename){
        ifstream fin(filename);
        if(fin.fail()){
            cout<<"Cant't open this file!!\n";
            return 0;
        }
        string valname;
        string userName;
        cout<<"Enter user name & password: ";
        string password;
        cin>>userName>>password;
        bool password_correct;    
        while(getline(fin,valname,',')){
            if(userName == valname){
                password_correct = true;
            }
            else if(password_correct){
                if(password == valname){
            cout<<"\nyour login is completed successfully :)\n";
            fin.close();
            return 1;
                }
                else if(!password_correct && fin.eof()){
                    fin.close();
                    return false;
                }
                password_correct = false;
            }
        }
        //return filescanner(filename,userName,password);
        fin.close();
        //if(!password_correct) 
        //{
        //    cout<<"\ninvalid user\nyou should sign up first!!\n";
        //    return ;
        //}
        return 0; 
        
    }
*/

/*
while(getline(fin,valname)){
            if(valname.find(userName) != -1 && valname.find(password) != -1){
                cout<<"Login successfully :)\n";
                fin.close();
                return true;
            }
            else if(valname.find(password) != -1 && valname.find(userName) == -1){
                    password_correct = true;
                    name_correct = false;
                    continue;
            }
            else if(valname.find(password) == -1 && valname.find(userName) != -1){
                    password_correct = false;
                    name_correct = true;
                    continue;
            }
            else if(valname.find(password) == -1 && valname.find(userName) == -1){
                    password_correct = false;
                    name_correct = false;
                    continue;
            }
        }
        if(!password_correct && !name_correct) {cout<<"you should sign up first";return 0;}
        else if(password_correct && !name_correct) {cout<<"invalid user name"; return 0;}
        else if(!password_correct && name_correct) {cout<<"wrong password";return 0;}
*/