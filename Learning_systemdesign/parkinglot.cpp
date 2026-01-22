#include<iostream>
#include<vector>
#include<ctime>
#include<thread>
#include<chrono>
using namespace std;
class Parkingticket{
    int spotnumber;
    string type;
    time_t entrytime;
    public:
    Parkingticket(int n , string t):spotnumber(n), type(t),entrytime(time(0)){};
    int getspot(){return spotnumber;}
    time_t gettime(){return entrytime;}
    void printdetails(){
        cout << "###############################################" << endl;
        cout << "Vehicle: " << type << " spotnumber: "<< spotnumber<<endl;
        cout << "booking time: "<< ctime(&entrytime) << endl;
        cout << "###############################################" << endl;
    }
};
class Parkingspot{
    int capacity;
    vector<bool> avail;
    string type;
    int price;
   
    public:
    Parkingspot(int n ,string t,int p):avail(n,false),type(t),price(p),capacity(n){
        
    }
    unique_ptr<Parkingticket> bookspot(){
        for(int i=0;i<capacity;i++){
            if(!avail[i]){
                cout << i+1 << " spot is available booking now.." << endl;
                avail[i] = true;
                auto ticket = make_unique<Parkingticket>(i,type);
                ticket->printdetails();
                return ticket;
             }
        }
        cout << "No available spots ..." << endl;
        return nullptr;

    }
    int calculatepay(time_t t){
        int seconds = difftime(time(0) , t);
        if(seconds < 60){return 0;}
        else{ return seconds/60*price;}
    }
    int freespot(unique_ptr<Parkingticket>& t){
        avail[t->getspot()] = false;
        return calculatepay(t->gettime());
    }


};
class Bikespot: public Parkingspot{
    
    public:
    Bikespot(int n):Parkingspot(n,"bike", 10){

    }


};
class Carspot: public Parkingspot{
    public:
    Carspot(int n): Parkingspot(n,"car",20){}
}
class Parkinglot{
    Bikespot bikespot;
    Carspot carspot;

    //Carlot carlot;
    public:
    Parkinglot():bikespot(3){}
    unique_ptr<Parkingticket> availability(string type){
        if(type=="bike"){
            return bikespot.bookspot();
        }
        if(type=="car"){
            return carspot.bookspot();
        }
        
    }
    int freespot(string type,unique_ptr<Parkingticket>& t){
        if(type=="bike"){
            return bikespot.freespot(t);
        }
        if(type=="car"){
            return carspot.freespot(t);
        }

    }
};
class Vehicle{
    string type;
    Parkinglot& lot;
    int costs;
    unique_ptr<Parkingticket> ticket;
    public:
    Vehicle(string t , Parkinglot& l):type(t),lot(l){}
     void park(){
        //checkavailablity
        ticket = lot.availability(type);

        //genertae tkt
    }
    void unpark(){
        costs = lot.freespot(type,ticket);
        cout << "Please pay : " << costs << endl;
        //free spot
        //generate costs
    }
};
class Bike: public Vehicle{
    public:
    Bike(Parkinglot& l):Vehicle("bike",l){

    }
   
};
class Car: public Vehicle{
    public:
    Car(Parkinglot& l): Vehicle("car", l){}
};


int main(){
    Parkinglot lot;
    Bike b(lot);
    b.park();
    b.unpark();
    Bike b1(lot);
    Bike b2(lot);
    Bike b3(lot);
    Bike b4(lot);
    Car c(lot);
    b1.park();
    b2.park();
    b3.park();
    b4.park();
    c1.park();
    this_thread::sleep_for(chrono::seconds(60));
    //Car c(lot);
    //entry
    // parkinglot 
    //parkingspot
    // bike , car , truck 
    //ticket/
    //payment 
    //exit 
    b1.unpark();
    this_thread::sleep_for(chrono::seconds(30));
    b2.unpark();
    this_thread::sleep_for(chrono::seconds(10));
    b3.unpark();
    c2.unpark();

    return 0;
}
