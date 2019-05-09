#ifndef TRABIES_DAO_H
#define TRABIES_DAO_H

#include <cstdio>

/*
 * Classe que contém o básico para interações com arquivo
 */
class DAO{
protected:
    int Topo;
    FILE *Arquivo;

public:
    DAO() {}

    void AtualizarTopoNoArquivo() {
        fseek(Arquivo,0,SEEK_SET);
        fprintf(Arquivo, "%d", Topo);
    }

    int getTopo(){
        return Topo;
    }

    void IrParaFinalDoArquivo(){
        char Aux[500];

        fgets(Aux, 500, Arquivo);

        while (fgets(Aux, 500, Arquivo)) {}

    }

    virtual ~DAO() {
        if(Arquivo) {
            AtualizarTopoNoArquivo();
            fclose(Arquivo);
        }
    }
};

#endif //TRABIES_DAO_H
