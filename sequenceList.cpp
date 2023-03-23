#include<iostream>

using namespace std;

const int maxsize=2000;

//创建一个顺序表
typedef struct{
    int *data;//定义顺序表中元素类型的数组指针
    int Maxsize;//顺序表最大长度
    int length;//顺序表最大长度
}SQList;

//初始化顺序表
void initlist(SQList &L){
    //用malloc函数申请一片空间
    L.data=(int *)malloc(maxsize*sizeof(int));
    L.length=0;//把顺序表当前长度设为0
    L.Maxsize=maxsize;//这是顺序表的最大长度
}

//向顺序表中插入元素（动态分配）
bool listinsert(SQList &L,int i,int e){
    if(i<1||i>L.length+1)return false;//判断元素下标是否越界
    if(L.length>=L.Maxsize){//判断顺序表存储空间是否满了
        int *newbase=(int *)realloc(L.data,(L.Maxsize+5)*sizeof(int));
        if(!newbase)exit(1);
        L.data=newbase;
        L.Maxsize+=5;
    }

    int *q=&(L.data[i-1]);
    int *p;
    for(p=&(L.data[L.length-1]);p>=q;p--)*(p+1)=*p;//往后逐个后移元素

    *q=e;//将新元素放入下标位i-1的位置
    ++L.length;//表长加1
    return true;
}

//删除顺序表中的某个元素
bool listdelete(SQList &L,int i,int &e){
    if(i<1||i>L.length+1)return false;//判断元素下标是否越界
    if(!L.data)return false;//判断是不是空表
    int *p=&(L.data[i-1]);
    e=*p;
    int *q=L.data+L.length-1;
    for(++p;p<=q;++p)*(p-1)=*p;//往前逐个前移元素
    --L.length;
    return true;
}

//查找顺序表中的元素（按值找）
bool search1(SQList &L,int e)//按值查找
{
	int k = 1;
	for (int i = 0; i < L.length; i++)
	if (L.data[i] == e){
		k = 0;
        return true;
		break;
	}
	if (k){
        return false;
    }
}

//查找顺序表中的元素（按位序找）
bool search2(SQList &L,int i){//直接通过数组下标定位取得
    if(i<1||i>L.length+1)return false;
    printf("第%d个元素是%d\n",i,L.data[i-1]);
    return true;
} 

//输出顺序表中的元素
bool output(SQList &L){
    if(!L.data)return false;//判断是不是空表
   for(int i=0;i<L.length;i++)printf("%d ",L.data[i]);
   cout<<endl;
   return true;
}

//计算顺序表中所有元素的平均值,并将这个值插入中间位置
void average(SQList &L){
    if(!L.data)exit(1);
    int sum=0;
    for(int i=0;i<L.length;i++)sum+=L.data[i];
    int res=sum/(L.length);
    cout<<"平均值是"<<res<<endl;

    int i=L.length/2+1;
    if(L.length>=L.Maxsize){//判断顺序表存储空间是否满了
        int *newbase=(int *)realloc(L.data,(L.Maxsize+5)*sizeof(int));
        if(!newbase)exit(1);
        L.data=newbase;
        L.Maxsize+=5;
    }

    int *q=&(L.data[i-1]);
    int *p;
    for(p=&(L.data[L.length-1]);p>=q;p--)*(p+1)=*p;//往后逐个后移元素

    *q=res;//将新元素放入下标位i-1的位置
    ++L.length;//表长加1
}

int main(){
    SQList L;
    initlist(L);//初始化
    cout<<"元素个数是：";
    scanf("%d",&L.length);//要存储的元素个数
    cout<<"请输入：";
    for(int i=0;i<L.length;i++)scanf("%d",&L.data[i]);
    cout<<endl;

    //插入操作
    listinsert(L,2,3);//第二个位置插入3
    cout<<"向第二个位置插入3"<<endl<<"结果是：";
    output(L);//输出验证
    cout<<endl;

    //删除操作
    int e=0;
    listdelete(L,2,e);//删除第二个位置的元素
    cout<<"删除第二个位置的元素"<<endl<<"结果是：";
    output(L);//输出验证
    cout<<"要删除的元素是："<<e<<endl;
    cout<<endl;

    //查找顺序表中的元素（按值找）
    if(search1(L,2))cout<<"找到了元素2"<<endl;//查找有没有元素2
    else cout<<"没找到元素2"<<endl;
    cout<<endl;

    //查找顺序表中的元素（按位序找）
    search2(L,4);//查找第四位元素
    cout<<endl;

    //计算顺序表中所有元素的平均值,并将这个值插入中间位置
    average(L);
    cout<<"插入后";
    output(L);

    return 0;
}
