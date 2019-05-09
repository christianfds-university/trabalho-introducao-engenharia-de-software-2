#include <cstdlib>
#include <memory.h>
#include "Condutor_DAO.h"
#include "../Model/Condutor_Model.h"
#include "../View/Utils.h"


Condutor_DAO::Condutor_DAO() {
    char aux[50];

    if(!(Condutor_DAO::Arquivo = fopen("../Resources/CondutorData","r+"))){
        Condutor_DAO::Arquivo = fopen("../Resources/CondutorData","w+");

        Condutor_DAO::Topo = 0;

        Condutor_DAO::AtualizarTopoNoArquivo();
    }
    else{
        fseek(Arquivo,0,SEEK_SET);

        fgets(aux,50,Condutor_DAO::Arquivo);

        sscanf(aux,"%d", &Topo);
    }
}

void Condutor_DAO::InserirCondutorNoArquivo(Condutor_Model *Condutor) {

    char Aux[500];
    int Posicao;

    if(Condutor->getMinhaPosicaoEmArquivo() == -1){
        Condutor->setMinhaPosicaoEmArquivo( Condutor_DAO::Topo );
        Condutor_DAO::Topo++;
        Condutor_DAO::AtualizarTopoNoArquivo();
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
            if (Posicao == Condutor->getMinhaPosicaoEmArquivo()) break;
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

    fprintf(Arquivo,"%d;%s;%d/%d/%d;%lld;%c\n", Condutor->getMinhaPosicaoEmArquivo(), Condutor->getNome(), Condutor->getDataDeNascimento()[0], Condutor->getDataDeNascimento()[1], Condutor->getDataDeNascimento()[2], Condutor->getCNH(), Condutor->getTipoDaCarteira());
}

Condutor_Model *Condutor_DAO::LerCondutorNoArquivo(int Posicao) {
    char Aux[500];
    int PosicaoAtual = -1;

    fclose(Arquivo);
    Condutor_DAO::Arquivo = fopen("../Resources/CondutorData","r");

        fseek(Arquivo,0,SEEK_SET);
    fgets(Aux, 500, Arquivo);

    while(!feof(Arquivo)){
        fgets(Aux, 500, Arquivo);
        sscanf(Aux,"%d", &PosicaoAtual);

        if(PosicaoAtual == Posicao) break;
    }

    if(PosicaoAtual == Posicao) {
        fclose(Arquivo);
        Condutor_DAO::Arquivo = fopen("../Resources/CondutorData","r+");
        return DeserializarStringCondutor(Aux);
    }

    fclose(Arquivo);
    Condutor_DAO::Arquivo = fopen("../Resources/CondutorData","r+");
    return NULL;
}

/*
 * Transforma um condutor salvo no formato string para o formato de uma classe
 */
Condutor_Model *Condutor_DAO::DeserializarStringCondutor(char *StringCondutor) {

    Condutor_Model *Condutor = new Condutor_Model();

    int auxData[3];
    int auxInt;
    long long auxLL;
    char *auxString;

    auxInt = atoi(Utils::strsep(&StringCondutor, ";"));
    Condutor->setMinhaPosicaoEmArquivo(auxInt);

    auxString = Utils::strsep(&StringCondutor, ";");
    Condutor->setNome(auxString);

    auxString = Utils::strsep(&StringCondutor, ";");
    sscanf(auxString,"%d/%d/%d", auxData, auxData+1, auxData+2);
    Condutor->setDataDeNascimento(auxData);

    auxLL = atoll(Utils::strsep(&StringCondutor, ";"));
    Condutor->setCNH(auxLL);

    auxString = Utils::strsep(&StringCondutor, ";");
    Condutor->setTipoDaCarteira(auxString[0]);

    return Condutor;
}

Condutor_DAO::~Condutor_DAO() {

}


