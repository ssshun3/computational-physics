#include <stdio.h>
#include <math.h>

/*微分方程式の関数dydxの定義*/
double dydx(double x, double y, double mum, double rho){
    double mu;
    mu = mum * rho;
    return (-mu * y);
}

/*ルンゲクッタ法を計算する関数*/
double RK(double x0, double y0, double xf, int n, double mum, double rho){
    int i;
    double h, x, y;
    double k1, k2, k3, k4;
    h = (xf-x0)/n;
    x=x0;
    y=y0;
    for (i=0; i<n; i++){
        k1 = dydx(x, y, mum, rho);
        k2 = dydx(x + h/2.0, y + h*k1/2.0, mum, rho);
        k3 = dydx(x + h/2.0, y + h*k2/2.0, mum, rho);
        k4 = dydx(x + h, y + h*k3, mum, rho);
        y = y + h * (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
        x = x + h;
        printf("%lf %.10e\n", x, y); // xとyの値を出力
    }
    return(y);
}

int main(void){
    double x0, y0, xf;
    int n;

    x0 = 0.0;
    y0 = 1.0;
    xf = 1.0; // この値は調整が必要かもしれません
    n = 1000;

    // printf("Al, 0.1 nm:\n");
    // RK(x0, y0, xf, n, 13.8, 2.70);
    
    // printf("\nPb, 0.1 nm:\n");
    // RK(x0, y0, xf, n, 74.2, 11.35);
    
    // printf("\nAl, 0.03 nm:\n");
    // RK(x0, y0, xf, n, 0.552, 2.70);

    printf("\nPb, 0.03 nm:\n");
    RK(x0, y0, xf, n, 12.8, 11.35);

    return(0);
}
