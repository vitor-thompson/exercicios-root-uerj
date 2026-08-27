#include <TGraph.h>
#include <TGraphErrors.h>
#include <TCanvas.h>
#include <TAxis.h>
#include <TROOT.h>

void exercicio2() {
    // 1. Desativa a tentativa de abrir janelas gráficas no SO
    gROOT->SetBatch(kTRUE);

    TCanvas *c2 = new TCanvas("c2", "Exercicio 2", 1200, 500);
    c2->Divide(2, 1); // Divide a tela em 2 painéis

    // --- Parte 1: TGraph simples lendo graphdata.txt ---
    c2->cd(1);
    TGraph *g = new TGraph("graphdata.txt");
    g->SetTitle("Pontos Conectados (TGraph);X;Y");
    
    // Marcador: Caixa preta (kFullSquare = 21, kBlack = 1)
    g->SetMarkerStyle(kFullSquare);
    g->SetMarkerColor(kBlack);
    g->SetMarkerSize(1.2);
    g->SetLineColor(kBlue);

    // Opção "ALP": A = Axis (Eixos), L = Line (Linha conectando), P = Points (Marcadores)
    g->Draw("ALP");

    // --- Parte 2: TGraphErrors lendo graphdata_error.txt ---
    c2->cd(2);
    // Espera arquivo com formato: x y ex ey
    TGraphErrors *ge = new TGraphErrors("graphdata_error.txt");
    ge->SetTitle("Gráfico com Erros (TGraphErrors);X;Y");
    
    ge->SetMarkerStyle(kFullSquare);
    ge->SetMarkerColor(kBlack);
    ge->SetMarkerSize(1.2);
    ge->SetLineColor(kRed);

    // Opção "AP": A = Axis, P = Points com barras de erro
    ge->Draw("AP");

    // --- 2. SALVAR AS IMAGENS NO DISCO ---
    c2->SaveAs("exercicio2.png"); // Imagem PNG
    c2->SaveAs("exercicio2.pdf"); // Gráfico Vetorial PDF (Alta Qualidade)
}
