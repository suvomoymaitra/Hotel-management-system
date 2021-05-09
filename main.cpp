#include <bits/stdc++.h>
using namespace std;

long long int x = 1;
long long int y = 1;

class Name {
    string name;

public:
    void get_name() {
        cout << name;
    }

    string name_val() {
        return name;
    }

    void put_name() {
        cin >> name;
    }

    void set_name(string s) {
        name = s;
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

    void set_date(int d, int m, int yy) {
        dd = d;
        mm = m;
        yyyy = yy;
    }
};

class Room {
protected:
    int no_of_beds;
    int room_no;

public:
    string room_type;
    float rent;
    int status;

    Room() {}

    Room(string room_type, int no_of_beds, float rent, int room_no, int status) {
        this->room_type = room_type;
        this->no_of_beds = no_of_beds;
        this->rent = rent;
        this->room_no = room_no;
        this->status = status;
    }

    int get_room_no() {
        return room_no;
    }

    void set_room() {
        status = 1;
    }

    bool is_vacant() {
        return !status;
    }

    void display_details(Room) {
        cout << "\nRoom number : " << room_no;
        cout << "\nRoom type : " << room_type;
        cout << "\nNumber of beds : " << no_of_beds;
        cout << "\nRent : " << rent;
        cout << "\nStatus : ";
        if (status == 0) cout << "Vacant";
        else cout << "Occupied";
    }

    void vacate_room() {
        status = 0;
    }

    void display_available(map<string, vector<int>> available) {
        for (auto itr : available) {
            cout << "For " << itr.first << " type the rooms available are : ";
            for (auto it : itr.second) cout << it << " ";
            cout << "\n";
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
        cout << dish_name << " " << price << "\n";
    }

    string get_dish_name() {
        return dish_name;
    }
};

class Veg : public Dish {
public:
    void get_veg_food(string) {
        cout << dish_name << " " << price << "\n";
    }
};

class NonVeg : public Dish {
public:
    void get_non_veg_food(string) {
        cout << dish_name << " " << price << "\n";
    }
};

class Resturant {
public:
    map<string, vector<Dish>> dishes;

    void display_menu() {
        cout
                << "\n-----------------------------------------Menu---------------------------------------------------------";
        cout
                << "\n------------------------------------------------------------------------------------------------------\n";
        for (auto itr : dishes) {
            cout << itr.first << ":\n";
            for (int i = 0; i < itr.first.size(); i++) cout << "-";
            cout << "\n";
            for (auto it : itr.second) it.get_dish();
            cout << "\n";
        }
    }

    void add_dish_ctime(string type, string name, float price) {
        Dish temp(name, price, type);
        dishes[type].push_back(temp);
    }

    void add_dish() {
        string s;
        cout << "\nEnter the dish type : ";
        cin >> s;
        string name;
        float price;
        cout << "Enter the dish name : ";
        cin >> name;
        cout << "Enter the price of the dish : ";
        cin >> price;
        Dish temp(name, price, s);
        dishes[s].push_back(temp);
    }
};

class Person {
protected:
    Name person_name;
    string person_addr;
    long long int person_phone;
    string person_mail;
    Date person_dob;

public:
    Person() {}

    Person(Name person_name, string person_addr, long int person_phone, string person_mail, Date person_dob) {
        this->person_name = person_name;
        this->person_addr = person_addr;
        this->person_mail = person_mail;
        this->person_phone = person_phone;
        this->person_dob = person_dob;
    }

    virtual void put_person() {
        cout << "\nName : ";
        person_name.put_name();
        cout << "\nDOB : ";
        person_dob.put_date();
        cout << "\nPhone number : ";
        cin >> person_phone;
        cout << "\nPerson email id : ";
        cin >> person_mail;
        cout << "\nPerson address : ";
        cin >> person_addr;
    }

    string get_mail() {
        return person_mail;
    }

    long long int get_phone() {
        return person_phone;
    }

    Name get_name() {
        return person_name;
    }

    virtual void print_person() {
        cout << "\nName : ";
        person_name.get_name();
        cout << "\nDOB : ";
        person_dob.get_date();
        cout << "\nPhone number : " << person_phone;
        cout << "\nPerson email id : " << person_mail;
        cout << "\nPerson address : " << person_addr;
    }
};


/// Customer classes
///---------------------------------------------------------------------------------------------------------------------


class Customer : public Person {
protected:
    string cust_id;
    string check_in_time;

public:
    int status;

    Customer() {}

    void set_data() {
        put_person();
        cout << "Enter check in time : ";
        cin >> check_in_time;
        status = 1;
        cust_id = to_string(x);
        x++;
    }

    string get_cust_id() {
        return cust_id;
    }

    void print_person() {}

    virtual void view_total_bill() {}

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
        float total = 0;
        cout << "\nPrinting the bill of the customer : \n";
        services_used.push_back(make_pair("Room rent", number_of_days * room.rent));
        for (int i = 0; i < services_used.size(); i++) {
            cout << i + 1 << ":" << services_used[i].first << "---->" << services_used[i].second << "\n";
            total += services_used[i].second;
        }
        room_bill = total;
        cout << "Total bill of the customer is :" << total;
        cout << "\n\n\nThank you!!!!\n\n";
        cout << "Please visit again!!!!\n";
    }

    void
    allocate_room(map<string, vector<int>> &vacant_room, map<string, vector<int>> &occupied_rooms, vector<Room> rooms) {
        for (auto itr:vacant_room) {
            cout << itr.first << " " << itr.second.size() << "\n";
        }
        char s[200];
        cout << "\nEnter the type of room you want : ";
        cin >> s;
        if (vacant_room[s].size() == 0) {
            cout << "\nEnter valid room type";
            return;
        }
        int room_no = vacant_room[s][vacant_room[s].size() - 1];
        room_no = vacant_room[s].back();
        vacant_room[s].pop_back();
        occupied_rooms[s].push_back(room_no);
        room = rooms[room_no];
        room.status = 1;
        room_bill = 0;
        number_of_days = 0;
        cout << "\nYour customer id is :" << cust_id;
    }

    void print_person() {
        cout << "\nName : ";
        person_name.get_name();
        cout << "\nDOB : ";
        person_dob.get_date();
        cout << "\nPhone number : " << person_phone;
        cout << "\nPerson email id : " << person_mail;
        cout << "\nPerson address : " << person_addr;
        cout << "\nCustomer id : " << cust_id;
        cout << "\nCheck in time : " << check_in_time;
        cout << "\nCurrent status : ";
        if (status == 0) cout << "Inactive";
        else cout << "Active";
        cout << "\nNumber of days stayed : " << number_of_days;
        cout << "\nTotal bill : " << room_bill;
        room.display_details(room);
    }

    Room get_room() {
        return room;
    }

    void check_out() {
        if (status == 0) {
            cout << "Customer inactive";
            return;
        }
        cout << "\nEnter the number of days stayed : ";
        cin >> number_of_days;
        view_total_bill();
        status = 0;
        book_status = 0;
    }
};

class ResturantCustomer : public Customer {
    int table_no;
    float dish_bill;
    int book_status;

public:
    vector<pair<string, float>> food_ordered;

    void view_total_bill() {
        float total = 0;
        cout << "\nPrinting the bill of the customer : \n";
        for (int i = 0; i < food_ordered.size(); i++) {
            cout << i + 1 << ":" << food_ordered[i].first << "---->" << food_ordered[i].second << "\n";
            total += food_ordered[i].second;
        }
        dish_bill = total;
        cout << "Total bill of the customer is :" << total;
        cout << "\n\n\nThank you!!!!\n\n";
        cout << "Please visit again!!!!\n";
    }

    int get_table_no() {
        return table_no;
    }

    void allocate_table(vector<int> &vacant, vector<int> &occupied) {
        set_data();
        cout << "Your table number is : " << vacant[vacant.size() - 1];
        occupied.push_back(vacant[vacant.size() - 1]);
        table_no = occupied[occupied.size() - 1];
        vacant.pop_back();
        book_status = 1;
        dish_bill = 0;
        cout << "\nYour customer id is :" << cust_id;
    }

    void print_person() {
        cout << "\nName : ";
        person_name.get_name();
        cout << "\nDOB : ";
        person_dob.get_date();
        cout << "\nPhone number : " << person_phone;
        cout << "\nPerson email id : " << person_mail;
        cout << "\nPerson address : " << person_addr;
        cout << "\nCustomer id : " << cust_id;
        cout << "\nCheck in time : " << check_in_time;
        cout << "\nCurrent status : ";
        if (status == 0) cout << "Inactive";
        else cout << "Active";
        cout << "\nTotal bill : " << dish_bill;
    }

    void check_out() {
        view_total_bill();
        status = 0;
        book_status = 0;
    }
};



///Employee classes
///---------------------------------------------------------------------------------------------------------------------

class Employee : public Person {
protected:
    long long int emp_no;
    string role;

public:
    Employee() {}

    Employee(Name name, string addr, long long int ph, string mail, Date d, long long int emp_no, string role) : Person(
            name, addr, ph, mail, d) {
        this->emp_no = emp_no;
        this->role = role;
    }

    void put_person() {}

    void print_person() {
        cout << "\nEmployee number : " << emp_no;
        cout << "\nRole : " << role;
        cout << "\nName : ";
        person_name.get_name();
        cout << "\nDOB : ";
        person_dob.get_date();
        cout << "\nPhone number : " << person_phone;
        cout << "\nPerson email id : " << person_mail;
        cout << "\nPerson address : " << person_addr;
    }

    long long int get_emp_id() {
        return emp_no;
    }

    virtual void perform_duty() {}
};

class RoomServiceEmployee : public Employee {
public:
    RoomServiceEmployee() {}

    RoomServiceEmployee(Name name, string addr, long int ph, string mail, long long int emp_no, Date d, string role)
            : Employee(name, addr, ph, mail, d, emp_no, role) {}

    virtual void perform_duty(RoomCustomer &R) {}
};

class Chef : public RoomServiceEmployee {
public:
    Chef() {}

    Chef(Name name, string addr, long int ph, string mail, long long int emp_no, Date d, string role)
            : RoomServiceEmployee(name, addr, ph, mail, emp_no, d, role) {}

    void perform_duty(RoomCustomer &R, Resturant temp) {
        cout << "\n-----------------------------------------------------------------\n";
        cout << "1 : order food\n";
        string s, type;
        int qty;
        temp.display_menu();
        cout << "\nEnter the names of the foods you want to order : ";
        while (s != "exit") {
            cout << "\nEnter the type : ";
            cin >> type;
            if (type == "exit" || type == "EXIT") return;
            cout << "\nEnter the food name : ";
            cin >> s;
            cout << "\nEnter quantity : ";
            cin >> qty;
            auto itr = temp.dishes[type].begin();
            for (; itr != temp.dishes[type].end(); itr++)
                if (s == itr->get_dish_name())
                    break;
            if (itr == temp.dishes[type].end()) cout << "\nEnter valid data";
            else R.services_used.push_back(make_pair("Room service Food : " + s, qty * itr->price));
//            R.services_used.push_back(make_pair("Room service Food : "+s,qty*(find(temp.dishes[type].begin(),temp.dishes[type].end(),s)->price)));
        }
    }
};

class Waiter : public Employee {
public:
    Waiter() {}

    Waiter(Name name, string addr, long int ph, string mail, long long int emp_no, Date d, string role) : Employee(name,
                                                                                                                   addr,
                                                                                                                   ph,
                                                                                                                   mail,
                                                                                                                   d,
                                                                                                                   emp_no,
                                                                                                                   role) {}

    void perform_duty(ResturantCustomer &R, Resturant temp) {
        cout << "\n-----------------------------------------------------------------\n";
        cout << "1 : order food\n";
        cout << "2 : Check out\n";
        string s, type;
        int qty;
        int ch = 0;
        cin >> ch;
        if (ch == 1) {
            temp.display_menu();
            cout << "\nEnter the names of the foods you want to order : ";
            while (s != "exit") {
                cout << "Enter the type : ";
                cin >> type;
                if (type == "exit" || type == "EXIT") return;
                cout << "Enter the food name : ";
                cin >> s;
                cout << "Enter quantity : ";
                cin >> qty;
                auto itr = temp.dishes[type].begin();
                for (; itr != temp.dishes[type].end(); itr++)
                    if (s == itr->get_dish_name())
                        break;
                if (itr == temp.dishes[type].end()) cout << "\nEnter valid data";
                else R.food_ordered.push_back(make_pair(s, qty * itr->price));
            }
        } else {
            R.check_out();
        }
    }
};

class LaundryEmployee : public RoomServiceEmployee {
public:
    LaundryEmployee() {}

    LaundryEmployee(Name name, string addr, long int ph, string mail, long long int emp_no, Date d, string role)
            : RoomServiceEmployee(name, addr, ph, mail, emp_no, d, role) {}

    void perform_duty(RoomCustomer &R) {
        cout << "Enter the number of clothes : ";
        int qty;
        cin >> qty;
        R.services_used.push_back(make_pair("Laundry service : ", qty * 900));
    }
};

class CleaningEmployee : public RoomServiceEmployee {
public:
    CleaningEmployee() {}

    CleaningEmployee(Name name, string addr, long int ph, string mail, long long int emp_no, Date d, string role)
            : RoomServiceEmployee(name, addr, ph, mail, emp_no, d, role) {}

    void perform_duty(RoomCustomer &R) {
        R.services_used.push_back(make_pair("Room cleaning service : ", 2300));
    }
};

class Hotel {
protected:
    string hotel_name;
    string hotel_address;
    vector<Chef> chefs;
    vector<Waiter> waiters;
    vector<LaundryEmployee> laundry_employees;
    vector<CleaningEmployee> cleaning_employees;
    vector<Chef> chefs_inactive;
    vector<Waiter> waiters_inactive;
    vector<LaundryEmployee> laundry_employees_inactive;
    vector<CleaningEmployee> cleaning_employees_inactive;
    vector<Room> rooms;
    Resturant R;
    map<string, vector<int>> vacant_room;
    map<string, vector<int>> occupied_rooms;
    vector<RoomCustomer> all_room_customers;
    vector<RoomCustomer> all_room_customers_inactive;
    vector<ResturantCustomer> all_resturant_customer;
    vector<ResturantCustomer> all_resturant_customer_inactive;
    vector<int> vacant_tables;
    vector<int> occupied_tables;
    vector<string> feedbacks;

public:
    Hotel() {}

    void generate_id() {}

    void set_hotel(Resturant tmp) {
        hotel_name = "greedy_dp_hotel";
        hotel_address = "jhfsdgvjsfdhgskdcsh,dcgds,hvdf,hvdffh";
        R = tmp;
        for (int i = 1; i <= 100; i++) vacant_tables.push_back(i);
        int i = 0;
        for (; i < 30; i++) {
            Room r("Single", 1, 1500, i, 0);
            rooms.push_back(r);
            vacant_room["Single"].push_back(i);
        }
        for (; i < 60; i++) {
            Room r("Double", 2, 2000, i, 0);
            rooms.push_back(r);
            vacant_room["Double"].push_back(i);
        }
        for (; i < 90; i++) {
            Room r("Triple", 3, 3000, i, 0);
            rooms.push_back(r);
            vacant_room["Triple"].push_back(i);
        }
        for (; i < 120; i++) {
            Room r("Quad", 4, 4500, i, 0);
            rooms.push_back(r);
            vacant_room["Quad"].push_back(i);
        }
        for (; i < 150; i++) {
            Room r("Deluxe", 1, 4800, i, 0);
            rooms.push_back(r);
            vacant_room["Deluxe"].push_back(i);
        }
    }

    void get_room() {
        cout << "\nEnter the person details : ";
        RoomCustomer tmp;
        tmp.set_data();
        tmp.allocate_room(vacant_room, occupied_rooms, rooms);
        all_room_customers.push_back(tmp);
    }

    void get_table() {
        cout << "\nEnter the person details : ";
        ResturantCustomer tmp;
        tmp.set_data();
        tmp.allocate_table(vacant_tables, occupied_tables);
        all_resturant_customer.push_back(tmp);
    }

    void room_customer_check_out() {
        cout << "Enter the customer id : ";
        string id;
        Room temp;
        cin >> id;
        for (auto itr : all_room_customers) {
            if (id == itr.get_cust_id()) {
                itr.check_out();
                temp = itr.get_room();
                break;
            }
        }
        vacant_room[temp.room_type].push_back(temp.get_room_no());
        auto itr1 = occupied_rooms[temp.room_type].begin();
        auto itr2 = occupied_rooms[temp.room_type].end();
        occupied_rooms[temp.room_type].erase(find(itr1, itr2, temp.get_room_no()));
        ask_feed_back();
    }

    void resturant_customer_check_out() {
        cout << "Enter the customer id : ";
        string id;
        int temp;
        cin >> id;
        for (auto itr : all_resturant_customer) {
            if (id == itr.get_cust_id()) {
                itr.check_out();
                temp = itr.get_table_no();
                break;
            }
        }
        vacant_tables.push_back(temp);
        auto itr1 = occupied_tables.begin();
        auto itr2 = occupied_tables.end();
        occupied_tables.erase(find(itr1, itr2, temp));
        ask_feed_back();
    }

    bool display_owner_menu() {
        cout << "\n\n";
        cout << "\n1. Add employee";
        cout << "\n2. Remove employee";
        cout << "\n3. Get a customer data";
        cout << "\nAny other number to go out of owner menu";
        cout << "\nEnter your choice : ";
        int choice;
        cin >> choice;
        if (choice == 1) {
            add_employee();
            return true;
        } else if (choice == 2) {
            remove_employee();
            return true;
        } else if (choice == 3) {
            get_customer_data();
            return true;
        } else return false;
    }

    void display_employee_menu() {
        employee_login();
    }

    void vacate_room() {
        room_customer_check_out();
    }

    void ask_feed_back() {
        string s;
        cout << "\nEnter your feedback : ";
        cin >> s;
        feedbacks.push_back(s);
    }

    void add_dish() {
        R.add_dish();
    }

    void get_customer_data() {
        cout << "\nSearch customer by : ";
        cout << "\n1. customer id";
        cout << "\n2. customer phone number";
        cout << "\n3. customer email id";
        cout << "\n4. customer name";
        int choice;
        cin >> choice;
        if (choice == 1) {
            string id;
            cout << "\nEnter the customer id : ";
            cin >> id;
            int flag = 0;
            for (auto itr:all_room_customers) {
                if (itr.get_cust_id() == id) {
                    cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                for (auto itr:all_resturant_customer) {
                    if (itr.get_cust_id() == id) {
                        cout << "\nCustomer found";
                        itr.print_person();
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 0) cout << "\nNo customer with given id found";
        } else if (choice == 2) {
            long long int ph;
            cout << "\nEnter the phone number to be searched : ";
            cin >> ph;
            int flag = 0;
            for (auto itr:all_room_customers) {
                if (itr.get_phone() == ph) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            for (auto itr:all_resturant_customer) {
                if (itr.get_phone() == ph) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nNo customer with given phone number found";
        } else if (choice == 3) {
            string m;
            cout << "\nEnter the email id to be searched : ";
            cin >> m;
            int flag = 0;
            for (auto itr:all_room_customers) {
                if (itr.get_mail() == m) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            for (auto itr:all_resturant_customer) {
                if (itr.get_mail() == m) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nNo customer with given email id found";
        } else {
            string n;
            cout << "\nEnter the name to be searched : ";
            cin >> n;
            int flag = 0;
            for (auto itr:all_room_customers) {
                if (itr.get_name().name_val() == n) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            for (auto itr:all_resturant_customer) {
                if (itr.get_name().name_val() == n) {
                    if (!flag)
                        cout << "\nCustomer found";
                    itr.print_person();
                    flag = 1;
                    cout << "\n------------------------------------------------------\n";
                }
            }
            if (flag == 0) cout << "\nNo customer with given name found";
        }
    }

    void add_employee() {
        cout << "\nEnter the role of the employee : ";
        cout << "\n1. Waiter";
        cout << "\n2. Chef";
        cout << "\n3. Laundry employee";
        cout << "\n4. Room cleaning employee";
        int choice;
        cin >> choice;
        cout << "\nEnter details of the employee : ";
        Name name;
        string addr;
        long long int ph;
        string mail;
        long long int emp_no;
        Date dob;
        string role;
        cout << "\nName : ";
        name.put_name();
        cout << "Address : ";
        cin >> addr;
        cout << "phone number : ";
        cin >> ph;
        cout << "Email id : ";
        cin >> mail;
        emp_no = y++;
        cout << "DOB : ";
        dob.put_date();
        cout << "\n---------------------------------------------------------------------------------------------";
        cout << "\nEmployee added sucessfully";
        if (choice == 1) {
            role = "Waiter";
            Waiter w(name, addr, ph, mail, emp_no, dob, role);
            waiters.push_back(w);
            w.print_person();
        } else if (choice == 2) {
            role = "Chef";
            Chef c(name, addr, ph, mail, emp_no, dob, role);
            chefs.push_back(c);
            c.print_person();
        } else if (choice == 3) {
            role = "Laundry employee";
            LaundryEmployee l(name, addr, ph, mail, emp_no, dob, role);
            laundry_employees.push_back(l);
            l.print_person();
        } else {
            role = "Cleaning employee";
            CleaningEmployee c(name, addr, ph, mail, emp_no, dob, role);
            cleaning_employees.push_back(c);
            c.print_person();
        }
    }

    void add_chef(Name name, string addr, long long int ph, string mail, long long int emp_no, Date dob, string role) {
        Chef c(name, addr, ph, mail, emp_no, dob, role);
        chefs.push_back(c);
    }

    void
    add_waiter(Name name, string addr, long long int ph, string mail, long long int emp_no, Date dob, string role) {
        Waiter w(name, addr, ph, mail, emp_no, dob, role);
        waiters.push_back(w);
    }

    void add_room_cleaning(Name name, string addr, long long int ph, string mail, long long int emp_no, Date dob,
                           string role) {
        CleaningEmployee c(name, addr, ph, mail, emp_no, dob, role);
        cleaning_employees.push_back(c);
    }

    void
    add_laundry(Name name, string addr, long long int ph, string mail, long long int emp_no, Date dob, string role) {
        LaundryEmployee l(name, addr, ph, mail, emp_no, dob, role);
        laundry_employees.push_back(l);
    }

    void remove_employee() {
        int choice;
        long long int emp_id;
        int flag = 0;
        cout << "\nEnter the role of the employee : ";
        cout << "\n1. Chef";
        cout << "\n2. Waiter";
        cout << "\n3. Laundry employee";
        cout << "\n4. Cleaning employee";
        cin >> choice;
        cout << "\nEnter the employee id of the employee : ";
        cin >> emp_id;
        if (choice == 1) {
            auto itr = chefs.begin();
            for (; itr != chefs.end(); itr++) {
                if (itr->get_emp_id() == emp_id) break;
            }
            if (itr == chefs.end()) {
                cout << "No employee found with given employee id";
            } else {
                chefs_inactive.push_back(*itr);
                chefs.erase(itr);
            }
        } else if (choice == 2) {
            auto itr = waiters.begin();
            for (; itr != waiters.end(); itr++) {
                if (itr->get_emp_id() == emp_id) break;
            }
            if (itr == waiters.end()) {
                cout << "No employee found with given employee id";
            } else {
                waiters_inactive.push_back(*itr);
                waiters.erase(itr);
            }
        } else if (choice == 3) {
            auto itr = laundry_employees.begin();
            for (; itr != laundry_employees.end(); itr++) {
                if (itr->get_emp_id() == emp_id) break;
            }
            if (itr == laundry_employees.end()) {
                cout << "No employee found with given employee id";
            } else {
                laundry_employees_inactive.push_back(*itr);
                laundry_employees.erase(itr);
            }
        } else {
            auto itr = cleaning_employees.begin();
            for (; itr != cleaning_employees.end(); itr++) {
                if (itr->get_emp_id() == emp_id) break;
            }
            if (itr == cleaning_employees.end()) {
                cout << "No employee found with given employee id";
            } else {
                cleaning_employees_inactive.push_back(*itr);
                cleaning_employees.erase(itr);
            }
        }
    }

    bool employee_login() {
        long long int id;
        cout << "\n-----------------------------------------------------------------\n";
        cout << "\nEnter your employee id : ";
        cin >> id;
        int flag = 0;
        for (auto itr:chefs) {
            if (itr.get_emp_id() == id) {
                flag = 1;
                while (1) {
                    int no;
                    cout << "\nEnter the customer number (-1 to exit) : ";
                    cin >> no;
                    if (no == -1) return false;
                    if (all_room_customers[no].status == 0) {
                        cout << "\nEnter valid customer number\n";
                    } else {
                        int j = 0;
                        for (auto it:all_room_customers) {
                            if (it.get_cust_id() == to_string(no)) break;
                            j++;
                        }
                        itr.perform_duty(all_room_customers[j], R);
                    }
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag) {
            for (auto itr:waiters) {
                if (itr.get_emp_id() == id) {
                    flag = 1;
                    while (1) {
                        int no;
                        cout << "Enter the customer number (-1 to exit): ";
                        cin >> no;
                        return false;
                        if (all_resturant_customer[no].status == 0) {
                            cout << "Enter valid customer number";
                        } else {
                            int j = 0;
                            for (auto it:all_resturant_customer) {
                                if (it.get_cust_id() == to_string(no)) break;
                                j++;
                            }
                            itr.perform_duty(all_resturant_customer[j], R);
                        }
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            for (auto itr:laundry_employees) {
                if (itr.get_emp_id() == id) {
                    flag = 1;
                    while (1) {
                        int no;
                        cout << "Enter the customer number (-1 to exit): ";
                        cin >> no;
                        return false;
                        if (all_room_customers[no].status == 0) {
                            cout << "Enter valid customer number";
                        } else {
                            int j = 0;
                            for (auto it:all_room_customers) {
                                if (it.get_cust_id() == to_string(no)) break;
                                j++;
                            }
                            itr.perform_duty(all_room_customers[j]);
                        }
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            for (auto itr:cleaning_employees) {
                if (itr.get_emp_id() == id) {
                    flag = 1;
                    while (1) {
                        int no;
                        cout << "Enter the customer number (-1 to exit): ";
                        cin >> no;
                        return false;
                        if (all_room_customers[no].status == 0) {
                            cout << "Enter valid customer number";
                        } else {
                            int j = 0;
                            for (auto it:all_room_customers) {
                                if (it.get_cust_id() == to_string(no)) break;
                                j++;
                            }
                            itr.perform_duty(all_room_customers[j]);
                        }
                        flag = 1;
                        break;
                    }
                }
            }
        }
        return true;
    }

    bool receptionist() {
        int choice;
        cout << "\n1.Room check in";
        cout << "\n2.Room check out";
        cout << "\n3.Resturant check in";
        cout << "\n4.Resturant check out";
        cout << "\nAny other number to exit";
        cout << "\nEnter your choice :";
        cin >> choice;
        if (choice == 1) {
            get_room();
            return true;
        } else if (choice == 2) {
            room_customer_check_out();
            return true;
        } else if (choice == 3) {
            get_table();
            return true;
        } else if (choice == 4) {
            resturant_customer_check_out();
            return true;
        } else return false;
    }
};

class invalid_password{};

int main() {

    ///--------------------------------------------Resturant------------------------------------------------------------

    Resturant R;
    /// All time favourites
    R.add_dish_ctime("All_time_favourites", "French_fries", 106);
    R.add_dish_ctime("All_time_favourites", "Chilli_cheese_toast", 115);
    R.add_dish_ctime("All_time_favourites", "Chilli_cheese_garlic_toast", 115);
    R.add_dish_ctime("All_time_favourites", "Garlic_bread", 98);
    R.add_dish_ctime("All_time_favourites", "Garlic_bread_with_cheese", 119);

    /// Sandwich
    R.add_dish_ctime("Sandwich", "Plain_sandwich", 175);
    R.add_dish_ctime("Sandwich", "Grilled_sandwich", 175);
    R.add_dish_ctime("Sandwich", "Club_sandwich", 175);

    /// South Indian
    R.add_dish_ctime("South_Indian", "Rice_idli", 50);
    R.add_dish_ctime("South_Indian", "Sambhar_vada", 55);
    R.add_dish_ctime("South_Indian", "Dahi_vada", 45);

    /// Dosas
    R.add_dish_ctime("Dosa", "Plain_dosa(Butter)", 125);
    R.add_dish_ctime("Dosa", "Onion_dosa(Butter)", 136);
    R.add_dish_ctime("Dosa", "Paper_dosa", 130);
    R.add_dish_ctime("Dosa", "Mysore_dosa", 123);
    R.add_dish_ctime("Dosa", "Rawa_dosa", 119);
    R.add_dish_ctime("Dosa", "Onion_rawa_dosa", 136);
    R.add_dish_ctime("Dosa", "Masala_dosa(Butter)", 136);

    /// Pizza
    R.add_dish_ctime("Pizza", "Plain_cheese_pizza", 190);
    R.add_dish_ctime("Pizza", "Capsicum_onion_pizza", 210);
    R.add_dish_ctime("Pizza", "Tomato_onion_pizza", 210);
    R.add_dish_ctime("Pizza", "Capsicum_onion_mushroom_pizza", 250);
    R.add_dish_ctime("Pizza", "Jain_special_pizza", 250);
    R.add_dish_ctime("Pizza", "Tandoori_pizza", 250);
    R.add_dish_ctime("Pizza", "Super_veggie_pizza", 265);

    /// Soups
    R.add_dish_ctime("Soup", "Hot_&_soup", 109);
    R.add_dish_ctime("Soup", "Lemon_&_coriander", 109);
    R.add_dish_ctime("Soup", "Veg_noodle_soup", 109);
    R.add_dish_ctime("Soup", "Sweet_corn", 109);
    R.add_dish_ctime("Soup", "Veg_munchow", 109);
    R.add_dish_ctime("Soup", "Veg_clear_soup", 109);

    /// Starters
    R.add_dish_ctime("Starters", "Spring_roll", 145);
    R.add_dish_ctime("Starters", "Chilly_paneer_dry", 195);
    R.add_dish_ctime("Starters", "Veg_manchurian_dry", 153);
    R.add_dish_ctime("Starters", "Potatoes_in_honey_&_chilly", 175);
    R.add_dish_ctime("Starters", "Fired_vegetables_in_salt_&_pepper", 190);
    R.add_dish_ctime("Starters", "Crispy_spinach_&_baby_corn", 198);
    R.add_dish_ctime("Starters", "Chilly_mushroom_dry", 193);

    /// Main course
    R.add_dish_ctime("Main_course", "Sahi_paneer", 210);
    R.add_dish_ctime("Main_course", "Kadhai_paneer", 210);
    R.add_dish_ctime("Main_course", "Paneer_butter_masala", 210);
    R.add_dish_ctime("Main_course", "Mushroom_masala", 215);
    R.add_dish_ctime("Main_course", "Malai_kofta", 210);
    R.add_dish_ctime("Main_course", "Dal_makhani", 192);
    R.add_dish_ctime("Main_course", "Yellow_dal", 141);
    R.add_dish_ctime("Main_course", "Rajma", 141);
    R.add_dish_ctime("Main_course", "Chole", 141);

    /// Breads
    R.add_dish_ctime("Breads", "Tandoori_roti", 30);
    R.add_dish_ctime("Breads", "Roomali_roti", 17);
    R.add_dish_ctime("Breads", "Butter_roti", 36);
    R.add_dish_ctime("Breads", "Plain_naan", 43);
    R.add_dish_ctime("Breads", "Butter_naan", 58);
    R.add_dish_ctime("Breads", "Garlic_naan_butter", 60);
    R.add_dish_ctime("Breads", "Tawa_parantha", 53);
    R.add_dish_ctime("Breads", "Laccha_parantha", 53);
    R.add_dish_ctime("Breads", "Pudina_parantha", 53);
    R.add_dish_ctime("Breads", "Stuffed_kulcha(aloo)", 65);
    R.add_dish_ctime("Breads", "Stuffed_kulcha(paneer)", 65);
    R.add_dish_ctime("Breads", "Stuffed_kulcha(onion)", 65);
    R.add_dish_ctime("Breads", "Papad", 15);

    /// Rice
    R.add_dish_ctime("Rice", "Steam_rice", 161);



    ///--------------------------------------------Employee-------------------------------------------------------------
    Hotel H;
    H.set_hotel(R);
    Name n;
    Date d;

    /// Chef

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_chef(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Chef");

    n.set_name("Ashutosh Parekh");
    d.set_date(31, 5, 1996);
    H.add_chef(n, "#56,Rajeevnagar,Hubballi", 8457961233, "ashupk55@gmail.com", y++, d, "Chef");

    n.set_name("Rahul Aryan");
    d.set_date(24, 5, 1996);
    H.add_chef(n, "#452,Gandhinagar,Dharwad", 7758899663, "raryan16@gmail.com", y++, d, "Chef");

    n.set_name("Avik G");
    d.set_date(27, 11, 1995);
    H.add_chef(n, "#44,Keshwapur,Hubballi", 9445833267, "avikg28@gmail.com", y++, d, "Chef");

    n.set_name("Jay Dixit");
    d.set_date(16, 6, 1994);
    H.add_chef(n, "#852,Akshay Park,Hubballi", 9463092047, "jayd13@gmail.com", y++, d, "Chef");

    n.set_name("Yash Mehta");
    d.set_date(23, 10, 1994);
    H.add_chef(n, "#22,Renuka Nagar,Hubballi", 8889993625, "yashmehta27@gmail.com", y++, d, "Chef");

    n.set_name("Kartik Raikar");
    d.set_date(17, 8, 1994);
    H.add_chef(n, "#112,CBT,Dharwad", 7458962366, "kraikar21@gmail.com", y++, d, "Chef");

    n.set_name("Aarav Kumar");
    d.set_date(13, 12, 1996);
    H.add_chef(n, "#444,Vidyanagar,Hubballi", 9874563214, "aaravk15@gmail.com", y++, d, "Chef");

    /// Waiter

    n.set_name("Vineet Bhatt");
    d.set_date(25, 4, 1997);
    H.add_waiter(n, "#236,Vijaynagar,Hubballi", 6325669874, "vineetb17@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_waiter(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Waiter");


    /// Laundry employee

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_laundry(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Laundry employee");


    /// Cleaning employee

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    n.set_name("Vihaan Singh");
    d.set_date(28, 11, 1995);
    H.add_room_cleaning(n, "#234,Vidyagiri,Hubballi", 9874563214, "vihnsh26@gmail.com", y++, d, "Cleaning employee");

    H.set_hotel(R);

    while (1) {
        int choice = 0;
        cout << "\n-----------------------------------------------------------------\n";
        cout << "\n---------------------------Main menu-----------------------------\n";
        cout << "\n1.Owner login";
        cout << "\n2.Employee login";
        cout << "\n3.Receptionist";
        cout << "\nEnter your choice : ";
        cin >> choice;
        if (choice == 1) {
            cout << "\nEnter password : ";
            string s;
            cin >> s;
            try {
                if (s == "password") {
                    while (H.display_owner_menu()) {}
                } else throw invalid_password();
            }
            catch (invalid_password a) {
                cout << "\nWorng password";
            }
        } else if (choice == 2) {
            while (H.employee_login()) {}
        } else if (choice == 3) {
            while (H.receptionist()) {}
        } else break;
    }
    return 0;
}
