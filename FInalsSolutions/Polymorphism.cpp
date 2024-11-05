#include <iostream>

using namespace std;

class employee{
    public:
        employee(){};
        ~employee(){};
        string setname(string name){
            this->name = name;
            return this->name;
        }

        string setID(string ID){
            this->ID = ID;
            return this->ID;
        }

        string getname() {
            return name;
        };

        string getID(){
            return ID;
        };

        virtual float calc_salary() = 0;
    private:
        string name;
        string ID;
};

class hourly_employee: public employee{
    private:
    int hoursWorked;
    double hourlyRate;

    public:
    void sethoursWorked(int hours){
        hoursWorked = hours;
    }

    void sethourlyRate(double rate){
        hourlyRate = rate;
    }

    int gethoursWorked() const {
        return hoursWorked;
    };

    double gethourlyRate(){
        return hourlyRate;
    };

    float calc_salary(){
        return hourlyRate * hoursWorked;
    };

};

class Commision_Employee: public employee{
    private:
    int TotalSales;
    double CommissionPercent;

    public:
    void setTotalSales(int Sales){
        TotalSales = Sales;
    }

    void setCommissionPercent(double CRate){
        CommissionPercent = CRate;
    }

    int getTotalSales() const {
        return TotalSales;
    };

    double getCommissionPercent(){
        return CommissionPercent;
    };

    float calc_salary(){
        return CommissionPercent * TotalSales;
    };  
};

void print_salary(employee *em){
    double salary = em->calc_salary();
    cout << "salary: " << salary;
}

int main(){
    hourly_employee* em1 = new hourly_employee();
    em1->setname("Rohan");
    em1->setID("001");
    em1->sethourlyRate(1.2);
    em1->sethoursWorked(12);

    cout << "Name: " << em1->getname() << endl;
    cout << "ID: " << em1->getID() << endl;
    cout << "Hourly Rate: " << em1->gethourlyRate() << endl;
    cout << "Hours Worked: " << em1->gethoursWorked() << endl;
    cout << "Salary: " << em1->calc_salary() << endl;

    cout << endl;

    Commision_Employee* em2 = new Commision_Employee();
    em2->setname("Aisha");
    em2->setID("002");
    em2->setTotalSales(5000);
    em2->setCommissionPercent(0.10);

    cout << "Name: " << em2->getname() << endl;
    cout << "ID: " << em2->getID() << endl;
    cout << "Commission Rate: " << em2->getCommissionPercent() << endl;
    cout << "Total Sales: " << em2->getTotalSales() << endl;
    cout << "Salary: " << em2->calc_salary() << endl;

    cout << endl;

    cout << "Salary Stats" << endl;
    cout << em1->getname() << ": "; print_salary(em1);
    cout << em2->getname() << ": "; print_salary(em2);

    delete em1;
    delete em2;

    return 0;
}