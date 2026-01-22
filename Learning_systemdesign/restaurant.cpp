#include<iostream>
#include<vector>
#include<condition_variable>
#include<mutex>
#include<chrono>
#include<thread>
using namespace std;
class Customer;
class Rest;
class Chef;
class Menu{
    public:
    string foodname;
    int cost;
    int preptime;
    bool avail;
    Menu(string f, int cos,int prep):foodname(f),cost(cos),preptime(prep),avail(true){}
};
class Order{
    public:
    int  orderitem;
    string ordername;
    int totalprice;
    int totalpreptime; 
    int chefid;

    Order():orderitem(-1),totalprice(0),totalpreptime(0),chefid(-1){}
    void generateord(Menu* m , Chef* c){
        if(!m || !c) return;
        ordername = m->foodname;
        totalprice = m->cost;
        totalpreptime = m->preptime;
        chefid = c->chefid;

    }
};
class Waiter{
    public:
    bool avail;
    Customer* c;
    Order* ord;
    Rest* re;
    mutex m;
    void Takeorder(int itemnum,Order* ord){
        unique_lock<mutex>lock(m);
        if(!re){cout << "Waiter is not assigned to any restaurant " << endl; return;}
        Chef* c =re->chefavailable();
        if(c){
            Menu* m = re->menudata(itemnum);
            if(!m){cout << "Menu item not seslected " << endl; return;}
            if(!ord){
                cout << "No orders " << endl;
                c->avail = true;
                avail = true;
                return;
            }
            ord->generateord(m,c);
            c->Preporder(ord);   
            DeliverOrder(ord); 
        }
        else{
            cout << "the chef are not available order not delivered successfully"<< endl;
        }
        
        
    }
    void DeliverOrder(Order* ord){
        if(!ord){return;}
        cout << "Delivering order " << endl;
        cout << "The cost of meal is " << ord->totalprice << endl;
        avail = true;
    }
    Waiter():c(nullptr),ord(nullptr),avail(true){}
    Waiter(Customer* Cust):c(Cust),avail(false){}
    void Display(Rest* R){
        re = R;
        re->Displaymenu();
    }
    ~Waiter() = default;
};

class Chef{
    public:
    bool avail;
    int chefid;
    int preptime;
    void Preporder(Order* ord){
        if(!ord) return;
        preptime = ord->totalpreptime;
        cout << "Chef is preparing your order" << endl;
        this_thread::sleep_for(chrono::seconds(preptime));
        cout << "Order Done " << endl;
        avail = true;
        
    }
    
    Chef(int i):chefid(i),avail(true),preptime(0){}

};
class Rest{
    public:
    vector<Menu*> dishes;
    vector<Waiter*> Waiters;
    vector<Chef*> chefs;
    Rest() = default;
    
    void Displaymenu(){
        cout << "Select numbers to order " << endl;
        for(int i=0;i<dishes.size();i++){
            if(dishes[i]->avail)
            cout << i << "----"<< dishes[i]->foodname << " " << dishes[i]->cost << " " << dishes[i]->preptime<< endl;
        }
    }
    Chef* chefavailable(){
        for(auto c: chefs){
            if(c->avail){
                c->avail = false;
                return c;
            }
        }
        return nullptr;
    }
    void addmenu(string f , int cost , int prep){
        dishes.push_back(new Menu(f,cost,prep));
    }
    void hirewaiter(int count){
        for(int i=0;i<count;i++){
            Waiters.push_back(new Waiter());
        }
    }
    void hirechef(int count){
        for(int i=0;i<count;i++){
            chefs.push_back(new Chef(i));
        }
    }
    Menu* menudata(int item){
        for(int i=0;i<dishes.size();i++){
            if(i == item){return dishes[i];}
        }
        return nullptr;
    }
    
    Waiter* allotwaiter(Customer* C){
        for(auto w:Waiters){
            if(w->avail){
                w->avail= false;
                w->c = C;
                w->re = this;
                return w;
            }
        }
        return nullptr;
    }
    ~Rest(){
        for(auto d: dishes){delete d;}
        for(auto w: Waiters){delete w;}
        for(auto c: chefs){delete c;}
    }
};
class Customer{
    public:
    int orderitems;
    Order* ordid;
    int customerid;
    Customer(int id):customerid(id),ordid(new Order()),orderitems(-1){}
    void Orderdish(Waiter* w){
        orderitems = 1;
        cout << "Ordered: " << orderitems-1 << endl;
        w->Takeorder(orderitems,ordid);
    }

};
int main(){
    Rest* R = new Rest();
    Customer* C= new Customer(1);
    //vector<orderdish> ord;
    cout << "Hi " << endl;
    R->addmenu("Rice",100,30);
    R->addmenu("Juice",50,10);
    R->hirewaiter(1);
    R->hirechef(1);

    Waiter* wait1 = R->allotwaiter(C);
    if(!wait1) cout << "waiters are busy ...." << endl;
    else{
        wait1->Display(R);
        C->Orderdish(wait1);
        
    }
    delete C;
    delete R;
    return 0;
}