#include <iostream>
#include <libintl.h>
#include <cstdlib>
#include "Condutor_View.h"
#include "Utils.h"
#include "../Controller/Condutor_Controller.h"

#define _(STRING) Utils::Traduzir(STRING)


Condutor_View::Condutor_View() {}

void Condutor_View::Cabecalho() {
    printf(_("****Condutores****"));
    putchar('\n');
}

void Condutor_View::TelaInicial() {
    int Escolha = -1;

    while (Escolha != 0) {
        Utils::LimparTela();
        Cabecalho();
        printf(_("(%d)-Inserir Condutor"), 1);
        putchar('\n');
        printf(_("(%d)-Buscar Condutor"), 2);
        putchar('\n');
        printf(_("(%d)-Voltar"), 0);
        putchar('\n');

        scanf("%d", &Escolha);

        switch (Escolha){
            case 1:{
                    InserirCondutor();
                break;
            }
            case 2:{
                    BuscaCondutor();
                break;
            }
            default:
                break;
        }
    }
}

void Condutor_View::ImprimeCondutor(Condutor_Model *Condutor) {
    printf(_("Nome: %s"), Condutor->getNome());
    putchar('\n');
    printf(_("Data de Nascimento: %02d/%02d/%d"), Condutor->getDataDeNascimento()[0], Condutor->getDataDeNascimento()[1], Condutor->getDataDeNascimento()[2]);
    putchar('\n');
    printf(_("CNH: %lld"), Condutor->getCNH());
    putchar('\n');
    printf(_("Tipo da Carteira: %c"), Condutor->getTipoDaCarteira());
    putchar('\n');
}

void Condutor_View::BuscaCondutor() {

    Utils::LimparTela();

    int Escolha = -1;
    long long CNHDoCondutor;
    Condutor_Model *Condutor = NULL;
    Condutor_Controller Controller;

    Cabecalho();
    while (true){
        printf(_("Insira o CNH do condutor desejado (-1 para cancelar):"));
        putchar('\n');
        scanf("%lld", &CNHDoCondutor);

        if (CNHDoCondutor == -1) break;

        Condutor = Controller.BuscarCondutor(CNHDoCondutor);

        if(Condutor){
            while(Escolha != 0){
                Utils::LimparTela();
                ImprimeCondutor(Condutor);
                printf(_("(%d)-Editar Condutor"),1);
                putchar('\n');
                printf(_("(%d)-Infracoes"),2);
                putchar('\n');
                printf(_("(%d)-Voltar"),0);
                putchar('\n');

                scanf("%d", &Escolha);

                switch (Escolha){
                    case 1:{
                        EditarCondutor(Condutor);
                        Controller.AdicionarOuAtualizarCondutor(Condutor);
                        break;
                    }
                    case 2:{
                        printf(_("Nao disponivel na versao atual, aguarde releases futuros"));
                        putchar('\n');
                        getchar();
                        break;
                    }

                    default:
                        break;
                }
            }
            break;
        }
        else{
            printf(_("Condutor não encontrado"));
            putchar('\n');
        }

    }
    free(Condutor);
}

void Condutor_View::EditarNome(Condutor_Model *Condutor, bool MostrarInfoAntiga) {
    char NovoNome[100];

    getchar();

    if(MostrarInfoAntiga){
        printf(_("Nome Atual: %s"), Condutor->getNome());
        putchar('\n');
    }

    printf(_("Novo Nome:"));
    putchar('\n');
    fgets(NovoNome,100,stdin);

    Utils::strTrim(NovoNome);

    Condutor->setNome(NovoNome);
}

void Condutor_View::EditarDataDeNascimento(Condutor_Model *Condutor, bool MostrarInfoAntiga) {
    int NovaDataDeNascimento[3];

    if(MostrarInfoAntiga){
        printf(_("Data de Nascimento Atual: %02d/%02d/%d"), Condutor->getDataDeNascimento()[0],
                                                              Condutor->getDataDeNascimento()[1],
                                                              Condutor->getDataDeNascimento()[2]);
        putchar('\n');
    }

    while(true) {
        printf(_("Nova Data de Nascimento (dd/mm/aaaa):"));
        putchar('\n');
        scanf("%d/%d/%d", &NovaDataDeNascimento[0], &NovaDataDeNascimento[1], &NovaDataDeNascimento[2]);

        if(NovaDataDeNascimento[0] >= 1 and NovaDataDeNascimento[0] <= 31 and NovaDataDeNascimento[1] >= 1 and NovaDataDeNascimento[1] <= 12 and NovaDataDeNascimento[2] >=0 ){
            Condutor->setDataDeNascimento(NovaDataDeNascimento);
            break;
        }

        printf(_("Data inválida"));
        putchar('\n');
    }
}

void Condutor_View::EditarCNH(Condutor_Model *Condutor, bool MostrarInfoAntiga) {
    long long NovoCNH;

    Utils::clearBuffer();

    if(MostrarInfoAntiga){
        printf(_("CNH Atual: %lld"), Condutor->getCNH());
        putchar('\n');
    }

    while(true) {

        printf(_("Novo CNH:"));
        putchar('\n');
        scanf("%lld", &NovoCNH);

        if (NovoCNH > 0) {
            Condutor->setCNH(NovoCNH);
            break;
        }

        printf(_("CNH inválido"));
        putchar('\n');
    }
}

void Condutor_View::EditarTipoDaCarteira(Condutor_Model *Condutor, bool MostrarInfoAntiga) {
    char NovoTipoDaCarteira;

    if(MostrarInfoAntiga){
        printf(_("Tipo Atual da Carteira: %c"), NovoTipoDaCarteira);
        putchar('\n');
    }

    while(true){

        Utils::clearBuffer();
        printf(_("Novo Tipo de Carteira:"));
        putchar('\n');
        scanf("%c", &NovoTipoDaCarteira);

        if((NovoTipoDaCarteira >= 'A' and NovoTipoDaCarteira <= 'F') or (NovoTipoDaCarteira >= 'a' and NovoTipoDaCarteira <= 'f')){
            Condutor->setTipoDaCarteira(NovoTipoDaCarteira);
            break;
        }

        printf(_("Tipo de carteira inválido"));
        putchar('\n');

    }
}

/*
 * Responsabilidade de salvar alterações depende de quem chamar estas opcoes
 * Uma vez que a mesma é responsavel apenas por editar o condutor
 */
void Condutor_View::EditarCondutor(Condutor_Model *Condutor) {
    int Escolha = -1;

    while (1) {
        Utils::LimparTela();

        printf(_("Qual informacao alterar?"));
        putchar('\n');
        printf(_("(%d)-Nome"), 1);
        putchar('\n');
        printf(_("(%d)-Data de nascimento"), 2);
        putchar('\n');
        printf(_("(%d)-CNH"), 3);
        putchar('\n');
        printf(_("(%d)-Tipo da carteira"), 4);
        putchar('\n');
        printf(_("(%d)-Voltar"), 0);
        putchar('\n');

        scanf("%d", &Escolha);

        switch (Escolha){
            case 1:{
                EditarNome(Condutor,true);
                break;
            }
            case 2:{
                EditarDataDeNascimento(Condutor,true);
                break;
            }
            case 3:{
                EditarCNH(Condutor,true);
                break;
            }
            case 4:{
                EditarTipoDaCarteira(Condutor,true);
                break;
            }
            default:
                break;
        }

        if(Escolha == 0) break;
    }
}


void Condutor_View::InserirCondutor() {
    Condutor_Controller controller;
    Condutor_Model Condutor;

    printf(_("Informações do condutor:"));
    putchar('\n');
    EditarNome(&Condutor,false);
    EditarDataDeNascimento(&Condutor,false);
    EditarCNH(&Condutor,false);
    EditarTipoDaCarteira(&Condutor,false);

    controller.AdicionarOuAtualizarCondutor(&Condutor);

}
