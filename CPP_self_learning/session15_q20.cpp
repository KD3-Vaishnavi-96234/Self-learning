#include <iostream>
#include <memory>
#include <typeinfo>
using namespace std;

class Base
{
public:
    virtual void show()
    {
        cout << "Base class object" << endl;
    }

    virtual ~Base() {}
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived class object" << endl;
    }
};

int main()
{
    cout << "\n---- unique_ptr (Ownership Transfer) ----" << endl;

    unique_ptr<Base> u1 = make_unique<Derived>();
    unique_ptr<Base> u2 = move(u1);

    if (!u1)
        cout << "Ownership transferred to u2" << endl;

    u2->show();
    cout << "RTTI type: " << typeid(*u2).name() << endl;
    cout << "\n---- shared_ptr (Shared Ownership) ----" << endl;

    shared_ptr<Base> s1 = make_shared<Derived>();
    shared_ptr<Base> s2 = s1;
    shared_ptr<Base> s3 = s1;

    cout << "Reference count = " << s1.use_count() << endl;

    s2->show();

    cout << "RTTI type: " << typeid(*s2).name() << endl;
    cout << "\n---- weak_ptr (Non-owning reference) ----" << endl;

    weak_ptr<Base> w1 = s1;

    cout << "Reference count after weak_ptr = " << s1.use_count() << endl;

    if (shared_ptr<Base> temp = w1.lock())
    {
        temp->show();
        Derived *d = dynamic_cast<Derived *>(temp.get());

        if (d)
            cout << "dynamic_cast successful: Derived object" << endl;
    }

    return 0;
}