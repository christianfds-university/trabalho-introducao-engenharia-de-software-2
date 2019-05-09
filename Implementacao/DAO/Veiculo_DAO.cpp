//
// Created by christian on 30/01/17.
//

#include <cstdlib>
#include <memory.h>
#include "Veiculo_DAO.h"
#include "../View/Utils.h"

Veiculo_DAO::Veiculo_DAO() {
    char aux[50];

    if(!(Veiculo_DAO::Arquivo = fopen("../Resources/VeiculoData","r+"))){
        Veiculo_DAO::Arquivo = fopen("../Resources/VeiculoData","w+");
        Veiculo_DAO::Topo = 0;

        Veiculo_DAO::AtualizarTopoNoArquivo();
    }
    else{
        fseek(Arquivo,0,SEEK_SET);

        fgets(aux,50,Veiculo_DAO::Arquivo);

        sscanf(aux,"%d", &(Veiculo_DAO::Topo));
    }
}

void Veiculo_DAO::InserirVeiculoNoArquivo(Veiculo_Model *Veiculo) {
    char Aux[500];
    int Posicao;

    if(Veiculo->getMinhaPosicaoEmArquivo() == -1){
        Veiculo->setMinhaPosicaoEmArquivo(Veiculo_DAO::Topo);
        Veiculo_DAO::Topo++;
        Veiculo_DAO::AtualizarTopoNoArquivo();
        fseek(Arquivo,0,SEEK_END);
    }
    else{
        fseek(Arquivo,0,SEEK_SET);
        fgets(Aux,500,Arquivo);

        int i;
        /*
         * Busca a posição onde será feita a substituição com as informações do condutor
         */
        for (i = 0; i < Topo; i++) {
            fgets(Aux,500,Arquivo);
            sscanf(Aux,"%d", &Posicao);
            if (Posicao == Veiculo->getMinhaPosicaoEmArquivo()) break;
        }

        /*
         * Posiciona o cursor para substituição
         */
        fseek(Arquivo,0,SEEK_SET);
        fgets(Aux,500,Arquivo);
        for (int j = 0; j < i; ++j) {
            fgets(Aux,500,Arquivo);
        }
    }

    fprintf(Arquivo,"%d;%d;%d;%s;%s;%s",Veiculo->getMinhaPosicaoEmArquivo(), Veiculo->getPosicaoCondutorEmArquivo(), Veiculo->getAno(), Veiculo->getMarca(), Veiculo->getModelo(), Veiculo->getPlaca());
}

Veiculo_Model *Veiculo_DAO::LerVeiculoNoArquivo(int Posicao) {
    char Aux[500];
    int PosicaoAtual = -1;

    fseek(Arquivo,0,SEEK_SET);
    fgets(Aux, 500, Arquivo);

    while(!feof(Arquivo)){
        fgets(Aux, 500, Arquivo);
        sscanf(Aux,"%d", &PosicaoAtual);

        if(PosicaoAtual == Posicao) break;
    }

    if(PosicaoAtual == Posicao) {
        return DeserializarStringVeiculo(Aux);
    }

    return NULL;
}

Veiculo_Model *Veiculo_DAO::DeserializarStringVeiculo(char *StringOriginal) {
    Veiculo_Model *Veiculo = new Veiculo_Model();

    int auxInt;
    char *auxString;

    auxInt = atoi(Utils::strsep(&StringOriginal,";"));
    Veiculo->setMinhaPosicaoEmArquivo(auxInt);

    auxInt = atoi(Utils::strsep(&StringOriginal,";"));
    Veiculo->setPosicaoCondutorEmArquivo(auxInt);

    auxInt = atoi(Utils::strsep(&StringOriginal,";"));
    Veiculo->setAno(auxInt);

    auxString = Utils::strsep(&StringOriginal,";");
    Veiculo->setMarca(auxString);

    auxString = Utils::strsep(&StringOriginal,";");
    Veiculo->setModelo(auxString);

    auxString = Utils::strsep(&StringOriginal,";");
    Veiculo->setPlaca(auxString);

    return Veiculo;
}

Veiculo_DAO::~Veiculo_DAO() {}
