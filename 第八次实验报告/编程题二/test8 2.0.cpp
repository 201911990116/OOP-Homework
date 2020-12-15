#include <iostream>
#include<cmath>
using namespace std;
 //−−−−−−−−−−−−−−−−−− 抽象类 Base−−−−−−−−−−−−−−−−−−−
 class Shapes
{
 public:
 virtual void display() = 0;// 纯虚函数
 };
 //−−−−−−−−−−−−−−−−− 具体类 Rectangle−−−−−−−−−−−−−−
 class Rectangles:public Shapes // 公有继承自基类
 {
 private:
 double a, b;// 长和宽
 public:
 Rectangles(double _a, double _b)
 {
 a = _a;
 b = _b;
 }
 ~Rectangles(){}

 void display()// 虚函数 ( 和基类的 display 的函数原型相同 )
 {
 cout << "矩形边长为:" << a << b << endl;
 cout << " 矩形面积为:" << a <<b << endl;
 }
 };
 //−−−−−−−−−−−−−−−−− 具体类 Circle−−−−−−−−−−−−−−
 class Circles: public Shapes // 公有继承自基类
 {
 private:
 double r;// 半径

 public:
 Circles(double _r)
 {
 r = _r;
 }
 ~Circles()
 {

 }
 void display() // 虚函数 ( 和基类的 display 函数原型相同 )
 {
 cout << " −−−−−−−−−−−−−−−−−− " << endl;
 cout << " 圆的半径为 : " <<r << endl;
 cout << " 圆的面积为 : " <<3.14*r*r << endl;
 cout << " −−−−−−−−−−−−−−−−−− " << endl;
 }
 };
 //∗−−−−−−−−−−−−−−−−−− 主函数 −−−−−−−−−−−−−−−−−−−−−∗/

 int main()
 {
 Shapes *p[2]; // 定义指针数组 , 数组内存放 2 个指针变量

 Rectangles rectangle(3, 4);// 矩形对象
 Circles circle(2); // 圆对象

 p[0] = &rectangle;// 这里指哪 , 下面 p[0]−>display() 就打哪 : 打矩形函数
 p[1] = &circle; // 这里指哪 , 下面 p[1]−>display() 就打哪 : 打圆形函数

 p[0]->display();
 p[1]->display();

 return 0;
}


















