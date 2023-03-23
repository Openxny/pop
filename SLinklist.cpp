#include<iostream>

using namespace std;

const int MAXSIZE=20;//静态链表的最大长度

//定义一个静态链表
typedef struct{//静态链表结构类型的定义
    int data;//存储数据元素
    int cur;//下一个元素的数组下标
}SLinklist[MAXSIZE];

//初始化静态链表
void initlist(SLinklist &L){
    for(int i=0;i<MAXSIZE-1;i++){
        L[i].cur=i+1;//将每个数组的分量链接在一起
        L[i].data=0;
    }
    L[MAXSIZE-1].cur=0;//链表最后一个结点的游标值为0
}

//静态链表的提取分配空间
int Malloc(SLinklist L){
    /*若备用链表非空，则返回分配的结点下标，否则返回 0（当分配最后一个结点时，
    该结点的游标值为 0）*/

    int i=L[0].cur;//获取备用结点的下标
    if(L[0].cur)L[0].cur=L[i].cur;//如果备用链表不是空链表，更新备用链表头结点
    return i;
}

//初始化几个元素
void add(SLinklist &L){
    cout<<"元素个数是：";
    int n;
    cin>>n;
    cout<<"输入：";
    for(int i=1;i<=n;i++){
        cin>>L[i].data;
    }

    L[0].cur=n+1;
    L[n].cur=0;
    L[MAXSIZE-1].cur=1;

}
//插入(在L链表中第i个元素前面插入e)
void Listinsert(SLinklist &L,int i,int e){
    int k=MAXSIZE-1;//遍历结构体数组使用
    int insert=0;
    //找到要插入位置的上一个结点在数组中的位置
    for(int j=1;j<i;j++){
        k=L[k].cur;
    }

    insert=Malloc(L);//申请空间，准备插入
    L[insert].data=e;
    
    L[insert].cur=L[k].cur;//新插入结点的游标等于其前驱节点的游标
    L[k].cur=insert;//直接前驱结点的游标等于新插入结点所在数组中的下标
    
}

//查找元素e在数组中的位置
int selectNum(SLinklist L,int e){
    //当游标值为0时，表示链表结束
    int temp=MAXSIZE-1;
    while(L[temp].cur!=0){
        if(L[temp].data==e)return temp;
        temp=L[temp].cur;
    }

    //判断最后一个结点是否符合要求
    if(L[temp].data==e)return temp;
    return -1;//返回-1，表示在链表中没有找到该元素
}

//释放结点
void Free(SLinklist &L,int k){
    L[k].cur=L[0].cur;
    L[0].cur=k;
}

//删除元素e
void Listdelete(SLinklist &L,int e){
    int temp=MAXSIZE -1;
    int del=0;
    int k=0;
    //找到被删除结点的位置
    while(L[temp].data!=e){
        temp=L[temp].cur;
        if(temp==0){
            cout<<"链表中没有此数据";
        }
    }

    //运行到此，证明有该结点
    del=temp;
    temp=MAXSIZE-1;
    //删除首元结点，需要特殊考虑
    if(del==L[MAXSIZE-1].cur){
        k=L[del].cur;
        L[MAXSIZE-1].cur=k;
        Free(L,del);
    }
    else {
        //找到该结点的上一个结点，做删除操作
        while(L[temp].cur!=del){
            temp=L[temp].cur;
        }
        //将被删除结点的游标直接给被删除结点的上一个结点
        L[temp].cur=L[del].cur;
        //回收被摘除结点的空间
        Free(L,del);
    }
}

//输出
void output(SLinklist L){
    
    int temp=MAXSIZE-1;//为遍历做准备
    temp=L[temp].cur;
    while(L[temp].cur){
        cout<<L[temp].data<<" ";
        temp=L[temp].cur;
    }
    cout<<L[temp].data<<endl;
}

int main(){
    SLinklist L;
    initlist(L);//初始化

    add(L);//初始化几个元素
    cout<<"静态链表为：";
    output(L);//输出
    
    //插入
    cout<<"向第二个位置插入元素3"<<endl;
    Listinsert(L,2,3);
    cout<<"结果是：";
    output(L);

    //查找元素5，并返回其位置
    if(selectNum(L,5)>0)cout<<"元素5的位置是"<<selectNum(L,5)<<endl;
    else cout<<"没找到"<<endl;

    //删除
    cout<<"删除元素2"<<endl;
    Listdelete(L,2);
    cout<<"结果是：";
    output(L);

    return 0;
}
