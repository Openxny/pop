#include<iostream>

using namespace std;

const int MAXLENGTH=100;

//定义顺序结构线性表
typedef struct{
    int data[MAXLENGTH];
    int length;
}SQList;

//初始化
void initlist(SQList &L) {
    L.data[MAXLENGTH]={0};
    L.length = 0;
}

//将表中的元素右移n位，表尾元素移至表头
void move(SQList &L,int n){
    if(n>L.length)return;//如果移的位数大于长度，则返回

    int b[MAXLENGTH];//定义数组b储存移位后的元素
    int j=0;
    for(int i=L.length-n;i<L.length;i++){//后n位储存到b的前n位
        b[j]=L.data[i];
        j++;
    }
    
    for(int i=0;i<L.length-n;i++)b[j++]=L.data[i];//剩余元素依次存入b数组中

    for(int i=0;i<L.length;i++)L.data[i]=b[i];//将b数组复制到原线性表中
}

int main(){
    SQList L;//声明一个静态分配的顺序表
    initlist(L);//初始化

    int x;//储存的元素个数
    cout<<"元素个数为：";
    cin>>x;
    cout<<"输入：";
    for(int i=0;i<x;i++){
        cin>>L.data[i];
        L.length++;//记录长度
    }
    int n;//右移n位
    cout<<"需要右移的位数：";
    cin>>n;
    move(L,n);//调用函数，实现移位操作
    
    cout<<"右移后结果：";
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<" ";//输出
    }
    cout<<endl;
    return 0;
}
