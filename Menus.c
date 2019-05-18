#include "stdio.h"
#include "stdio_ext.h"
#include "unistd.h"
#include "stdlib.h"

#include "Headers/Menus.h"
#include "Headers/functions.h"


void WelcomeMenu(void) {
    printf("+----------------------------------------------------------+\n");
    printf("|          »»»  Bem-Vindo ao Gestor de Viagens!! «««       |\n");
    printf("|                      -------------                       |\n");
    printf("|             by João Leitão and Pedro Rodrigues           |\n");
    printf("+----------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

void ByeByeMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|####################### Boa Viagem!! #######################|\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

void MainMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|            > Escolha uma das seguintes opções <            |\n");
    printf("|                                                            |\n");
    printf("|                1 - Contas de Alunos                        |\n");
    printf("|                                                            |\n");
    printf("|                2 - Viagens e Pontos de Interesse           |\n");
    printf("|                                                            |\n");
    printf("|                        0 - Sair                            |\n");
    printf("|                                                            |\n");
    printf("|                       ___________                          |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(30, 10);
}

void StudentAccountsMenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|                        > Pretende <                        |\n");
    printf("|                                                            |\n");
    printf("|                 1 - Criar uma nova conta                   |\n");
    printf("|                                                            |\n");
    printf("|                 2 - Alterar dados de uma conta             |\n");
    printf("|                                                            |\n");
    printf("|                 3 - Eliminar uma conta                     |\n");
    printf("|                                                            |\n");
    printf("|                    0 - Menu Principal                      |\n");
    printf("|                                                            |\n");
    printf("|                        ___________                         |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(31, 12);
}

void StudentLoginMenu(void) {
    printf("+------------------------------------------------+\n");
    printf("|           Alteração de dados da conta!         |\n");
    printf("|      Insira o numero de telemovel da conta     |\n");
    printf("|          que vai ser sujeita a alteração.      |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 6);
}

void removeStudentMenu(void) {
    printf("+------------------------------------------------+\n");
    printf("|           Remoção de uma conta de um aluno     |\n");
    printf("|      Insira o numero de telemovel da conta     |\n");
    printf("|              que vai ser removida.             |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 6);
}

void login(void) {
    printf("+------------------------------------------------+\n");
    printf("|                >>>   LOGIN  <<<                |\n");
    printf("|                                                |\n");
    printf("| Numero de Telemovel:                           |\n");
    printf("+------------------------------------------------+\n");
    gotoxy(24, 4);
}


void whichPlaceMenu(void) {
    printf("+-----------------------------------------------------+\n");
    printf("|  > Insira o nome do local que prentede adicionar <  |\n");
    printf("|                                                     |\n");
    printf("| Nome do local:                                      |\n");
    printf("+-----------------------------------------------------+\n");
    gotoxy(18, 14);
}

void whichPointOfInterestMenu(void) {
    printf("+------------------------------------------------------------------+\n");
    printf("|  > Insira o nome do ponto de interesse que prentede adicionar <  |\n");
    printf("|                                                                  |\n");
    printf("| Nome do ponto de interesse:                                      |\n");
    printf("+------------------------------------------------------------------+\n");
    gotoxy(31,22);
}

void whichPointOfInterestRemoveMenu(void) {
    printf("+------------------------------------------------------------------+\n");
    printf("|  > Insira o nome do ponto de interesse que prentede remover <    |\n");
    printf("|                                                                  |\n");
    printf("| Nome do ponto de interesse:                                      |\n");
    printf("+------------------------------------------------------------------+\n");
    gotoxy(31,28);
}


void tripsMenu(void) {
    printf("+----------------------------------------------------------------------+\n");
    printf("|                             > Pretende <                             |\n");
    printf("|                                                                      |\n");
    printf("|      1 - Listar Locais e Pontos de Interesse disponiveis             |\n");
    printf("|                                                                      |\n");
    printf("|      2 - Adicionar um Local                                          |\n");
    printf("|                                                                      |\n");
    printf("|      3 - Remover um Local                                            |\n");
    printf("|                                                                      |\n");
    printf("|      4 - Adicionar um Ponto de Interesse                             |\n");
    printf("|                                                                      |\n");
    printf("|      5 - Remover um Ponto de Interesse                               |\n");
    printf("|                                                                      |\n");
    printf("|      6 - Construir uma Viagem (Necessário ter 3 Locais favoritos!)   |\n");
    printf("|                                                                      |\n");
    printf("|      7 - Os meus dados e preferencias                                |\n");
    printf("|                                                                      |\n");
    printf("|                                                                      |\n");
    printf("|                          0 - Menu Principal                          |\n");
    printf("|                               (LOGOUT)                               |\n");
    printf("|                                                                      |\n");
    printf("|                              ___________                             |\n");
    printf("+----------------------------------------------------------------------+\n");
    gotoxy(37, 22);
}

void yesOrno(void) {
    printf("+------------------------------------------------------------+\n");
    printf("| Locais favoritos totalmente preenchidos deseja substituir  |\n");
    printf("|        algum dos locais anteriores para colocar este?      |\n");
    printf("|                                                            |\n");
    printf("|            1 - Sim                  0 - Não                |\n");
    printf("|                        =========                           |\n");
    printf("+------------------------------------------------------------+\n");
}

void successRemovePlace(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("|               Local removido com sucesso!!                |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
}

void successAddPlace(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("|               Local adicionado com sucesso!!              |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

void justPause(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|            Carregue no Enter para continuar...             |\n");
    printf("+------------------------------------------------------------+\n");
}

void noFav(void) {
    gotoxy(0, 0);
    printf("+-----------------------------------------------------------------+\n");
    printf("|       O aluno ainda não tem locais favoritos definidos          |\n");
    printf("+-----------------------------------------------------------------+\n");
    ConsolePause(2);
}

void alreadyFavPlace(void) {
    printf("+-----------------------------------------------------------------+\n");
    printf("| Este local já se encontra na lista de locais favoritos do aluno |\n");
    printf("+-----------------------------------------------------------------+\n");
    ConsolePause(2);
}

void noPlace(void) {
    printf("+------------------------------------------------------------+\n");
    printf("| Este local não se encontra na lista de locais disponiveis! |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
}

void noPointOfInterest(void) {
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|   Este ponto de interesse não se encontra na lista de pontos de interesse disponiveis!   |\n");
    printf("+------------------------------------------------------------------------------------------+\n");
    ConsolePause(3);
}
void notFavPointOfInterest(void) {
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|   Este ponto de interesse não se encontra na lista de pontos de interesse favoritos!     |\n");
    printf("+------------------------------------------------------------------------------------------+\n");
    ConsolePause(3);
}

void alreadyFavPointOfInterest(void) {
    printf("+-------------------------------------------------------------------------------------------+\n");
    printf("| Este ponto de interesse já se encontra na lista de pontos de interesse favoritos do aluno |\n");
    printf("+-------------------------------------------------------------------------------------------+\n");
    ConsolePause(2);
}

void successPointOfInterest(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("|        Ponto de Interesse adicionado com sucesso!!        |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
}

void successremovePointOfInterest(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("|        Ponto de Interesse removido com sucesso!!          |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
}

void changeInfomenu(void) {
    printf("+------------------------------------------------------------+\n");
    printf("|             > Que parametro deseja alterar? <              |\n");
    printf("|                 1 - Alterar o nome                         |\n");
    printf("|                                                            |\n");
    printf("|                 2 - Alterar a morada                       |\n");
    printf("|                                                            |\n");
    printf("|                 3 - Alterar a data de nascimento           |\n");
    printf("|                                                            |\n");
    printf("|                 4 - Alterar o numero de Telemovel          |\n");
    printf("|                                                            |\n");
    printf("|                         0 - Voltar                         |\n");
    printf("|                                                            |\n");
    printf("|                        ____________                        |\n");
    printf("+------------------------------------------------------------+\n");
    gotoxy(33, 13);
}

void added(void) {
    ClearConsole();
    printf("+------------------------------------------------------------+\n");
    printf("|            A conta foi criada com sucesso!!                |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
}

void removed(void) {
    ClearConsole();
    printf("+------------------------------------------------------------+\n");
    printf("|           A conta foi removida com sucesso!!               |\n");
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
}

void noAccount(void) {
    printf("+------------------------------------------------------------+\n");
    printf("| O aluno com este número de telemovel não tem conta criada! |\n");;
    printf("+------------------------------------------------------------+\n");
    ConsolePause(2);
}

void hasAccount(void) {
    printf("+-----------------------------------------------------------+\n");
    printf("| O aluno com este número de telemovel já tem conta criada! |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
}

void invalidOption(void){
    printf("+-----------------------------------------------------------+\n");
    printf("|                       Opção Invalida                      |\n");
    printf("+-----------------------------------------------------------+\n");
    ConsolePause(2);
    ClearConsole();
}

