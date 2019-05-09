//
// Created by christian on 30/01/17.
//

#include <string.h>
#include "Veiculo_Model.h"

Veiculo_Model::Veiculo_Model() {
    Veiculo_Model::MinhaPosicaoEmArquivo = -1;
    Veiculo_Model::PosicaoCondutorEmArquivo = -1;
}

int Veiculo_Model::getMinhaPosicaoEmArquivo() {
    return MinhaPosicaoEmArquivo;
}

void Veiculo_Model::setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo) {
    Veiculo_Model::MinhaPosicaoEmArquivo = MinhaPosicaoEmArquivo;
}

int Veiculo_Model::getPosicaoCondutorEmArquivo() {
    return PosicaoCondutorEmArquivo;
}

void Veiculo_Model::setPosicaoCondutorEmArquivo(int PosicaoCondutorEmArquivo) {
    Veiculo_Model::PosicaoCondutorEmArquivo = PosicaoCondutorEmArquivo;
}

int Veiculo_Model::getAno() {
    return Ano;
}

void Veiculo_Model::setAno(int Ano) {
    Veiculo_Model::Ano = Ano;
}

char *Veiculo_Model::getMarca() {
    return Marca;
}

void Veiculo_Model::setMarca(char *Marca) {
    strcpy(Veiculo_Model::Marca, Marca);
}

void Veiculo_Model::setModelo(char *Modelo){
    strcpy(Veiculo_Model::Modelo,Modelo);
}

char *Veiculo_Model::getModelo() {
    return Modelo;
}

void Veiculo_Model::setPlaca(char *Placa){
    strcpy(Veiculo_Model::Placa,Placa);
}

char *Veiculo_Model::getPlaca() {
    return Placa;
}

Veiculo_Model::~Veiculo_Model() {

}

