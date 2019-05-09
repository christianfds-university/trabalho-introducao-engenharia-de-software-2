//
// Created by christian on 30/01/17.
//

#ifndef TRABIES_INFRACAO_H
#define TRABIES_INFRACAO_H


class Infracao_Model {
private:
    int MinhaPosicaoEmArquivo;
    int PosicaoCondutorEmArquivo;
    int PosicaoVeiculoEmArquivo;
    /*
     * Tipagem da infração foi feita na forma que onde os seguintes valores tem os seguintes significados:
     * 3 = Infração Leve
     * 4 = Infração Média
     * 5 = Infração Grave
     * 7 = Infração Gravissíma
     */
    int TipoDeInfracao;
    double Valor;
    bool isPago;

public:
    Infracao_Model();

    int getMinhaPosicaoEmArquivo();
    void setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo);

    int getPosicaoCondutorEmArquivo();
    void setPosicaoCondutorEmArquivo(int PosicaoCondutor);

    int getPosicaoVeiculoEmArquivo();
    void setPosicaoVeiculoEmArquivo(int PosicaoVeiculoEmArquivo);

    int getTipoDeInfracao();
    void setTipoDeInfracao(int TipoDeInfracao);

    double getValor();
    void CalcularValor();

    bool getIsPago();
    void setIsPago(bool isPago);

    virtual ~Infracao_Model();
};


#endif //TRABIES_INFRACAO_H
