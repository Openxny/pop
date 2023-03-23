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

//建立双链表（头插法）
DLinklist T(DLinklist &L){
    InitDLinklist(L); //初始化
    cout<<"头插法"<<endl;
    int n,x;
	cout<<"元素个数为：";
    cin>>n;
    cout<<"输入：";
    cin>>x;
    while(n--){
        DNode *s = (DNode *)malloc(sizeof(DNode));
        s->data = x;
        if(L->next == NULL){
            s->next = NULL;
            s->prior = L;
            L->next = s;
        }else{
            s->next = L->next;
            L->next->prior = s;
            s->prior = L;
            L->next = s;
        }
        if(n==0)break;
		else scanf("%d",&x);
    }
    return L;
}

//建立双链表（尾插法）
DLinklist W(DLinklist &L){
    InitDLinklist(L); //初始化
    cout<<"尾插法"<<endl;
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

//插入（前驱）
bool qinsert(DLinklist &L,int i,int e){
    if(i<1)return false;
    DNode *list;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	list=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(list!=NULL&&j<i){//循环找到第i个结点
		list=list->next;
		j++;
	}
    DNode *s=(DNode *)malloc(sizeof(DNode));
    s->data=e;
    s->prior=list->prior;
    list->prior->next=s;
    s->next=list;
    list->prior=s;
    return true;
}

//插入（当前位置）
bool dinsert(DLinklist &L,int i,int e){
    if(i<1)return false;
    DNode *list;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	list=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(list!=NULL&&j<i){//循环找到第i个结点
		list=list->next;
		j++;
	}
    list->data=e;
    return true;
}

//插入（后继）
bool hinsert(DLinklist &L,int i,int e){
    if(i<1)return false;
    DNode *list;//指针p指向当前扫描到的结点
	int j=0;//当前p指向的是第几个节点
	list=L;//L指向头结点，头结点是第0个结点（不存数据）
    while(list!=NULL&&j<i){//循环找到第i个结点
		list=list->next;
		j++;
	}
    DNode *s=(DNode *)malloc(sizeof(DNode));
    s->data=e;
    s->next=list->next;
    if(list->next!=NULL)list->next->prior=s;
    s->prior=list;
    list->next=s;
    return true;
}

//查找（按值）
DNode *Locatelem(DLinklist L,int x){
    DNode *p=L->next;
    while(p&&p->data!=x)p=p->next;
    return p;
}

//查找（按位）
DNode *Getelme(DLinklist L,int i){
    int j=1;
    DNode *p=L->next;
    if(i==0)return L;
    if(i<1)return NULL;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    cout<<"第2位元素是"<<p->data<<endl;
    return p;//如果i大于表长，p=NULL,直接返回p即可
}

//删除（前驱）
void qdelete(DLinklist &L,int i){
    if(i<1)return;

    int j=0;
    DNode *list=L;
    while(list&&j<i-1){//循环找到第i-1个结点
        list=list->next;
        j++;
    }
    
    DNode *p=list->next;
    list->next=p->next;
    if(p->next!=NULL)p->next->prior=list;
    free(p);
}

//删除（当前位置）
void ddelete(DLinklist &L,int i){
    if(i<1)return;

    int j=0;
    DNode *list=L;
    while(list&&j<i){//循环找到第i个结点
        list=list->next;
        j++;
    }

    DNode *p=list;
    p->prior->next=list->next;
    if(list->next!=NULL)list->next->prior=p->prior;
    free(p);
}

//删除（后继）
void hdelete(DLinklist &L,int i){
    if(i<1)return;

    int j=0;
    DNode *list=L;
    while(list&&j<i+1){//循环找到第i+1个结点
        list=list->next;
        j++;
    }

    if(list!=NULL){
        DNode *p=list->prior;
        list->prior=p->prior;
        p->prior->next=list;
        free(p);
    }
    else {//如果第i+1个结点为NULL
        int j=0;
        DNode *list=L;
        while(list&&j<i){
            list=list->next;
            j++;
        }
        list->prior->next=NULL;
    }
}

//双向链表的输出
void output(DLinklist L){
    DLinklist p=L->next;
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main(){
    DLinklist L1,L2;
    
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
    //插入（前驱）
    cout<<"前驱插入"<<endl;
    qinsert(L1,2,3);
    output(L1);
    cout<<endl;
    //插入（当前位置）
    cout<<"当前位置插入"<<endl;
    dinsert(L1,2,3);
    output(L1);
    cout<<endl;
    //插入（后继）
    cout<<"后继插入"<<endl;
    dinsert(L1,2,3);
    output(L1);
    cout<<endl;

    //查找（按值）
    if(Locatelem(L1,2))cout<<"找到元素2了"<<endl;
    else cout<<"没找到元素2"<<endl;
    cout<<endl;

    //查找（按位）
    Getelme(L1,2);
    cout<<endl;

    //删除（前驱）
    cout<<"前驱删除"<<endl;
    qdelete(L1,3);
    output(L1);
    cout<<endl;
    //删除（当前位置）
    cout<<"当前位置删除"<<endl;
    ddelete(L1,3);
    output(L1);
    cout<<endl;
    //删除（后继）
    cout<<"后继删除"<<endl;
    hdelete(L1,3);
    output(L1);
    cout<<endl;
    
    return 0;
} 
