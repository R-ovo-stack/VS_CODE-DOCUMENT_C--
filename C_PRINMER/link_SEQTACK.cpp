#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;   //数据域
    struct node *next;   //链域
} LkStk;

//初始化
void init(LkStk *ls){
    printf("初始化操作\n");
    ls = (LkStk *)malloc(sizeof(LkStk)); 
    ls->next = NULL;
}

// 进栈
void push(LkStk *head,int x){
    printf("进栈操作\n");
    LkStk *temp;
    temp = (LkStk*)malloc(sizeof(LkStk));//给temp新申请一块空间
    temp->data = x;
    temp->next = head->next;
    head->next = temp;
    printf("%d进栈成功\n",x);
}

int empty(LkStk *head){
    if(head->next ==NULL){
        return 1;
    }
    else return 0;
}

// 出栈
int pop(LkStk *head){
    LkStk *temp;
    //判断栈是否为空
    if(!empty(head)){
        temp= head->next;  // 准备出栈的元素指向head的下一结点
        head->next = temp->next;   // 原栈顶的下一个结点称为新的栈顶
        printf("栈顶元素：%d\n",temp->data);
        free(temp); //释放原栈顶的结点空间
        return 1;       
    }
    return 0;
}

int main()
{
    LkStk ls;
    init(&ls);
    
    push(&ls,1);
    push(&ls,2);
    
    pop(&ls);
    pop(&ls);
    system("pause");
    return 0;
}
