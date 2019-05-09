#include <cstdlib>
#include <cstring>
#include "Veiculo_Controller.h"
#include "../View/Utils.h"

Veiculo_Controller::Veiculo_Controller() {}

Veiculo_Model *Veiculo_Controller::BuscarVeiculo(char *placa) {
    Veiculo_Model *Veiculo = NULL;
    char PlacaComparacao[8];

    int QuantidadeDeVeiculos = Veiculo_Controller::dao.getTopo();

    /*
     * Busca no arquivo binário pelo veículo com placa identica a informada
     * caso o mesmo não seja encontrado o retorno será NULL
     */
    for (int i = 0; i < QuantidadeDeVeiculos; i++) {
        Veiculo = dao.LerVeiculoNoArquivo(i);

        strcpy(PlacaComparacao,Veiculo->getPlaca());
        Utils::strTrim(PlacaComparacao);

        if(strcmp(placa, PlacaComparacao) == 0) return Veiculo;

        if(Veiculo)
            free(Veiculo);
    }
    return NULL;
}

void Veiculo_Controller::AdicionarOuAtualizar(Veiculo_Model *Veiculo) {

    dao.InserirVeiculoNoArquivo(Veiculo);

}


