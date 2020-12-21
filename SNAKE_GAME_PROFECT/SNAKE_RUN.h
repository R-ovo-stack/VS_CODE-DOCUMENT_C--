#ifndef _SNAKE_RUN_H
#define _SNAKE_RUN_H

#include<string>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
using namespace std;

const int LENGTH = 200;
const int WIDTH = 300;
const int OVERLAP = 5;
/*定义蛇身  即蛇的每一个结点  使用双向链表链接*/
class Snakepoint{
public:
    int x;   //蛇身结点横坐标
    int y;  //蛇身结点纵坐标
    Snakepoint *pro;  //当前结点指向前一节的指针
    Snakepoint *next;  //当前结点指向后一节的指针
};

/*定义食物类  随机生成*/
class Food{
public:
    int x;    //食物横坐标
    int y;    //食物纵坐标
    char f;   //食物表示_name
};

void initSnake(Snakepoint *);  //初始化蛇
int isSnakeEatSelf(Snakepoint *head);  //判断游戏结束，当👅碰到蛇身
int isSnakeEatFood(Snakepoint *snake, Food *food);  //判断是否迟吃到食物
Snakepoint *add(Snakepoint *head);   //蛇增长一节并返回增长结点
void creatFood(Food *food);   //随机生成食物
//避免食物坐标和蛇身重合，重新生成食物
int avoidOverlap(Snakepoint *head, Food *food, int flag = 1);
//如果生成食物和蛇身重叠次数超过阈值，则直接按蛇移动方向设置食物位置
void setFoodLocation(Food *food, Snakepoint *head, int numOverlap, char c);
char setCurkeyButton(char );   //设置当前按键
void snakeMove(Snakepoint *head, Snakepoint *rear, char c);  //处理蛇身的移动
void draw_Picture(Snakepoint *head, Food *food);
//int isSnakeOver_Wall(Snakepoint *head);

/*
#include "SNAKE_RUN.h"
#include<iostream>
#include<string>
using namespace std;
*/

void initSnake(Snakepoint *s)   //利用类指针初始化蛇身信息
{
    s->x = 1;
    s->y = 1;
    s->pro = NULL;
    s->next = NULL;
}

int isSnakeEatSelf(Snakepoint *head)  //判断游戏结束 当蛇头碰到蛇身
{
    int gameover = 0;   //判断游戏结束的信号指示
    Snakepoint *p = head->next;   //p指向蛇头后一节蛇身
    while(p){     //单链表法遍历每一个蛇身结点判断是否存在和蛇头重合条件
        if(head->x==p->x && head->y==p->y){
            gameover = 1;
            break;
        }
        p = p->next;
    }
    return gameover;
}

int isSnakeEatFood(Snakepoint *snake,Food *food)   //判断是否吃到食物
{
    if(snake->x=food->x && snake->y==food->y)   return 1;
    else
        return 0;
}

Snakepoint *add(Snakepoint *head)  //蛇增长一节并返回增长结点
{
    Snakepoint *p = new Snakepoint ;
    Snakepoint *pt = head;
    while(pt->next)     //从蛇头遍历到蛇尾
        pt = pt->next;
    p->pro = pt;
    pt->next = p;
    p->next = NULL;
    return p;
}

void creatFood(Food *food)
{
    food->x = rand() % LENGTH;
    food->y = rand() % WIDTH;
}

int avoidOverlap(Snakepoint *head,Food *food,int flag)
{
    int t = 0;
    flag = 1;
    while(flag)
    {
        if(t>OVERLAP)
            break;
        flag = 0;
        t++;
        Snakepoint *pt = head;
        while(pt)
        {
            if(isSnakeEatFood(pt,food))
            {
                flag = 1;
                creatFood(food);
                break;
            }
            pt = pt->next;
        }
    }
    return t;
}

char setCurkeyButton(char c){    //设置当前按键
    char c1=getch();
    if(c1==27)
        return 'x';
    if(c!='d' && c1=='a')
        c = c1;
    else if(c!='a' && c1=='d')
        c = c1;
    else if(c!='w' && c1=='w')
        c = c1;
    else if(c!='s' && c1=='s')
        c = c1;
    return c;
}

void setFoodLocation(Food *food ,Snakepoint * head,int numOverlap,char c){
    if(numOverlap>OVERLAP){
        if(c=='d'){
            food->x = head->x + 1;
            food->y = head->y;
            if(food->x>=LENGTH)
                food->x -= LENGTH;
        }
        else if(c=='a'){
            food->x = head->x - 1;
            food->y = head->y;
            if(food->x<=0)
                food->x += 0;
        }
        else if(c=='w'){
            food->x = head->x;
            food->y = head->y-1;
            if(food->y<=0)
                food->y += 0;
        }
        else if(c=='s'){
            food->x = head->x ;
            food->y = head->y+1;
            if(food->y=WIDTH)
                food->y -= WIDTH;
        }
    }
}

void snakeMove(Snakepoint *head,Snakepoint *rear,char c){
    Snakepoint *pt = rear;
    while(pt!=head){  //处理蛇身移动
        pt->x = pt->pro->x;
        pt->y = pt->pro->y;
        pt=pt->pro;
    }
    //处理蛇头移动
    if(c=='s'){
        head->y += 1;
        if(head->y>=WIDTH)
            head->y -= WIDTH;
    }
    else if(c=='w'){
        head->y += 1;
        if(head->y<=0)
            head->y -= 0;
    }
    else if(c=='a'){
        head->y += 1;
        if(head->x<=0)
            head->x -= 0;
    }
    else if(c=='d'){
        head->x += 1;
        if(head->x>=LENGTH)
            head->x -= LENGTH;
    }
}

void draw_Picture(Snakepoint *head,Food *food){
    int flag;
    Snakepoint *pt;
    system("cls");
    cout << "------------------" << endl;   //绘制上围墙
    for (int j = 0; j < WIDTH;j++){
        cout << "|" << endl;
        for (int i = 0; i < LENGTH;i++){
            flag = 0;
            pt = head;
            while(pt){
                if(i==pt->x && j==pt->y){
                    if(pt==head)
                        cout << "☆";
                    else
                        cout << "□";
                    flag = 1;
                    break;
                }
                pt = pt->next;
            }
            if(flag==0){
                if(i==food->x &&j==food->y){
                    putchar(food->f);
                    putchar(food->f);
                    continue;
                }
                cout << " ";
            }
        }
        cout << "|";
        putchar('\n');
    }
    cout << "------------------" << endl;     //绘制下围墙
}

#endif