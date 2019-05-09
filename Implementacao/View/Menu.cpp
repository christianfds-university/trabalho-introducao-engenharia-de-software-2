#include <windows.h>
#include <libintl.h>
#include "Menu.h"
#include "Veiculo_View.h"
#include "Condutor_View.h"
#include "Utils.h"

#define _(STRING) Utils::Traduzir(STRING)

Menu::Menu() {}

/*
 * Inicia a sequência de execução de menus
 */
void Menu::Iniciar() {
    this->TelaDeBoasVindas();
    this->TelaInicial();
}

void Menu::TelaDeBoasVindas() {
    Utils::LimparTela();
    printf(_("***************************************\n"));
    printf(_("*********Bem vindo ao SysTRAN!*********"));
    putchar('\n');
    printf(_("***************************************\n"));
    Sleep(2500);
    Utils::LimparTela();
}

void Menu::TelaInicial() {

    int Escolha = -1;

    while(Escolha != 0){
    Utils::LimparTela();

    printf(_("****Sistema DETRAN****"));
    putchar('\n');
    printf(_("(%d)-Veiculos"),1);
    putchar('\n');
    printf(_("(%d)-Condutores"),2);
    putchar('\n');
    printf(_("(%d)-Relatorio"),3);
    putchar('\n');
    printf(_("(%d)-Sair"),0);
    putchar('\n');

    scanf("%d", &Escolha);
        switch (Escolha){
            case 1:{
                Veiculo_View TelaVeiculo;
                TelaVeiculo.TelaInicial();
                break;
            }
            case 2:{
                Condutor_View TelaCondutor;
                TelaCondutor.TelaInicial();
                break;
            }
            case 3:{
                Utils::GerarRelatorio();
                Utils::LimparTela();
                break;
            }
            default:
                break;
        }
    }
}

