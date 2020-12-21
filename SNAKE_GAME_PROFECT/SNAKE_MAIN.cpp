#include"SNAKE_RUN.h"
#include<windows.h>
#include<time.h>
int main()
{
    int testNum = 0;    //食物和蛇身重叠次数检测
    char c = 'd';    //方向键初始化为d
    srand((unsigned)time(NULL));    //随机种子
    Food food = {5, 8, 'A'};        //初始化食物
    Snakepoint snake;    // 定义结构体
    Snakepoint *head, *rear;   //定义结构体指针
    initSnake(&snake);  //初始化蛇身
    head = rear = &snake;   //初始化蛇只有蛇头

    while(1){
        draw_Picture(head, &food);

        /*蛇迟到食物后的处理*/
        if(isSnakeEatFood(head,&food)){
            rear = add(head);   //蛇身增长一节
            creatFood(&food);
            testNum = avoidOverlap(head, &food);
            setFoodLocation(&food, head, testNum, c);
        }

        /*按键处理*/
        if(kbhit())
            c = setCurkeyButton(c);
        if(c=='x')
            break;
        snakeMove(head, rear, c);
        if(isSnakeEatSelf(head)){
            //判断游戏结束
            cout << "game over ! " << endl;
            break;
        }
        Sleep(5*1000);   //屏幕刷新时间间隔
    }
    getch();
    return 0;
}