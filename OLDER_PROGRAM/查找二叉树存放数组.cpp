#include <iostream>
using namespace std;

int main(void)
{  
	int i,level;
	int data[]={0,6,3,5,9,7,8,4,2}; //原始数组
	int btree[16]={0}; //存放二叉树的数组
	cout<<"原始数组内容："<<endl;
	for (i=1;i<9;i++)
		cout<<"["<<data[i]<<"] ";
	cout<<endl;
	for(i=1;i<9;i++)   //把原始数组中的值逐一对比
	{  
		for(level=1;btree[level]!=0;)//比较树根和数组内的值
		{  
			if(data[i]>btree[level]) //如果数组内的值大于树根，则往右子树比较
				level=level*2+1;
			else  //如果数组内的值小于或等于树根，则往左子树比较
				level=level*2;
		}         //如果子树节点的值不为0，则再与数组内的值比较一次
		btree[level]=data[i];        //把数组值放入二叉树
	}
	cout<<"二叉树内容："<<endl;
	for (i=1;i<16;i++)
		cout<<"["<<btree[i]<<"] ";
	cout<<endl;
	system("pause");
	return 0;
}
/*

class tree //节点链表结构声明
{  
	public:
	int data; //节点数据
	class tree *left,*right; //节点左指针和右指针
};

typedef class tree node;
typedef node *btree;

void Inorder(btree ptr)
{
	if(ptr!=NULL)
	{
		Inorder(ptr->left); //遍历左子树
		cout<<"["<<ptr->data<<"]"; //遍历并打印树根
		Inorder(ptr->right); //遍历右子树
	}
}

*/