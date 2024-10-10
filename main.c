#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char usuario[30];
    char senha[7];
    char classe[50];
    int vida;
    int nivel;
    int xp;
    int mana;
    int forca;
    int inteligencia;
    int destreza;
    int vitalidade;
} jogador;

int cadastro();
int login();

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

    printf("Certo, %s, agora diga sua palavra-passe, para quando voltar, sabermos se é você mesmo. \n", novojogador.usuario);
    scanf("%s", novojogador.senha);

    printf("Perfeito, agora vamos montar seu personagem e atributos. \n");
    printf("1. Guerreiro. \n");
    printf("2. Bardo. \n");
    printf("3. Druida. \n");
    printf("4. Mago. \n");
    printf("5. Samurai. \n");
    printf("6. Arqueiro. \n");
    
    printf("Escolha uma opção. \n");
    scanf("%d", &opccharacter);

    if(opccharacter == 1){
        int confirm;
        printf("lore guerreiro\n");
        printf("Deseja escolher a classe Guerreiro? 1 - Sim / 2 - Não \n");
        scanf("%d", &confirm);
        if(confirm == 1){

        novojogador.vida = 100;
        novojogador.nivel = 1;
        novojogador.xp = 0;
        novojogador.mana = 50;
        novojogador.forca = 10;
        novojogador.inteligencia = 10;
        novojogador.destreza = 10;
        novojogador.vitalidade = 10;
        strcpy(novojogador.classe, "guerreiro");   
        }
        else{
            printf("Voltando... \n");
        }

    }
    else if(opccharacter == 2){
        int confirm;
        printf("lore bardo \n");
        printf("Deseja escolher a classe Bardo? 1 - Sim / 2 - Não \n");
        scanf("%d", &confirm);
        if(confirm == 1){

        }

    }
    




    novojogador.vida = 100;
    novojogador.nivel = 1;
    novojogador.xp = 0;
    novojogador.mana = 50;
    novojogador.forca = 10;
    novojogador.inteligencia = 10;
    novojogador.destreza = 10;
    novojogador.vitalidade = 10;

    FILE *arquivo = fopen("jogadores.bin", "ab");

    fwrite(&novojogador, sizeof(jogador), 1, arquivo);
    fclose(arquivo);
    printf("Tudo preparado, aventureiro. \n");

    login();

}

int login(){
    char usuario[30];
    char senha[7];
    int encontrado = 0;
    jogador jogadoratual;

    printf("Bem vindo de volta! Diga-me como é chamado em nossas terras. \n");
    scanf("%s", usuario);

    printf("Certo, agora me diga sua palavra-passe, apenas para confirmação. \n");
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

