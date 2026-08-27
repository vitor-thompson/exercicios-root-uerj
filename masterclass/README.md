# Masterclass: Análise de Dados CMS OpenData com `MakeClass`

## Descrição da Atividade
O objetivo desta atividade é realizar a análise de física de partículas utilizando uma amostragem de dados simulados em formato Ntupla **NanoAOD** do experimento CMS (CERN OpenData). 

Através da ferramenta automatizada `MakeClass` do CERN ROOT, foi gerada a estrutura em C++ para ler a árvore de eventos (`Events`) do processo Drell-Yan ($DY \to \ell^+\ell^-$) e extrair as distribuições cinemáticas dos múons identificados nos eventos.

---

## Passo a Passo de Execução

### Passo 1: Abertura dos Dados no ROOT
O arquivo de entrada contendo as Ntuplas em formato NanoAOD foi acessado diretamente no terminal Linux do JupyterHub da UERJ:

```bash
root -l /cms/opendata/mc/RunIISummer20UL16NanoAODv9/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v1/30000/0082C29D-E74C-024A-BE9B-97B29EE7A4A2.root
```
###Passo 2: Geração do Esqueleto C++ com MakeClass
Dentro do prompt interativo do ROOT, mapeou-se a árvore de eventos Events para criar os arquivos do código-fonte esqueleto (MeuAnalise.h e MeuAnalise.C):

```C++
root [0] .ls
root [1] Events->MakeClass("MeuAnalise")
root [2] .q
```
###Passo 3: Implementação e Código Completo (MeuAnalise.C)
O arquivo MeuAnalise.C foi editado e substituído pelo código para instanciar três histogramas 1D, iterar sobre os eventos da amostra e salvar as saídas.

###Passo 4: Execução no ROOT
A classe foi compilada via ACLiC (.L MeuAnalise.C+) no interpretador e executada através dos comandos:

```C++
root -l
root [0] .L MeuAnalise.C+
root [1] MeuAnalise t
root [2] t.Loop()
