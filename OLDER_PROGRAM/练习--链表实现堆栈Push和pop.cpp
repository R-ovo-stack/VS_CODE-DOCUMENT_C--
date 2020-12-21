#include<iostream>
using namespace std;

class Node{
    public:
    int data;  //声明堆栈中存放数据的变量
    class Node *next;  //堆栈中用来指向下一个节点的指针
};
//top是一个指针变量
typedef class Node Stack_Node;
typedef Stack_Node* Linked_Stack;
Linked_Stack top=NULL;

int isempty()
{
    if(top==NULL)
    return 1;
    else
    return 0;
}

void push(int data)
{
    Linked_Stack newnode;
    //为新节点分配空间
    newnode=new Stack_Node;
    newnode->data=data;  //将数据赋值给新节点的data
    newnode->next=top;   //将新节点的next 指针指向top;
    top=newnode;   //top指向新节点【新节点成为top节点】
}

int pop()
{
    Linked_Stack ptr;
    int temp;
    if(isempty())
    {
        cout<<"堆栈已空，无法弹出元素！"<<endl;
        return -1;
    }
    else
    {
        ptr=top;
        top=top->next;
        temp=ptr->data;
        free(ptr);
        return temp;
    }
}

int main()
{
    cout<<"请按顺序输入10个数据: "<<endl;
    int i;
    int inx;
    for(i=0;i<10;i++)
    {
        cin>>inx;
        push(inx);
    }
    cout<<"================="<<endl;
    while(!isempty())
        cout<<"堆栈输出的顺序为: "<<pop()<<endl;
    cout<<"================="<<endl;  
    return 0;
}


/*

                                    //原教材内的代码//

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;
class Node	//声明堆栈链表节点
{
   public:
   int data;	//声明存放堆栈数据的变量
    class Node *next;	//堆栈中用来指向下一个节点的指针
    };
typedef class Node Stack_Node;		//定义堆栈中节点的新类型
typedef Stack_Node *Linked_Stack;	//定义链表堆栈的新类型
Linked_Stack top=NULL;				//指向堆栈顶端的指针

//判断是否为空堆栈
int isEmpty()
{
    if(top==NULL) return 1;
    else return 0;
}
//将指定的数据压入堆栈
void push(int data)
{
    Linked_Stack new_add_node;	//新加入节点的指针
    //分配内存给新节点
    new_add_node=new Stack_Node;
    new_add_node->data=data;		//将传入的值赋值给节点的数据变量
    new_add_node->next=top;		//将新节点指向堆栈的顶端
    top=new_add_node;			//新节点成为堆栈的顶端
}
//从堆栈弹出数据
int pop()
{
    Linked_Stack ptr;		//指向堆栈顶端的指针
    int temp;
    if(isEmpty())			//判断堆栈是否为空,如果是则返回-1
    {
       cout<<"===目前为空堆栈==="<<endl;
       return -1;
    }
    else
    {
        ptr=top;		//指向堆栈的顶端
        top=top->next;	//将堆栈顶端的指针指向下一个节点
        temp=ptr->data;	//取出堆栈的数据
        free(ptr);			//将节点占用的内存释放
        return temp;		//将从堆栈取出的数据返回给主程序
    }
}
//主程序
int main(void)
{
    int value;
    int i;
    cout<<"请按序输入10个数据:"<<endl;
    for(i=0;i<10;i++)
    {
       cin>>value;
       push(value);
    }
    cout<<"===================="<<endl;
    while(!isEmpty()) //将数据陆续从顶端弹出
       cout<<"堆栈弹出的顺序为:"<<setw(2)<<pop()<<endl; 
    cout<<"===================="<<endl;
    system("pause");      
    return 0; 
}
*/