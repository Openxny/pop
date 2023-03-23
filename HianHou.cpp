#include<iostream>

using namespace std;

//定义双向链表
typedef struct DNode{//定义双链表结点类型
    int data;//数据域
    struct DNode *prior,*next;//前驱和后继指针
}DNode,*DLinklist;

//初始化双链表（带头结点）
bool InitDLinklist(DLinklist &L){
    L=(DNode *)malloc(sizeof(DNode));//分配一个头结点
    if(L==NULL)return false;//内存不足，分配失败
    L->prior=NULL;//头结点的prior永远指向NULL
    L->next=NULL;//头结点之后暂时还没有结点
    return true;
}

//建立双链表（尾插法）
DLinklist W(DLinklist &L){
    InitDLinklist(L); //初始化
    int n,x;
    cout<<"元素个数为：";
    cin>>n;
    cout<<"输入：";
    cin>>x;
    DNode *s,*r=L;
    while(n--){
        s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        s->next=NULL;
        s->prior=r;
        r->next=s;
        r=s;
        if(n==0)break;
		else scanf("%d",&x);
    }
    return L;
}

//找前驱元素
void precursor(DLinklist L,int n){
    DNode *list;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	list=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(list!=NULL&&j<n){//循环找到第n个结点
		list=list->next;
		j++;
	}

    if(list->prior->prior==NULL)cout<<"不存在前驱元素"<<endl;
    else cout<<"前驱元素为："<<list->prior->data<<endl;
}

//找后继元素
void successor(DLinklist L,int n){
     DNode *list;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	list=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(list!=NULL&&j<n){//循环找到第n个结点
		list=list->next;
		j++;
	}

    if(list->next==NULL)cout<<"不存在后继元素"<<endl;
    else cout<<"后继元素为："<<list->next->data<<endl;
}

//输出
void output(DLinklist L){
    DLinklist p=L->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    DLinklist L;
    
	L=W(L);//创建

    cout<<"请输入元素n:";
    int n;
    cin>>n;
    precursor(L,n);//前驱
    
    successor(L,n);//后继
    
    return 0;
}
