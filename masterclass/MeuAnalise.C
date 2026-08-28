#define MeuAnalise_cxx
#include "MeuAnalise.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TH1F.h>
#include <iostream>

void MeuAnalise::Loop()
{
   if (fChain == 0) return;

   // 1. Criar o arquivo de saída
   TFile *outFile = new TFile("histogramas_saida.root", "RECREATE");

   // 2. Ajustes globais do estilo (Mover a caixa de estatísticas para cima e para a direita)
   gStyle->SetOptStat(1111); // Entradas, Média, RMS
   gStyle->SetStatX(0.88);   // Posição X (direita)
   gStyle->SetStatY(0.90);   // Posição Y (topo, mais para cima)
   gStyle->SetStatW(0.22);   // Largura da caixa
   gStyle->SetStatH(0.18);   // Altura da caixa

   // 3. Instanciar os Histogramas
   TH1F *h_nMuon = new TH1F("h_nMuon", "Numero de Muons por Evento;N_{#mu};Eventos", 10, 0, 10);
   TH1F *h_Muon_pt = new TH1F("h_Muon_pt", "Pt do Muon Lider;p_{T} [GeV];Eventos", 100, 0, 200);
   TH1F *h_Muon_eta = new TH1F("h_Muon_eta", "Eta do Muon Lider;#eta;Eventos", 50, -3.0, 3.0);

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "Processando " << nentries << " eventos..." << std::endl;

   Long64_t nbytes = 0, nb = 0;

   // 4. Loop principal sobre os eventos
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;

      if (jentry % 10000 == 0) {
         std::cout << "Evento atual: " << jentry << " / " << nentries << std::endl;
      }

      h_nMuon->Fill(nMuon);

      if (nMuon > 0) {
         h_Muon_pt->Fill(Muon_pt[0]);
         h_Muon_eta->Fill(Muon_eta[0]);
      }
   }

// 5. Desenhar e salvar as imagens PNG
   TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
   c1->SetLeftMargin(0.13); // Evita cortar o rótulo "Eventos" na esquerda

   // --- Histograma nMuon ---
   gStyle->SetStatX(0.88); // Posição padrão no canto superior direito
   gStyle->SetStatY(0.90);
   h_nMuon->Draw();
   c1->SaveAs("histograma_nMuon.png");

   // --- Histograma Pt ---
   h_Muon_pt->Draw();
   c1->SaveAs("histograma_pt_muon.png");

   // --- Histograma Eta (Mover caixa para a esquerda) ---
   gStyle->SetStatX(0.38); // Posiciona a caixa no canto superior esquerdo
   gStyle->SetStatY(0.88);
   h_Muon_eta->Draw();
   c1->SaveAs("histograma_eta_muon.png");
}
