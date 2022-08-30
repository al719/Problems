#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void split_str( string const &str, const char delim,  vector<string> &out )  
        {  
            // create a stream from the string  
            stringstream s(str);  
              
            string s2;  
            while ( getline (s, s2, delim) )  
            {  
                out.push_back(s2); // store the string in s2  
            }  
}

struct operations{
        string current_user_login_info="";
        map<string,vector<string>> Questions_from;
        map<string,vector<string>> Questions_to;
        vector<string> user_current_info;
        vector<string> backUp_Questions_data;
 

        bool check_anonymous(string id){
            ifstream fin("users.text");
            if(fin.fail()){
                cout<<"Can't open this fail\n";
                return false;
            }
            string checke="";
            //id += ",";
            
            while(!fin.eof()){
                getline(fin,checke);
                vector<string> findId;
                split_str(checke,',',findId);
                if(findId[0] == id){
                    vector<string> out;
                    split_str(checke,',',out);
                    fin.close();
                    if(out.back() == "1") return true;
                    if(out.back() == "0") return false;
                }
                findId.clear();
            }
            fin.close();
            return false;
        }
        void writeToQuestions(){
            ofstream fout("questions.text",fstream::app);
            if(fout.fail()){
                cout<<"can't return data to file!\n";
                return;
            }
            for(auto x:backUp_Questions_data){
                fout<<x<<"\n";
            }
            fout.close();
            backUp_Questions_data.clear();
        }
        void remove_questionData(){
            ofstream fout("questions.text");
            if(fout.fail()){
                cout<<"can't remove data from file\n";
                return;
            }
            fout<<"";
            fout.close();
        }
        // store data before remove it from file!!
        void back_up_file_data(){
            ifstream fin("questions.text");
            if(fin.fail()){
                cout<<"can't back up data questions\n";
                return;
            }
            string s;
            backUp_Questions_data.clear();
            while(!fin.eof()){
                getline(fin,s);
                if(s == "") continue;//need to ignore empty line 
                backUp_Questions_data.push_back(s);
            }
            fin.close();
            //remove_questionData();
        }
        bool this_is_my_question(string qid){
           // back_up_file_data();
            user_current_info.clear();
            split_str(current_user_login_info,',',user_current_info);
            for(auto &x:backUp_Questions_data){
                vector<string> check;
                split_str(x,',',check);
                if((check[0] == qid || check[0].find("."+qid)) && (check[1] == user_current_info.front() || check[1] == "**"+user_current_info.front())){
                    return true;//this is my question 
                }
            }
            return false;
        }
        void delete_children(string qid){
            for(auto it = backUp_Questions_data.begin();it != backUp_Questions_data.end();){
                vector<string> check;
                split_str(*it,',',check);
                if(check[0].find(qid+".") != -1){
                    it = backUp_Questions_data.erase(it);
                }
                else ++it;
            }
        }
        void delete_question(){
            back_up_file_data();
            remove_questionData();
            cout<<"Enter Question id or -1 to cancel: ";
            string qid;
            cin>>qid;
            //To Do check if this is my question or not
            bool a =this_is_my_question(qid);
            if(!a) {
                cout<<"\nERROR: this isn't your question, just you can remove yours\n";
                writeToQuestions();
                return;
            }
            for(auto it = backUp_Questions_data.begin();it != backUp_Questions_data.end();){
            vector<string> check;
            split_str(*it,',',check);
            if(check[0] == qid){ //deleting parent question means delete all its thread questions
                it = backUp_Questions_data.erase(it);
                //To Do delete childrens
                delete_children(qid);
                writeToQuestions();
                return;
            }
            else if(check[0].find("."+qid) != -1){//deleting thread question
                it = backUp_Questions_data.erase(it);
                writeToQuestions();
                return;
            }
            else ++it;
        }
            
        }

        //bug --> check_asked_user_id.back() should be answers like one in print ask to me function
        void justOneQuestion(string &x){
                user_current_info.clear();
                split_str(current_user_login_info,',',user_current_info);
                vector<string> check_asked_user_id;
                //check_asked_user_id.clear();
                split_str(x,',',check_asked_user_id);
               // if(check_asked_user_id[2] == user_current_info.front()){
                       if(check_asked_user_id[0].find('.') == -1) {
                        //print main question!!
                        if(check_asked_user_id[1].find("**") != -1){
                            cout<<"Question id ("<<check_asked_user_id[0]<<") from user id (**)\t";
                            cout<<"Question: "<<check_asked_user_id.back()<<"\n";
                            int i = x.find("&");
                            x= x.substr(0,i);//question ready for new updated !!!!
                            return;
                        }

                        cout<<"Question id ("<<check_asked_user_id[0]<<") from user id ("<<check_asked_user_id[1]<<")\t";
                        cout<<"Question: "<<check_asked_user_id.back()<<"\n";
                        int i = x.find("&");
                        x= x.substr(0,i);//question ready for new updated !!!!
                       }
                        if(check_asked_user_id[0].find('.') != -1){
                            //Print thread Questions!!
                            //string threadGetId;  using ERROR
                            vector<string> dotSplit;
                            split_str(check_asked_user_id[0],'.',dotSplit);
                            if(check_asked_user_id[1].find("**") != -1){
                                   cout<<"Question id ("<<dotSplit[1]<<") from user id (**)\t";
                                   cout<<"Question: "<<check_asked_user_id.back()<<"\n";
                                   //dotSplit.clear();
                                   int i = x.find("&");
                                   x= x.substr(0,i);//question ready for new updated !!!!
                                   return;
                            }
                            cout<<"\tThread: Question Id ("<<dotSplit[1]<<") from user id ("<<check_asked_user_id[1]<<")\t";
                            cout<<"Question: "<<check_asked_user_id.back()<<"\n";
                            //dotSplit.clear();
                            int i = x.find("&");
                            x= x.substr(0,i);//question ready for new updated !!!!
                            return;
                        }
                       
               // }
        }
        void Answer_Question(){
            backUp_Questions_data.clear();
            back_up_file_data();
            remove_questionData();
            string id;
            cout<<"Enter Question id or -1 to cancel: ";
            cin>>id;
            if(id == "-1") return;
            for(auto &x:backUp_Questions_data){
                vector<string> check;
                split_str(x,',',check);
                if(check[0] == id){ //for answer parent question
                    if(check.back().find("&") != -1){
                        justOneQuestion(x);
                        cout<<"\n\nWarning: Already answered. Answer will be updated!!";
                    }
                    string answer;
                    cout<<"Enter answer: ";
                    cin.ignore();
                    getline(cin,answer);
                    x += ("&"+answer);//causing error
                    break;
                }
                else if(check[0].find("."+id) != -1){
                    if(check.back().find("&") != -1){
                        justOneQuestion(x);
                        cout<<"\n\nWarning: Already answered. Answer will be updated!!";
                    }
                    string answer;
                    cout<<"Enter answer: ";
                    cin.ignore();
                    getline(cin,answer);
                    x += ("&"+answer);//causing error
                    break;
                }
            }
            //To Do return data to file !!!
            writeToQuestions();
        }
        void storeQuestions(string qid,bool asked_user_allowed_anonymous,string userID,string askedID,string questionTEXT){
            ofstream fout("questions.text",ios::app);
            if(fout.fail()){
                cout<<"can't open this file\n";
                return;
            }
            if(asked_user_allowed_anonymous){
            int choice;
            cout<<"Do you want to be appeared as asker? (0 - 1):";
            cin>>choice;
            if(choice == 1) fout<<qid<<","<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
            else fout<<qid<<","<<"**"<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
        }
        else{
            fout<<qid<<","<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
        }
            fout.close();
        }
        
        void store_threadQuestion(string parent_id,string qid,bool asked_user_allowed_anonymous,string userID,string askedID,string questionTEXT){
            ofstream fout("questions.text",ios::app);
            if(fout.fail()){
                cout<<"Can't store thread question\n";
                return;
            }
            if(asked_user_allowed_anonymous){
            int choice;
            cout<<"Do you want to be appeared as asker? (0 - 1):";
            cin>>choice;
            if(choice == 1) fout<<parent_id<<"."<<qid<<","<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
            else fout<<parent_id<<"."<<qid<<","<<"**"<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
            }
            else{
                fout<<parent_id<<"."<<qid<<","<<userID<<","<<askedID<<","<<asked_user_allowed_anonymous<<","<<questionTEXT<<"\n";
            }
            fout.close();
        }
        void askParentQuestion(){
            fstream qID("QuestionID.text",ios::in|ios::out|ios::app);
            if(qID.fail()){
                cout<<"Can't generate id questions\n";
                return;
            }
            static int id =1;
            while(!qID.eof()){
            qID>>id;
            }
            qID.clear();
            ostringstream oss;
            oss<<id;//to convert id to string just add oss.str()
            split_str(current_user_login_info,',',user_current_info);
            string user_asked_id;
            cout<<"Enter user id or -1 to cancel: ";
            cin>>user_asked_id;
            if(user_asked_id == "-1") return;
            else if(user_asked_id == user_current_info.front()){
                cout<<"ERROR : you can't ask your self!!\n";
                return;
            }
            // TO DO check if asked id exist or not with func. check_anonymous() 
            bool askedUser_allowed_anonymous = check_anonymous(user_asked_id);
            if(!askedUser_allowed_anonymous){
                cout<<"Note: Anonymous Questions aren't allowed for this user!!\n";
            }
            string threadID="";
            cout<<"For Thread Question: Enter Question ID or -1 for new question: ";
            cin>>threadID;
            string Question_text;
            cout<<"Enter question text: ";
            cin.ignore();
            getline(cin,Question_text);
            if(threadID == "-1")
            //TO DO write question to data base    Done
            {
            storeQuestions(oss.str(),askedUser_allowed_anonymous,user_current_info.front(),user_asked_id,Question_text);
            }
            else{
                store_threadQuestion(threadID,oss.str(),askedUser_allowed_anonymous,user_current_info.front(),user_asked_id,Question_text);
            }
            qID<<++id<<"\n";
            qID.close();
        }
       // bool check_yourQuestion_is_answered(){
       //         ifstream fin("questions.text");
       //         if(fin.fail()){
       //             cout<<"can't check if answered or not!!\n";
       //             return false;
       //         }
       //         string s;
       //         while(!fin.eof()){
       //             getline(fin,s);
       //             vector<string> check;
       //             split_str(s,',',check);
       //             if(check.back().find('&') != -1){
       //                 return true;
       //             }
       //         }
       //         return false;
       // }
        void list_feed(){
            ifstream fin("questions.text");
            if(fin.fail()){
                cout<<"can't ask from me\n";
                return;
            }
            string getQuestion;
            user_current_info.clear();  // i can't detect but this vector cause storage error!!
            split_str(current_user_login_info,',',user_current_info);
            while(!fin.eof()){
                            getline(fin,getQuestion);
                if(getQuestion.find(',') == -1) continue; //causing error
                vector<string> check_asked_user_id;
                check_asked_user_id.clear();
                split_str(getQuestion,',',check_asked_user_id);
                vector <string> answers;
                //if(check_asked_user_id.back().find("&") != -1){
                split_str(check_asked_user_id.back(),'&',answers);
               // }
                if(((check_asked_user_id[1] == "**"+user_current_info.front()) || (check_asked_user_id[1] == user_current_info.front())) ){//|| (((check_asked_user_id[1] == "**"+user_current_info.front()) || (check_asked_user_id[1] == user_current_info.front()))&& check_asked_user_id.back().find('&') != -1)
                        if(check_asked_user_id[0].find('.') != -1){
                            //Print thread Questions!!
                            //string threadGetId;  using ERROR
                            vector<string> dotSplit;

                            split_str(check_asked_user_id[0],'.',dotSplit);
                            if(check_asked_user_id[1].find("**") != -1){
                                   cout<<"\tThread: Question id ("<<dotSplit[1]<<") to user id ("<<check_asked_user_id[2]<<")\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                            }
                            cout<<"\tThread: Question Id ("<<dotSplit[1]<<") from user id "<<check_asked_user_id[1]<<" to user id ("<<check_asked_user_id[2]<<")\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                        }
                        //print main question!!
                        if(check_asked_user_id[1].find("**") != -1){
                            cout<<"Question id ("<<check_asked_user_id[0]<<") to user id ("<<check_asked_user_id[2]<<")\t";
                            //cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                            //cout<<"\tAnswer: "<<answers[1]<<"\n";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            continue;
                        }
                        cout<<"Question id ("<<check_asked_user_id[0]<<") from user id "<<check_asked_user_id[1]<<" to user id ("<<check_asked_user_id[2]<<")\t";
                        if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                        cout<<"Question: "<<answers[0]<<"\n";
                }
            }
            fin.close();
        }
        void list_users(){
            ifstream fin("users.text");
            if(fin.fail()){
                cout<<"can't list our users\n";
                return;
            }
            vector<string> check;
            string get_user;
            while(!fin.eof()){
                getline(fin,get_user);
                check.clear();
                split_str(get_user,',',check);
                cout<<"ID: "<<check[0]<<" Name: "<<check[3]<<"\n";
            }
        }
        void print_ask_from_me(){
            ifstream fin("questions.text");
            if(fin.fail()){
                cout<<"can't ask from me\n";
                return;
            }
            string getQuestion;
            user_current_info.clear();  // i can't detect but this vector cause storage error!!
            split_str(current_user_login_info,',',user_current_info);
            while(!fin.eof()){
                            getline(fin,getQuestion);
                if(getQuestion.find(',') == -1) continue; //causing error
                vector<string> check_asked_user_id;
                check_asked_user_id.clear();
                split_str(getQuestion,',',check_asked_user_id);
                vector <string> answers;
                //if(check_asked_user_id.back().find("&") != -1){
                split_str(check_asked_user_id.back(),'&',answers);
               // }
                if(((check_asked_user_id[1] == "**"+user_current_info.front()) || (check_asked_user_id[1] == user_current_info.front())) ){//|| (((check_asked_user_id[1] == "**"+user_current_info.front()) || (check_asked_user_id[1] == user_current_info.front()))&& check_asked_user_id.back().find('&') != -1)
                        if(check_asked_user_id[0].find('.') != -1){
                            //Print thread Questions!!
                            //string threadGetId;  using ERROR
                            vector<string> dotSplit;

                            split_str(check_asked_user_id[0],'.',dotSplit);
                            if(check_asked_user_id[1].find("**") != -1){
                                   cout<<"\tThread: Question id ("<<dotSplit[1]<<") to user id ("<<check_asked_user_id[2]<<")\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                            }
                            cout<<"\tThread: Question Id ("<<dotSplit[1]<<") !AQ to user id ("<<check_asked_user_id[2]<<")\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                        }
                        //print main question!!
                        if(check_asked_user_id[1].find("**") != -1){
                            cout<<"Question id ("<<check_asked_user_id[0]<<") to user id ("<<check_asked_user_id[2]<<")\t";
                            //cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                            //cout<<"\tAnswer: "<<answers[1]<<"\n";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            continue;
                        }
                        cout<<"Question id ("<<check_asked_user_id[0]<<") !AQ to user id ("<<check_asked_user_id[2]<<")\t";
                        if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                        cout<<"Question: "<<answers[0]<<"\n";
                }
            }
            fin.close();
        }
        void print_Questions_to_me(){
            ifstream fin("questions.text");
            if(fin.fail()){
                cout<<"Can't print to me\n";
                return;
            }
            string getQuestion;
            user_current_info.clear();  // i can't detect but this vector cause storage error!!
            split_str(current_user_login_info,',',user_current_info);
            //To Do
           // bool w =check_yourQuestion_is_answered();
            while(!fin.eof()){
                getline(fin,getQuestion);
                if(getQuestion.find(',') == -1) continue; //causing error
                vector<string> check_asked_user_id;
                check_asked_user_id.clear();
                split_str(getQuestion,',',check_asked_user_id);
                vector <string> answers;
                //if(check_asked_user_id.back().find("&") != -1){
                split_str(check_asked_user_id.back(),'&',answers);
               // }
                if(check_asked_user_id[2] == user_current_info.front() || (((check_asked_user_id[1] == "**"+user_current_info.front()) || (check_asked_user_id[1] == user_current_info.front()))&& check_asked_user_id.back().find('&') != -1)){
                        if(check_asked_user_id[0].find('.') != -1){
                            //Print thread Questions!!
                            //string threadGetId;  using ERROR
                            vector<string> dotSplit;

                            split_str(check_asked_user_id[0],'.',dotSplit);
                            if(check_asked_user_id[1].find("**") != -1){
                                   cout<<"\tThread: Question id ("<<dotSplit[1]<<") from user id (**)\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                            }
                            cout<<"\tThread: Question Id ("<<dotSplit[1]<<") from user id ("<<check_asked_user_id[1]<<")\t";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                dotSplit.clear();
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            dotSplit.clear();
                            continue;
                        }
                        //print main question!!
                        if(check_asked_user_id[1].find("**") != -1){
                            cout<<"Question id ("<<check_asked_user_id[0]<<") from user id (**)\t";
                            //cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                            //cout<<"\tAnswer: "<<answers[1]<<"\n";
                            if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                            cout<<"Question: "<<answers[0]<<"\n";
                            continue;
                        }
                        cout<<"Question id ("<<check_asked_user_id[0]<<") from user id ("<<check_asked_user_id[1]<<")\t";
                        if(answers.size() == 2){
                                cout<<"Question: "<<answers[0]<<"\n";//check_asked_user_id.back()
                                cout<<"\tAnswer: "<<answers[1]<<"\n";
                                continue;
                            }
                        cout<<"Question: "<<answers[0]<<"\n";
                }
            }
            fin.close();
        }      

};

struct login_signup{
    string signup_user="";
    string user_login_info,userAllinfo;//later: vector
    string filedata;
       bool signUp(){
        //static int id =1;
        ofstream fout("users.text",fstream::app);
        //ofstream fonline("online_users.text",fstream::app);
        if(fout.fail()){//    || fonline.fail()
            cout<<"Cant't open this file!!\n";
            return 0;
        }
        ifstream fin("users.text");
        if (fin.fail()) {
            cout << "Can't open this file!!\n";
            return 0;
        }

        fstream idFile("ids.text",ios::in | ios::out | ios::app);
        if(idFile.fail()){
            cout<<"Cant't open this file!!\n";
            return 0;
        }
        static int id =1;
        //idFile<<id;
        while(!idFile.eof()){
            idFile>>id;
        }
        idFile.clear();
        ostringstream oss;
        oss<<id;
        //int id = rand()%100 +1;
        string user_name,email;
        string password;
        string anonymous;
        string valname;
        bool userNameExist = false;
            cout << "Enter user name. (No spaces): "; cin >> user_name;
            while (getline(fin, valname,',')) {
                if (valname.find(user_name) != -1) {
                    cout << "\nthis name is already exist , try with another name!!\n";
                    userNameExist = true;
                    break;
                }
                userNameExist = false;
            }
            if (userNameExist) {
                signUp();
                return true;}
                fin.close();
       
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
        while(1){
        cout<<"Allow anonymous questions?: (0 or 1) ";cin>>anonymous;
        if(anonymous != "0" && anonymous != "1"){
            cout<<"anonymous value should be 0 or 1!!\n";
            continue;
        }
        break;
        }
        cout<<"\nYour Registeration is completed :)\n";
        signup_user = oss.str()+","+user_name+","+password+","+fullname+","+email+","+anonymous;
        fout<<id<<","<<user_name<<","<<password<<","<<fullname<<","<<email<<","<<anonymous<<"\n";
        fout.close();
        //fonline<<id<<","<<user_name<<","<<password<<","<<fullname<<","<<email<<","<<anonymous<<"\n";
        idFile<<++id<<"\n";
        idFile.close();
        
        
        return true;
    }
    string userLoginInfo(){
        ifstream fin(filedata);
        if(fin.fail()){
            cout<<"can't open this file\n";
            return 0;
        }

        while(!fin.eof()){
            getline(fin,userAllinfo);
            if(userAllinfo.find(user_login_info) != -1) break;
        }
        fin.close();
        return userAllinfo;
    }
    bool login(string filename){
        string userName="",password="",valname;
        filedata = filename;
        bool password_correct,name_correct ;
        cout<<"Enter user name & password: ";
        cin>>userName>>password;
        ifstream fin(filename);
        if(fin.fail()){
            cout<<"there is no database till now please sign up to be our first user :)!!\n";
            return 0;
        }
        name_correct = false;
        password_correct = false;
        
        while(getline(fin,valname,',')){
            if(userName == valname) {
                password_correct =true;
                name_correct = true;
                user_login_info = valname;
                }
            else if(password_correct){
                password_correct =false;
                if(valname == password){
                    user_login_info +=","+valname;
                    //cout<<user_login_info<<"\n"; 
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

};

struct AskFm{
    operations currentuser;
    login_signup user;
    string file_current_login_users = "online_users.text";
    //string user_login_info1111 ="";
    vector<string> user_login_info;
    string file_name = "users.text";//just like our database
    void remove_file_when_logOut(){
        ofstream fremoved(file_current_login_users,ofstream::trunc);//over write
        if(fremoved.fail()){
            cout<<"Can't open this file\n";
            return;
        }
        fremoved<<"";
        fremoved.close();
    }
    void user_info_updates(){
        ifstream fin(file_current_login_users);
        if(fin.fail()){
            cout<<"Can't open this file\n";
            return;
        }
        user_login_info.clear();
        string updates_values;
        while(getline(fin,updates_values)){
            user_login_info.push_back(updates_values);
        }
        fin.close();
        remove_file_when_logOut();
    }
    void updated_login_logout_users(string user_info_if_login,string user_info_if_signUp){
        ofstream fout(file_current_login_users,fstream::app);
        if(fout.fail()){
            cout<<"Can't open this file\n";
            return;
        }
        for(auto it = user_login_info.begin();it != user_login_info.end();){
            if(*it == user_info_if_login){
                it = user_login_info.erase(it);
            }
            else if(*it == user_info_if_signUp){
                it = user_login_info.erase(it);
            }
            else ++it;
        }
        for(auto x:user_login_info){
            fout<<x<<"\n";
            cout<<x<<"\n";
        }
        fout.close();
        
    }
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
            if(choice == 1) {
                currentuser.back_up_file_data();
                currentuser.remove_questionData();
                currentuser.writeToQuestions();
                currentuser.print_Questions_to_me();
            }
            else if(choice == 2){
                currentuser.back_up_file_data();
                currentuser.remove_questionData();
                currentuser.writeToQuestions();
                currentuser.print_ask_from_me();
           }
            else if(choice == 3) currentuser.Answer_Question();
            else if(choice == 4) currentuser.delete_question();
            else if(choice == 5) currentuser.askParentQuestion();
            else if(choice == 6) currentuser.list_users();
            else if(choice == 7){
                currentuser.back_up_file_data();
                currentuser.remove_questionData();
                currentuser.writeToQuestions();
                currentuser.list_feed();
            }
            else if(choice == 8) {
                user_info_updates();
                updated_login_logout_users(user.userLoginInfo(),user.signup_user);
                //remove_file_when_logOut();//user.userLoginInfo(),user.signup_user
                registeration_process();
                return;}
            cout<<"\n*************************\n";
        }
    }

    void check_update_online_user(string user_info){
        //if(user_login_info.size() == 0) return;
        ofstream fout(file_current_login_users,fstream::app);
        ifstream fin(file_current_login_users);
        if(fout.fail() || fin.fail()){
            cout<<"Can't open this file\n";
            return;
        }
        fout<<user_info<<"\n";
        fout.close();
        user_login_info.clear();
        string onlin_current_user;
        while(!fin.eof()){
        getline(fin,onlin_current_user);
        //if(onlin_current_user == user.userLoginInfo()) continue;
        user_login_info.push_back(onlin_current_user);}
        //fout.close();
        fin.close();
        
        //for(auto it = user_login_info.begin();it != user_login_info.end();){
        //    if(*it == user.userLoginInfo()){
        //        it = user_login_info.erase(it);
        //    }
        //    else if(*it == user.signup_user){
        //        it = user_login_info.erase(it);
        //    }
        //    else ++it;
        //}
        for(auto x:user_login_info){
            cout<<x<<"\n";
        }
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
                bool x = user.login(file_name);
                if(x){ 
                    //string go = user.userLoginInfo();
                    currentuser.current_user_login_info = user.userLoginInfo();
                    check_update_online_user(user.userLoginInfo());//may cause error!!!
                    runner();
                }
                else if(!x) cout<<"Login failed :(\n";}
            else if(choice == 2){   
                bool z =user.signUp(); 
                if(z) {
                    currentuser.current_user_login_info = user.signup_user;
                    check_update_online_user(user.signup_user);
                    runner();
                }
                else cout<<"\nyour sign up faild Try again\n";
            }
            cout<<"\n*************************\n";
        }
    }
};
void remove_(){
    ofstream fout("online_users.text");
    if(fout.fail()){
        cout<<"can't remove \n";
        return;
    }
    fout<<"";
    fout.close();
}
int main(){
    AskFm tst ;
    tst.registeration_process();
    //if( remove( "online_users.txt" ) != 0 )
    //    perror( "Error deleting file" );
    //else
    //    puts( "File successfully deleted" );
    remove_();
    return 0;
}

/*
fstream fremoved(file_current_login_users,ios::in|ios::out|ios::trunc);
        if(fremoved.fail()){
            cout<<"Can't open this file\n";
            return;
        }
        user_login_info.clear();
        string added_to_vector="";

        while(getline(fremoved,added_to_vector)){
            user_login_info.push_back(added_to_vector);
        }
        fremoved.clear();
        fremoved<<" ";
        fremoved.close();
        ofstream fadded(file_current_login_users,fstream::app);
        //ifstream fin(file_current_login_users);
        if(fadded.fail()){
            cout<<"can't open this file\n";
            return;
        }
        //fin.close();
        //string removed_user;
        //while(!fremoved.eof()){
        //    getline(fremoved,removed_user);
        //    if(removed_user == user_info_ifLogin || removed_user == user_info_ifSignUp){
        //        fremoved<<"";  
        //    }
        //}
        fremoved.close();
        for(auto it = user_login_info.begin();it != user_login_info.end();){
            if(*it == user_info_ifLogin){
                it = user_login_info.erase(it);
            }
            else if(*it == user_info_ifSignUp){
                it = user_login_info.erase(it);
            }
            else ++it;
        }
        
        for(auto x:user_login_info){
            fadded<<x<<"\n";
            cout<<x<<"\n";
        }
        fadded.close();
*/
