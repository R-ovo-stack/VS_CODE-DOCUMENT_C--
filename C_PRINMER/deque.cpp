/*
循环队列： 解决边进边出问题从而开发出来的数据结构

*/
#include <stdio.h>
#include <stdlib.h>

//循环队列最大数据元素个数
const int maxsize = 8; 

//循环队列的结构体
typedef struct cycqueue{
    int *data;  //数组
    int front,rear; 
} CycQue;


//队列初始化
void init(CycQue *CQ){
    CQ->data = (int *)malloc(maxsize*sizeof(int));
    CQ->front = 0;
    CQ->rear = 0;
}


//判断队列是否为空
int empty(CycQue *CQ){
    if(CQ->rear==CQ->front) return 1;
    else return 0;
}


//入队列
int EnQueue(CycQue *CQ,int x){
    if((CQ->rear+1)%maxsize==CQ->front){
        printf("队列满");
        return 0;
    }
    else{
        CQ->rear =(CQ->rear+1) % maxsize;
        CQ->data[CQ->rear] = x;
        return 1;
    }
}

//出队列
int OutQueue(CycQue *CQ){
    if(empty(CQ)){
        printf("队列为空");
        return 0;
    }
    else{
        CQ->front = (CQ->front+1) % maxsize;
        return 1;
    }
}

int main()
{
    CycQue CQ;
    init(&CQ);

    EnQueue(&CQ,2);
    EnQueue(&CQ,4);
    printf("%d",CQ.rear);
    OutQueue(&CQ);
    printf("%d",CQ.front);
    system("pause");
    return 0;
}

