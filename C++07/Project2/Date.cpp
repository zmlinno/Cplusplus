#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass(int value) : _value(value) {}

    void SetValue(int value) {
        this->_value = value; // 使用 this 指针显式访问成员变量
    }

    int GetValue() const {
        return this->_value; // 使用 this 指针显式访问成员变量
    }

private:
    int _value;
};

int main() {
    MyClass obj1(10);
    cout << "Initial value: " << obj1.GetValue() << endl;

    obj1.SetValue(20);
    cout << "Updated value: " << obj1.GetValue() << endl;

    return 0;
}








