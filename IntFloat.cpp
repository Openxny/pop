#include<iostream>

using namespace std;

// 功能：实现与三目运算符表达式 x ? y : z 具有等价功能的函数
// 合法的运算符：! ~ & ^ | + << >>
// 可使用的运算符数：16
// 难度：4
int conditional(int x, int y, int z) {
  //x不为0时结果为y,为0时结果为z.
  int test1,test2,test3;
  test1=(!!x);
  test1=(test1<<31)>>31; //获得!!x的值填充32位。
  test2=!x;
  test2=(test2<<31)>>31; //获得!x的值填充32位。

  test3=(test1&y)+(test2&z); //分别和y,z进行与运算即可得出结果。
  return test3;
}

// 功能：当 x >=0 时，返回1；否则返回0
// 合法的运算符：! ~ & ^ | + << >>
// 可使用的运算符数：6
// 难度：3
int isNonNegative(int x) {
  //判断x的符号位
  int temp=x>>31;//为0xFFFFFFFF则要return0,为0x00000000要return1
  temp=!temp;//使用！将其变为0与1
  return temp;
}

// 功能：当 x > y 时，返回1，否则返回0
// 合法的运算符：! ~ & ^ | + << >>
// 可使用的运算符数：24
// 难度：3
int isGreater(int x, int y) {
  //需要判断x与y同号和x与y异号的情况
  int equalval=x^y;//判断x与y相等及符号位是否相同
  int subval=x+(~(y+1)+1);//计算x-y-1
  int res=(((~subval)&(~equalval))+(y&equalval))>>31;//分别计算同号与异号的情况。
                                                  //并取符号位。前一个为同号，后一个为异号
  res=res&0x01;
  return res;
}

// 功能：计算x的绝对值
// 合法的运算符：! ~ & ^ | + << >>
// 可使用的运算符数：10
// 难度：4
int absVal(int x) {
  //x为正则返回x，x为负则返回~x+1
  int res,signbit;
  signbit=x>>31;
  res=((~signbit)&x)+(signbit&(~x+1));//利用符号位计算结果。
                                        //若x为正数，则后半段为0，前半段为x
                                        //若x为负数，则前半段为0，后半段为~x+1
  return res;
}

// 功能：判断x是否恰好等于 $2^n$，如果等于则返回1，否则返回0
// 提示：负数必然不是$2^n$
// 示例：isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
// 合法的运算符：! ~ & ^ | + << >>
// 可使用的运算符数：20
// 难度：4
int isPower2(int x) {
  //首先2的幂有x&(x-1)为0的特征，然后只要判断x大于0
  int signbit=(x>>31)&0x01;
  int signbit2=((x+~0x00)>>31)&0x01;
  int abzero=signbit+(signbit2&(~signbit));//判断是否大于0，大于0为0，否则为1
  int nat=x&(x+~0x00);//性质符合为0
  int res=abzero+nat;//两者都满足的情况下为0，其他情况都不为0
  return !res;
}

// 功能：求浮点数f的相反数
// 说明：参数uf为浮点数f为在计算机中的二进制编码所对应的无符号数。返回值为浮点数-f在计算机中的二进编码所对应的无符号数。
// 合法的运算符：全部有符号数和无符号数的运算符、||、&&、if 和 while
// 注意：如果输入为NaN，则返回值等于uf
// 可使用的运算符数：10
// 难度：2
unsigned float_neg(unsigned uf) {
  //分为NAN和规范数两种情况。
  unsigned result;
  int elsign=uf&0x7fffffff;//排除符号位影响。
  int exp=elsign>>23;//获得阶码位
  if((!(exp^0xff))&&(elsign^0x7f800000))//前一个判断阶码位是否全为1
                                        //后一个在前一个基础上判断小数字段是否不全为0
  return uf;
  result=uf^0x80000000;
    return result;
}

// 功能：返回浮点数(float)x在计算机中的二进制编码所对应的无符号数
// 合法的运算符：全部有符号数和无符号数的运算符、||、&&、if 和 while
// 可使用的运算符数：30
// 难度：4
unsigned float_i2f(int x) {
  unsigned shiftleft=0;
	unsigned aftershift, tmp, flag;
	unsigned absx=x;
	unsigned sign=0;
	if(x==0)
	return 0;
	if(x<0){
	sign=0x80000000;
	absx=-x;
	}
	aftershift=absx;
	while(1)
	{
	tmp=aftershift;
	aftershift=aftershift<<1;
	shiftleft++;
	if(tmp&0x80000000)
	break;
	}
	if((aftershift&0x01ff)>0x0100)//出现在规定位置后大于0b100的情况就进1
	flag=1;
	else if((aftershift&0x03ff)==0x0300)//出现最后一位为1，且下一位为1的情况也进1(向偶取整)
	flag=1;
	else flag=0;
	return (sign+(aftershift>>9)+((159-shiftleft)<<23)+flag);
}

int main(){
    return 0;
}
