//
// Created by christian on 02/02/17.
//

#ifndef TRABIES_VEICULO_VIEW_H
#define TRABIES_VEICULO_VIEW_H


#include "../Model/Veiculo_Model.h"

class Veiculo_View {
public:
    Veiculo_View();

    void Cabecalho();
    void TelaInicial();
    void ImprimeVeiculo(Veiculo_Model *Veiculo);

    void BuscarVeiculo();
    void EditarVeiculo(Veiculo_Model *Veiculo);
    void AdicionarVeiculo();

    void EditarPlaca(Veiculo_Model *Veiculo, bool MostrarInfoAntiga);
    void EditarModelo(Veiculo_Model *Veiculo, bool MostrarInfoAntiga);
    void EditarMarca(Veiculo_Model *Veiculo, bool MostrarInfoAntiga);
    void EditarAno(Veiculo_Model *Veiculo, bool MostrarInfoAntiga);
    void EditarCondutor(Veiculo_Model *Veiculo, bool MostrarInfoAntiga);
};


#endif //TRABIES_VEICULO_VIEW_H
