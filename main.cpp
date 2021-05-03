#include <bits/stdc++.h>
using namespace std;

class Name {
    string name;

public:
    void get_name() {
        cout << name;
    }

    void put_name() {
        cin >> name;
    }
};

class Date {
    int dd;
    int mm;
    int yyyy;

public:
    void get_date() {
        cout << dd << ":" << mm << ":" << yyyy;
    }

    void put_date() {
        cin >> dd >> mm >> yyyy;
    }
};

class Room {
protected:
    string room_type;
    int no_of_beds;
    float rent;
    int room_no;
    int status;

public:
    Room() {}

    Room(string room_type,int no_of_beds,float rent,int room_no,int status) {
        this->room_type = room_type;
        this->no_of_beds = no_of_beds;
        this->rent = rent;
        this->room_no = room_no;
        this->status = status;
    }

    void set_room() {}

    bool is_vacant() {
        return !status;
    }

    void display_details(Room) {
        cout<<"\nRoom number : "<<room_no;
        cout<<"\nRoom type : "<<room_type;
        cout<<"\nNumber of beds : "<<no_of_beds;
        cout<<"\nRent : "<<rent;
        cout<<"\nStatus : ";
        if(status==0) cout<<"Vacant";
        else cout<<"Occupied";
    }

    void vacate_room(int) {
        status = 0;
    }

    void display_available(map <string,vector <int>> available) {
        for(auto itr : available){
            cout<<"For "<<itr.first<<" type the rooms available are : ";
            for(auto it : itr.second) cout<<it<<" ";
            cout<<"\n";
        }
    }
};

class Dish {
protected:
    string dish_name;
    float price;
    string dish_type;

public:
    Dish() {}

    Dish(string dish_name, float price, string dish_type) {
        this->dish_name = dish_name;
        this->price = price;
        this->dish_type = dish_type;
    }

    void get_dish() {
        cout<<dish_name<<" "<<price<<"\n";
    }
};

class Veg : public Dish{
public:
    void get_veg_food(string) {
        cout<<dish_name<<" "<<price<<"\n";
    }
};

class NonVeg : public Dish {
public:
    void get_non_veg_food(string) {
        cout<<dish_name<<" "<<price<<"\n";
    }
};

class Resturant{
protected:
    map <string,vector<Dish>> dishes;

public:
    void display_menu() {
        for(auto itr : dishes){
            cout<<itr.first<<"\n";
            for(auto it : itr.second) it.get_dish();
        }
    }

    void take_order() {

    }

    void add_dish() {
        string s;
        cout<<"\nEnter the dish type : ";
        cin>>s;
        string name;
        float price;
        cout<<"Enter the dish name : ";
        cin>>name;
        cout<<"Enter the price of the dish : ";
        cin>>price;
        Dish temp(name,price,s);
        dishes[s].push_back(temp);
    }
};

class Person {
protected:
    Name person_name;
    string person_addr;
    long int person_phone;
    string person_mail;
    Date person_dob;

public:
    Person(){}

    Person(Name person_name,string person_addr,long int person_phone,string person_mail,Date person_dob){
        this->person_name = person_name;
        this->person_addr = person_addr;
        this->person_mail = person_mail;
        this->person_phone = person_phone;
        this->person_dob = person_dob;
    }

    virtual void put_person() {}

    virtual void print_person() {
        cout<<"\nName : ";person_name.get_name();
        cout<<"\nDOB : ";person_dob.get_date();
        cout<<"\nPhone number : "<<person_phone;
        cout<<"\nPerson email id : "<<person_mail;
        cout<<"\nPerson address : "<<person_addr;
    }
};

class Employee : public Person{
protected:
    int emp_no;
    string role;

public:
    Employee() {}

    Employee(Name name,string addr,long int ph,string mail,Date d,int emp_no,string role):Person(name,addr,ph,mail,d) {
        this->emp_no = emp_no;
        this->role = role;
    }

    void put_person() {}

    void print_person() {
        cout<<"\nEmployee number : "<<emp_no;
        cout<<"\nRole : "<<role;
        cout<<"\nName : ";person_name.get_name();
        cout<<"\nDOB : ";person_dob.get_date();
        cout<<"\nPhone number : "<<person_phone;
        cout<<"\nPerson email id : "<<person_mail;
        cout<<"\nPerson address : "<<person_addr;
    }

    virtual void perform_duty() {}
};

class RoomServiceEmployee : public Employee{
public:
    RoomServiceEmployee() {}

    RoomServiceEmployee(Name name,string addr,long int ph,string mail,int emp_no,Date d,string role):Employee(name,addr,ph,mail,d,emp_no,role) {}

    void perform_duty() {}
};

class Chef : public Employee{
public:
    Chef() {}

    Chef(Name name,string addr,long int ph,string mail,int emp_no,Date d,string role):Employee(name,addr,ph,mail,d,emp_no,role) {}

    void perform_duty() {}
};

class Waiter : public Employee{
public:
    void perform_duty() {};
};

class LaundryEmployee : public RoomServiceEmployee{
public:
    void perform_duty() {}
};

class CleaningEmployee : public RoomServiceEmployee{
public:
    void perform_duty() {}
};

class Customer : public Person {
protected:
    string cust_id;
    string check_in_time;
    int status;

public:
    Customer() {}

    void set_data() {}

    int select_choice() {}

    void print_person() {}

    virtual void view_total_bill() {}

    virtual void allocate_rooms() {}

    virtual void check_out() {}
};

class RoomCustomer:public Customer {
protected:
    float room_bill;
    int book_status;
    Room room;
    vector<pair<string, float>> services_used;

public:
    void view_total_bill() {}

    void allocate_room() {}

    void print_person() {}

    void check_out() {}

    void room_service() {}
};

class ResturantCustomer : public Customer {
    int table_no;
    float dish_bill;
    int book_status;
    vector<pair<string, float>> food_ordered;

public:
    void view_total_bill() {}

    void allocate_table() {}

    void print_person() {}

    void check_out() {}

    void order_food() {}
};

class Hotel{
protected:
    string hotel_name;
    string hotel_address;
    vector <Employee> emp;
    vector <Room> rooms;
    map <string,vector<int>> vacant_room;
    map <string,vector<int>> occupied_rooms;
    vector <RoomCustomer> all_room_customers;
    vector <ResturantCustomer> all_resturant_customer;
    vector<int> vacant_tables;

public:
    Hotel() {}

    Hotel get_hotel() {}

    void generate_id() {}

    void set_hotel(Resturant,Room) {}

    void get_room() {}

    void display_available() {}

    void display_menu() {}

    void vacate_room() {}

    void ask_feed_back() {}

    void get_customer_data() {}

    void take_order() {}

    void add_employee() {}

    void remove_employee() {}
};


int main(){
    cout<<"hello there";

    return 0;
}