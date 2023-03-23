#include<iostream>

using namespace std;


//定义一个链表
typedef struct LNode{
	int date;
	struct LNode *next;
}LNode,*Linklist;

//创建一个链表（头插法）
Linklist T(Linklist &L){
	int x,n;
	cout<<"头插法"<<endl;
	cout<<"元素个数为：";
	scanf("%d",&n);
	cout<<"输入：";
	L=(Linklist)malloc(sizeof(LNode));//建立头节点
	LNode *s;
	L->next=NULL;//初始为空链表
	scanf("%d",&x);//输入结点的值
	while(n--){//输入n个数
		s=(LNode *)malloc(sizeof(LNode));//创立新结点
		s->date=x;
		s->next=L->next;
		L->next=s;
		if(n==0)break;
		else scanf("%d",&x);
	}
    return L;
}
//创建一个链表（尾插法）
Linklist W(Linklist &L){
	int x,n;
	cout<<"尾插法"<<endl;
	cout<<"元素个数为：";
	scanf("%d",&n);
	cout<<"输入：";
	L=(Linklist)malloc(sizeof(LNode));//建立头结点
	LNode *s,*r=L;//r为表尾指针
	scanf("%d",&x);//输入结点的值
	while(n--){//输入n个数
		s=(LNode *)malloc(sizeof(LNode));
		s->date=x;
        r->next=s;
		r=s;//r指向新的表尾结点
		if(n==0)break;
		else scanf("%d",&x);
	}

	r->next=NULL;//尾结点指针置空
	return L;
}

//向链表中插入元素
bool listinsert(Linklist &L,int i,int e){
	if(i<1)return false;
	LNode *p;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	p=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(p!=NULL&&j<i-1){//循环找到第i-1个结点
		p=p->next;
		j++;
	}
	if(p==NULL)return false;
	LNode *s=(LNode *)malloc(sizeof(LNode));
	s->date=e;
	s->next=p->next;
	p->next=s;
	return true;

}

//删除链表中的某个元素
bool listdelete(Linklist &L,int i,int &e){
    if(i<0)return false;
	LNode *p;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个结点
	p=L;//L指向头结点，头结点是第0个结点（不存数据）
	while(p!=NULL&&j<i-1){//循环找到第i-1个结点
		p=p->next;
		j++;
	}
	if(p==NULL)return false;//i值不合法
	if(p->next==NULL)return false;//第i-1个结点之后已无其他结点
	LNode *q=p->next;//令q指向被删除结点
	e=q->date;//用e返回元素的值
	p->next=q->next;//将*q结点从链中断开
	free(q);//释放结点的存储空间
	return true;//删除成功
}

//查找链表中的元素（按值找）
LNode *LocateElem(Linklist L,int e){
    LNode *p=L->next;
	//从第1个结点开始查找数据域为e的结点
	while(p!=NULL&&p->date!=e){
		p=p->next;
	}
	return p;//找到后返回该结点指针，否则返回NULL
}

//查找链表中的元素（按位找）
LNode *GetElem(Linklist L,int i){
	if(i<0)return NULL;
	LNode *p;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个结点
	p=L;//L指向头结点，头结点是第0个结点（不存数据）
	while(p!=NULL&&j<i){//循环找到第i个结点
		p=p->next;
		j++;
	}
	cout<<"该元素是"<<p->date<<endl;
	return p;
}

//输出链表中的元素
void output(Linklist L){
	LNode *p=L->next;
	while(p!=NULL){
		cout<<p->date<<" ";
		p=p->next;
	}
	cout<<endl;
}

int main(){
    Linklist L1,L2;
    
	//头插法创建链表
	L1=T(L1);
	cout<<"则该链表为：";
	output(L1);
	cout<<endl;

	//尾插法创建链表
	L2=W(L2);
	cout<<"则该链表为：";
	output(L2);
    cout<<endl;

	cout<<"以下对第一个链表进行操作"<<endl;
	//向链表中插入元素
	cout<<"向链表第二个位置插入3";
	listinsert(L1,2,3);
	cout<<"结果为：";
	output(L1);
    cout<<endl;

	//向链表中删除元素
	cout<<"删除链表第二个位置元素";
	int e=0;
	listdelete(L1,2,e);
	cout<<"结果为：";
	output(L1);
    cout<<"被删除的元素是"<<e<<endl;
    cout<<endl;

	//查找链表中的元素（按值找）
	if(LocateElem(L1,2)!=NULL)cout<<"找到了元素2"<<endl;
	else cout<<"没找到元素2"<<endl;
    cout<<endl;
    
	//查找链表中的元素（按位找）
	cout<<"查找第二位元素"<<endl;
    GetElem(L1,2);

    return 0;
}
