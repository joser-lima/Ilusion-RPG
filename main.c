#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char usuario[30];
    char senha[7];
    char classe[50];
    int vida;
    int forca;
    int inteligencia;
    int agilidade;
    int ataquefisico;
    int ataqueespecial;
} jogador;

typedef struct {
    char nome[50];
    int vida;
    int forca;
    int inteligencia;
    int agilidade;
    int ataquefisico;
    int ataqueespecial;
} inimigo;

int cadastro();
int login();
void combate(jogador *jogador, inimigo *inimigo);

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opc;

    while (1){
        printf("Bem vindo(a), diga-me, o que deseja fazer? \n");
        printf("1. Novo jogo \n");
        printf("2. Carregar progresso \n");
        printf("3. Sair \n");
        scanf("%d", &opc);

        if(opc == 1){
            cadastro();
        }
        else if(opc == 2){
            login();
        }
        else if(opc == 3){
            printf("Saindo... \n");
            break;
        }
        else{
            printf("Inválido, tente novamente. \n");
        }
    }



    return 0;
}

int cadastro(){
    jogador novojogador;
    int opccharacter;

    printf("Bem vindo desafiante! Como prefere ser chamado? \n");
    scanf("%s", novojogador.usuario);

    printf("Certo, %s, agora me diga um código de 6 números, para quando voltar, sabermos se é você mesmo. \n", novojogador.usuario);
    scanf("%s", novojogador.senha);

    printf("Perfeito, agora vamos montar seu personagem e atributos. \n");
    
    while(1){
        printf("1. Guerreiro. \n");
        printf("2. Mago. \n");
        printf("3. Druida. \n");
        printf("4. Ninja. \n");

        printf("Escolha uma opção. \n");
        scanf("%d", &opccharacter);

        if(opccharacter == 1){
            int confirm;
            printf("Nascido no centro de Faramont, sempre dedicou sua vida inteira para o rei. Foi o guerreiro mais leal e guiou incontáveis exércitos para a vitória. Usando espada e escudo, é um mestre na arte de atacar e defender.\nVida: 120\nForca: 30\nInteligencia: 20\nAgilidade: 20\nAtaque físico: 20\nAtaque especial: 10");
            printf("Deseja escolher a classe Guerreiro? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 120;
                novojogador.forca = 30;
                novojogador.inteligencia = 5;
                novojogador.agilidade = 10;
                novojogador.ataquefisico = 20;
                novojogador.ataqueespecial = 10;
                strcpy(novojogador.classe, "guerreiro");
                printf("Seja bem vindo, guerreiro %s\n", novojogador.usuario);
                break;
            }
            else{
                printf("Voltando... \n");
            }

        }
        else if(opccharacter == 2){
            int confirm;
            printf("lore mago \n");
            printf("Vida: 70\nForça: 5\nInteligencia: 50\nAgilidade: 25\nAtaque físico: 10\nAtaque especial: 20");
            printf("Deseja escolher a classe Mago? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 70;
                novojogador.forca = 5;
                novojogador.inteligencia = 50;
                novojogador.agilidade = 25;
                novojogador.ataquefisico = 10;
                novojogador.ataqueespecial = 20;
                strcpy(novojogador.classe, "mago");
                printf("Seja bem vindo, mago %s\n", novojogador.usuario);
                break;               
            }
            else{
                printf("Voltando...\n");
            }

        }
        else if(opccharacter == 3){
            int confirm;
            printf("lore druida \n");
            printf("Vida: 100\nForça: 20\nInteligencia: 20\nAgilidade: 20\nAtaque físico: 15\nAtaque especial: 15\n");
            printf("Deseja escolher a classe Druida? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 100;
                novojogador.forca = 20;
                novojogador.inteligencia = 20;
                novojogador.agilidade = 20;
                novojogador.ataquefisico = 15;
                novojogador.ataqueespecial = 15;
                strcpy(novojogador.classe, "druida");
                printf("Seja bem vindo, druida %s\n", novojogador.usuario);    
                break;            
            }     
            else{
                printf("Voltando...\n");
            }   
        }
        else if(opccharacter == 4){
            int confirm;
            printf("lore ninja \n");
            printf("Vida: 90\nForça: 15\nInteligencia: 15\nAgilidade: 40\nAtaque físico: 15\nAtaque especial: 15\n");
            printf("Deseja escolher a classe Ninja? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 90;
                novojogador.forca = 15;
                novojogador.inteligencia = 15;
                novojogador.agilidade = 40;
                novojogador.ataquefisico = 15;
                novojogador.ataqueespecial = 15;
                strcpy(novojogador.classe, "ninja");
                printf("Seja bem vindo, ninja %s\n", novojogador.usuario);
                break;
            }
            else{
                printf("Voltando...\n");
            }
        }
    }

    FILE *arquivo = fopen("jogadores.bin", "ab");

    fwrite(&novojogador, sizeof(jogador), 1, arquivo);
    fclose(arquivo);
    printf("Tudo preparado, aventureiro. \n");

    login();
    return 1;
}

int login(){
    char usuario[30];
    char senha[7];
    int encontrado = 0;
    jogador jogadoratual;

    printf("Bem vindo de volta! Diga-me como é chamado em nossas terras. \n");
    scanf("%s", usuario);

    printf("Certo, agora me diga seu código de 6 números, apenas para confirmação. \n");
    scanf("%s", senha);

    FILE *arquivo = fopen("jogadores.bin", "rb");

    while(fread(&jogadoratual, sizeof(jogador), 1, arquivo)){
        if(strcmp(jogadoratual.usuario, usuario) == 0 && strcmp(jogadoratual.senha, senha) == 0){
            printf("Seja bem-vindo %s, pronto para continuar sua aventura? \n", usuario);
            encontrado = 1;
        }
    }

    fclose(arquivo); 

    if(!encontrado){
        printf("Alguma informação não está correta, por favor tente novamente. \n");
        return 0;
    }

    return 1;
}

void combate(jogador *jogador, inimigo *inimigo) {
    srand(time(NULL));
    int turno = 1;
    int dano, atkinimigo;
    int opcatk;

    while (jogador->vida > 0 && inimigo->vida > 0) {
        printf("Turno %d\n", turno);

        if (jogador->agilidade > inimigo->agilidade) {

            printf("Vez de %s\n", jogador->usuario);
            printf("1 - Ataque físico\n2 - Ataque especial\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    dano = (jogador->forca / 10) * jogador->ataquefisico;
                    inimigo->vida -= dano;
                } else {
                    inimigo->vida -= jogador->ataquefisico;
                }
            } else if (opcatk == 2) {
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                    inimigo->vida -= dano;
                } else {
                    inimigo->vida -= jogador->ataqueespecial;
                }
            }

            if (inimigo->vida <= 0) {
                printf("%s foi derrotado!\n", inimigo->nome);
                break;
            }

            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                jogador->vida -= inimigo->ataquefisico;
            } else {
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                jogador->vida -= inimigo->ataqueespecial;
            }

            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                break;
            }
        } else {
            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                jogador->vida -= inimigo->ataquefisico;
            } else {
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                jogador->vida -= inimigo->ataqueespecial;
            }

            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                break;
            }

            printf("Vez de %s\n", jogador->usuario);
            printf("1 - Ataque físico\n2 - Ataque especial\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    dano = (jogador->forca / 10) * jogador->ataquefisico;
                    inimigo->vida -= dano;
                } else {
                    inimigo->vida -= jogador->ataquefisico;
                }
            } else if (opcatk == 2) {
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                    inimigo->vida -= dano;
                } else {
                    inimigo->vida -= jogador->ataqueespecial;
                }
            }

            if (inimigo->vida <= 0) {
                printf("%s foi derrotado!\n", inimigo->nome);
                break;
            }
        }

        turno++;
    }
}