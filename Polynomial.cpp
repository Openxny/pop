#include<iostream>

using namespace std;

//多项式的定义
typedef struct Lnode{
    int coef;//系数
    int expn;//指数
    struct Lnode *next;
}Lnode,*Linklist;

//尾插法建立多项式单链表
Linklist Creat(Linklist &L){
    Linklist rear;//为尾指针
    //对链表进行初始化
    L=(Lnode *)malloc(sizeof(Lnode));
    L->next=NULL;

    rear=L;
    int c=1;//系数
    int e;//指数
    int num;
    Linklist s;
    while(c){
        cin>>c>>e;
        if(c==0)break;//如果为0则跳出循环结束
        s=(Lnode *)malloc(sizeof(Lnode));//申请新节点
        s->coef=c;//尾插
        s->expn=e;
        rear->next=s;
        rear=s;
    }
    rear->next=NULL;
    return L;
}

//多项式输出
void output(Linklist L){
    Linklist p=L->next;
    int flag=1;//定义标志是为了在第一个项式前不加'+’号

    while(p){
        if(p->coef>0&&flag!=1)cout<<"+";
        if(p->coef!=1&&p->coef!=-1){
            cout<<p->coef;
            if(p->expn==1)cout<<"x";
            else if(p->expn)cout<<"x^"<<p->expn;
        }
        else {
            if(p->coef==1){//条件：系数为1 
                if(!p->expn)cout<<"1";
                if(p->expn==1)cout<<"x";
                else cout<<"x^"<<p->expn;
            }
            if(p->coef==-1){//条件：系数为-1
                if(!p->expn)cout<<"-1";
                if(p->expn==1)cout<<"-x";
                if(p->expn)cout<<"x^"<<p->expn;
            }
        }

        p=p->next;//结点遍历
        flag++;//标志随项数增加而增加
    }
    cout<<endl;
}

//多项式相加
Linklist ADD(Linklist A,Linklist B){
    Linklist C,c,head;
    Linklist a,b;
    a=A->next;
    b=B->next;
    C=(Linklist)malloc(sizeof(Lnode));//C来存放A与B相加
    head=C;
    
    //当两个多项式都没有扫描结束时
    while(a!=NULL&&b!=NULL){
        c=(Linklist)malloc(sizeof(Lnode));
        if(a->expn<b->expn){//a的指数小于b的指数
            c->coef=a->coef;//存入a的系数和指数
            c->expn=a->expn;
            a=a->next;
        }
        else if(a->expn==b->expn){//a,b对应的指数相等
            c->coef=a->coef+b->coef;//二者系数相加，存入c
            c->expn=a->expn;
            a=a->next;
            b=b->next;
        }
        else if(a->expn>b->expn){ //b的指数小于a的指数
			c->coef=b->coef;//存入b的系数和指数
			c->expn=b->expn;
			b=b->next;
		}
        if(c->coef!=0){
            c->next=head->next;
            head->next=c;
            head=c;
        }
        else free(c);
    }

    while(a!=NULL){//A还有剩余的项式，而B没有
        c=(Lnode *)malloc(sizeof(Lnode));
        c->coef=a->coef;
        c->expn=a->expn;
        a=a->next;
        c->next=head->next;
        head->next=c;
        head=c;
    }
    while(b!=NULL){//B还有剩余的项式，而A没有
        c=(Lnode *)malloc(sizeof(Lnode));
        c->coef=b->coef;
        c->expn=b->expn;
        b=b->next;
        c->next=head->next;
        head->next=c;
        head=c;
    }

    head->next=NULL;
    output(C);
    return C;
}

//多项式相乘
Linklist MCL(Linklist A,Linklist B){
    Linklist mult;//mult来存放A与B相乘
    mult=(Linklist)malloc(sizeof(Lnode));//对mult进行初始化
    mult->next=NULL;

    Lnode *node;//记录系数和指数
    Linklist ax[100];//建立一个指针数组
    int i=0;         //记录固定的一个多项式的某一项
                     //使这一项与另一个多项式相乘
    Linklist a,b;    //最后相加
    a=A->next;

    while(a!=NULL){//固定多项式B,使A多项式的每一项相乘
        b=B->next;
        Linklist L=(Linklist)malloc(sizeof(Lnode));
        ax[i]=L;
        while(b!=NULL){
            //结点插入失败
            node=(Lnode *)malloc(sizeof(Lnode));//申请新结点
            node->next=NULL;
            node->coef=a->coef*b->coef;//记录系数相乘
            node->expn=a->expn+b->expn;//记录指数相加
            L->next=node;
            L=L->next;
            b=b->next;
        }
        i++;
        a=a->next;//移项
    }

    i--;
    Linklist m=ax[0];
    mult=ax[0];
    while(i>0){
        mult=ADD(m,ax[i]);//累计相加，并输出
        m=mult;
        i--;
    }
    
    return mult;//返回结果
}

int main (){
    Linklist A,B;//创建两个多项式

    //按指数从小到大顺序
    cout<<"请输入多项式A的相关系数及指数:";
    Creat(A);
    cout<<endl<<"则A多项式为:";
    output(A);

    cout<<endl<<"请输入多项式B的相关系数及指数:";
    Creat(B);
    cout<<endl<<"则B多项式为:";
    output(B);

    cout<<endl;

    cout<<"A+B = ";
    ADD(A,B);//多项式加法
    cout<<endl;

    cout<<"A*B = ";
    MCL(A,B);//多项式乘法
    
    return 0;
}
