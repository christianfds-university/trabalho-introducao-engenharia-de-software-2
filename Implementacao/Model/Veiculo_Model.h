#ifndef TRABIES_VEICULO_H
#define TRABIES_VEICULO_H


class Veiculo_Model {
private:
    int MinhaPosicaoEmArquivo;
    int PosicaoCondutorEmArquivo;
    int Ano;
    char Marca[100];
    char Modelo[100];
    char Placa[8];

public:
    Veiculo_Model();

    int getMinhaPosicaoEmArquivo();
    void setMinhaPosicaoEmArquivo(int MinhaPosicaoEmArquivo);

    int getPosicaoCondutorEmArquivo();
    void setPosicaoCondutorEmArquivo(int PosicaoCondutorEmArquivo);

    int getAno();
    void setAno(int Ano);

    char *getMarca();
    void setMarca(char *Marca);

    void setModelo(char *Modelo);
    char *getModelo();

    void setPlaca(char *Placa);
    char *getPlaca();

    virtual ~Veiculo_Model();
};


#endif //TRABIES_VEICULO_H
