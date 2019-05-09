#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include "../Model/Condutor_Model.h"
#include "../Controller/Condutor_Controller.h"
#include "Utils.h"
#include "../Controller/Veiculo_Controller.h"


#define _(STRING) Traduzir(STRING)

void Utils::LimparTela() {
    system("cls");
}

char *Utils::Traduzir(const char *StringOriginal) {

    FILE *Propriedades = fopen("../config.prop","r");
    char Linguagem[100];
    char LocalArquivo[100];
    char Aux[200];
    char *Leitura;

    if(Propriedades == NULL) return (char *) StringOriginal;

    fscanf(Propriedades,"LANG =%s\n", Linguagem);

    strcpy(LocalArquivo,"../Resources/");
    strcat(LocalArquivo,Linguagem);

    FILE *Traducao = fopen(LocalArquivo,"r");

    if(Traducao == NULL) return (char *) StringOriginal;

    fseek(Traducao,0,SEEK_SET);

    while(!feof(Traducao)){
        fgets(Aux,200,Traducao);

        Leitura = strtok(Aux,"=");

        if(strcmp(Leitura, StringOriginal) == 0) {
            Leitura = strtok(NULL,"=");
            char *Resposta = (char *) malloc(sizeof(char) * 200);
            strcpy(Resposta,Leitura);
            strTrim(Resposta);
            return Resposta;
        }

    }

    return (char *) StringOriginal;

}

void Utils::GerarRelatorio() {
    FILE *Relatorio = fopen("../Relatorio.txt", "w");

    Condutor_Controller CondutorController;
    Condutor_DAO CondutorDao;

    Veiculo_Controller VeiculoController;
    Veiculo_DAO VeiculoDao;

    int NumeroDeCondutores = CondutorDao.getTopo();
    for (int i = 0; i < NumeroDeCondutores; ++i) {
        Condutor_Model *Condutor = CondutorDao.LerCondutorNoArquivo(i);
        fprintf(Relatorio,"========================================================================\n");
        fprintf(Relatorio,"Condutor %s\n", Condutor->getNome());
        fprintf(Relatorio,"CNH: %lld\n", Condutor->getCNH());
        fprintf(Relatorio,"Data de nascimento: %d/%d/%d\n", Condutor->getDataDeNascimento()[0],Condutor->getDataDeNascimento()[1],Condutor->getDataDeNascimento()[2]);
        fprintf(Relatorio,"Carteira tipo: %c\n", Condutor->getTipoDaCarteira());

        int NumeroDeVeiculos = VeiculoDao.getTopo();
        for (int j = 0; j < NumeroDeVeiculos; ++j) {
            Veiculo_Model *Veiculo = VeiculoDao.LerVeiculoNoArquivo(j);
            if(Veiculo->getPosicaoCondutorEmArquivo() == Condutor->getMinhaPosicaoEmArquivo()){
                fprintf(Relatorio, "\n");
                fprintf(Relatorio, "\tMarca do veiculo: %s\n",Veiculo->getMarca());
                fprintf(Relatorio, "\tModelo do veiculo: %s\n",Veiculo->getModelo());
                fprintf(Relatorio, "\tAno do veiculo: %d\n",Veiculo->getAno());
                fprintf(Relatorio, "\tPlaca do veiculo: %s\n",Veiculo->getPlaca());
            }
            delete Veiculo;
        }

        delete Condutor;
        fprintf(Relatorio,"========================================================================\n");
    }

    fclose(Relatorio);
    printf(_("Arquivo 'Relatorio.txt' gerado com sucesso e disponivel na mesma pasta que o programa!"));
    putchar('\n');
    printf(_("Aperte [Enter] para continuar"));
    clearBuffer();
    getchar();
}

char* Utils::strsep(char** stringp, const char* delim) {
    char* start = *stringp;
    char* p;

    p = (start != NULL) ? strpbrk(start, delim) : NULL;

    if (p == NULL)
    {
        *stringp = NULL;
    }
    else
    {
        *p = '\0';
        *stringp = p + 1;
    }

    return start;
}


void Utils::strTrim(char *String) {
    while(String){

        if(*String == '\n') {
            *String = '\0';
            break;
        }

        String++;
    }
}

void Utils::clearBuffer() {
    fflush(stdin);
}
