#include <string>
#include <iostream>

class Person {
public:
    // Parameterized constructor
    Person(const std::string& name, const std::string& address, const std::string& dob)
        : name(name), address(address), dob(dob) {}

    // Default constructor
    Person() sa;

    // Getter methods
    std::string getName() const { return name; }
    std::string getAddress() const { return address; }
    std::string getDob() const { return dob; }

protected:
    std::string name;
    std::string address;
    std::string dob;
};

class Employee : public Person {
public:
    // Parameterized constructor
    Employee(const std::string& name, const std::string& address, const std::string& dob,
             const std::string& employee_id, const std::string& position)
        : Person(name, address, dob), employee_id(employee_id), position(position) {}

    // Default constructor
    Employee();

    // Getter methods
    std::string getEmployeeId() const { return employee_id; }
    std::string getPosition() const { return position; }

protected:
    std::string employee_id;
    std::string position;
};

class Student : public Person {
public:
    // Parameterized constructor
    Student(const std::string& name, const std::string& address, const std::string& dob,
            const std::string& student_id, const std::string& program)
        : Person(name, address, dob), student_id(student_id), program(program) {}

    // Default constructor
    Student();

    // Getter methods
    std::string getStudentId() const { return student_id; }
    std::string getProgram() const { return program; }

protected:
    std::string student_id;
    std::string program;
};

class HourlyEmployee : public Employee {
public:
    // Parameterized constructor
    HourlyEmployee(const std::string& name, const std::string& address, const std::string& dob,
                   const std::string& employee_id, const std::string& position,
                   float hours_worked, float wage)
        : Employee(name, address, dob, employee_id, position), hours_worked(hours_worked), wage(wage) {}

    // Default constructor
    HourlyEmployee();

    // Getter methods
    float getHoursWorked() const { return hours_worked; }
    float getWage() const { return wage; }

protected:
    float hours_worked;
    float wage;
};

class CommissionEmployee : public Employee {
public:
    // Parameterized constructor
    CommissionEmployee(const std::string& name, const std::string& address, const std::string& dob,
                       const std::string& employee_id, const std::string& position,
                       float total_sales, float commission_percent)
        : Employee(name, address, dob, employee_id, position), total_sales(total_sales), commission_percent(commission_percent) {}

    // Default constructor
    CommissionEmployee();

    // Getter methods
    float getTotalSales() const { return total_sales; }
    float getCommissionPercent() const { return commission_percent; }

protected:
    float total_sales;
    float commission_percent;
};

int main() {
    // Example usage of HourlyEmployee
    HourlyEmployee hEmployee("John Doe", "123 Main St", "01-01-1990", "E123", "Technician", 40.5, 20.0);
    std::cout << "Hourly Employee: " << hEmployee.getName() << " earns $" << hEmployee.getWage() << " per hour." << std::endl;

    // Example usage of CommissionEmployee
    CommissionEmployee cEmployee("Jane Smith", "456 Elm St", "02-02-1985", "E456", "Sales", 5000.0, 10.0);
    std::cout << "Commission Employee: " << cEmployee.getName() << " has a commission percent of " << cEmployee.getCommissionPercent() << "%" << std::endl;

    return 0;
}
