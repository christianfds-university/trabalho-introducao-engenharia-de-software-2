//
// Created by christian on 30/01/17.
//

#ifndef TRABIES_CONDUTOR_DAO_H
#define TRABIES_CONDUTOR_DAO_H

#include <cstdio>
#include "../Model/Condutor_Model.h"
#include "../DAO/DAO.h"

class Condutor_DAO: public DAO {
public:
    Condutor_DAO();

    /*
     * Insere um condutor novo ou atualiza um antigo, com base no valor salvo em Condutor_Model->MinhaPosicaoNoArquivo
     */
    void InserirCondutorNoArquivo(Condutor_Model *Condutor);

    Condutor_Model *DeserializarStringCondutor(char *StringCondutor);

    Condutor_Model *LerCondutorNoArquivo(int Posicao);

    virtual ~Condutor_DAO();

};


#endif //TRABIES_CONDUTOR_DAO_H
