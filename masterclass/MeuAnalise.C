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

   // 2. Instanciar os Histogramas
   TH1F *h_nMuon = new TH1F("h_nMuon", "Numero de Muons por Evento;N_{#mu};Eventos", 10, 0, 10);
   TH1F *h_Muon_pt = new TH1F("h_Muon_pt", "Pt do Muon Lider;p_{T} [GeV];Eventos", 100, 0, 200);
   TH1F *h_Muon_eta = new TH1F("h_Muon_eta", "Eta do Muon Lider;#eta;Eventos", 50, -3.0, 3.0);

   Long64_t nentries = fChain->GetEntriesFast();
   std::cout << "Processando " << nentries << " eventos..." << std::endl;

   Long64_t nbytes = 0, nb = 0;

   // 3. Loop principal
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

   // 4. Desenhar e salvar as imagens PNG PRIMEIRO (enquanto estão na memória)
   TCanvas *c1 = new TCanvas("c1", "Canvas", 800, 600);
   
   h_nMuon->Draw();
   c1->SaveAs("histograma_nMuon.png");
   
   h_Muon_pt->Draw();
   c1->SaveAs("histograma_pt_muon.png");
   
   h_Muon_eta->Draw();
   c1->SaveAs("histograma_eta_muon.png");

   // 5. Salvar e fechar o arquivo ROOT POR ÚLTIMO
   outFile->cd();
   h_nMuon->Write();
   h_Muon_pt->Write();
   h_Muon_eta->Write();
   outFile->Close();

   std::cout << "Análise concluída com sucesso! Arquivos gerados." << std::endl;
}
