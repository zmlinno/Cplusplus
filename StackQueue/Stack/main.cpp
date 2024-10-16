//
//  main.cpp
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

#include"Stack.cpp"
int main() {
    Stack s;

    s.StackPush(10);
    s.StackPush(20);
    s.StackPush(30);
    cout << "栈顶元素: " << s.StackTop() << endl; // 输出 30

    s.StackPop();
    cout << "栈顶元素: " << s.StackTop() << endl; // 输出 20

    cout << "栈大小: " << s.StackSize() << endl; // 输出 2

    cout << (s.StackEmpty() ? "栈为空" : "栈不为空") << endl; // 输出 "栈不为空"

    return 0;
}
