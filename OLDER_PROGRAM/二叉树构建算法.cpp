#include <iostream>
#include <cstdlib>
#include <iomanip>
#define ArraySize 10
using namespace std;
class Node//二叉树节点数据结构的声明 

{
    public:
    int value;//节点数据
    class Node *left_Node;//指向左子树的指针
    class Node *right_Node;//指向右子树的指针
};

typedef class Node TreeNode;//定义新的二叉树节点数据类型
typedef TreeNode *BinaryTree;//定义二叉树指针
BinaryTree rootNode;//二叉树的根节点的指针 

//将指定的值加入到二叉树中适当的节点
void Add_Node_To_Tree(int value)
{
      BinaryTree currentNode;
      BinaryTree newnode;
      int flag=0;//用来纪录是否插入新的节点
      newnode=(BinaryTree) malloc(sizeof(TreeNode));
      //建立节点内容
      newnode->value=value;
      newnode->left_Node=NULL;
      newnode->right_Node=NULL;
      //如果为空的二叉树,便将新的节点设定为根节点
      if(rootNode==NULL)
          rootNode=newnode;
      else 
      {
          currentNode=rootNode;//指定一个指针指向根节点
          while(!flag)
            if (value<currentNode->value) 
            { //在左子树
               if(currentNode->left_Node==NULL)
               {
                  currentNode->left_Node=newnode;
                  flag=1;
               }
               else
                  currentNode=currentNode->left_Node;
            }
            else
            { //在右子树
               if(currentNode->right_Node==NULL) 
               {
                  currentNode->right_Node=newnode;
                  flag=1;
               }
               else
                  currentNode=currentNode->right_Node;
            }
      }
}
int main(void)
{
    int tempdata;
    int content[ArraySize];
    int i=0;
    rootNode=(BinaryTree) malloc(sizeof(TreeNode));    //能否不要这条语句？？？？？？？
    rootNode=NULL;
    cout<<"请连续输入10项数据: "<<endl;
    for(i=0;i<ArraySize;i++)
    {
      cout<<"请输入第"<<setw(1)<<(i+1)<<"项数据: ";
      cin>>tempdata;       
      content[i]=tempdata;
    }
    for(i=0;i<ArraySize;i++) 
         Add_Node_To_Tree(content[i]);
    cout<<"完成以链接的方式建立二叉树";
    cout<<endl;  
	system("pause");
	return 0;
}
