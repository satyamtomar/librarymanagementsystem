#include<bits/stdc++.h>
using namespace std;

class temp{
   string id,name,author,search;
   fstream file;
   public:
   void addBook();
   void showAll();
   void extractBook();
};
int main(){

    cout<<"-------------------------";
    cout<<"1-Show All Books";
    cout<<"2-Extract Book";
    cout<<"3-Add books(Admin)";
    cout<<"3-Exit";
    cout<<"-------------------------";
    cout<<"Enter Your Choice ::";
    char choice;
    cin>>choice;
    temp obj;
    switch(choice)
    {

        case '1':
        cin.ignore();
        obj.showAll();

        break;

        
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
        

        default:cout<<"Invalid Choice!";
    }


    
    
    }

 void temp :: addBook(){
    cout<<"\nEnter Book ID :: ";
    getline(cin,id);
    cout<<"Enter Book Name";
    getline(cin,name);
    cout<<"Enter Book's Author name ::";
    getline(cin,author);

    file.open("bookData.txt,ios:: out | ios :: app");
    file<<id<<"*"<<name<<"*"<<author<<endl;
    file.close();
 } 

 void temp :: showAll(){
    file.open("bookData.txt",ios :: in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');
        cout<<"\n\n";
        cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;

    while(!file.eof())
    {
         cout<<"\t\t"<<id<<" \t\t\t"<<name<<"\t\t\t "<<author<<endl;
    }
    file.close();
 } 

 void temp :: extractBook()
 {
    showAll();
    cout<<"Enter Book ID ::";
    getline(cin,search);
    
    file.open("bookData.txt",ios::in);
    getline(file,id,'*');
    getline(file,name,'*');
    getline(file,author,'\n');

     cout<<"\n\n";
    cout<<"\t\t Book Id \t\t\t Book Name \t\t\t Author's Name"<<endl;
    
    while(file.eof())
    {
        if(search ==id )
        {
            cout<<"\t\t"<<id<<" \t\t\t"<<name<<"\t\t\t "<<author<<endl;
        }
    }

 }

