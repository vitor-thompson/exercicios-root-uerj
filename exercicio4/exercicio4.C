#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCut.h>
#include <TCanvas.h>
#include <TString.h>
#include <iostream>

void exercicio4() {
    // 1. Abrir o arquivo de dados
    TFile *f = TFile::Open("tree.root");
    if (!f || f->IsOpen() == kFALSE) {
        std::cout << "Erro ao abrir o arquivo tree.root!" << std::endl;
        return;
    }

    // Obter a TTree
    TTree *tree1 = (TTree*)f->Get("tree1");

    // 2. Criar Canvas para desenhar
    TCanvas *c1 = new TCanvas("c1", "Exercicio 4", 800, 600);

    // 3. Obter o valor da média do ebeam
    TH1F *h_temp = new TH1F("h_temp", "", 100, 0, 100);
    tree1->Draw("ebeam >> h_temp", "", "goff");
    double ebeam_mean = h_temp->GetMean();

    // 4. Criar a string de corte formatada ANTES do TCut
    TString condicao = Form("abs(ebeam - %f) > 0.2", ebeam_mean);
    TCut cut_ebeam(condicao);

    // 5. Criar os dois cortes TCut exatamente como no exemplo do professor
    TCut *px_plane = new TCut("px / log(px*2 + py**2) > 0.10");
    TCut *py_plane = new TCut("py / log(px*2 + py**2) > 0.10");

    // 6. Criar o histograma de destino do momento total
    TH1F *h_p = new TH1F("h_p", "Distribuição do Momento Total;p [GeV/c];Eventos", 100, 130, 150);

    // 7. Projetar o momento total aplicando a combinação dos cortes no histograma
    tree1->Draw("sqrt(px*px + py*py + pz*pz) >> h_p", cut_ebeam && *px_plane && *py_plane);

    // 8. Desenhar e salvar a imagem do gráfico resultante
    h_p->Draw();
    c1->SaveAs("exercicio4_momento.png");

    // 9. Salvar o histograma em um arquivo .root de saída
    TFile *outFile = new TFile("exercicio4_saida.root", "RECREATE");
    h_p->Write();
    outFile->Close();

    std::cout << "Processamento concluído com sucesso!" << std::endl;
    std::cout << "Média de ebeam: " << ebeam_mean << std::endl;
}
