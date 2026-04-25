#include <iostream>
#include <vector>
#include<algorithm>
#include<cctype>
using namespace std;
class Book{
    public:
    string Name, Author;
    bool isAval  = true;
    void ok(string name, string author){
        Name = name;
        Author = author;
    }
};
string toLower(string s){
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
        }
        return s;
}
void searchbook(vector<Book>& boui,  string& target);
void searchbok(vector<Book>& boui,   string& authorn);
int main(){ 
 Book library;
 vector<Book> boui ;
library.ok("Holy Bible", "GOD");
boui.push_back(library);
while(true){

 int choise;
        cout << "\nEnter number:\n";
        cout << "0 : Exit\n";
        cout << "1 : Add new Book\n";
        cout << "2 : See Books\n";
        cout << "3 : Borrow books\n";
        cout << "4 : Search for book\n";
        cin >> choise;
        cin.ignore();

        switch (choise){  
                case 0:
                return 0;
        case 1:{
            Book newbok;
            string n, a;
            newbok.ok(n, a);
            cout << "Enter BOOK NAME: ";
            getline(cin, newbok.Name);
             cout << endl;
             cout << "Enter BOOK AUTHOR : ";
             getline(cin, newbok.Author);
             boui.push_back(newbok);
            break;
        }
        case 2:{
            for(int i = 0; i < boui.size(); i++){
        cout << boui[i].Name << " by " << boui[i].Author << endl;      
      }
      break;
        }
        case 3: {
            int numbook, index;
        for(int i = 0; i < boui.size(); i++){
        cout << i + 1 << ": " << boui[i].Name << " by " << boui[i].Author << endl; 
        }
        cout << "Enter the number of book   : ";
        cin >> numbook;
        numbook--;
        if(numbook >= 0 && numbook < boui.size()){
            cout << "BOOK : " << boui[numbook].Name << " by "<<boui[numbook].Author << endl;
            cout << "What would you like to do: \n" << "1 : Borrow book\n" << "2 : For chek the current state of the Book\n" << "3 : Return book\n";
            cin >> index;
            if (index == 1){
                if (boui[numbook].isAval == false){
                    cout << "Book is alredy taken\n";
                }
               else{
                cout << "Book borrowed!\n";
                boui[numbook].isAval = false;
               }
            }
            else if (index == 3){
                if(boui[numbook].isAval == true){
                    cout << "You don't have this book\n";
                }
                else{
                    cout << "Book returned\n";
                boui[numbook].isAval = true;
                }
            }
             else if (index == 2 ){
                if(boui[numbook].isAval == true){
                    cout << "The book is free you can take it \n";
                }
                else{
                    cout << "Book is already taken \n";
}
} 
break;}}    
                case 4:{
                string name;
                int oo;
                cout << "How you want to find book : \n 1: By name of Book \n 2: By name of Author \n";
                cin >> oo;
                cin.ignore();
                if(oo == 2 ){
                 cout << "Enter the name of the Author: ";  
                getline(cin, name)  ;
                searchbok(boui, name);
                }
                else{
                cout << "Enter the name of the Book: ";
                getline(cin, name);
                searchbook(boui, name);    
                }

                break; 
                }

            default:
             return 0;}}}
             void searchbook(vector<Book>& boui,  string& target){
                bool found = false;
                target = toLower(target);
                for(int i = 0 ; i < boui.size(); i++){
                    string bookName = toLower(boui[i].Name);
                    if(bookName.find(target) != string::npos ){
                        cout << "Found: " << boui[i].Name << " by " << boui[i].Author << endl;
                        found = true;
                    }
                }
                             if(!found){
                cout << "Did not found \n";
             }
             }
             void searchbok(vector<Book>& boui,  string& authorn){
                bool found = false;
                authorn = toLower(authorn);
                for(int i = 0; i < boui.size(); i++){
                    string authorName = toLower(boui[i].Author);
                    if(authorName.find(authorn) != string::npos){
                        cout << "Found Author: " << boui[i].Author << " Book " << boui[i].Name << endl;
                        found = true;
                    }
                }
                if(!found){
                    cout << "Nothing Found \n";
                }
             }
