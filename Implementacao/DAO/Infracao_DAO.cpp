//
// Created by christian on 01/02/17.
//

#include "Infracao_DAO.h"

Infracao_DAO::Infracao_DAO() {
    if(!(Infracao_DAO::Arquivo = fopen("../Resources/InfracaoData.bin","r+b"))){
        Infracao_DAO::Arquivo = fopen("../Resources/InfracaoData.bin","w+b");
        Infracao_DAO::Topo = 0;

        Infracao_DAO::AtualizarTopoNoArquivo();
    }
    else{
        fseek(Infracao_DAO::Arquivo,0,SEEK_SET);
        fread(&(Infracao_DAO::Topo),sizeof(int),1,Infracao_DAO::Arquivo);
    }
}

void Infracao_DAO::InserirInfracaoNoArquivo(Infracao_Model *Infracao) {
    if(Infracao->getMinhaPosicaoEmArquivo() == -1){
        Infracao->setMinhaPosicaoEmArquivo(Infracao_DAO::Topo);
        Infracao_DAO::Topo++;
        Infracao_DAO::AtualizarTopoNoArquivo();
    }

    fseek(Infracao_DAO::Arquivo,sizeof(int) + sizeof(Infracao_Model)*Infracao->getMinhaPosicaoEmArquivo(),SEEK_SET);
    fwrite(Infracao,sizeof(Infracao_Model),1,Infracao_DAO::Arquivo);

}

Infracao_Model *Infracao_DAO::LerInfracaoNoArquivo(int Posicao) {
    Infracao_Model *Infracao = NULL;

    fseek(Infracao_DAO::Arquivo, sizeof(int) + sizeof(Infracao_Model)*Posicao,SEEK_SET);
    fread(Infracao, sizeof(Infracao_Model),1,Infracao_DAO::Arquivo);

    return Infracao;
}

Infracao_DAO::~Infracao_DAO() {}
