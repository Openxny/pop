#include<iostream>

using namespace std;

//定义循环链表
typedef struct header{//头结点
	int length;//保存循环链表的信息
	struct node*next;//指向第一个数据节点
}head;

typedef struct node{//数据节点结构体
	int val;//数据域
	struct node*next;//指针域
}node;

//初始化循环链表
head *initlist(){
	head*p;//定义头结点
	p=(head*)malloc(sizeof(head));
    p->next=NULL;//此时没有数据节点，所以头结点指向NULL
	p->length=0;//初始化头结点
	return p;//返回创建好的头结点地址
}

//插入
void listinsert(head *p,int i,int e){
	if(p==NULL||i<0||i>p->length){
		cout<<"错误"<<endl;
		return;
	}

	node *temp=(node *)malloc(sizeof(node));
	temp->val=e;
	node *cur=p->next;//指向第一个数据结点
	node *last=p->next;//指向最后一个数据结点
	while(cur!=NULL&&last->next!=cur){//使last指向最后一个结点
		last=last->next;
	}

	if(p->length==0){//判断循环链表为空的情况
		p->next=temp;
		temp->next=temp;
	}
	else if(i==0){//头插
        last->next=temp;
		temp->next=cur;
		p->next=temp;
	}
	else if(i==p->length){//尾插
		last->next=temp;
		temp->next=cur;
	}
    else {
		node *pval=p->next;//pval用来指向要插入位置的数据结点
		for(int j=1;j<i;j++){
			pval=pval->next;
		}
		temp->next=pval->next;
		pval->next=temp;
	}
	p->length++;
	return;
}

//删除
void listdelete(head *p,int x){
	node *temp;//temp指向要删除的结点
	temp=p->next;
	for(int i=0;i<p->length;i++){
		if(temp->val==x)break;
		temp=temp->next;
	}
	if(temp->val!=x)cout<<"未找到元素"<<endl;
	node *cur=p->next;//cur指向第一个结点
    node *last=p->next;//last用来指向最后一个结点
	while(last->next!=cur){
		last=last->next;
	}
	if(p->length==1){//只有一个元素时
		p->next=NULL;
	}
    else if(temp==cur){//删除的是第一个结点
		p->next=cur->next;
		last->next=cur->next;
	}
	else if(temp==last){//删除的是最后一个结点
	    node *pre=p->next;//指向倒数第二个结点
		while(pre->next!=last){
			pre=pre->next;
		}
		pre->next=cur;
	}
	else {
		node *pre=p->next;
		while(pre->next!=temp){//使pre指向temp的前一个元素
			pre=pre->next;
		}
		pre->next=temp->next;
	}
	p->length--;
}

//输出
void output(head *p){
	if(p==NULL||p->length==0){
		cout<<"错误"<<endl;
		return;
	}
	node *temp=p->next;
	for(int i=0;i<p->length;i++){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
	return;
}

int main(){
	head *p;//定义循环链表头结点
	p=initlist();
	cout<<"请输入约瑟夫环的总人数:";
	int m;
	cin>>m;
	cout<<"请输入被踢出的报数:";
	int n;
	cin>>n;
	for(int i=m;i>0;i--){//围圈操作（即按要求构建循环链表）
		listinsert(p,0,i);
	}

	cout<<"输出初始循环链表:";
	output(p);

	node* temp=p->next;//定义指向循环链表第一个数据节点的指针，方便报数
    int count=1;//因为此时temp已经指向第一个人了，所以报数从1开始，多看几遍也许好理解一点
	printf("被踢顺序:");
    while(temp->next!=temp){
		if(count==n){//如果报数等于需要出局的数
		   node *pre=p->next;//用于保留位置使temp不至于丢失
		   while(pre->next!=temp){//遍历到指向temp的前一个节点
		       pre=pre->next;
		   }
		   cout<<temp->val<<" ";
		   listdelete(p,temp->val);//出局操作（即删除该数据节点）
           //此时如果没有前面定义的pre，那么temp就没有任何指向了，而有了pre，出局后就可以用temp代表pre的指向，temp就不会丢失指向
		   temp=pre;
		   count=0;//因为temp指向了出局的前一个人，下一个人报数从一开始，所以报数先归0
		   continue;//出局时就不执行遍历和报数操作
		}
		count++;
		temp=temp->next;
	}
	cout<<endl;
    cout<<"链表中最后被剩下的是:";
    output(p);

	return 0;
}
