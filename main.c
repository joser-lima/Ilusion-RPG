#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char usuario[30];
    char senha[7];
    char classe[50];
    int frascoscura;
    int vida_maxima;
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
void testecombate(jogador *jogador);
void cura(jogador *jogador);
int fase1(jogador *jogador, inimigo *inimigo);
int fase2(jogador *jogador, inimigo *inimigo);
int fase3(jogador *jogador, inimigo *inimigo);
int fase4(jogador *jogador, inimigo *inimigo);
int fase5(jogador *jogador, inimigo *inimigo);
int fase6(jogador *jogador, inimigo *inimigo);

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
            printf("Nascido no centro de Faramont, sempre dedicou sua vida inteira para o rei. Foi o guerreiro mais leal e guiou incontáveis exércitos para a vitória. Usando espada e escudo, é um mestre na arte de atacar e defender.\nVida: 120\nForca: 30\nInteligencia: 20\nAgilidade: 20\nAtaque físico: 20\nAtaque especial: 10\nFrascos de cura: 5\n");
            printf("Deseja escolher a classe Guerreiro? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 120;
                novojogador.vida_maxima = 120;
                novojogador.forca = 30;
                novojogador.inteligencia = 10;
                novojogador.agilidade = 10;
                novojogador.ataquefisico = 20;
                novojogador.ataqueespecial = 10;
                novojogador.frascoscura = 5;
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
            printf("Vida: 70\nForça: 5\nInteligencia: 50\nAgilidade: 25\nAtaque físico: 10\nAtaque especial: 20\nFrascos de cura: 5\n");
            printf("Deseja escolher a classe Mago? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 70;
                novojogador.vida_maxima = 70;
                novojogador.forca = 10;
                novojogador.inteligencia = 50;
                novojogador.agilidade = 25;
                novojogador.ataquefisico = 10;
                novojogador.ataqueespecial = 20;
                novojogador.frascoscura = 5;
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
            printf("Vida: 100\nForça: 20\nInteligencia: 20\nAgilidade: 20\nAtaque físico: 15\nAtaque especial: 15\nFrascos de cura: 5\n");
            printf("Deseja escolher a classe Druida? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 100;
                novojogador.vida_maxima = 100;
                novojogador.forca = 20;
                novojogador.inteligencia = 20;
                novojogador.agilidade = 20;
                novojogador.ataquefisico = 15;
                novojogador.ataqueespecial = 15;
                novojogador.frascoscura = 5;
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
            printf("Vida: 90\nForça: 15\nInteligencia: 15\nAgilidade: 40\nAtaque físico: 15\nAtaque especial: 15\nFrascos de cura: 5\n");
            printf("Deseja escolher a classe Ninja? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 90;
                novojogador.vida_maxima = 90;
                novojogador.forca = 15;
                novojogador.inteligencia = 15;
                novojogador.agilidade = 40;
                novojogador.ataquefisico = 15;
                novojogador.ataqueespecial = 15;
                novojogador.frascoscura = 5;
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
            testecombate(&jogadoratual);
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
    int turno = 1;
    int dano, atkinimigo;
    int opcatk;
    srand(time(NULL));;

    while (jogador->vida > 0 && inimigo->vida > 0) {
        printf("Turno %d\n", turno);

        if (jogador->agilidade > inimigo->agilidade) {

            printf("Vez de %s\n", jogador->usuario);
            printf("1 - Ataque físico\n2 - Ataque especial\n3 - Usar cura\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                int dado = (rand() % 20) + 1;
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");                        
                    }
                    else{
                    printf("Você rolou um d20 e obteve: %d\n", dado);
                    printf("Dano comum!\n");  
                    dano = (jogador->forca / 10) * jogador->ataquefisico;
                    inimigo->vida -= dano;
                    printf("%s causou %d de dano.\n",jogador->usuario, dano);
                    printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                } else {
                    if(dado >=17){
                       printf("Você rolou um d20 e obteve: %d\n", dado);
                       printf("Acerto crítico!\n");
                       dano = jogador->ataquefisico * 2;
                       inimigo->vida -= jogador->ataquefisico * 2; 
                       printf("%s causou %d de dano.\n",jogador->usuario, dano);
                       printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else{
                    printf("Você rolou um d20 e obteve: %d\n", dado);
                    printf("Dano comum!\n");
                    inimigo->vida -= jogador->ataquefisico;
                    printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                    printf("Vida dehhdgfg  %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);                       
                    }
                    else{
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Dano comum!\n");
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                    }
                } else {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);                       
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);                        
                    }
                    else{
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                    }
                }
            }
            else if(opcatk == 3){
                cura(jogador);
            }

            if (inimigo->vida <= 0) {
                printf("%s foi derrotado!\n", inimigo->nome);
                break;
            }

            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
                else if(dado >= 0 && dado < 4){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Errou o ataque!\n");
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);                        
                }
                else{
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataquefisico;
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataquefisico);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
            } else {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
                else if(dado >= 0 && dado < 4){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Errou o ataque!\n");
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);                    
                }
                else{
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);                   
                }
            }
            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                break;
            }
        } else {
            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
                else if(dado >= 0 && dado < 4){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Errou o ataque!\n");
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida); 
                }
                else{
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataquefisico;
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
            } else {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
                else if(dado >= 0 && dado < 4){
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Errou o ataque!\n");
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);                     
                }
                else{
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                }
            }

            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                break;
            }

            printf("Vez de %s\n", jogador->usuario);
            printf("1 - Ataque físico\n2 - Ataque especial\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");                        
                    }
                    else{
                    printf("Você rolou um d20 e obteve: %d\n", dado);
                    printf("Dano comum!\n");  
                    dano = (jogador->forca / 10) * jogador->ataquefisico;
                    inimigo->vida -= dano;
                    printf("%s causou %d de dano.\n",jogador->usuario, dano);
                    printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                } else {
                    if(dado >=17){
                       printf("Você rolou um d20 e obteve: %d\n", dado);
                       printf("Acerto crítico!\n");
                       dano = jogador->ataquefisico * 2;
                       inimigo->vida -= jogador->ataquefisico * 2; 
                       printf("%s causou %d de dano.\n",jogador->usuario, dano);
                       printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else{
                    printf("Você rolou um d20 e obteve: %d\n", dado);
                    printf("Dano comum!\n");
                    inimigo->vida -= jogador->ataquefisico;
                    printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                    printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);                       
                    }
                    else{
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Dano comum!\n");
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                    }
                } else {
                    if(dado >= 17){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);                       
                    }
                    else if(dado >= 0 && dado < 4){
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Errou o ataque!\n");
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);                        
                    }
                    else{
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                    }
                }
            }
            else if(opcatk == 3){
                cura(jogador);
            }
        }

        turno++;
    }
}

void testecombate(jogador *jogador) {
    inimigo goblin;
    
    // Definindo os atributos do inimigo da fase 1
    strcpy(goblin.nome, "Goblin");
    goblin.vida = 500;
    goblin.forca = 5;
    goblin.inteligencia = 3;
    goblin.agilidade = 7;
    goblin.ataquefisico = 10;
    goblin.ataqueespecial = 5;
    
    printf("Você entrou na fase 1 e encontrou um %s!\n", goblin.nome);
    
    // Chama a função de combate entre o jogador e o inimigo
    combate(jogador, &goblin);

    if (jogador->vida > 0) {
        printf("Você derrotou o %s e avançou para a próxima fase!\n", goblin.nome);
    } else {
        printf("Você foi derrotado e o jogo acabou.\n");
    }
}

int fase1(jogador *jogador, inimigo *inimigo){
    return 1;
}

int fase2(jogador *jogador, inimigo *inimigo){
    return 1;
}

int fase3(jogador *jogador, inimigo *inimigo){
    return 1;
}

int fase4(jogador *jogador, inimigo *inimigo){
    return 1;
}

int fase5(jogador *jogador, inimigo *inimigo){
    return 1;
}

int fase6(jogador *jogador, inimigo *inimigo){
    return 1;
}

void cura(jogador *jogador){
    if(jogador->frascoscura <= 0){
        printf("Você não tem frascos de cura suficientes!\n");
    }
    else{
        jogador->vida += 30;
        jogador->frascoscura -= 1;
        if(jogador->vida > jogador->vida_maxima){
            jogador->vida = jogador->vida_maxima;
        }
        printf("Você usou um frasco de cura!\n");
        printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
    }
}