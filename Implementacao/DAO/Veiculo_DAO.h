//
// Created by christian on 30/01/17.
//

#ifndef TRABIES_VEICULO_DAO_H
#define TRABIES_VEICULO_DAO_H

#include "../Model/Veiculo_Model.h"
#include "../DAO/DAO.h"

class Veiculo_DAO: public DAO {
private:
public:
    Veiculo_DAO();

    void InserirVeiculoNoArquivo(Veiculo_Model *Veiculo);

    Veiculo_Model *LerVeiculoNoArquivo(int Posicao);

    Veiculo_Model *DeserializarStringVeiculo(char *StringOriginal);

    virtual ~Veiculo_DAO();
};


#endif //TRABIES_VEICULO_DAO_H
