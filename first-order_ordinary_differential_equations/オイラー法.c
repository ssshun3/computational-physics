#include <stdio.h>
#include <math.h>


//x0<x<xfでy(x)を解く
double df(double,double);
double euler(double,double,double,double);

int main (void){
    //x0<x<xfでy(x)を解く
    double x0=0.0, xf=5.0,y0=1.0,yf,h;
    h=0.1;
    yf=euler(x0,xf,y0,h);
    printf("%.16f\n",yf);
    return(0);
}

//オイラー法
double euler(double x0,double xf, double y0,double h){
    double x,y;
    int i,n;
    x=x0;
    y=y0;
    n=(xf-x0)/h;
    for (i=0;i<n;i++){
        y+=h*df(x,y);
        x=x0+(i+1)*h;
        printf("%d %.16f %.16f %.10e \n",i,x,y,fabs(y-(exp(-x*x/2.0))));
    }
    return y;
}

double df(double x, double y){
    return -x*y;
    //df=dy/dx=-xy解きたい微分方程式
}