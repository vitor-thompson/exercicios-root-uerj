#include <TF1.h>
#include <TCanvas.h>
#include <iostream>

void exercicio1() {
    TF1 *f1 = new TF1("f1", "[0]*sin([1]*x)/x", 0.01, 10.0);
    f1->SetParameters(1.0, 2.0);
    f1->SetLineColor(kBlue);
    f1->SetLineWidth(2);
    f1->SetTitle("Funcao Parametrica; x; f(x)");

    TCanvas *c1 = new TCanvas("c1", "Exercicio 1", 800, 600);
    f1->Draw();

    TF1 *f2 = new TF1("f2", "[0]*sin([1]*x)/x", 0.01, 10.0);
    f2->SetParameters(2.0, 1.0);
    f2->SetLineColor(kRed);
    f2->SetLineStyle(2);
    f2->Draw("SAME");

    double val = f1->Eval(1.0);
    double deriv = f1->Derivative(1.0);
    double integ = f1->Integral(0.0, 3.0);

    std::cout << "--- Resultados (p0=1, p1=2) ---" << std::endl;
    std::cout << "a. f(1)           = " << val << std::endl;
    std::cout << "b. f'(1)          = " << deriv << std::endl;
    std::cout << "c. Integral(0, 3) = " << integ << std::endl;
}
