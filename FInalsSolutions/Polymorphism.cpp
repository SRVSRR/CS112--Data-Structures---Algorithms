#include <iostream>

using namespace std;

class employee{
    public:
        employee(){};
        ~employee(){};
        void setname(string name){
            this->name = name;
        }

        void setID(string ID){
            this->ID = ID;
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

int main(){
    hourly_employee em1;
    em1.setname("Rohan");
    em1.setID("001");
    em1.sethourlyRate(1.2);
    em1.sethoursWorked(12);

    cout << "Name: " << em1.getname() << endl;
    cout << "ID: " << em1.getID() << endl;
    cout << "Hourly Rate: " << em1.gethourlyRate() << endl;
    cout << "Hours Worked: " << em1.gethoursWorked() << endl;
    cout << "Salary : " << em1.calc_salary() << endl;


    return 0;
}