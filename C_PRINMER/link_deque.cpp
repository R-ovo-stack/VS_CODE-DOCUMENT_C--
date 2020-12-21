#include <stdio.h>
#include <stdlib.h>

typedef struct LinkQueueNode{
	int *data;
	struct LinkQueueNode *next;
} LkQueNode;    

typedef struct LkQueue{
    LkQueNode *front,*rear;
} LkQue;


void init(LkQue *LQ){
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode)); //生成队列的头结点
    LQ->front = temp;    //队列头指针指向队列头结点
    LQ->rear = temp;     //队列尾指针指向队列尾结点
    (LQ->front)->next = NULL;
    
}

//入队列
void EnQueue(LkQue *LQ,int x){
    
    LkQueNode *temp;
    temp = (LkQueNode *)malloc(sizeof(LkQueNode));
    temp->data = x;
    temp->next = NULL;
    (LQ->rear)->next = temp;
    LQ->rear = temp;
}

