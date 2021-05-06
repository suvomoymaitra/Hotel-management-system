#include <bits/stdc++.h>
using namespace std;
long long int x=1;

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
    int room_no;

public:
    float rent;

    int status;

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
    string dish_type;

public:
    float price;

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
public:
    map <string,vector<Dish>> dishes;

    void display_menu() {
        cout<<"\n-----------------------------------------Menu---------------------------------------------------------";
        cout<<"\n------------------------------------------------------------------------------------------------------";
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

    virtual void put_person() {
        cout<<"\nName : ";
        person_name.put_name();
        cout<<"\nDOB : ";
        person_dob.put_date();
        cout<<"\nPhone number : ";
        cin>>person_phone;
        cout<<"\nPerson email id : ";
        cin>>person_mail;
        cout<<"\nPerson address : ";
        cin>>person_addr;
    }

    virtual void print_person() {
        cout<<"\nName : ";
        person_name.get_name();
        cout<<"\nDOB : ";
        person_dob.get_date();
        cout<<"\nPhone number : "<<person_phone;
        cout<<"\nPerson email id : "<<person_mail;
        cout<<"\nPerson address : "<<person_addr;
    }
};

/// Customer classes
///---------------------------------------------------------------------------------------------------------------------


class Customer : public Person {
protected:
    string cust_id;
    string check_in_time;
    int status;

public:
    Customer() {}

    void set_data() {
        put_person();
        cout<<"Enter check in time : ";
        cin>>check_in_time;
        status = 1;
        cust_id = to_string(x);
        x++;
    }

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
    int number_of_days;

public:
    vector<pair<string, float>> services_used;

    void view_total_bill() {
        float total=0;
        cout<<"Printing the bill of the customer : ";
        services_used.push_back(make_pair("Room rent",number_of_days*room.rent));
        for(int i=0;i<services_used.size();i++){
            cout<<i+1<<":"<<services_used[i].first<<"---->"<<services_used[i].second<<"\n";
            total+=services_used[i].second;
        }
        room_bill = total;
        cout<<"Total bill of the customer is :"<<total;
        cout<<"\n\n\nThank you!!!!\n\n";
        cout<<"Please visit again!!!!\n";
    }

    void allocate_room(map <string,vector<int>> &vacant_room,map <string,vector<int>> &occupied_rooms,vector<Room> rooms) {
        string s;
        cout<<"\nEnter the type of room you want : ";
        cin>>s;
        int room_no = vacant_room[s][vacant_room[s].size()-1];
        vacant_room[s].pop_back();
        occupied_rooms[s].push_back(room_no);
        room = rooms[room_no];
        room.status = 1;
    }

    void print_person() {
        cout<<"\nName : ";
        person_name.get_name();
        cout<<"\nDOB : ";
        person_dob.get_date();
        cout<<"\nPhone number : "<<person_phone;
        cout<<"\nPerson email id : "<<person_mail;
        cout<<"\nPerson address : "<<person_addr;
        cout<<"\nCustomer id : "<<cust_id;
        cout<<"\nCheck in time : "<<check_in_time;
        cout<<"\nCurrent status : ";
        if(status==0) cout<<"Inactive";
        else cout<<"Active";
        cout<<"\nNumber of days stayed : "<<number_of_days;
        cout<<"\nTotal bill : "<<room_bill;
        room.display_details(room);
    }

    void check_out() {
        cout<<"\nEnter the number of days stayed : ";
        cin>>number_of_days;
        view_total_bill();
        status=0;
        book_status = 0;
    }

    void room_service() {}
};

class ResturantCustomer : public Customer {
    int table_no;
    float dish_bill;
    int book_status;

public:
    vector<pair<string, float>> food_ordered;

    void view_total_bill() {
        float total=0;
        cout<<"Printing the bill of the customer : ";
        for(int i=0;i<food_ordered.size();i++){
            cout<<i+1<<":"<<food_ordered[i].first<<"---->"<<food_ordered[i].second<<"\n";
            total+=food_ordered[i].second;
        }
        dish_bill = total;
        cout<<"Total bill of the customer is :"<<total;
        cout<<"\n\n\nThank you!!!!\n\n";
        cout<<"Please visit again!!!!\n";
    }

    void allocate_table(vector<int> vacant, vector<int> occupied) {
        set_data();
        cout<<"Your table number is : "<<vacant[vacant.size()-1];;
        occupied.push_back(vacant[vacant.size()-1]);
        table_no = occupied[occupied.size()-1];
        vacant.pop_back();
        book_status = 1;
    }

    void print_person() {}

    void check_out() {
        view_total_bill();
        status=0;
        book_status = 0;
    }

    void order_food() {}
};


///Employee classes
///---------------------------------------------------------------------------------------------------------------------

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

    virtual void perform_duty(RoomCustomer &R) {
        cout<<"1 : order food\n";
        Resturant temp;
        string s,type;
        int qty;
        temp.display_menu();
        cout<<"\nEnter the names of the foods you want to order : ";
        while(s!="exit"){
            cout<<"Enter the type : ";
            cin>>type;
            cout<<"Enter the food name : ";
            cin>>s;
            cout<<"Enter quantity : ";
            cin>>qty;
            R.services_used.push_back(make_pair("Room service Food : "+s,qty*find(temp.dishes[type].begin(),temp.dishes[type].end(),s)->price));
        }
    }
};

class Chef : public Employee{
public:
    Chef() {}

    Chef(Name name,string addr,long int ph,string mail,int emp_no,Date d,string role):Employee(name,addr,ph,mail,d,emp_no,role) {}

    void perform_duty(RoomCustomer &R) {}
};

class Waiter : public Employee{
public:
    void perform_duty(ResturantCustomer &R) {
        cout<<"1 : order food\n";
        cout<<"2 : Check out\n";
        Resturant temp;
        string s,type;
        int qty;
        int ch=0;
        cin>>ch;
        switch(ch){
            case 1:
                temp.display_menu();
                cout<<"\nEnter the names of the foods you want to order : ";
                while(s!="exit"){
                    cout<<"Enter the type : ";
                    cin>>type;
                    cout<<"Enter the food name : ";
                    cin>>s;
                    cout<<"Enter quantity : ";
                    cin>>qty;
                    R.food_ordered.push_back(make_pair(s,qty*find(temp.dishes[type].begin(),temp.dishes[type].end(),s)->price));
                }
                break;
            case 2:
                R.check_out();
        }
    }
};

class LaundryEmployee : public RoomServiceEmployee{
public:
    void perform_duty(RoomCustomer &R) {

    }
};

class CleaningEmployee : public RoomServiceEmployee{
public:
    void perform_duty(RoomCustomer &R) {

    }
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
    vector <RoomCustomer> all_room_customers_inactive;
    vector <ResturantCustomer> all_resturant_customer;
    vector <ResturantCustomer> all_resturant_customer_inactive;
    vector<int> vacant_tables;
    vector<int> occupied_tables;

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

    void employee_login(){}
};

int main(){

    return 0;
}