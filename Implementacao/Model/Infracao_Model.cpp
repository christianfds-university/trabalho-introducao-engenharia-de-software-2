//
// Created by christian on 30/01/17.
//

#include "Infracao_Model.h"

Infracao_Model::Infracao_Model() {
    Infracao_Model::MinhaPosicaoEmArquivo = -1;
    Infracao_Model::PosicaoCondutorEmArquivo = -1;

}

int Infracao_Model::getMinhaPosicaoEmArquivo() {
    return MinhaPosicaoEmArquivo;
}

void Infracao_Model::setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo) {
    Infracao_Model::MinhaPosicaoEmArquivo = MinhaPosicaoEmArquivo;
}

int Infracao_Model::getPosicaoCondutorEmArquivo() {
    return PosicaoCondutorEmArquivo;
}

void Infracao_Model::setPosicaoCondutorEmArquivo(int PosicaoCondutorEmArquivo) {
    Infracao_Model::PosicaoCondutorEmArquivo = PosicaoCondutorEmArquivo;
}

int Infracao_Model::getPosicaoVeiculoEmArquivo() {
    return PosicaoVeiculoEmArquivo;
}

void Infracao_Model::setPosicaoVeiculoEmArquivo(int PosicaoVeiculoEmArquivo) {
    Infracao_Model::PosicaoVeiculoEmArquivo = PosicaoVeiculoEmArquivo;
}

int Infracao_Model::getTipoDeInfracao() {
    return TipoDeInfracao;
}

void Infracao_Model::setTipoDeInfracao(int TipoDeInfracao) {
    Infracao_Model::TipoDeInfracao = TipoDeInfracao;
}

double Infracao_Model::getValor() {
    return Valor;
}

Infracao_Model::~Infracao_Model() {

}

bool Infracao_Model::getIsPago(){
    return isPago;
}

void Infracao_Model::setIsPago(bool isPago) {
    Infracao_Model::isPago = isPago;
}

void Infracao_Model::CalcularValor() {
    if(TipoDeInfracao == 3)
        Valor = 50;
    else if(TipoDeInfracao == 4)
        Valor = 150;
    else if(TipoDeInfracao == 5)
        Valor = 300;
    else if(TipoDeInfracao == 7)
        Valor = 450;
}

