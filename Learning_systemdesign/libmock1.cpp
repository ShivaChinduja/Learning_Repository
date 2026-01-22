#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Books{
    
    string bookname;
    int bookid;
    int copy;
    bool availability;
    public:
    Books(string b,int id,int cop):bookname(b),bookid(id),copy(cop),availability(true){}
    void show(){
        cout << bookname << " " << copy << " " << availability << " " << bookid << endl;
    }

};
class Section{
    public:
    string sectionname;
    vector<Books*> book;
    Section(string name):sectionname(name){}
    void Showbooks(){
        cout << "Books in section " << sectionname << endl;
        for(auto i: book){
            i->show(); 
        }
    }

};
class Receipt{
    int refno;
    string bookname;
    int bd;
    int rd;
    Receipt(int r,string bn, int borrow, int retur):refno(r),bookname(bn),bd(borrow),rd(retur){}
};
class User{
    public:
    virtual bool search(string bookname)=0;
};
class Member:public User{
    public:
    bool search(string bn){

    }
    void borrowbook(string bookname){
        // borrowbook and get the receipt/

    }
    int returnbook(string bookname){
        // return amount if any late fees
        
    }

};

class Librarian{
    public:
    void addbook(vector<Books*>&b , Books* obj){
        b.push_back(obj);
    }
    void removebook(vector<Books*>&b , Books* obj){
        b.erase(find(b.begin(),b.end(), obj));
    }
};


int main(){
    Librarian L;
    Section fiction("fiction");
    Books* b1 = new Books("harry",123,2);
    Books* b2 = new Books("Potter", 234,3);
    L.addbook(fiction.book,b1);
    L.addbook(fiction.book,b2);
    fiction.Showbooks();
    Section Motivation("Motivation");
    Books* b3 = new Books("life" , 345, 2);
    Books* b4 = new Books("Happy", 567,2);
    L.addbook(Motivation.book,b3);
    L.addbook(Motivation.book ,b4);
    Motivation.Showbooks();
    L.removebook(fiction.book , b2);
    fiction.Showbooks();
    return 0;
}