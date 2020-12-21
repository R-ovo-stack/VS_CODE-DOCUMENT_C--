#include<iostream>
#include<cstdlib>
using namespace std;

class Node{
public:
    int data;
    class Node* next;   //定义队列中指向下一元素的指针
};

typedef class Node Queue_Node;
typedef Queue_Node* Linked_queueNode;

Linked_queueNode front=NULL;
Linked_queueNode rear=NULL;

void enqueue(int data)
{
    Linked_queueNode newnode;
    newnode=new Queue_Node;
    newnode->data=data;
    newnode->next=NULL;
    if(rear==NULL)
        front=newnode;
    else
        rear->next=newnode;
    rear=newnode;
}

int dequeue()
{
    int temp;
    if(front==NULL){
    cout<<"队列已空! "<<endl;
    return -1;
    }
    else{
		if(front==rear)  //队列只有一个元素
            {
                rear=NULL;
                temp=front->data;
                front=front->next;
                return temp;
            }
    else
    {
        temp=front->data;
        front=front->next;
        return temp;
    }
    }
}

int main()
{
    cout<<"         以链表形式实现队列"<<endl;
    cout<<"====================================="<<endl;
    int i;
    int tx;
    for(i=0;i<6;i++){
        cout<<"在队列尾端加入第"<<i+1<<"个数据,此数据为: ";
        cin>>tx;
        enqueue(tx);
    }
    cout<<"====================================="<<endl;
    while(front){
        cout<<"从队列前端按序取出的元素数据值为: "<<dequeue()<<endl;
    }
    return 0;
}