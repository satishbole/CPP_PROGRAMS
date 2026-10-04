#include <iostream>
using namespace std;

class Parent
{
protected:
    int age = 20;
};

class Child : public Parent
{
public:
    void display()
    {
        cout << age;
    }
};

int main()
{
    Child c;
    c.display();

    return 0;
}
