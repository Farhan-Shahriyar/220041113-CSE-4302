#include<bits/stdc++.h>
using namespace std;

class Book{
private:
    string title;
    string author;
    string ISBN;
public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i){}
    string getTitle() const{ 
        return title; 
    }
    string getAuthor() const{ 
        return author; 
    }
    string getISBN() const{ 
        return ISBN; 
    }
    void displayBook() const{
        cout<<"Title: "<<title<<", Author: "<< author<<", ISBN: "<<ISBN<<endl;
    }
    string toCSV() const{
        return title + "," + author + "," + ISBN;
    }
};

class Library{
private:
    vector<Book> inventory;        
    deque<Book> borrowedBooks;     
    list<Book> archivedBooks;      
public:
    void addBook(){
        string title, author, ISBN;
        cout<<"Enter title: ";
        getline(cin, title);
        cout<<"Enter author: ";
        getline(cin, author);
        cout<<"Enter ISBN: ";
        getline(cin, ISBN);
        inventory.push_back(Book(title, author, ISBN));
        cout<<"Book added successfully."<<endl;
    }
    void borrowBook(){
        if(inventory.empty()){
            cout<<"No books available to borrow."<<endl;
            return;
        }
        string isbn;
        cout<<"Enter ISBN of the book to borrow: ";
        cin>>isbn;
        for(auto it = inventory.begin(); it != inventory.end(); it++){
            if(it->getISBN() == isbn){
                borrowedBooks.push_back(*it);
                inventory.erase(it);
                cout<<"Book borrowed successfully."<<endl;
                return;  
            }
        }
        cout<<"Book not found in inventory.\n";
        
    }
    void returnBook(){
        if(borrowedBooks.empty()){
            cout<<"No borrowed books to return."<<endl;
            return;
        }
        string isbn;
        cout<<"Enter ISBN of the book to return: ";
        cin>>isbn;
        for(auto it = borrowedBooks.begin(); it != borrowedBooks.end(); it++){
            if(it->getISBN() == isbn){  
                inventory.push_back(*it); 
                borrowedBooks.erase(it);  
                cout<<"Book returned successfully."<<endl;
                return;  
            }
        }
        cout<<"Book not found in borrowed list."<<endl;
        
    }
    void archiveBook(){
        if (inventory.empty()){
            cout<<"No books available to archive."<<endl;
            return;
        }
        string isbn;
        cout<<"Enter ISBN of the book to archive: ";
        cin>>isbn;
        for(auto it = inventory.begin(); it != inventory.end(); it++){
            if(it->getISBN() == isbn){  
                archivedBooks.push_back(*it); 
                inventory.erase(it);  
                cout<<"Book archived successfully."<<endl;
                return; 
            }
        }
        cout<<"Book not found in inventory."<<endl;
        
    }
    void displayAllBooks(){
        cout<<"Inventory Books:"<<endl;
        for(auto &book : inventory){
            book.displayBook();
        }
        cout<<"Borrowed Books:"<<endl;
        for(auto &book : borrowedBooks){
            book.displayBook();
        }
        cout<<"Archived Books:"<<endl;
        for(auto &book : archivedBooks){
            book.displayBook();
        }
    }
    void saveData(){
        ofstream invFile("inventory.txt"), borFile("borrowed.txt"), archFile("archived.txt");
        if(!invFile || !borFile || !archFile){
            cout<<"Error opening files"<<endl;
            return;
        }
        for(auto &book : inventory){
            invFile<<book.toCSV()<<"\n";
        }
        for(auto &book : borrowedBooks){ 
            borFile<<book.toCSV()<<"\n";
        }
        for(auto &book : archivedBooks){
            archFile<<book.toCSV()<<"\n";
        }
        cout<<"Data saved successfully."<<endl;
    }
    void loadData(){
        ifstream invFile("inventory.txt"), borFile("borrowed.txt"), arcFile("archived.txt");
        string line, title, author, isbn;
        inventory.clear();
        borrowedBooks.clear();
        archivedBooks.clear();
        while(getline(invFile, line)){
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, isbn, ',');
            inventory.push_back(Book(title, author, isbn));
        }
        while(getline(borFile, line)){
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, isbn, ',');
            borrowedBooks.push_back(Book(title, author, isbn));
        }
        while(getline(arcFile, line)){
            stringstream ss(line);
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, isbn, ',');
            archivedBooks.push_back(Book(title, author, isbn));
        }

    }
};

int main(){
    Library library;
    int choice;
    do{
        cout<<"Library Management System"<<endl;
        cout<<"1. Add Book"<<endl;
        cout<<"2. Borrow Book"<<endl;
        cout<<"3. Return Book"<<endl;
        cout<<"4. Archive Book"<<endl;
        cout<<"5. Display Books"<<endl;
        cout<<"6. Save Data"<<endl;
        cout<<"7. Load Data"<<endl;
        cout<<"0. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        cin.ignore();
        switch(choice){
            case 1: 
                library.addBook(); 
                break;
            case 2: 
                library.borrowBook(); 
                break;
            case 3: 
                library.returnBook(); 
                break;
            case 4: 
                library.archiveBook(); 
                break;
            case 5: 
                library.displayAllBooks(); 
                break;
            case 6: 
                library.saveData(); 
                break;
            case 7: 
                library.loadData(); 
                break;
            case 0: 
                cout<<"Exiting"<<endl; 
                break;
            default: 
                cout<<"Invalid choice"<<endl;
        }
    }while(choice != 0);
    return 0;
}
