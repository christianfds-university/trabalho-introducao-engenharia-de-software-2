//
// Created by christian on 02/02/17.
//

#ifndef TRABIES_VEICULO_CONTROLLER_H
#define TRABIES_VEICULO_CONTROLLER_H


#include "../DAO/Veiculo_DAO.h"

class Veiculo_Controller {
private:
    Veiculo_DAO dao;

public:
    Veiculo_Controller();

    Veiculo_Model *BuscarVeiculo(char *placa);

    void AdicionarOuAtualizar(Veiculo_Model *Veiculo);

};


#endif //TRABIES_VEICULO_CONTROLLER_H
