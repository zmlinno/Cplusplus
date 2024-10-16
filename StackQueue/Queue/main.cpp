//
//  main.cpp
//  Algorithm
//
//  Created by 张木林 on 10/16/24.
//

#include"Queue.cpp"
int main()
{
    Queue q;
    q.QueuePush(10);
    q.QueuePush(20);
    q.QueuePush(30);
    
    cout<<"队列头部: "<<q.QueueFront()<<endl;//输出10
    cout<<"队列尾部: "<<q.QueueBack()<<endl; //输出30
    cout<<"队列大小: "<<q.QueueSize()<<endl; //输出3
    
    q.QueuePop();
    cout<<"队列头部: "<<q.QueueFront()<<endl;
    cout<<"队列大小: "<<q.QueueSize()<<endl;
    
    q.QueueDestory();
    cout<<endl;
}
