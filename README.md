# Library
#include <iostream>
#include <vector>
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


int main(){ 
 Book library;
 vector<Book> boui ;
library.ok("Holy Bible", "GOD");
boui.push_back(library);
while(true){

 int choise;
        cout << "\nEnter number:\n";
        cout << "1 : Add new Book\n";
        cout << "2 : See Books\n";
        cout << "3 : Borrow books\n";
        cout << "4 : Exit\n";
        cin >> choise;
        cin.ignore();

        switch (choise){  
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
                    cout << "You don't have this book";
                }
                else{
                    cout << "Book returned";
                boui[numbook].isAval = true;
                }
            }
             else if (index == 2 ){
                if(boui[numbook].isAval == true){
                    cout << "The book is free you can take it \n";
                }
                else{
                    cout << "Book is alredy taken";
}
} 
break;}}    case 4:
                return 0;
            default:
             return 0;}}}
