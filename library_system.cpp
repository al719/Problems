#include <bits/stdc++.h>
using namespace std;

bool is_prefix(string input,string str){
    bool isPrefix =false;
    for(int i=0;i<str.size();i++){
        if(str[i] == input[i]) isPrefix =true;
        else {
            isPrefix = false;
            break;
        }
    }
    if(isPrefix) return true;
    else return false;
}
struct book{
        string name;
        int id;
        int quantity=0;
        int borrow_quantity=0;
        bool is_borrowed = false;
        vector<string> user_borrowed_book;
        book(){}
        book(string bookname,int bookid,int bookquantity = 0){
                name = bookname;
                id = bookid;
                quantity = bookquantity;
        }
        void print_prefix(){
                cout<<name<<"\n";
        }
        void print(){
                cout<<"id= "<<id<<" name= "<<name<<" totalQuantity= "<<quantity<<" borrow quantity= "<<borrow_quantity;
        }
};
bool compare_id(book &a,book &b){
        //cout<<"teest\n";
        return a.id < b.id ;
}
bool compare_name(book &a,book &b){
        return a.name<b.name;
}
struct user{
        string name;
        int national_id;
        vector<int> user_booksID;
        void print(){
                for(int i=0;i<user_booksID.size();i++){
                        cout<<user_booksID.at(i)<<" ";
                }
                cout<<"\n";
        }
};
struct library_system{
        book books[100];
        user users[100];
        int len;
        int user_len;
        library_system(){
                 len =0;
                 user_len =0;
        }
        void add_book(){
                cout<<"Enter book info: id & name & totalQuantity: ";
                string name_added;
                int id_added;
                int quantity;
                cin>>id_added>>name_added>>quantity;
                books[len++] = {name_added,id_added,quantity};
        }
        void search_prefix(){
                cout<<"Enter book name prefix: ";
                string str_prefix;
                cin>>str_prefix;
                bool is_ok =false;
                for(int i=0;i<len;i++){
                       // if(books[i].is_borrowed) continue;
                        if(is_prefix(books[i].name,str_prefix))
                                {
                                        cout<<books[i].name<<"\n";
                                        is_ok = true;
                                }
                }
                if(!is_ok) cout<<"No book with such prefix\n";
        }
        void print_who_borrow_book_by_name(){
                cout<<"Enter book name: ";
                string bookName;
                int temp=0;
                bool notfound = false;
                cin>>bookName;
                for(int i=0;i<len;i++){
                        if(books[i].name == bookName){
                                temp =i;
                                notfound = true;
                                break;
                        }
                }
                if(!notfound){
                        cout<<"Invalid book name\n";
                        return;
                }
                for(int j=0;j<books[temp].user_borrowed_book.size();j++){
                        cout<<books[temp].user_borrowed_book.at(j)<<"\n";
                }
        }
        void print_by_id()
                {
                //cout<<"yes\n";
                sort(books,books+len,compare_id);
                //cout<<"yesssss\n";
                for(int i=0;i<len;i++){
                        books[i].print();
                        //cout<<"yeskkkk\n";
                        cout<<"\n";
                }
        }
        void print_by_name(){
                sort(books,books+len,compare_name);
                for(int i=0;i<len;i++){
                        books[i].print();
                        cout<<"\n";
                }
        }
        void add_user(){
                cout<<"Enter user name & national id: ";
                string userName;
                int nationalID;
                cin>>userName>>nationalID;
                users[user_len++] = {userName,nationalID};
        }
        void user_borrow_book(){
                cout<<"Enter user name and book name: ";
                string user_name;
                string book_name;
                int id_temp;
                cin>>user_name>>book_name;
                //string name_found = find(books)
                for(int i=0;i<len;i++){
                        if(books[i].name == book_name){
                                if(books[i].quantity == 0)
                                        {
                                                cout<<"Sorry, this book can't be borrowed\n";
                                                break;
                                        }
                                //books[i].quantity--;
                                books[i].borrow_quantity++;
                                books[i].is_borrowed =true;
                                books[i].user_borrowed_book.push_back(user_name);
                                id_temp = books[i].id;
                                break;
                        }
                }
                for(int i =0;i<user_len;i++){
                        if(user_name == users[i].name){
                                users[i].user_booksID.push_back(id_temp);
                                break;
                        }
                }
        }
        void user_return_book(){
                cout<<"Enter user name and book name: ";
                string user_name,book_name;
                int id_temp;
                int id_book;
                cin>>user_name>>book_name;
                for(int i=0;i<len;i++){
                        if(books[i].name == book_name){
                                if(books[i].borrow_quantity == 0)
                                {
                                        books[i].is_borrowed =false;
                                        cout<<"no user borrow this book!!\n";
                                        break;
                                }
                                books[i].quantity++;
                                books[i].borrow_quantity--;
                                id_temp = i;
                                id_book = books[i].id;
                                break;
                        }
                }
                books[id_temp].user_borrowed_book.erase(remove(books[id_temp].user_borrowed_book.begin()
                ,books[id_temp].user_borrowed_book.end(),user_name),books[id_temp].user_borrowed_book.end());
                for(int k=0;k<user_len;k++){
                        if(users[k].name == user_name){
                                id_temp = k;
                                break;
                        }
                }
                users[id_temp].user_booksID.erase(remove(users[id_temp].user_booksID.begin()
                ,users[id_temp].user_booksID.end(),id_book),users[id_temp].user_booksID.end());                   
        }
        void print_users(){
                for(int i=0;i<user_len;i++){
                cout<<"user "<<users[i].name<<" id "<<users[i].national_id<<" borrowed books ids: ";
                users[i].print();
                }
        }
        int menu(){
                int choice =-1;
                while (choice == -1)
                {
                        cout<<"Library Menu;\n";
                        cout<<"1) Add Book\n";
                        cout<<"2) Search Book by prefix\n";
                        cout<<"3) print who borrowed book by name\n";
                        cout<<"4) print library by id\n";
                        cout<<"5) print library by name\n";
                        cout<<"6) Add user\n";
                        cout<<"7) User borrow book\n";
                        cout<<"8) User return book\n";
                        cout<<"9) print users\n";
                        cout<<"10)Exit\n";
                        cout<<"Enter your menu choice[1-10]: \n";
                        cin>>choice;
                        if(choice>10 || choice < 1){
                                cout<<"Invalid input, please try again!!\n*************************\n";
                                choice = -1;
                        }
                }
                return choice;
        }
        void runner(){
                
                while(1){
                        int choice = menu();
                        if(choice == 1) add_book(); 
                        else if(choice == 2) search_prefix();
                        else if(choice == 3) print_who_borrow_book_by_name();
                        else if(choice == 4) print_by_id();
                        else if(choice == 5) print_by_name();
                        else if(choice == 6) add_user();
                        else if(choice == 7) user_borrow_book();
                        else if(choice == 8) user_return_book();
                        else if(choice == 9) print_users();
                        else if(choice == 10) break;
                        cout<<"\n******************************\n";
                }
        }
};
int main(){
        library_system tst = library_system();
        tst.runner();

        return 0;
}