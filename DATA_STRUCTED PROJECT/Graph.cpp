#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MaxVNum 100 //顶点最大值
#define Max 10000   //网权值初始值

typedef char VexType; //顶点数据类型 || C语言版本，此处无需设定模板类
typedef int EdgeType; //边的权值类型

struct Graph
{
    VexType Point[MaxVNum];          //存储顶点
    EdgeType Edge[MaxVNum][MaxVNum]; //存储边权值，由于是无向图，此处不带权值，仅为0||1
    //若为有权，则0为不相连，1Edge为权值
    int pointNum; //顶点数
    int EdgeNum;  //边数
};

typedef Graph AMGraph;

//给定顶点返回该顶点在顶点表中的存储索引
int Locate(AMGraph &G, VexType m)
{
    int res = 0; //res作为下标值返回
    for (int i = 0; i < G.pointNum; i++)
    {
        if (G.Point[i] == m)
        {
            res = i;
            break;
        }
    }
    return res;
}
void CreateAMGraph(AMGraph &G)
{ //此处直接引用安排
    //创建无向带权邻接矩阵
    VexType u, v; //u,v用于之后进行邻接矩阵的连接赋值
    int value;    //寄存权值
    int i, j;
    cout << "请输入顶点数:" << endl;
    cin >> G.pointNum;
    cout << "请输入边数:" << endl;
    cin >> G.EdgeNum;
    cout << "开始输入顶点信息" << endl;
    for (int i = 0; i < G.pointNum; i++)
    {
        cin >> G.Point[i];
    }
    //初始化邻接矩阵所有值为0,若为网，则初始化为无穷大
    for (int i = 0; i < G.pointNum; i++)
    {
        for (int j = 0; j < G.pointNum; j++)
        {
            G.Edge[i][j] = 0;
        }
    }
    cout << "输入每条边依附的两个顶点:" << endl;
    while (G.EdgeNum--)
    {                     //循环边Num次
        cin >> u >> v;    //输入的两条顶点之间直接存在边
        i = Locate(G, u); //获取顶点u在G中点表中的存储索引
        j = Locate(G, v);
        if (i != -1 && j != -1)
        {
            // G.Edge[i][j] = G.Edge[j][i] = 1; //此处为无向图，没有权值
            cout << "请输入" << u << "->" << v << "方向边的权值:" << endl;
            cin >> value;
            G.Edge[i][j] = G.Edge[j][i] = value;
            //若为有向图，则G.Edge[i][j]=1
            //若为网，则先输入权值，再赋值个G.Edge[i][j]
        }
    }
}

void CreateAMGraph2(AMGraph &G) //此处直接引用安排
{
    //创建有向网
    VexType u, v; //u,v用于之后进行邻接矩阵的连接赋值
    int i, j;
    int value; //寄存权值
    cout << "请输入顶点数:" << endl;
    cin >> G.pointNum;
    cout << "请输入边数:" << endl;
    cin >> G.EdgeNum;
    cout << "开始输入顶点信息" << endl;
    for (int i = 0; i < G.pointNum; i++)
    {
        cin >> G.Point[i];
    }
    //初始化为无穷大
    for (int i = 0; i < G.pointNum; i++)
    {
        for (int j = 0; j < G.pointNum; j++)
        {
            G.Edge[i][j] = Max;
        }
    }
    cout << "输入每条边依附的两个顶点:" << endl;
    while (G.EdgeNum--)
    {                     //循环边Num次
        cin >> u >> v;    //输入的两条顶点之间直接存在边
        i = Locate(G, u); //获取顶点u在G中点表中的存储索引
        j = Locate(G, v);
        if (i != -1 && j != -1)
        {
            cout << "请输入" << u << "->" << v << "方向边的权值:" << endl;
            cin >> value;
            G.Edge[i][j] = value;
            //若为网，则先输入权值，再赋值个G.Edge[i][j]
        }
    }
}

//邻接表创建图AMGraph
void CreateAmGraphByLink()
{
}

void AMGraphBfs(AMGraph G, int v) //v为搜索的初始顶点在顶点表中索引，
{
    //也可以传入Vextype,利用Locate函数取得`索引
    //广度优先遍历 图G  || 广度优先搜索 || 基于邻接矩阵
    //连通图的BFS
    bool visited[G.pointNum];
    for (int i = 0; i < G.pointNum; i++)
    {
        visited[i] = false; //初始化均未被访问
    }
    int u, w;     //遍历顶点寄存器
    queue<int> Q; //存放int
    cout << G.Point[v] << "\t";
    visited[v] = true;
    Q.push(v);
    while (!Q.empty())
    {
        u = Q.front(); //取出队头
        Q.pop();       //队头出队
        for (int i = 0; i < G.pointNum; i++)
        { //一次检查u的所有邻接点
            if (G.Edge[u][i] && !visited[i])
            {
                cout << G.Point[i] << "\t";
                visited[i] = true;
                Q.push(i); //邻接点依次入队并进行，入队顺序并不严格
            }
        }
    }
}

/**
 * @brief 后被访问的顶点，其邻接点先被访问 || 不撞南墙不回头 || 回溯
 * 
 * @param G 
 * @param v 
 */
bool visited[10] = {false};
void AMGraphDfs(AMGraph G, int v)
{
    //基于邻接矩阵的深度优先搜索
    int w;
    cout << G.Point[v] << "\t";
    visited[v] = true; //标记已访问
    for (w = 0; w < G.pointNum; w++)
    {
        if (G.Edge[v][w] && !visited[w])
        {
            AMGraphDfs(G, w); //从顶点w开始递归深度优先遍历
        }
    }
}

//单源最短路径Dijkstra || 基于有向网
void Dijkstra(AMGraph G, int v, int p[])
{ //v为单源点
    //int p[G.pointNum];    //用于记录路径字符串
    int dist[G.pointNum]; //用于记录dist[i]，通过更新该dist数组以达到求单源路径最小值
    int flag[G.pointNum]; //顶点T是否在S中

    //1.初始化距离数组dist[]
    for (int i = 0; i < G.pointNum; i++)
    {
        dist[i] = G.Edge[v][i];
        flag[i] = false; //都不再S中
        if (dist[i] == Max)
            p[i] = -1;
        else
            p[i] = v;
    }
    dist[v] = 0;
    flag[v] = true; //初始，S中仅含v

    for (int i = 0; i < G.pointNum; i++)
    {                  //找源点到每一顶点的最短路径
        int min = Max; //用于求dist[]中最小值
        int t = v;     //移动顶点
        for (int j = 0; j < G.pointNum; j++)
        { //得出dist[]最小值的顶点
            if (!flag[j] && dist[j] < min)
            {
                min = dist[j];
                t = j;
            }
        }
        if (t == v)
            return;                          //如果找不到t则直接退出，表明寻找完了所有顶点
        flag[t] = true;                      //将t加入集合S
        for (int i = 0; i < G.pointNum; i++) //此处直接暴力遍历所有顶点,更新与t相邻接的顶点到源点u的距离
        {
            if (!flag[i] && G.Edge[t][i] < Max) //在相邻顶点并且V-S中搜索
            {
                if (dist[i] > (dist[t] + G.Edge[t][i])) //在V-S中寻找
                {
                    dist[i] = dist[t] + G.Edge[t][i];
                    p[i] = t;
                }
            }
        }
    }
}

void findPath(AMGraph G, VexType v, int p[Max])
{
    //通过该函数处理p[]数组得出各条路径
    int x;
    stack<int> S;
    cout << "源点: " << v << endl;
    for (int i = 0; i < G.pointNum; i++)
    {
        x = p[i];
        if (x == -1 && v != G.Point[i])
        {
            cout << "源点到其他个顶点最短路径为: " << v << "";
        }
    }
}
/**
 * @brief 
 * 
struct Graph
{
    VexType Point[MaxVNum];          //存储顶点
    EdgeType Edge[MaxVNum][MaxVNum]; //存储边权值，由于是无向图，此处不带权值，仅为0||1
    //若为有权，则0为不相连，1Edge为权值
    int pointNum; //顶点数
    int EdgeNum;  //边数
};

 * 
 * @param G 
 * @return int 
 */
//克鲁斯科尔最小生成树算法
int Kruskaer(AMGraph G)
{ //初代--基于无向带权图的克鲁斯卡尔最小生成树
    //1.S,V-S，S为处理过的顶点,V为总顶点集合,V-S为未处理的顶点
    //int len = G.pointNum;

    int S[G.pointNum] = {0}; //定义S,当S满,len--，当len为0终止方法
    int res = 0;             //记录最小生成树的代价总和

    for (int k = 0; k < G.pointNum; k++)
    {
        int min = 100;
        int a, b;
        for (int i = 0; i < G.pointNum; i++)
        {
            for (int j = 0; j < G.pointNum; j++)
            {
                if (!(S[i] == 1 && S[j] == 1) && G.Edge[i][j] > 0) //在未处理边集中选择最小边,如果碰到闭圈，直接pass该边
                {
                    if (G.Edge[i][j] <= min)
                    {
                        min = G.Edge[i][j];
                        a = i; //记录顶点索引号
                        b = j;
                    }
                }
            }
        }
        //cout << "min: " << min << endl;
        if (min == 100)
        { //当V-S为空,直接跳出
            return res;
        }
        res += min;         //代价和累加
        S[a] = 1, S[b] = 1; //a,b顶点归并->S
        cout << "第" << k + 1 << "次搜索:" << G.Point[a] << "  " << G.Point[b] << "加入S" << endl;
        //cout << "当前res为: " << res << endl;
    }
    //2.分散成n个点树
    //3.挑选权值最小的边，将两个顶点合并到一个集合
    //4.继续挑选权值最小的边，合并到刚才的集合中
    //条件:当碰到某权值最小的边的两个顶点都在之前的集合中，出现圈现象，则跳过
    //终止条件:当集合S中
    //将S中所有的边权值累加，得出最小生成树的代价和res
    return res;
}

//Prim最小生成树算法
int PrimAlgothim(AMGraph G, int m)
{ //从G中的m结点为起点计算最小生成树
    //基于无向连通带权图
    int closest[G.pointNum]; //记录V-U顶点j到集合U的最邻近点下标
    int lowcost[G.pointNum]; //记录V-U中顶点j到集合U中最邻近点的边权值
    bool U[G.pointNum];
    U[m] = true; //初始U中只有m一个元素
    for (int i = 0; i < G.pointNum; i++)
    { //初始化lowcost[],closest[]
        if (i != m)
        {
            lowcost[i] = G.Edge[m][i];
            closest[i] = m;
            U[i] = false;
        }
        else
            lowcost[i] = 0;
    }
    for (int i = 0; i < G.pointNum; i++)
    {
        int temp = 100;
        int tpoint = m;
        for (int j = 1; j < G.pointNum; j++)
        { //在集合V-U中寻找距离集合U最近的顶点t
            if (!U[j] && lowcost[j] < temp)
            {
                tpoint = j;
                temp = lowcost[j];
            }
        }
        if (tpoint == m)
            break;
        U[tpoint] = true; //tpoint加入S
        for (int j = 0; j < G.pointNum; j++)
        {
            if (!U[j] && (G.Edge[tpoint][j] < lowcost[j]))
            {
                lowcost[j] = G.Edge[tpoint][j];
                closest[j] = tpoint;
            }
        }
    }
}

#define n 10
//合并
int nodeset[n];

int Merge(int a, int b)
{
    int p = nodeset[a];
    int q = nodeset[b];
    if (p == q)
        return 0;
    for (int i = 0; i < n; i++) //n为顶点数
    {
        if (nodeset[i] == q)
            nodeset[i] = p;
    }
    return 1;
}
/*
int Kruskaer2(AMGraph G)
{ //书中实现 || P308
    int ans = 0;
    for (int i = 0; i < G.pointNum; i++)
    {
        if (Merge())
    }
}
*/
int main()
{
    AMGraph G;
    CreateAMGraph(G);
    AMGraphBfs(G, 0);
    cout << endl;
    AMGraphDfs(G, 0);
    cout << endl;
    int value = Kruskaer(G);
    cout << endl;
    cout << "图G的最小生成树的代价为: " << value << endl;
    system("pause");
}