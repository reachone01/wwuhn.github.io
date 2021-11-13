/*
二分法是在计算机科学中很重要的一种方法，用于查找产生二分查找算法，还可以用在很多场合。
　　可以用二分法解方程。
　　对于区间[a，b]上连续不断且f(a)·f(b)<0的函数y=f(x)，通过不断地把函数f(x)的零点所在的区间一分为二， 
使区间的两个端点逐步逼近零点，进而得到零点近似值的方法叫二分法。
　　假设要求方程f(x)=0的解，给定精确度ξ。其算法是：

  1 确定区间[a,b],验证f(a)·f(b)<0
  2 求区间(a,b)的中点c
  3 判断
  (1) 若f(a)·f(c)<0,则令b=c;
  (2) 若f(c)·f(b)<0,则令a=c.
  4 判断f(c)是否达到精确度ξ:即若┃f(c)┃<ξ，则x=c就是使f(x)接近零点的近似值，否则重复2-4.
  　　请按照上面的算法，编程序求解方程f(x)=2x^3-5x^2+3x-6=0，要求精确到0.00001
  
*/
#include <stdio.h>
double f(double); //f(x)函数
int main()
{
    double a,b,c;
    do
    {
        printf("请输入一个范围x0 x1：");
        scanf("%lf %lf", &a, &b); //尝试输入a和b的值，即确定可能解所在的区间
        
    }
    while(f(a)*f(b)>=0); //要求这两点上的函数值异号，从而保证[a, b]之间有解
    printf("在[%.2f, %.2f]间，方程将有一个根\n",a, b);
    do
    {
        c=(a+b)/2;
        if(f(a)*f(c)<0) //二分法判断函数值包含0的X取值区间
        {
            b=c;
        }
        else
        {
            a=c;
        }
    } while((f(c)>1e-5)||(f(c)<-1e-5));//判断根c是否在接近函数值0的精确范围内
    printf("方程的根为：%.5f\n",c);
    while(1);
    return 0;
}
double f(double x)
{
    return(3*x*x*x-5*x*x+3*x-6);
}