#include <windows.h>
#include <unistd.h>
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
    int fase;
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
void salvar(jogador *jogador);
int carregar(jogador *jogador);
void cura(jogador *jogador);
int fase1(jogador *jogador);
int fase2(jogador *jogador, inimigo *inimigo);
int fase3(jogador *jogador, inimigo *inimigo);
int fase4(jogador *jogador, inimigo *inimigo);
int fase5(jogador *jogador, inimigo *inimigo);
int fase6(jogador *jogador, inimigo *inimigo);
void limpar();
void pausar();

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
    pausar();
    limpar();
    
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
                novojogador.fase = 1;
                strcpy(novojogador.classe, "guerreiro");
                printf("Seja bem vindo, guerreiro %s\n", novojogador.usuario);
                pausar();
                limpar();
                break;
            }
            else{
                printf("Voltando... \n");
                pausar();
                limpar();
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
                novojogador.fase = 1;
                strcpy(novojogador.classe, "mago");
                printf("Seja bem vindo, mago %s\n", novojogador.usuario);
                pausar();
                limpar();
                break;               
            }
            else{
                printf("Voltando...\n");
                pausar();
                limpar();
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
                novojogador.fase = 1;
                strcpy(novojogador.classe, "druida");
                printf("Seja bem vindo, druida %s\n", novojogador.usuario);  
                pausar();
                limpar();  
                break;            
            }     
            else{
                printf("Voltando...\n");
                pausar();
                limpar();
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
                novojogador.fase = 1;
                strcpy(novojogador.classe, "ninja");
                printf("Seja bem vindo, ninja %s\n", novojogador.usuario);
                pausar();
                limpar();
                break;
            }
            else{
                printf("Voltando...\n");
                pausar();
                limpar();
            }
        }

        return 1;

    }

    salvar(&novojogador);

    FILE *arquivo = fopen("jogadores.bin", "ab");

    fwrite(&novojogador, sizeof(jogador), 1, arquivo);
    fclose(arquivo);
    printf("Tudo preparado, aventureiro. \n");
    pausar();
    limpar();

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
            pausar();
            limpar();
            encontrado = 1;
            
            if(carregar(&jogadoratual)){
                printf("Progresso carregado. Você está na fase %d.\n", jogadoratual.fase);
                pausar();
                limpar();

                switch(jogadoratual.fase){
                    case 1:
                        fase1(&jogadoratual);
                        break;
                    case 2:
                        fase2(&jogadoratual, NULL);
                        break;
                    case 3:
                        fase3(&jogadoratual, NULL);
                        break;
                    case 4:
                        fase3(&jogadoratual, NULL);
                        break;
                    case 5:
                        fase3(&jogadoratual, NULL);
                        break;
                    case 6:
                        fase3(&jogadoratual, NULL);
                        break;
                    default:
                        printf("Erro!\n");
                        break;                    
                }
            }
        }
    }

    fclose(arquivo); 

    if(!encontrado){
        printf("Alguma informação não está correta, por favor tente novamente. \n");
        pausar();
        limpar();
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
            sleep(1);
            printf("1 - Ataque físico\n2 - Ataque especial\n3 - Usar cura\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){        
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n"); 
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");  
                        dano = (jogador->forca / 10) * jogador->ataquefisico;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >=17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n");
                        dano = jogador->ataquefisico * 2;
                        inimigo->vida -= jogador->ataquefisico * 2; 
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");
                        inimigo->vida -= jogador->ataquefisico;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >= 17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano); 
                        salvar(jogador);       
                        pausar();
                        limpar();               
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);    
                        salvar(jogador);        
                        pausar();
                        limpar();            
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        salvar(jogador);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        pausar();
                        limpar();
                    }
                }
            }
            else if(opcatk == 3){
                cura(jogador);
                salvar(jogador);
            }

            if (inimigo->vida <= 0) {
                printf("%s foi derrotado!\n", inimigo->nome);
                salvar(jogador);
                pausar();
                limpar();
                break;
            }

            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Errou o ataque!\n");
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();                        
                }
                else{
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Dano commum!\n");
                    sleep(1);
                    jogador->vida -= inimigo->ataquefisico;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataquefisico);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
            } else {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Errou o ataque!\n");
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);   
                    salvar(jogador);
                    pausar();
                    limpar();                 
                }
                else{
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida); 
                    salvar(jogador);
                    pausar();
                    limpar();                  
                }
            }
            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                salvar(jogador);
                pausar();
                limpar();
                break;
            }
        } else {
            printf("Vez de %s\n", inimigo->nome);
            atkinimigo = rand() % 2;

            if (atkinimigo == 0) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Errou o ataque!\n");
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida); 
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else{
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataquefisico;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
            } else {
                srand(time(NULL));
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Errou o ataque!\n");
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);   
                    salvar(jogador);
                    pausar();
                    limpar();                  
                }
                else{
                    sleep(1);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    sleep(1);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    sleep(1);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    sleep(1);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
            }

            if (jogador->vida <= 0) {
                printf("Você foi derrotado!\n");
                salvar(jogador);
                pausar();
                limpar();
                break;
            }

            sleep(1);
            printf("Vez de %s\n", jogador->usuario);
            sleep(1);
            printf("1 - Ataque físico\n2 - Ataque especial\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");      
                        salvar(jogador);
                        pausar();
                        limpar();                  
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");  
                        dano = (jogador->forca / 10) * jogador->ataquefisico;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >=17){
                        sleep(1);
                       printf("Você rolou um d20 e obteve: %d\n", dado);
                       sleep(1);
                       printf("Acerto crítico!\n");
                       dano = jogador->ataquefisico * 2;
                       inimigo->vida -= jogador->ataquefisico * 2; 
                       sleep(1);
                       printf("%s causou %d de dano.\n",jogador->usuario, dano);
                       sleep(1);
                       printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                       salvar(jogador);
                       pausar();
                       limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");
                        inimigo->vida -= jogador->ataquefisico;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                        salvar(jogador);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        pausar();
                        limpar();
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                sleep(1);
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);  
                        salvar(jogador);
                        pausar();
                        limpar();                     
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");
                        sleep(1);
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >= 17){
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);   
                        salvar(jogador);
                        pausar();
                        limpar();                    
                    }
                    else if(dado >= 0 && dado < 4){
                        sleep(1);                        
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Errou o ataque!\n");
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        sleep(1);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        sleep(1);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        sleep(1);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        sleep(1);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();
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


int fase1(jogador *jogador){
    if(jogador->vida == 0){
        jogador->vida = jogador->vida_maxima;
    }
    
    inimigo goblin;
    

    strcpy(goblin.nome, "Goblin");
    goblin.vida = 500;
    goblin.forca = 5;
    goblin.inteligencia = 3;
    goblin.agilidade = 7;
    goblin.ataquefisico = 10;
    goblin.ataqueespecial = 5;
    
    printf("Você entrou na fase 1 e encontrou um %s!\n", goblin.nome);

    

    combate(jogador, &goblin);

    if (jogador->vida > 0) {
        printf("Você derrotou o %s e avançou para a próxima fase!\n", goblin.nome);
        jogador->fase++;
        salvar(jogador);

    } else {
        printf("Você foi derrotado e o jogo acabou.\n");
    }
}

int fase2(jogador *jogador, inimigo *inimigo){
    printf("Voce esta na fase 2\n");
    jogador->fase++;
    salvar(jogador);
    return 1;
}

int fase3(jogador *jogador, inimigo *inimigo){
    printf("Voce esta na fase 3\n");
    jogador->fase++;
    salvar(jogador);
    return 1;
}

int fase4(jogador *jogador, inimigo *inimigo){
    printf("Voce esta na fase 4\n");
    jogador->fase++;
    salvar(jogador);
    return 1;
}

int fase5(jogador *jogador, inimigo *inimigo){
    printf("Voce esta na fase 5\n");
    jogador->fase++;
    salvar(jogador);
    return 1;
}

int fase6(jogador *jogador, inimigo *inimigo){
    printf("Voce esta na fase 6\n");
    jogador->fase++;
    salvar(jogador);
    return 1;
}

void cura(jogador *jogador){
    if(jogador->frascoscura <= 0){
        printf("Você não tem frascos de cura suficientes!\n");
        pausar();
        limpar();
    }
    else{
        jogador->vida += 30;
        jogador->frascoscura -= 1;
        if(jogador->vida > jogador->vida_maxima){
            jogador->vida = jogador->vida_maxima;
        }
        sleep(1);
        printf("Você usou um frasco de cura!\n");
        sleep(1);
        printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
        pausar();
        limpar();
    }
}


void salvar(jogador *jogador) {
    char filename[50];
    sprintf(filename, "%s.txt", jogador->usuario);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erro ao salvar o progresso.\n");
        return;
    }

    fprintf(file, "%s\n", jogador->usuario);
    fprintf(file, "%s\n", jogador->senha);
    fprintf(file, "%s\n", jogador->classe);
    fprintf(file, "%d\n", jogador->vida);
    fprintf(file, "%d\n", jogador->vida_maxima);
    fprintf(file, "%d\n", jogador->forca);
    fprintf(file, "%d\n", jogador->inteligencia);
    fprintf(file, "%d\n", jogador->agilidade);
    fprintf(file, "%d\n", jogador->ataquefisico);
    fprintf(file, "%d\n", jogador->ataqueespecial);
    fprintf(file, "%d\n", jogador->frascoscura);
    fprintf(file, "%d\n", jogador->fase);

    fclose(file);
}


int carregar(jogador *jogador) {
    char filename[50];
    sprintf(filename, "%s.txt", jogador->usuario);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Progresso não encontrado para o jogador %s.\n", jogador->usuario);
        return 0;
    }

    fscanf(file, "%s", jogador->usuario);
    fscanf(file, "%s", jogador->senha);
    fscanf(file, "%s", jogador->classe);
    fscanf(file, "%d", &jogador->vida);
    fscanf(file, "%d", &jogador->vida_maxima);
    fscanf(file, "%d", &jogador->forca);
    fscanf(file, "%d", &jogador->inteligencia);
    fscanf(file, "%d", &jogador->agilidade);
    fscanf(file, "%d", &jogador->ataquefisico);
    fscanf(file, "%d", &jogador->ataqueespecial);
    fscanf(file, "%d", &jogador->frascoscura);
    fscanf(file, "%d", &jogador->fase);

    fclose(file);
    return 1;
}



void limpar() {
    #ifdef _WIN32   // pro windows
        system("cls");
    #else
        system("clear");    // pro linux ou mac
    #endif
}


void pausar() {
    #ifdef _WIN32
        system("pause");  // pro windows
    #else
        printf("Pressione qualquer tecla para continuar...\n");
        getchar();  // pro linux ou mac
    #endif
 }