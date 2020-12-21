/*
BINARY_STRUCTED.h CONTAINS:
    BINARY_TREE  //链表存储结构二叉树

二叉链表存储结构：
struct BinaryTreeNode{
    Type data;
    BinaryTreeNode *Lchild;
    BInaryTreeNode *Rchild;
};

 三叉链表存储结构:
 struct BinaryTreeNode{
     type data;
     BinaryTreeNode *Parent;
     BinaryTreeNode *Lchild;
     BinaryTreeNode *Rchild;
 }
*/

#include<iostream>
using namespace std;

//二叉树抽象类
template <class type>
class BinaryTree;

//二叉树的节点类
template <class type>  class BinaryTreeNode{
    friend class BinaryTree<type>;  //设定友元二叉树抽象类以访问类中函数
    public:
        BinaryTreeNode();   //构造函数
        BinaryTreeNode(type &value):Lchild(NULL),Rchild(NULL){}
        BinaryTreeNode(type &value, BinaryTreeNode<type> *left = NULL, BinaryTreeNode<type> *right = NULL)
        {
            data = value;
            Lchild = Rchild = NULL;
        }
        BinaryTreeNode<type> *copy() const  //复制以当前节点为根的二叉树
        {
            BinaryTree Node<type> *newLeft, *newRchild;
            if(Lchild!=NULL)
                newLeft = Lchild->copy();  //递归调用复制左子树
            else
                newLeft = NULL;
            if(Rchild!=NULL)
                newRchild = Rchild->copy();
            else
                newRichld = NULL;
            BinaryTree Node<type> *newptr;
            newptr = new BinaryTree Node<type>(data, newLeft, newRight); //复制本节点
            assert(newptr != NULL);
            return newptr;
        }
        void release();  //删除以当前节点的左右子树
        type &GetData() const { return data; }//获取当前节点数据值
        BinaryTree Node<type> GetLeft() const { return Lchild; }//获取左孩子指针
        BinaryTree Node<type> GetRight() const { return Rchild; }//获取右孩子指针
        void SetData(type &value) { data = value; }//修改当前节点数据值
        void SetLeft(BinaryTree Node<type> *L) { Lchild = L; } //修改节点左孩子指针
        void SetRight(BinaryTree Node<type> *R) { Rchild = R; } // 修改结点右孩子指针
    private:
        type data;
        BinaryTree Node<type> *Rchild;  //左孩子树指针
        BinaryTree Node<type> *Lchild;  //右孩子树指针
};