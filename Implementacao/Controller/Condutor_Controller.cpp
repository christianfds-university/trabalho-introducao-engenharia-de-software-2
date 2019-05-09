#include <cstdlib>
#include "Condutor_Controller.h"

Condutor_Controller::Condutor_Controller() {
}

Condutor_Model *Condutor_Controller::BuscarCondutor(long long CNH) {

    Condutor_Model *Condutor = NULL;
    int QuantidadeDeElementos = Condutor_Controller::dao.getTopo();

    /*
     * Verifica todos os condutores até encontrar o condutor com o CNH buscado,
     * caso o mesmo não seja encontrado o retorno será nulo
     */
    for (int i = 0; i < QuantidadeDeElementos; i++) {
        Condutor = Condutor_Controller::dao.LerCondutorNoArquivo(i);

        if(Condutor->getCNH() == CNH) return Condutor;

        if(Condutor)
            free(Condutor);
    }

    return NULL;
}

void Condutor_Controller::AdicionarOuAtualizarCondutor(Condutor_Model *Condutor) {
    dao.InserirCondutorNoArquivo(Condutor);
}

Condutor_Controller::~Condutor_Controller() {

}
