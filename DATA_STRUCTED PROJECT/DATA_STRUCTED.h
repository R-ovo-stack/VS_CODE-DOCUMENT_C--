//类模板方法测试情况：
//循环链表测试不通过
//其余模板方法目前为出现bug
/*
DATA_STRUCTED.H CONTAINS:
    SEQLIST   简单可扩容顺序表
    CIR_LINKLIST   循环链表
    SIMPLE_LINKLIST   简单单链表
    DB_LINKLIST    双向链表
*/

/*线性表*/
#include<iostream>
#include<assert.h>
#include<string>
//extern ostream cout;
//清空函数出现异常，需要重构
template <class type>   //抽象线性表类定义
class ablist     //增删查改虚函数定义
{
public:
//   ablist(Length=0){}    //虚基类构造函数
//    int GetLength() {    return Length;  }    //获取线性表有效结点长度并返回    查
    virtual type Get(int i)=0;    //取出第i个元素并返回     查
    virtual bool Set(type value,int i)=0;    //对第i个结点元素设置数据value      改
    virtual void MakeEmpty()=0;   //置为空表    操作
    virtual bool Insert (type value,int i)=0;   //第i个位置插入value    增
  //  virtual type Remove(int i)=0;    //删去第i个结点     删
  //  virtual type Remove1(type value)=0;   //将元素值为value的结点删去     删
protected:
    int Length;     //线性表有效结点长度
	type n;
};

template <class type>
//定义顺序性表类,该类由线性表基类派生   [VECTOR]
class Seqlist:public ablist<int>  //此处若为ablist<type>  为什么派生类模板找不到Length基类变量
//length是C++11之后的关键词吗?
{
protected:
 //   int Length;
    type *elements;    //指向数组的指针
    int maxsize;    //线性表最大长度
public:
    Seqlist(int maxsz=10)    //默认构造函数
    {
        maxsize=maxsz > 10 ? maxsz : 10;
        Length=0;    //有效结点数置零
        elements=NULL;   //指针初始化置空
        elements=new type[maxsize];  //重新分配内存空间
        assert(elements!=NULL);    //分配不成功则警告并退出
    }
    ~Seqlist()   //析构函数
    {   if(elements)  delete []elements;    }
    bool Expand(int newmaxsz)   //扩容函数[满足特定条件才扩容]
    {
        type *p,*q;
        if(newmaxsz<=maxsize)
        {
           std::cout<<"new maxsize is smaller than current one !"<<std::endl;
            return false;
        }
        p=new type[newmaxsz];
        if(!p)
        {
            std::cout<<"cannot Expand Seqlist !"<<std::endl;
            return false;
        }
        memmove(p,elements,sizeof(type)*Length);   //将原内容复制到新分配第内存空间
        q=elements;  //保存原内存区地址
        elements=p;
        delete []q;
        maxsize=newmaxsz;
        return true;
    }
    bool Set(type value,int index)    //设置结点i值函数
    {
        if(index>=maxsize)
        {
            std::cout<<"index is out of range ! "<<std::endl;
            return false;
        }
        if(index>=Length)
        {
            index=Length+1;
            elements[index]=value;
            return true;
        }
        else
        {
            elements[index]=value;
            return true;
        }
    }
    int Gets()
    {   return maxsize; }
    int Gets(int)
    {
        return Length;
    }
    type Get(int index)    //返回（获取）结点index的元素值
    {
        assert(index<Length);
        return elements[index];
    }
    void MakeEmpty()   //线性表置空函数[先清除内存再进行数组有效长度置零]
    {
        if (elements)
            delete[] elements;
        elements = NULL;
        Length = 0;
        std::cout << "Seqlist is cleaned !" << std::endl;
    }
    bool Insert(type value,int i)      //插入函数
    {
        int j;
        if(i>=maxsize)
        {
            if(Expand(maxsize*1.5))
                elements[Length]=value;
            else{std::cout<<"could't expand Seqlist"<<std::endl;  return false;}
        }
        else if(i>=Length)
            elements[Length]=value;
        else
        {
            for(j=Length;j>i;j--)
                elements[j]=elements[j-1];
            elements[j]=value;
        }
        Length++;
        return true;
    }
    type Remove(int index)     //删除指定位置结点并返回删除的结点元素内容
    {
        int i;
        assert(index<maxsize);
        type value=elements[index];
        for(i=index;i<Length-1;i++)
            elements[i]=elements[i+1];
        Length--;
        return value;
    }
    type Remove1(type value)   //删除指定内容结点并返回删除的结点元素内容
    {
        int i;
        int index;
        for(i=0;i<Length;i++)
        {      
            if(elements[i]==value)
                    break;
        }
        index=i;
        assert(index<Length);   //未找到则警告返回
        for(i=index;i<Length-1;i++)
            elements[i]=elements[i+1];
        Length--;
        return value;
    }
    Seqlist<type> & Copy(Seqlist<type> &s1)    //拷贝函数    ****此处并非拷贝构造函数****
    {
        if(elements)    delete []elements;
        maxsize=0;
        Length=0;
        elements=new type[s1.maxsize];
        if(elements)
        {
            maxsize=s1.maxsize;
            Length=s1.Length;
            memmove(elements,s1.elements,sizeof(type)*maxsize);
        }
        return *this;
    }
    Seqlist<type> & operator = (Seqlist<type> &s1)  //重载=运算符
    {
        Copy(s1);   return *this;
    }
    bool push_back(type value)
    {
        int index = Length;   //事实上此处不必定义额外变量index
        if(index>=maxsize)
        {
            if(Expand(maxsize*1.5))
            {
                elements[index] = value;
                Length++;
                return true;
            }
            else
            {
                std::cout << "EXPAND ERROR !" << std::endl;
                return false;
            }
        }
        else
        {
            elements[index] = value;
            Length++;
            return true;
        }
    }
	type pop_back(void)     //删除线性表最后一个结点并返回该结点
    {
        type p = elements[Length];
        --Length;
        return p;
    }
    friend std::ostream & operator << (std::ostream &print ,const Seqlist<type> & s1)     //重载输出<<运算符
    {
        if(s1.elements)
        {
            int i = 0;
            print << "\n maxsize: " << s1.maxsize << " Length : " << s1.Length << std::endl;
            for (i = 0; i < s1.Length; i++)
                print << s1.elements[i] << "  ";
            print << std::endl;
        }
        else
            print << "Seqlist is empty !" << std::endl;
        return print;
    }
};

//template <class type>
//定义链表链结点
/*
class ListNode
{
public:
    type data;   //存储自身结点信息
    ListNode<type> *next;   //存储后一个结点的地址  结点类型指针！
    ListNode()  //构造函数
    {
        next = NULL;
    }
    ListNode(const type& item,ListNode <type> *next1=NULL)  //带参构造函数
    {
        data = item;
        next = next1;
    }
};
*/
/*定义双向链表链结点 ListNode*/
template <class type> class ListNode{
    public:
        ListNode()
        {
            next = NULL;
        }
        ListNode(const type & item , ListNode<type> *next1=NULL)
        {
            data = item;
            next = next1;
        }
        type data;
        ListNode<type> *next, *pre;
};
template <class type>
//抽象链表类  因为链表有很多种类型 故以基类写出多种类型链表的统一FUNCTION 
//该链表继承了超类唯一保护成员Length
class ablinklist:public ablist<int>
{
    protected:
        ListNode<int> *head;   //链表头指针  第一个链结点的地址  仅存储链表第一个节点的地址
        //不影响链表长度Length,head->next即为第一个有效节点地址
    public:
        ListNode<int> *GetHead()   //获取头结点指针
        {
            return head;
        }
        ListNode<int> *GetNext(ListNode<int> &n) //得到结点n的下一个结点位置*next
        {
            return n.next == head ? n.next->next : n.next; //使用三目运算符简化代码
        }
        type Get(int i) //获取结点i的内容
        //先查找到对应结点再操作
        {
            ListNode<int> *p = Find2(i);
            assert(p && p != head);   //断言不太擅长   
            return p->data;
        }
        bool Set(type value, int i)  //设置第i 个结点的元素内容
        //该方法需先通过i查找对应结点再进行设置元素值
        {
            ListNode<int> *p = Find2(i);
            if(p==NULL||p==head)
                return false;
            else
                p->data = value;
            return true;
        }
        //查找结点
        ListNode<int> *Find1(type value)  //通过输入结点元素以查找整个结点并返回
        //确保所有链结点中存在与value等价的元素
        {
            ListNode<int> *p = head->next;
            int i = 1;
            while (i++<=Length && p->data!=value)
            {
                p = p->next;
            }
            return p;
        }
        ListNode<int>* Find2(int i)  //通过结点索引查找结点元素并返回
        {   //i为索引值
            if(i<0||i>Length)
                return NULL;
            if(i==0)   //此处与数组类似，0为第一个节点索引下标
                return head;
            ListNode<int> *p = head->next;    //设置遍历指针并初始化为首元节点指针
            int j = 1;   //设置j计时器对p的下移进行移动次数控制
            while(p!=NULL && j<i)
            {
                p = p->next;
                j++;
            }
            return p;
        }
        void MakeEmpty()   //删除链表所有内容
        {
            ListNode<int> *p = head->next;
            int i = 1;
            while(i++<=Length)  //包括i也在循环内dir
            {
                head->next = p->next;//头节点后移导致p指针后移以逐个删除所有头节点后续节点 
                //头节点不属于Length包含范围
                delete p;
                p = head->next;
            }
            Length = 0;  //有效链表节点数置零
        }
        // 实现链表多态FUNCTION
//        virtual bool Insert(type value, int i) = 0;   //指定位置插入函数
 //       virtual type Remove1(int i) = 0;   //通过结点索引删除指定结点
 //       virtual type Remove2(type value) = 0;  //通过查找内容以删除相应结点
};

template<class type> class SIMPLE_LINKLIST:public ablinklist<int>{    //该单链表类继承了基础成员head 与 Length
public:
    SIMPLE_LINKLIST()   //默认构造函数
    {
        head = new ListNode<int>;  //建立头节点
        Length = 0;  //初始化链表长度为0
    }
    SIMPLE_LINKLIST( SIMPLE_LINKLIST<type> &L)   //拷贝构造函数用于拷贝一个现有类建立新链表
    {
        Copy(L);
    }
    ~SIMPLE_LINKLIST()
    {
        MakeEmpty();   //链表置空
        delete head;   //释放头节点占用空间
    }
    bool Insert(type  value,int i)  //重写虚函数插入函数[链表索引也从0开始]
    {   //定位插入点的前一位置，利用next指针插入元素
        ListNode<int> *p = Find2(i - 1);
        if(p==NULL)
            return false;
        ListNode<type> *newnode = new ListNode<type>(value, p->next);
        assert(newnode);
        p->next = newnode;
        Length++;
        return true;
    }
    type Remove1(int i)  //删除指定i位置的节点
    {
        ListNode<int> *p = Find2(i - 1);
        ListNode<int> *q;
        assert(p && p->next);
        q = p->next;
        p->next = q->next;
        type value = q->next;
        delete q;
        Length--;
        return value;
    }
    ListNode<int> *Push_back(type value)    //在链表尾部增加节点
    {
        ListNode<int> *p = head;
        while(p->next!=NULL)
        {
            p = p->next;
        }
        ListNode<int> *q = new ListNode<int>;
        q->data=value;
        p->next = q;
        Length++;
        return q;
    }
    ListNode<int> *Pop_back()
    {
        ListNode<int> *p = head, *q;
        while(p->next->next!=NULL)  //遍历找出尾节点前一节点
        {
            p = p->next;
        }
        q = p->next;
        p->next = NULL;  //删除尾节点
        delete q;
        Length--;
        return q;
    }

    //已重构//////////////////////////////////

    type Remove2(type value)   // value 为 ListNode 的data项
    {
        /*
        ListNode<type> *p = Find1(value);
        ListNode<type> *q;
        q->next = p;
        assert(p && q);
        q->next = p;
        q->next = p->next;
        Length--;
        delete p;
        */

        ListNode<int> *p, *q = head;   //定义p为value的节点地址
        while (q->next != NULL && q->next->data!=value)   //找到value前一个节点
        {
            q = q->next;
        }
        assert(q->next);
        p = q->next;   //p为value节点
        q->next = p->next;
        delete p;
        Length--;
        return value;
    }
    SIMPLE_LINKLIST<type> Copy(SIMPLE_LINKLIST<type> &l)
    {
        ListNode<int> *p, *q, *r;
        Length = l.Length;   //复制链表长度
        head = NULL;   //初始化 head 指针
        if(!l.head)
            return *this;
        head = new ListNode<int>;  //给 head 赋予空间地址
        if(!head)
            return *this;
        head->data = (l.head)->data;//将L的头节点地址复制给当前链表的头节点地址
        head->next = NULL;
        r = NULL;   //r作为新创建节点的暂时媒介指针域
        p = head;   //扫描指针初始化为头指针
        q = l.head->next; //l的首元节点指针域复制给q
        while(q)
        {
            r = new ListNode<int>;  //new一个新节点并将其复制给P指针
            if(!r)
                return *this;
            r->data = q->data;
            r->next = NULL;
            p->next = r;  
            p = p->next;  //p指针后移
            q = q->next;   //q指针后移
        }
        return *this;
    }
    //重载=赋值运算符
    SIMPLE_LINKLIST<type> operator = (SIMPLE_LINKLIST<type> &l)
    {
        if(head)
            MakeEmpty();
        Copy(l);     //调用Copy将l复制给当前链表
        return *this;
    }
    //重载<<输出运算符
    friend std::ostream & operator << (std::ostream & out,const SIMPLE_LINKLIST<type> &l)
    {
        ListNode<int> *p = l.head->next; //p为l首元节点
        out << "Length: " << l.Length << "\n Data : " << std::endl;
        while(p)
        {
            out << p->data << "  ";
            p = p->next;
        }
        out << std::endl;
        return out;
    }
};

template<class type> class CIR_LINKLIST:public ablinklist<int>{
    public:
        CIR_LINKLIST()  //默认无参构造函数
        {
            tail = head = new ListNode<int>;
            tail->next = head;
            Length = 0;
        }

        CIR_LINKLIST(CIR_LINKLIST<type> &l)   //拷贝构造函数
        {
            Copy(l);
        }
        ~CIR_LINKLIST()  //析构函数  释放抢占的内存
        {
            MakeEmpty();  //超类内已经实现了该函数方法
            delete head;
        }
        bool Insert(int value , int i)   //插入函数
        {
            //首先找到i的前一个结点
            ListNode<int> *p = Find2(i - 1);
            if(p==NULL)
                return false;
            ListNode<int> *newnode = new ListNode<int>(value, p->next); //为该结点数据域以及指针域传入实参
            if(p->next==head)   //如果p为尾节点
            {
                tail = newnode;
                tail->next = head;
            }   
            p->next = newnode;   //正常情况下
            Length++;   //链表长度加一
            return true;
        }
        ListNode<int> *Push_back(type value)    //在链表尾部增加节点
        {
    //            ListNode<int> *p;
            ListNode<int> *newnode = new ListNode<int>(value, tail->next);
            tail = newnode;
            tail->next = head;
            Length++;
            return newnode;
        }

        //异常应该在变量进行方法之前就预先检查并优先被抛出


        type Remove1(int i)   //根据下标索引删除节点并返回被删除的结点
        {
            ListNode<int> *p = Find2(i - 1), *q;
            assert(!(p->next == head || p == NULL));
            q = p->next;
            type value = q->data;
            //if(q->next=head)
            if(q==tail)
            {               
                tail = p;
                tail->next = head;
            }
            p->next = q->next;
            delete q;
            Length--;
            return value;
        }
        type Remove2(type value)   //根据内容索引删除节点
        {
            ListNode<int> *p, *q = head;
            while(q->next!=head && q->next->data!=value)
                q = q->next;
            assert(!(q->next == head && q->data != value));  //到表尾仍然没有找到value则退出程序
            p = q->next;
            p->next = q->next;
            if(p==tail)
            {
                q->next = head;
                q = tail;
            }
            delete p;
            Length--;
            return value;
        }
        type Pop_back()   //删除尾巴结点
        {
            ListNode<int> *p, *q = head;
            while(q->next !=tail)  //找到尾巴结点前一个结点
                q = q->next;
            assert(q->next == tail);
            p = q->next;
            type value = p->data;
            q = tail;
            tail->next = head;
            delete p;
            Length--;
            return value;
        }
        CIR_LINKLIST<type> & Copy(CIR_LINKLIST<type> & l)   //Copy拷贝函数
        {
            ListNode<int> *p, *q, *r;  
            Length = l.Length;  //复制链表长度
            head = tail = NULL;  //初始化头尾指针为NULL
            if(!l.head)
            {
                return *this;
            }
            head = new ListNode<int>;   //创建本体链表头指针，也就是头结点
            if(!head)
                return *this;
            head->data = (l.head)->data;  //首先对本体表头结点数据域进行赋值
            tail = head;  //头尾相连   ，头尾结点均为空结点
            tail->next = head;
            r = head;  //临时变量
            p = head;  //本体链表循环扫描指针
            q = l.head->next;  //待拷贝链表循环扫描指针
            while(q!=l.head)  //依次对每个结点进行复制
            {
                r = new ListNode<int>;
                if(!r)   
                    return *this;
                r->data = q->data;   //保证在本体链表尾部增加结点并赋值以及与头结点相连
                r->next = head;
                p->next = r;
                tail = r;
                p = p->next;
                q = q->next;
            }
            return *this;
        }
        CIR_LINKLIST<type> &operator = (CIR_LINKLIST<type> &l)  //重载=复赋值运算符
        {
            if(head)    //若本链表非空  先清空链表
                MakeEmpty();
            Copy(l);   //调用Copy将l复制给本链表
            return *this;
        }
        friend std::ostream & operator << (std::ostream & print , const CIR_LINKLIST<type> & l)  //重载输出<<运算符
        {
            print << "THE CIR_LINKLIST'S WILL BE DISPLAY : " << std::endl;
            print << "THE LENGTH IS : " << l.Length << std::endl;
            ListNode<int> *q = l.head->next;
         //   while (q != tail)
            while( q != l.head)
            {
                print << q->data << "  ";
                q = q->next;
            }
            print << std::endl;
            return print;
        }
    private:
        ListNode<int> *tail;   //尾指针
};

//循环链表尚未通过测试!!!!!!!

//带有头结点以及循环结构的双向链表
template<class type> class DBLINKLIST:public ablinklist<int>{
    public:
        DBLINKLIST()
        {
            Length = 0;
            tail = head = new ListNode<type>;
            tail->next = head;
            tail->pre = head;
        }
        DBLINKLIST(DBLINKLIST &l)   //拷贝构造函数
        {
            Copy(l);
        }
        ~DBLINKLIST()
        {
            MakeEmpty();
            delete head;
        }
        bool Insert(type value,int i)
        {
            ListNode<type> *p = Find2(i - 1);
            if(p==NULL)
                return false;
            //创建新的结点
            ListNode<type> *newnode = new ListNode<type>(value);
            if(p->next==head)
            {
                tail = newnode;
                tail->next = head;
                head->pre = tail;
            }
            newnode->pre = p;
            newnode->next = p->next;
            p->next->pre = newnode;
            p->next = newnode;
            Length++;
            return true;
        }
        type Remove1(int i)
        {
            ListNode<type> *p = Find2(i - 1), *q;
            assert(!(p == NULL || p->next == head));

            //画图是一个很好用来理解以及写算法代码的好方法！！！！！

            q = p->next;
            p->next = q->next;
            q->next->pre = p;
            type value = q->data;
            if(q==tail)
            {
                tail = p;
                tail->next = head;
                head->pre = p;
            }
            delete q;
            Length--;
            return value;
        }
        type Remove2(type value)
        {
            ListNode<type> *p, *q=head;
            while(q->next!=head && q->next->data!=value) //遍历所有除头结点以外结点找出value前一个结点
            {
                q = q->next;
            }
            assert(!(q == NULL || q->next == head));
            p = q->next;
            q->next = p->next;
            p->next->pre = q;
            if(p==tail)
            {
                tail = q;
                tail->next = head;
                head->pre = q;
            }
            delete p;
            Length--;
            return value;
        }
        DBLINKLIST<type> & Copy (DBLINKLIST<type> & l)
        {
            ListNode<type> *p, *q, *r;
            Length = l.Length;
            head = tail = NULL;
            if(!l.head)
                return *this;
            head = new ListNode<type>;
            if(!head)
                return *this;
            head->data = l.head->data;
            tail = head;
            tail->next = head;
            tail->pre = head;
            r = head;
            p = head;
            q = l.head->next;
            while(q!=l.head)
            {
                r = new ListNode<type>;
                if(!r)
                    return *this;
                r->data = q->data;
                r->next = head;
                r->pre = p;
                p->next = r;
                tail = r;
                p = p->next;
                q = q->next;
            }
            return *this;
        }
        DBLINKLIST<type> & operator = (DBLINKLIST<type> &l)
        {
            if(head)
                MakeEmpty();
            Copy(l);
            return *this;
        }
        friend std::ostream & operator << (std::ostream & out ,const DBLINKLIST<type> & l)
        {
            DBLINKLIST<type> *p = l.head->next;
            out << "\n"
                << "Length is : " << l.Length << "\n data : ";
            while(p!=l.head)
            {
                out << p->data << "  ";
                p = p->next;
            }
            out << std::endl;
            return out;
        }
    protected:
        ListNode<type> *tail;
};

//if you use '-fpermissive', G++ will accept your code, but allowing the use of an undeclared name is deprecated
