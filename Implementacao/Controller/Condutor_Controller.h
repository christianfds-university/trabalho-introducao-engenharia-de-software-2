#ifndef TRABIES_CONDUTOR_CONTROLLER_H
#define TRABIES_CONDUTOR_CONTROLLER_H

#include "../Model/Condutor_Model.h"
#include "../DAO/Condutor_DAO.h"

class Condutor_Controller {
private:
    Condutor_DAO dao;

public:
    Condutor_Controller();

    Condutor_Model *BuscarCondutor(long long CNH);

    void AdicionarOuAtualizarCondutor(Condutor_Model *Condutor);

    virtual ~Condutor_Controller();

};


#endif //TRABIES_CONDUTOR_CONTROLLER_H
