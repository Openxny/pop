#include<iostream>

using namespace std;

//功能：当0x30<=x<=0x39时（即字符0-9的ASCII码值）返回1；其他情况下返回0
//示例：
//isAsciiDigit(0x35) == 1
//isAsciiDigit(0x3a) == 0
//isAsciiDigit(0x05) == 0
//难度：3
//可使用运算符数：15
int isAsciiDigit(int x) {
  int min=0x2F+(~x+1);
  int max=0x39+(~x+1);
  min=!!(min>>31);//通过符号位来判断的，则将符号位右移31位，同时将结果都转化为true
  max=!(max>>31);//这也需要将结果转化为true，这样下面才能通过与运算来确定我们要的结果
  return min&max;
}

//功能：当x的任意偶数位为1时，返回1；其他情况下返回0
//示例：
//anyEvenBit(0xA) == 0
//anyEvenBit(0xE) == 1
//难度：2
//可使用运算符数：12
int anyEvenBit(int x) {
  return !!((x|(x>>8)|(x>>16)|(x>>24))&0x55);
}

//功能：将返回值中的所有位全部设置成x中的第0位的值
//示例：
//copyLSB(5) == 0xFFFFFFFF
//copyLSB(6) == 0x00000000
//难度：2
//可使用运算符数：5
int copyLSB(int x) {
  return x<<31>>31;//使用算数右移来拓展最低位,需将最低位放在最高位x<<31
}

// 功能：返回⼀个掩码，在该掩码中标识了⼆进制数x的最低位编码为1的位置
// 示例：
// leastBitPos(0x60) == 0x20
// 难度：2
// 可使用运算符数：6
int leastBitPos(int x) {
  /*假设二进制数x为1的最低位在第n位，将x-1时，则[n-1,0]变为全1，[n+1,31]位不变，
  这部分做异或操作就可变为0，即x^(x-1)，这时候[n,0]会全部变为1，所以做与操作*/
  return (((x+~0)^x)&x);
}

// 功能：计算 x / 2^n，并将结果取整
// 示例：
// divpwr2(15,1) == 7
// divpwr2(-33,4) = -2
// 难度：2
// 可使用运算符数：15
int divpwr2(int x, int n) {
  int op=(x>>31)+1;//符号标志位，正数为1，负数为0
  int temp=x>>n;//x右移n位
  int temp2=temp<<n;//temp左移n位
  int is_exact_division=!!(temp2^x);//能整除为0，反之为1
  return (temp+((!op)&(!!n)&(is_exact_division)));
}

// 功能：计算二进制数x中，对应位值“1”的总位数
// 示例：
// bitCount(5) == 2
// bitCount(7) == 3
// 难度：4
// 可使用运算符数：40
int bitCount(int x) {
  int mask=(0x11<<24)|(0x11<<16)|(0x11<<8)|(0x11);

  int temp=x&mask;

  x=x>>1;
  temp=temp+(x&mask);
  x=x>>1;
  temp=temp+(x&mask);
  x=x>>1;
  temp=temp+(x&mask);

  return ((temp&0xf)+
           ((temp>>4)&0xf)+
           ((temp>>8)&0xf)+
           ((temp>>12)&0xf)+
           ((temp>>16)&0xf)+
           ((temp>>20)&0xf)+
           ((temp>>24)&0xf)+
           ((temp>>28)&0xf));
}

int main(){
    return 0;
}
