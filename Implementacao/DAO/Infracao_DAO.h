//
// Created by christian on 01/02/17.
//

#ifndef TRABIES_INFRACAO_DAO_H
#define TRABIES_INFRACAO_DAO_H

#include "../Model/Infracao_Model.h"
#include "DAO.h"

class Infracao_DAO: public DAO {
public:
    Infracao_DAO();

    void InserirInfracaoNoArquivo(Infracao_Model *Infracao);

    Infracao_Model *LerInfracaoNoArquivo(int Posicao);

    virtual ~Infracao_DAO();

};


#endif //TRABIES_INFRACAO_DAO_H
