#include <TH1F.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TStyle.h>

void exercicio3() {
    // Modo Batch (sem interface gráfica) - previne erros de display
    gROOT->SetBatch(kTRUE);

    // Configura a caixa de estatísticas completa
    gStyle->SetOptStat(111111111);

    // Criando o histograma 1D: 50 bins entre 0 e 10
    TH1F *h1 = new TH1F("h1", "Distribuição Gaussiana;Valor;Contagens", 50, 0.0, 10.0);

    // Gerador de números aleatórios com semente fixa
    TRandom3 rand(42);

    // Preenchendo com 10.000 números gaussianos (média = 5, sigma = 2)
    for (int i = 0; i < 10000; ++i) {
        h1->Fill(rand.Gaus(5.0, 2.0));
    }

    TCanvas *c3 = new TCanvas("c3", "Exercicio 3", 800, 600);
    h1->SetFillColor(kAzure + 7);
    h1->SetLineColor(kBlue + 2);
    h1->Draw();

    // --- SALVANDO A IMAGEM ---
    c3->SaveAs("exercicio3.png"); // Salva como PNG
    c3->SaveAs("exercicio3.pdf"); // Opcional: Salva também em alta resolução (PDF)
}
