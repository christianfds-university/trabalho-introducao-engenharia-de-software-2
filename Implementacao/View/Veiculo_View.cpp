// Created by christian on 02/02/17.
//

#include <stdio.h>
#include <libintl.h>
#include <cstdlib>
#include "Veiculo_View.h"
#include "Utils.h"
#include "../Model/Condutor_Model.h"
#include "../Controller/Condutor_Controller.h"
#include "../Controller/Veiculo_Controller.h"

#define _(STRING) Utils::Traduzir(STRING)

Veiculo_View::Veiculo_View() {}

void Veiculo_View::Cabecalho() {
    printf(_("****Veiculos****"));
    putchar('\n');
}

void Veiculo_View::TelaInicial() {

    int Escolha = -1;

    while(Escolha != 0){
        Utils::LimparTela();
        Cabecalho();
        printf(_("(%d)-Adicionar novo veiculo"),1);
        putchar('\n');
        printf(_("(%d)-Buscar veiculo"),2);
        putchar('\n');
        printf(_("(%d)-Voltar"),0);
        putchar('\n');

        scanf("%d", &Escolha);

        switch (Escolha){
            case 1:{
                AdicionarVeiculo();
                break;
            }
            case 2:{
                BuscarVeiculo();
                break;
            }
            default:
                break;
        }

    }

}

void Veiculo_View::ImprimeVeiculo(Veiculo_Model *Veiculo) {
    printf(_("Placa do veiculo: %s"), Veiculo->getPlaca());
    putchar('\n');
    printf(_("Modelo: %s"), Veiculo->getModelo());
    putchar('\n');
    printf(_("Marca: %s"),Veiculo->getMarca());
    putchar('\n');
    printf(_("Ano: %d"),Veiculo->getAno());
    putchar('\n');

    Condutor_Model *Condutor;
    Condutor_DAO CondutorDao;
    Condutor = CondutorDao.LerCondutorNoArquivo(Veiculo->getPosicaoCondutorEmArquivo());

    printf(_("CNH do condutor: %lld"), Condutor->getCNH());
    putchar('\n');

    free(Condutor);
}

void Veiculo_View::BuscarVeiculo() {

    Veiculo_Controller controller;
    Veiculo_Model *Veiculo = NULL;

    getchar();
    char Placa[8];
    int PlacaAux;

    while(true){
        Utils::clearBuffer();

        printf(_("Placa do veiculo (-1 para cancelar):"));
        putchar('\n');
        fgets(Placa,8,stdin);

        /*
         * Verifica a presenca de -1 na string, para que a função atual seja encerrada
         */
        sscanf(Placa,"%d", &PlacaAux);
        if(PlacaAux == -1) break;

        Veiculo = controller.BuscarVeiculo(Placa);
        if(!Veiculo){
            printf(_("Veiculo não encontrado"));
            putchar('\n');
        } else break;
    }

    if(Veiculo){

        int Escolha = -1;

        while(Escolha != 0){
            Utils::LimparTela();
            Cabecalho();
            ImprimeVeiculo(Veiculo);
            printf(_("(%d)-Editar veiculo"),1);
            putchar('\n');
            printf(_("(%d)-Voltar"),0);
            putchar('\n');

            scanf("%d", &Escolha);

            switch (Escolha){
                case 1:{
                    EditarVeiculo(Veiculo);
                    controller.AdicionarOuAtualizar(Veiculo);
                    break;
                }
                default:
                    break;
            }

        }

    }
}

void Veiculo_View::EditarPlaca(Veiculo_Model *Veiculo, bool MostrarInfoAntiga) {

    Utils::clearBuffer();

    if(MostrarInfoAntiga){
        printf(_("Placa atual: %s"), Veiculo->getPlaca());
        putchar('\n');
    }

    char NovaPlaca[8];
    printf(_("Nova placa:"));
    putchar('\n');
    fgets(NovaPlaca,8,stdin);

    Utils::strTrim(NovaPlaca);

    Veiculo->setPlaca(NovaPlaca);
}

void Veiculo_View::EditarModelo(Veiculo_Model *Veiculo, bool MostrarInfoAntiga) {

    Utils::clearBuffer();

    if(MostrarInfoAntiga){
        printf(_("Modelo atual: %s"), Veiculo->getModelo());
        putchar('\n');
    }

    char NovoModelo[100];
    printf(_("Novo modelo:"));
    putchar('\n');
    Utils::clearBuffer();
    fgets(NovoModelo,100,stdin);

    Utils::strTrim(NovoModelo);

    Veiculo->setModelo(NovoModelo);
}

void Veiculo_View::EditarMarca(Veiculo_Model *Veiculo, bool MostrarInfoAntiga) {

    Utils::clearBuffer();

    if(MostrarInfoAntiga){
        printf(_("Marca atual: %s"), Veiculo->getMarca());
        putchar('\n');
    }

    char NovaMarca[100];
    printf(_("Nova marca:"));
    putchar('\n');
    Utils::clearBuffer();
    fgets(NovaMarca,100,stdin);

    Utils::strTrim(NovaMarca);

    Veiculo->setMarca(NovaMarca);

}

void Veiculo_View::EditarAno(Veiculo_Model *Veiculo, bool MostrarInfoAntiga) {

    if(MostrarInfoAntiga){
        printf(_("Ano atual: %d"), Veiculo->getAno());
        putchar('\n');
    }

    int NovoAno;
    printf(_("Novo ano:"));
    putchar('\n');
    scanf("%d", &NovoAno);

    Veiculo->setAno(NovoAno);

}

void Veiculo_View::EditarCondutor(Veiculo_Model *Veiculo, bool MostrarInfoAntiga) {
    Condutor_Model *Condutor;
    Condutor_Controller CondutorController;

    if(MostrarInfoAntiga){
        Condutor_DAO CondutorDao;
        Condutor = CondutorDao.LerCondutorNoArquivo(Veiculo->getPosicaoCondutorEmArquivo());

        if(!Condutor){
            printf(_("Condutor não encontrado"));
            putchar('\n');
        }
        else {
            printf(_("CNH do condutor atual: %lld"), Condutor->getCNH());
            putchar('\n');
            free(Condutor);
        }
    }

    long long NovoCNH;

    printf(_("CNH do novo condutor:"));
    putchar('\n');
    scanf("%lld", &NovoCNH);

    Condutor = CondutorController.BuscarCondutor(NovoCNH);

    if(Condutor==NULL){
        printf(_("Condutor não encontrado"));
        putchar('\n');
    }
    else{
        Veiculo->setPosicaoCondutorEmArquivo(Condutor->getMinhaPosicaoEmArquivo());
        printf(_("Condutor %lld vinculado ao veiculo"), NovoCNH);
        putchar('\n');
    }
}

void Veiculo_View::EditarVeiculo(Veiculo_Model *Veiculo) {

    int Escolha = -1;

    while(Escolha != 0){
        Utils::LimparTela();
        Cabecalho();
        printf(_("Qual informacao alterar?"));
        putchar('\n');
        printf(_("(%d)-Placa"),1);
        putchar('\n');
        printf(_("(%d)-Modelo"),2);
        putchar('\n');
        printf(_("(%d)-Marca"),3);
        putchar('\n');
        printf(_("(%d)-Ano"),4);
        putchar('\n');
        printf(_("(%d)-Condutor"),5);
        putchar('\n');
        printf(_("(%d)-Voltar"),0);
        putchar('\n');

        scanf("%d", &Escolha);

        switch (Escolha){
            case 1:{
                EditarPlaca(Veiculo,true);
                break;
            }
            case 2:{
                EditarModelo(Veiculo,true);
                break;
            }
            case 3:{
                EditarMarca(Veiculo,true);
                break;
            }
            case 4:{
                EditarAno(Veiculo,true);
                break;
            }
            case 5:{
                EditarCondutor(Veiculo,true);
                break;
            }
            default:
                break;
        }

    }


}

void Veiculo_View::AdicionarVeiculo() {
    Veiculo_Model *Veiculo = new Veiculo_Model();
    Veiculo_Controller VeiculoController;

    EditarPlaca(Veiculo,false);
    EditarModelo(Veiculo,false);
    EditarMarca(Veiculo,false);
    EditarAno(Veiculo,false);

    while(Veiculo->getPosicaoCondutorEmArquivo()==-1){
        EditarCondutor(Veiculo,false);
    }

    VeiculoController.AdicionarOuAtualizar(Veiculo);

}

