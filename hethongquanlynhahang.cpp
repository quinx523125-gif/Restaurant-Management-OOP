#include <iostream>
#include <vector>
#include <string>

using namespace std;

//================ ABSTRACT CLASS =================
class Person
{
protected:
    string name;

public:
    Person(string n)
    {
        name = n;
    }

    virtual void displayInfo() = 0; // Pure virtual function
};

//================ INHERITANCE =================
class Employee : public Person
{
private:
    int employeeID;

public:
    Employee(string n, int id)
        : Person(n)
    {
        employeeID = id;
    }

    void displayInfo()
    {
        cout << "Nhan vien: " << name
             << " | ID: " << employeeID << endl;
    }
};

class Customer : public Person
{
private:
    int tableNumber;

public:
    Customer(string n, int table)
        : Person(n)
    {
        tableNumber = table;
    }

    void displayInfo()
    {
        cout << "Khach hang: " << name
             << " | Ban so: " << tableNumber << endl;
    }
};

//================ ENCAPSULATION =================
class Food
{
private:
    string foodName;
    double price;

public:
    Food(string name, double p)
    {
        foodName = name;
        price = p;
    }

    string getFoodName()
    {
        return foodName;
    }

    double getPrice()
    {
        return price;
    }
};

//================ ORDER CLASS =================
class Order
{
private:
    vector<Food> foods;

public:
    void addFood(Food food)
    {
        foods.push_back(food);
    }

    double calculateTotal()
    {
        double total = 0;

        for (Food food : foods)
        {
            total += food.getPrice();
        }

        return total;
    }

    void showOrder()
    {
        cout << "\n===== DON HANG =====\n";

        for (Food food : foods)
        {
            cout << food.getFoodName()
                 << " - "
                 << food.getPrice()
                 << " VND\n";
        }

        cout << "Tong tien: "
             << calculateTotal()
             << " VND\n";
    }
};

//================ MAIN =================
int main()
{
    // Object
    Employee emp("Nguyen Van A", 101);
    Customer cus("Tran Thi B", 5);

    emp.displayInfo();
    cus.displayInfo();

    Food food1("Com Chien", 50000);
    Food food2("Tra Sua", 30000);
    Food food3("Ga Ran", 70000);

    Order order;

    order.addFood(food1);
    order.addFood(food2);
    order.addFood(food3);

    order.showOrder();

    return 0;
}