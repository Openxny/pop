#include<iostream>

using namespace std;

//定义一个链表
typedef struct LNode{
	int date;
	struct LNode *next;
}LNode,*Linklist;

//创建一个链表（尾插法）
Linklist W(Linklist &L){
	int x,n;
    cout<<"元素个数为：";
	scanf("%d",&n);
    cout<<"输入：";
	L=(Linklist)malloc(sizeof(LNode));//建立头结点
    L=NULL;
	LNode *s,*r=L;//r为表尾指针
	scanf("%d",&x);//输入结点的值
	while(n--){//输入n个数
		s=(LNode *)malloc(sizeof(LNode));
		s->date=x;
        s->next=NULL;
        if(L==NULL){
            L=s;
            r=L;
        }
        else {
            r->next=s;
            r=s;
        }
        if(n==0)break;
		else scanf("%d",&x);
	}

	r->next=NULL;//尾结点指针置空
	return L;
}

//不带头结点的单链表头插
Linklist firstinsert(Linklist &list,Linklist &a){
    LNode *q;
    while(a!=NULL){
        q=(Linklist)malloc(sizeof(LNode));//建立一个新的结点
        q->date=a->date;//复制要倒置的数据
        q->next=list;//新节点指向原来的第一个结点，实现倒置
        list=q;//更新第一个结点，以便后续头插
        a=a->next;//更新需要倒置的数据
    }
    return q;//返回第一个结点，方便后续输出
}

//输出链表中的元素
void output(Linklist L){
	while(L!=NULL){
        cout<<L->date<<" ";
        L=L->next;
    }
	cout<<endl;
}

int main(){
    Linklist list;
    W(list);//创建单链表

    LNode *a=list->next;//断开链表头
    list->next=NULL;    //然后以头插法的方式将原链表的数据添加链表
    LNode *q=firstinsert(list,a);
    cout<<"链表倒置结果为：";
    output(q);//输出
    return 0;
}
