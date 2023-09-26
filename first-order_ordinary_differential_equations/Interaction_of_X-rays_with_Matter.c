#include <stdio.h>

// 微分方程式の関数dydxの定義
double dydx(double x, double y, double mu){
    return -mu * y;
}

// ルンゲクッタ法を計算する関数
void calculateIntensity(double mu_m, double rho, char* material, double x0, double y0, double xf, int n){
    double mu = mu_m * rho;
    double x, y, h;
    double k1, k2, k3, k4;

    char filename[100];
    sprintf(filename, "datafile_%s.txt", material);
    FILE *outputFile = fopen(filename, "w");

    h = (xf - x0) / n;
    x = x0;
    y = y0;

    for (int i = 0; i <= n; i++){
        fprintf(outputFile, "%lf\t%lf\n", x, y);
        k1 = dydx(x, y, mu);
        k2 = dydx(x + h/2.0, y + h*k1/2.0, mu);
        k3 = dydx(x + h/2.0, y + h*k2/2.0, mu);
        k4 = dydx(x + h, y + h*k3, mu);
        y = y + h * (k1 + 2.0*k2 + 2.0*k3 + k4) / 6.0;
        x = x + h;
    }

    fclose(outputFile);
}

int main(void){
    double x0 = 0.0, y0 = 1.0, xf = 5.0; // xf: 深さの最大値
    int n = 100; // ステップ数
    double rho_Al = 2.70, rho_Pb = 11.35; // 密度

    // 質量吸収係数（波長0.1nmの場合）
    double mu_m_Al_0_1 = 13.8;
    double mu_m_Pb_0_1 = 74.2;

    // 質量吸収係数（波長0.03nmの場合）
    double mu_m_Al_0_03 = 0.552;
    double mu_m_Pb_0_03 = 12.8;

    calculateIntensity(mu_m_Al_0_1, rho_Al, "Al_0_1", x0, y0, xf, n);
    calculateIntensity(mu_m_Pb_0_1, rho_Pb, "Pb_0_1", x0, y0, xf, n);

    calculateIntensity(mu_m_Al_0_03, rho_Al, "Al_0_03", x0, y0, xf, n);
    calculateIntensity(mu_m_Pb_0_03, rho_Pb, "Pb_0_03", x0, y0, xf, n);

    return 0;
}
