#include<bits/stdc++.h>
using namespace std;
class Car
{
public:
    int num;

    // Default constructor
    Car()
    {
        cout << "Default constructor" << endl;
    }

    // Parameterized constructor
    Car(int n)
    {
        num=n;
        
    }

    // Copy constructor
    Car(Car&c2)
    {
        num = c2.num;
    }

    // Move constructor
    Car(Car && c3)
    {
        num = c3.num;
        c3.num = 0;
	}
};
main()
{
    Car c;          // Default constructor

    Car c1(123);     // Parameterized constructor

    Car c2(c1);      // Copy constructor

    Car c3(move(c1));  // Move constructor

    cout << "Parameterized constructor: " << c1.num << endl;
    cout << "Copy constructor: " << c2.num << endl;
    cout << "Move constructor: " << c3.num << endl;

}
