#ifndef TRABIES_CONDUTOR_VIEW_H
#define TRABIES_CONDUTOR_VIEW_H


#include "../Model/Condutor_Model.h"

class Condutor_View {
public:
    Condutor_View();

    void Cabecalho();
    void TelaInicial();
    void ImprimeCondutor(Condutor_Model *Condutor);
    void BuscaCondutor();

    void EditarCondutor(Condutor_Model *Condutor);
    void InserirCondutor();

    void EditarNome(Condutor_Model *Condutor, bool MostrarInfoAntiga);
    void EditarDataDeNascimento(Condutor_Model *Condutor, bool MostrarInfoAntiga);
    void EditarCNH(Condutor_Model *Condutor, bool MostrarInfoAntiga);
    void EditarTipoDaCarteira(Condutor_Model *Condutor, bool MostrarInfoAntiga);

};


#endif //TRABIES_CONDUTOR_VIEW_H
