//
// Created by christian on 01/10/17.
//

#include <string.h>
#include "Condutor_Model.h"

Condutor_Model::Condutor_Model() {
    Condutor_Model::MinhaPosicaoEmArquivo = -1;
}

int Condutor_Model::getMinhaPosicaoEmArquivo(){
    return MinhaPosicaoEmArquivo;
}

void Condutor_Model::setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo) {
    Condutor_Model::MinhaPosicaoEmArquivo = MinhaPosicaoEmArquivo;
}

char *Condutor_Model::getNome() {
    return Nome;
}

void Condutor_Model::setNome(char *Nome) {
    strcpy(Condutor_Model::Nome,Nome);
}

void Condutor_Model::setDataDeNascimento(int *DataDeNascimento) {
    for (int i = 0; i < 3; i++) {
        Condutor_Model::DataDeNascimento[i] = DataDeNascimento[i];
    }
}

int *Condutor_Model::getDataDeNascimento() {
    return DataDeNascimento;
}

long long int Condutor_Model::getCNH() {
    return CNH;
}

void Condutor_Model::setCNH(long long CNH) {
    Condutor_Model::CNH = CNH;
}

char Condutor_Model::getTipoDaCarteira() {
    return TipoDaCarteira;
}

void Condutor_Model::setTipoDaCarteira(char TipoDaCarteira) {
    Condutor_Model::TipoDaCarteira = TipoDaCarteira;
}

Condutor_Model::~Condutor_Model() {

}


