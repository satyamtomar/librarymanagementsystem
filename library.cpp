#include<iostream>
#include<fstream>
using namespace std;

class temp{
   string id,name,author,search;
   fstream file;
   public:
   void addBook();
   void showAll();
   void extractBook();
}obj;
int main(){

    cout<<"-------------------------\n";
    cout<<"1-Show All Books\n";
    cout<<"2-Extract Book\n";
    cout<<"3-Add books(Admin)\n";
    cout<<"4-Exit\n";
    cout<<"-------------------------\n";
    cout<<"Enter Your Choice ::\n";
    char choice;
    cin>>choice;
   
    switch(choice)
    {

        case '1':
        cin.ignore();
        obj.showAll();

        break;

        
        case '2':
        cin.ignore();
        obj.extractBook();
        break;

        case '3':
        cin.ignore();
        obj.addBook();
        
         break;

        case '4':
       return 0;
        break;

        default:cout<<"Invalid Choice!";
    }


    
    
    }

 void temp :: addBook(){
    cout<<"\nEnter Book ID :: ";
    getline(cin,id);
    cout<<"Enter Book Name :: ";
    getline(cin,name);
    cout<<"Enter Book's Author name ::";
    getline(cin,author);

    file.open("booksData.txt",ios:: out | ios :: app);
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
 } 

 void temp :: showAll(){
    file.open("booksData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
        cout<<"\n\n";
        cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;

    while(!file.eof())
    {
         cout<<"\t\t"<<id<<" \t\t\t"<<name<<"\t\t\t "<<author<<endl;
         getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    }
    file.close();
 } 

 void temp :: extractBook()
 {
    showAll();
    cout<<"Enter Book ID ::";
    getline(cin,search);
    
    file.open("booksData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

     cout<<"\n\n";
    cout<<"\t\t Book ID \t\t\t Book Name \t\t\t Author's Name"<<endl;
    
    while(!file.eof())
    {
        if(search ==id )
        {
            cout<<"\t\t"<<id<<" \t\t\t"<<name<<"\t\t\t "<<author<<endl;
            cout<<"Book Extracted Successfully!!!";
        }
        getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
    }

 }