#include <iostream>
#include <iomanip>
using namespace std;
class tree //节点链表结构的声明
{  
	public :
	int data; //节点数据
	class tree *left,*right; //节点左指针和右指针 
};
typedef class tree node;
typedef node *btree;   //btree是一个指向二叉树各个结点的指针
btree creat_tree(btree,int);  //为二叉树添置结点的函数
void pre(btree);   //二叉树的三种遍历算法
void in(btree);
void post(btree);

btree creat_tree(btree root,int val)//建立二叉树的子程序 [细节：此处boot为需要添置结点的二叉树的根节点]
{  
	btree newnode,current,backup;   //声明一个新节点newnode存放数组数据 
	newnode = new node; //current和backup存放暂存指针 
	newnode->data=val;  //指定新节点的数据和左右指针 
	newnode->left=NULL;
	newnode->right=NULL;
	if (root==NULL)//如果root为空值，把新节点返回当作树根 
	{  
		root=newnode;
		return root;
	}
	else //若root不是空值，则建立二叉树 
	{  
		//循环遍历找到添置的叶子节点	
		for(current=root;current!=NULL;) //current复制root，以保留当前的树根值 
		{  
			backup=current; //保留父节点 
			if(current->data > val)//比较树根节点和新节点数据 
				current=current->left;
			else
				current=current->right;
		}
		if(backup->data >val)//把新节点和树根连接起来 
			backup->left=newnode;
		else
			backup->right=newnode;
	}
	return root; //返回树指针 
}


void pre(btree ptr) //前序遍历 
{  
	if (ptr != NULL)
	{  
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		pre(ptr->left);
		pre(ptr->right);
	}
}


void in(btree ptr) //中序遍历 
{  
	if (ptr != NULL)
	{  
		in(ptr->left);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
		in(ptr->right);
	}
}


void post(btree ptr)//后序遍历
{  
	if (ptr != NULL)
	{  
		post(ptr->left);
		post(ptr->right);
		cout<<"["<<setw(2)<<ptr->data<<"] ";
	}
}

int main(void)
{  
	int arr[]={7,4,1,5,16,8,11,12,15,9,2};//原始数组内容 
	btree ptr=NULL; //声明树根 
	cout<<"[原始数组内容]"<<endl;
	for (int i=0;i<11;i++)//建立二叉树，并将二叉树内容打印出来 
	{  
		ptr=creat_tree(ptr,arr[i]);
		cout<<"["<<setw(2)<<arr[i]<<"] ";
	}
	cout<<endl;
	cout<<"[二叉树的内容]"<<endl;
	cout<<"前序遍历结果："<<endl;//打印前、中、后序遍历结果 
	pre(ptr);
	cout<<endl;
	cout<<"中序遍历结果："<<endl;
	in(ptr);
	cout<<endl;
	cout<<"后序遍历结果："<<endl;
	post(ptr);
	cout<<endl;
	system("pause");
	return 0;
}