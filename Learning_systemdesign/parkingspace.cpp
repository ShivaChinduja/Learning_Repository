#include<iostream>
#include<vector>
#include<chrono>
#include<thread>

using namespace std;
class GenerateTicket;
class Parkingspot{
    int spot_number;
    int pay_per_hour;
    bool avail= true;
    string type;
    public:
    Parkingspot(int pay,int spot, string t):pay_per_hour(pay),spot_number(spot),type(t),avail(true){}
    bool isAvailable(){return avail;}
    void occupy(){avail = false;}
    void freespot(){avail = true;}
    int pay(){return pay_per_hour;}

};
class Vehicle{
    public:
    string vehicle_type;
    int vehicle_number;
    Vehicle(string t , int no):vehicle_type(t),vehicle_number(no){}
};
class Floor{
    public:
    int cap=0;
    vector<Parkingspot*> bs;
    vector<Parkingspot*> cs;
    vector<Parkingspot*> hs;
    int fn=0;
    Floor(int floor_number,int capacity , int& w2 , int& w4 ,int& hw){
        cap = capacity;
        fn = floor_number;
        for(int i=0;i<w2;i++){bs.push_back(new Parkingspot(10 , i+1 ,"bike"));}
        for(int j=0;j<w4;j++){cs.push_back(new Parkingspot(20,j+1, "car"));}
        for(int k=0;k<hw;k++){hs.push_back(new Parkingspot(30,k+1,"heavy"));}
    }
    ~Floor(){
        for(auto p: bs){delete p;}
        for(auto p: cs){delete p;}
        for(auto p: hs){delete p;}
    }
    
};
class ParkingLot{
    vector<Floor*> floors;
    int two_wheeler,four_wheeler,heavy;
    public:
    GenerateTicket* allocate(Vehicle*);
    void deallocate(Vehicle*,GenerateTicket*);
    void decodeslot(int, int& ,int& , int& );
    void calculatepay(int,chrono::system_clock::time_point);

    ParkingLot(int floorcount,int capacity,int w2,int w4 ,int hw){
        two_wheeler=w2;
        four_wheeler = w4;
        heavy = hw;
        for(int i=0;i<floorcount;i++){
            floors.push_back(new Floor(i+1,capacity , w2,w4,hw));
        }
    }
    
    int findavailablity(string type){
        vector<Parkingspot*>*vec = nullptr;
        int base =0;
        for(int i=0;i<floors.size();i++){
            if(type=="bike"){vec = &floors[i]->bs;base=1;}
            else if(type=="car"){vec =&floors[i]->cs;base =2;}
            else if(type=="heavy"){vec = &floors[i]->hs;base = 3;}
            if(vec == nullptr) return -1;
            for(int j=0;j< vec->size();j++){
                if((*vec)[j]->isAvailable()){
                    (*vec)[j]->occupy();
                    return (i+1)*1000 + base*100 + (j+1);
                }
            }
        }
        return -1;

    }
    ~ParkingLot(){
        for(auto p: floors){delete p;}
    }
};

class GenerateTicket{
    public:
    string type;
    int vehiclenumber;
    int tkt_id;
    int slot;
    chrono::system_clock::time_point entry_time;
    chrono::system_clock::time_point exit_time;
   
    GenerateTicket(string t ,int v_no , int slot_number , int id){
        type = t;
        vehiclenumber = v_no;
        tkt_id = id;
        slot = slot_number;
        entry_time = chrono::system_clock::now();
    
    }

};
GenerateTicket* ParkingLot::allocate(Vehicle* v1){
        // spot_number = floor*1000 + base(1,2,3)*1-- + j+1;
        //e.g bike in floor 1 spot 1 => spot_number = 1000+100+1 = 1101
        int spot_number = ParkingLot::findavailablity(v1->vehicle_type);
        if(spot_number!=-1)
        {
            GenerateTicket* tkt = new GenerateTicket(v1->vehicle_type,v1->vehicle_number,spot_number,v1->vehicle_number+spot_number);
            return tkt;
        }
        cout << "No spot available" << endl;
        return nullptr;


    }
void ParkingLot::decodeslot(int slot, int& f,int&b , int& spo){
    f = (slot/1000) -1;
    b = (slot%1000)/100;
    spo = (slot%100) -1;
}
void ParkingLot::calculatepay(int pay,chrono::system_clock::time_point entrytime){
    chrono::system_clock::time_point exit = chrono::system_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(exit-entrytime).count();
    //int dur = ceil(duration);
    cout << "duration of parked lots: " << duration << endl;
    cout << "amount to be paid: " << pay*duration << endl;


} 
void ParkingLot::deallocate(Vehicle* v1 , GenerateTicket* t1){
    cout << "Vehicle number :  " << t1->vehiclenumber << endl;
    cout << "vehicle type: "<<t1->type << endl;
    int floor , base , spot;
    Parkingspot* sp = nullptr;
    ParkingLot::decodeslot(t1->slot,floor,base,spot);
    if(base==1){ sp = floors[floor]->bs[spot];}
    else if(base==2){sp = floors[floor]->cs[spot];}
    else if(base==3){sp = floors[floor]->hs[spot];}
    sp->freespot();
    ParkingLot::calculatepay(sp->pay(),t1->entry_time);
    
}
void print(GenerateTicket* t){
    if(!t){cout << "No spot allocated no availablility check later" << endl;return;}
    cout << "################################################" << endl;
    cout << "Vehicle number :  " << t->vehiclenumber << endl;
    cout << "vehicle type: "<<t->type << endl;
    cout << "Ticket Number: " <<t->tkt_id << endl;
    cout << "Allocated slot: " <<  t->slot << endl;
    time_t entry = chrono::system_clock::to_time_t(t->entry_time);
    cout << "Entry time: " <<  ctime(&entry) << endl;
    cout << "################################################" << endl;


}


int main(){
    ParkingLot* L = new ParkingLot(2,20,10,5,5);

    Vehicle* v1 = new Vehicle("bike" , 123);
    Vehicle* v2 = new Vehicle("car" , 345);
    cout << "Allocating  space...." << endl;
    GenerateTicket* t = L->allocate(v1);
    GenerateTicket* t2 = L->allocate(v2);
    print(t);
    print(t2);
    // add wait time here 
    this_thread::sleep_for(chrono::seconds(5));
    cout << "Exiting ...." << endl;
    L->deallocate(v1 , t);
    this_thread::sleep_for(chrono::seconds(5));
    L->deallocate(v2,t2);
    delete L;
    delete v1,v2;
    delete t,t2;

    return 0;
}