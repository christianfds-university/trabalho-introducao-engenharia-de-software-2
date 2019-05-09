//
// Created by christian on 01/10/17.
//

#ifndef TRABIES_CONDUTOR_H
#define TRABIES_CONDUTOR_H


class Condutor_Model {
private:
    int MinhaPosicaoEmArquivo;
    char Nome[100];
    int DataDeNascimento[3];
    long long CNH;
    char TipoDaCarteira;

public:
    Condutor_Model();

    int getMinhaPosicaoEmArquivo();
    void setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo);

    char *getNome();
    void setNome(char *Nome);

    void setDataDeNascimento(int *DataDeNascimento);
    int *getDataDeNascimento();

    long long getCNH();
    void setCNH(long long CNH);

    char getTipoDaCarteira();
    void setTipoDaCarteira(char TipoDaCarteira);

    virtual ~Condutor_Model();

};


#endif //TRABIES_CONDUTOR_H
