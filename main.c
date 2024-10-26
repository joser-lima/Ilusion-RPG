#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#ifdef _WIN32
    #include <windows.h>
    #define SLEEP(ms) Sleep(ms)
#else
    #include <unistd.h>
    #define SLEEP(ms) usleep((ms) * 1000)
#endif


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
int fase2(jogador *jogador);
int fase3(jogador *jogador);
int fase4(jogador *jogador);
int fase5(jogador *jogador);
int fase6(jogador *jogador);
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
            printf("Um forte e corajoso lutador, que está sempre na linha de frente do combate preparado para resolver as coisas com suas próprias mãos.\nVida: 120\nForca: 30\nInteligencia: 20\nAgilidade: 20\nAtaque físico: 20\nAtaque especial: 10\nFrascos de cura: 5\n");
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
                continue;
            }

        }
        else if(opccharacter == 2){
            int confirm;
            printf("Um poderoso e inteligente feiticeiro, que apesar de sua fragilidade compensa com sua magia extremamente poderosa capaz de destruir tudo pela sua frente.\n");
            printf("Vida: 70\nForça: 5\nInteligencia: 40\nAgilidade: 25\nAtaque físico: 10\nAtaque especial: 20\nFrascos de cura: 5\n");
            printf("Deseja escolher a classe Mago? 1 - Sim / 2 - Não \n");
            scanf("%d", &confirm);
            if(confirm == 1){
                novojogador.vida = 70;
                novojogador.vida_maxima = 70;
                novojogador.forca = 10;
                novojogador.inteligencia = 40;
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
                continue;
            }

        }
        else if(opccharacter == 3){
            int confirm;
            printf("Um equilíbrio entre todas as forças, resistente e veloz sendo altamente eficaz com quaisquer tipo de ataque, estando sempre preparado para qualquer combate.\n");
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
                continue;
            }   
        }
        else if(opccharacter == 4){
            int confirm;
            printf("Se movimentando como um vulto suas habilidades vão muito além de sua agilidade, sendo capaz de atacar com suas mãos ou com magia, combinado com sua velocidade se torna uma arma letal.\n");
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
                continue;
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
                        fase2(&jogadoratual);
                        break;
                    case 3:
                        fase3(&jogadoratual);
                        break;
                    case 4:
                        fase4(&jogadoratual);
                        break;
                    case 5:
                        fase5(&jogadoratual);
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
            SLEEP(1000);
            printf("1 - Ataque físico\n2 - Ataque especial\n3 - Usar cura\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){        
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n"); 
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");  
                        dano = (jogador->forca / 10) * jogador->ataquefisico;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >=17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n");
                        dano = jogador->ataquefisico * 2;
                        inimigo->vida -= jogador->ataquefisico * 2; 
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");
                        inimigo->vida -= jogador->ataquefisico;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >= 17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano); 
                        salvar(jogador);       
                        pausar();
                        limpar();               
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);    
                        salvar(jogador);        
                        pausar();
                        limpar();            
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        salvar(jogador);
                        SLEEP(1000);
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
                SLEEP(1000);
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Errou o ataque!\n");
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();                        
                }
                else{
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Dano commum!\n");
                    SLEEP(1000);
                    jogador->vida -= inimigo->ataquefisico;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataquefisico);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
            } else {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Errou o ataque!\n");
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);   
                    salvar(jogador);
                    pausar();
                    limpar();                 
                }
                else{
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    SLEEP(1000);
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
                SLEEP(1000);
                printf("%s atacou com um ataque físico\n", inimigo->nome);
                if(dado >= 17){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataquefisico) * 2;
                    dano = (inimigo->ataquefisico) * 2;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Errou o ataque!\n");
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida); 
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else{
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataquefisico;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
            } else {
                srand(time(NULL));
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s atacou com um ataque especial\n", inimigo->nome);
                if(dado >= 17){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Acerto crítico!\n");
                    jogador->vida -= (inimigo->ataqueespecial) * 2;
                    dano = (inimigo->ataqueespecial) * 2;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, dano);
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);
                    salvar(jogador);
                    pausar();
                    limpar();
                }
                else if(dado >= 0 && dado < 4){
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Errou o ataque!\n");
                    SLEEP(1000);
                    printf("Vida de %s restante: %d\n",jogador->usuario, jogador->vida);   
                    salvar(jogador);
                    pausar();
                    limpar();                  
                }
                else{
                    SLEEP(1000);
                    printf("%s rolou um d20 e obteve: %d\n",inimigo->nome, dado);
                    SLEEP(1000);
                    printf("Dano commum!\n");
                    jogador->vida -= inimigo->ataqueespecial;
                    SLEEP(1000);
                    printf("%s causou %d de dano.\n",inimigo->nome, inimigo->ataqueespecial);
                    SLEEP(1000);
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

            SLEEP(1000);
            printf("Vez de %s\n", jogador->usuario);
            SLEEP(1000);
            printf("1 - Ataque físico\n2 - Ataque especial\n3 - Usar cura\n");
            scanf("%d", &opcatk);

            if (opcatk == 1) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s ataca com um ataque físico.\n", jogador->usuario);
                if (jogador->forca >= inimigo->forca) {
                    if(dado >= 17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->forca / 10) * jogador->ataquefisico) * 2;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");      
                        salvar(jogador);
                        pausar();
                        limpar();                  
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");  
                        dano = (jogador->forca / 10) * jogador->ataquefisico;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >=17){
                        SLEEP(1000);
                       printf("Você rolou um d20 e obteve: %d\n", dado);
                       SLEEP(1000);
                       printf("Acerto crítico!\n");
                       dano = jogador->ataquefisico * 2;
                       inimigo->vida -= jogador->ataquefisico * 2; 
                       SLEEP(1000);
                       printf("%s causou %d de dano.\n",jogador->usuario, dano);
                       SLEEP(1000);
                       printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                       salvar(jogador);
                       pausar();
                       limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");
                        inimigo->vida -= jogador->ataquefisico;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataquefisico);
                        salvar(jogador);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        pausar();
                        limpar();
                    }
                }
            } else if (opcatk == 2) {
                srand(time(NULL));;
                int dado = (rand() % 20) + 1;
                SLEEP(1000);
                printf("%s ataca com um ataque especial.\n", jogador->usuario);
                if (jogador->inteligencia > inimigo->inteligencia) {
                    if(dado >= 17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n");
                        dano = ((jogador->inteligencia / 10) * jogador->ataqueespecial) * 2;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida);  
                        salvar(jogador);
                        pausar();
                        limpar();                     
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");
                        SLEEP(1000);
                        dano = (jogador->inteligencia / 10) * jogador->ataqueespecial;
                        inimigo->vida -= dano;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();
                    }
                } else {
                    if(dado >= 17){
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Acerto crítico!\n"); 
                        dano = jogador->ataqueespecial * 2;
                        inimigo->vida -= jogador->ataqueespecial * 2;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, dano);   
                        salvar(jogador);
                        pausar();
                        limpar();                    
                    }
                    else if(dado >= 0 && dado < 4){
                        SLEEP(1000);                        
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Errou o ataque!\n");
                        SLEEP(1000);
                        printf("Vida de %s restante: %d\n",inimigo->nome, inimigo->vida); 
                        salvar(jogador);
                        pausar();
                        limpar();                       
                    }
                    else{
                        SLEEP(1000);
                        printf("Você rolou um d20 e obteve: %d\n", dado);
                        SLEEP(1000);
                        printf("Dano comum!\n");                       
                        inimigo->vida -= jogador->ataqueespecial;
                        SLEEP(1000);
                        printf("%s causou %d de dano.\n",jogador->usuario, jogador->ataqueespecial);
                        SLEEP(1000);
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
    if(jogador->vida <= 0){
        jogador->vida = jogador->vida_maxima;
    }
    

    inimigo inseto;
    inimigo fantasma;
    

    strcpy(inseto.nome, "Inseto");
    inseto.vida = 100;
    inseto.forca = 10;
    inseto.inteligencia = 10;
    inseto.agilidade = 5;
    inseto.ataquefisico = 10;
    inseto.ataqueespecial = 15;

    strcpy(fantasma.nome, "Rigel");
    fantasma.vida = 200;
    fantasma.forca = 10;
    fantasma.inteligencia = 10;
    fantasma.agilidade = 35;
    fantasma.ataquefisico = 20;
    fantasma.ataqueespecial = 10;

    
    printf("Você começa sua jornada saindo do vilarejo que sempre conheceu, e logo se depara com um enxame de insetos que se tornam seus adversários perfeitos para um primeiro combate.\n", inseto.nome);
    pausar();
    limpar();
    

    combate(jogador, &inseto);

    if (jogador->vida > 0) {
        printf("Você derrotou os insetos. Depois desse combate, você segue uma caminhada melancólica, perdida. Até encontrar um grupo de viajantes, que comentam sobre um monge que vive após o oceano, então é pra lá que deve seguir.\n");
        pausar();
        limpar();

        printf("Ao encontrar a água, você se depara com um navio pirata abandonado, explorando o interior para seguir a viagem, %s, o capitão fantasma te surpreende com sua espada, e você não tem nenhuma outra opção além de um duelo.\n", fantasma.nome);
        pausar();
        limpar();
        
        combate(jogador, &fantasma);
        if(jogador->vida > 0){
            int respuser;
            printf("%s foi derrotado.\nVocê ganhou uma melhoria para seus atributos. Escolha o atributo que deseja melhorar.\n1 - Vida\n2 - Força\n3 - Inteligencia\n4 - Agilidade\n", fantasma.nome);
            scanf("%d", &respuser);
            if(respuser == 1){
                jogador->vida_maxima += 20;
                printf("Você aumentou sua vida em 20 pontos\n");
                jogador->fase++;
                salvar(jogador);
                pausar();
                limpar();
                fase2(jogador);
            }
            else if(respuser == 2){
                jogador->ataquefisico += 5;
                printf("Você aumentou seu ataque fisico em 5\n");
                jogador->fase++;
                salvar(jogador);
                pausar();
                limpar();
                fase2(jogador);                
            }
            else if(respuser == 3){
                jogador->ataqueespecial += 5;
                printf("Você aumentou seu ataque especial em 5\n");
                jogador->fase++;
                salvar(jogador);
                pausar();
                limpar();
                fase2(jogador);
            }
            else{
                jogador->agilidade += 5;
                printf("Você aumentou sua agilidade em 5\n");
                jogador->fase++;
                salvar(jogador);
                pausar();
                limpar();
                fase2(jogador);                
            }
        }
        else{
            printf("Você foi derrotado e o jogo acabou.\n");
        }

    }
    else {
        printf("Você foi derrotado e o jogo acabou.\n");
    }
}

int fase2(jogador *jogador){
    if(jogador->vida <= 0){
        jogador->vida = jogador->vida_maxima;
    }
    

    printf("Continuando a aventura, você segue pelo, a princípio, calmo mar e aproveita para fazer uma pescaria, depois de muita calma e espera você consegue um bau de tesouro, dentro dele tem 3 poções de cura!\n");
    jogador->frascoscura += 3;
    pausar();
    limpar();
    
    printf("Mais a frente o tempo vira, e dá início uma grande tempestade. Em meio a ondas gigantes você encontra outro navio pirata, que também quer sua cabeça.\n");
    pausar();
    limpar();

    inimigo pirata;
    strcpy(pirata.nome, "Pirata");
    pirata.vida = 150;
    pirata.forca = 25;
    pirata.inteligencia = 5;
    pirata.agilidade = 10;
    pirata.ataquefisico = 25;
    pirata.ataqueespecial = 10;
    
    inimigo sereia;
    strcpy(sereia.nome, "Sereia");
    sereia.vida = 140;
    sereia.forca = 25;
    sereia.inteligencia = 5;
    sereia.agilidade = 20;
    sereia.ataquefisico = 10;
    sereia.ataqueespecial = 30;

    inimigo kraken;
    strcpy(kraken.nome, "Kraken");
    kraken.vida = 220;
    kraken.forca = 25;
    kraken.inteligencia = 5;
    kraken.agilidade = 25;
    kraken.ataquefisico = 20;
    kraken.ataqueespecial = 20;

    combate(jogador, &pirata);

    if (jogador->vida > 0) {
        printf("Após uma árdua batalha, anoitece e você se encontra perdido em mar aberto. Um pouco a frente surge uma luz no horizonte, você segue até ela.!\n");
        pausar();
        limpar();
        printf("Ao se aproximar, percebe que foi atraido para uma armadilha feita por uma sereia, então você se prepara para a luta.\n");
        pausar();
        limpar();
        combate(jogador, &sereia);

        if(jogador->vida > 0){
            printf("Depois desses eventos o caminho parece estar tranquilo, então você segue em direção a costa, até que o mar se agita e uma espécie de furacão se forma em sua frente, saindo do meio dele um gigantesco Kraken que logo te ataca.\n");
            pausar();
            limpar();
            combate(jogador, &kraken);
            if(jogador->vida > 0){
                int respuser;
                printf("%s foi derrotado.\nVocê ganhou uma melhoria para seus atributos. Escolha o atributo que deseja melhorar.\n1 - Vida\n2 - Força\n3 - Inteligencia\n4 - Agilidade\n", kraken.nome);
                scanf("%d", &respuser);
                if(respuser == 1){
                    jogador->vida_maxima += 20;
                    jogador->vida = jogador->vida_maxima;
                    printf("Você aumentou sua vida em 20 pontos\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    fase3(jogador);
                }
                else if(respuser == 2){
                    jogador->ataquefisico += 5;
                    printf("Você aumentou seu ataque fisico em 5\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    fase3(jogador);                
                }
                else if(respuser == 3){
                    jogador->ataqueespecial += 5;
                    printf("Você aumentou seu ataque especial em 5\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    fase3(jogador);
                }
                else{
                    jogador->agilidade += 5;
                    printf("Você aumentou sua agilidade em 5\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    fase3(jogador);                
                }  

            }

        }

        else{
            printf("Você foi derrotado e o jogo acabou.\n");
        }

    } else {
        printf("Você foi derrotado e o jogo acabou.\n");
    }
}

int fase3(jogador *jogador){
    if(jogador->vida <= 0){
        jogador->vida = jogador->vida_maxima;
    }
    

    
    inimigo boneco;
    strcpy(boneco.nome, "Boneco de treino");
    boneco.vida = 70;
    boneco.forca = 25;
    boneco.inteligencia = 5;
    boneco.agilidade = 10;
    boneco.ataquefisico = 10;
    boneco.ataqueespecial = 10;
    
    inimigo aluno;
    strcpy(aluno.nome, "Aluno");
    aluno.vida = 140;
    aluno.forca = 25;
    aluno.inteligencia = 5;
    aluno.agilidade = 20;
    aluno.ataquefisico = 20;
    aluno.ataqueespecial = 20;

    inimigo monge;
    strcpy(monge.nome, "Monge");
    monge.vida = 250;
    monge.forca = 25;
    monge.inteligencia = 5;
    monge.agilidade = 25;
    monge.ataquefisico = 30;
    monge.ataqueespecial = 30;


    printf("Passada essa difícil batalha você consegue voltar a terra firme. Andando poucos metros você logo encontra uma vila que acredita ser a que ouvira anteriormente.\n");
    pausar();
    limpar();

    printf("Você sente clima muito diferente de tudo que já tinha sentido nesse vilarejo, parece que o caos não entrou nessa civilização, cada passo dado naquela estrada batida de terra você se sentia mais esperançoso sobre esse mundo. Até que uma senhora que o vê passar te indaga com uma pergunta -“O que faz aqui filho ? ” e você prontamente responde  -“Estou atrás de um famoso monge que me auxiliará a salvar esse mundo”, com essa resposta ela fica motivada com seu propósito e conta que o monge vive no templo que está à oeste do vilarejo e é pra lá que deve seguir.\n");
    pausar();
    limpar();

    printf("Chegando lá você encontra o monge virado para a parede, fragilizado, então ele sem se quer olhar quem tinha entrado pela porta pergunta -“Também está aqui para dominar o mundo ? ”, e você conta a ele sua trajetória até chegar naquele momento, mas você curioso pergunta -“Por que o também em sua pergunta ? ”, então ele conta -“ Fui eu quem ensinou tudo que Surtur sabe. Ele foi o aluno mais habilidoso que sempre tive, chegou aqui jovem, assim como você, ele era gentil e bondoso, mas a morte de seu pai o mudou completamente, passando a ser obcecado pela vida eterna e visando proteger a qualquer custo aqueles que ele gostava. Após uma intenção discussão que nos tivemos ele foi atrás do coração, mas pela nossa relação ele impediu que a maldição entrasse nesse vilarejo, por isso estamos seguros aqui.” , você então súplica pelo treinamento dele para derrotar Surtur, o monge fica relutante mas aceita te treinar.\n");
    pausar();
    limpar();

    combate(jogador, &boneco);

    if(jogador->vida > 0){
        printf("Você derrotou o boneco de treino e melhorou todos seus atributos!\n");
        jogador->vida_maxima += 30;
        jogador->vida = jogador->vida_maxima;
        jogador->inteligencia += 5;
        jogador->forca += 5;
        jogador->ataquefisico += 10;
        jogador->ataqueespecial += 10;
        jogador->agilidade += 5;
        pausar();
        limpar();

        printf("Após este treinamento, o monge chama um de seus melhores alunos para lutar contra você.\n");
        pausar();
        limpar();

        combate(jogador, &aluno);

        if(jogador->vida > 0){
            printf("Você derrotou o aluno e melhorou todos seus atributos!\n");
            jogador->vida_maxima += 30;
            jogador->vida = jogador->vida_maxima;
            jogador->inteligencia += 5;
            jogador->forca += 5;
            jogador->ataquefisico += 10;
            jogador->ataqueespecial += 10;
            jogador->agilidade += 5;
            pausar();
            limpar();

            printf("Depois de derrotar o aluno com maestria, o Monge se prepara para a última parte do treinamento, uma luta entre vocês dois.\n");
            pausar();
            limpar();

            combate(jogador, &monge);

            if(jogador->vida > 0){
                printf("Você derrotou o Monge e melhorou todos seus atributos!\n");
                jogador->vida_maxima += 50;
                jogador->vida = jogador->vida_maxima;
                jogador->inteligencia += 10;
                jogador->forca += 10;
                jogador->ataquefisico += 20;
                jogador->ataqueespecial += 20;
                jogador->agilidade += 10;
                jogador->frascoscura += 10;
                pausar();
                limpar();

                int respuser;
                printf("Agora escolha qual atributo desse melhorar mais ainda: \n1 - Vida\n2 - Força\n3 - Inteligencia\n4 - Agilidade\n");
                scanf("%d", &respuser);
                if(respuser == 1){
                    jogador->vida_maxima += 50;
                    jogador->vida = jogador->vida_maxima;
                    printf("Você aumentou sua vida em 50 pontos\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    printf("Depois desse treinamento o monge da a você 10 frascos de cura e diz que Surtur está em Titã, a maior montanha do planeta, que é para lá que você deve seguir.\n");
                    pausar();
                    limpar();
                    fase4(jogador);
                }
                else if(respuser == 2){
                    jogador->ataquefisico += 20;
                    printf("Você aumentou seu ataque fisico em 20\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    printf("Depois desse treinamento o monge da a você 10 frascos de cura e diz que Surtur está em Titã, a maior montanha do planeta, que é para lá que você deve seguir.\n");
                    pausar();
                    limpar();
                    fase4(jogador);                
                }
                else if(respuser == 3){
                    jogador->ataqueespecial += 20;
                    printf("Você aumentou seu ataque especial em 20\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    printf("Depois desse treinamento o monge da a você 10 frascos de cura e diz que Surtur está em Titã, a maior montanha do planeta, que é para lá que você deve seguir.\n");
                    pausar();
                    limpar();
                    fase4(jogador);
                }
                else{
                    jogador->agilidade += 10;
                    printf("Você aumentou sua agilidade em 10\n");
                    jogador->fase++;
                    salvar(jogador);
                    pausar();
                    limpar();
                    printf("Depois desse treinamento o monge da a você 10 frascos de cura e diz que Surtur está em Titã, a maior montanha do planeta, que é para lá que você deve seguir.\n");
                    pausar();
                    limpar();
                    fase4(jogador);                
                }
            }
            else{
                printf("Você foi derrotado e o jogo acabou.\n");
            }

        }
        else{
            printf("Você foi derrotado e o jogo acabou.\n");
        }

    }
    else{
        printf("Você foi derrotado e o jogo acabou.\n");
    }
    return 1;
}

int fase4(jogador *jogador){
    if(jogador->vida <= 0){
        jogador->vida = jogador->vida_maxima;
    }
    

    
    inimigo grifo;
    strcpy(grifo.nome, "Grifo");
    grifo.vida = 300;
    grifo.forca = 25;
    grifo.inteligencia = 5;
    grifo.agilidade = 10;
    grifo.ataquefisico = 40;
    grifo.ataqueespecial = 20;
    
    inimigo medusa;
    strcpy(medusa.nome, "Medusa");
    medusa.vida = 400;
    medusa.forca = 25;
    medusa.inteligencia = 5;
    medusa.agilidade = 20;
    medusa.ataquefisico = 20;
    medusa.ataqueespecial = 50;

    inimigo hydra;
    strcpy(hydra.nome, "Hydra");
    hydra.vida = 500;
    hydra.forca = 25;
    hydra.inteligencia = 5;
    hydra.agilidade = 25;
    hydra.ataquefisico = 40;
    hydra.ataqueespecial = 40;

    printf("Ao chegar no pé da montanha você se depara com uma íngreme subida, e logo se apresenta seu primeiro inimigo, um majestoso Grifo.\n");
    pausar();
    limpar();
    combate(jogador, &grifo);

    if(jogador->vida > 0){
        printf("Com dificuldades você continua subindo, até encontrar Medusa que quer impedir sua chegada ao topo.\n");
        pausar();
        limpar();
        combate(jogador, &medusa);

        if(jogador->vida > 0){
            printf("Finalmente você chega em um lugar plano para descansar, mas antes disso tem uma Hydra que precisa derrotar para conquistar esse local.\n");
            pausar();
            limpar();
            combate(jogador, &hydra);

            if(jogador->vida > 0){
                printf("Vasculhando o lugar você encontra uma mochila com 5 poções de cura, as quais eram de outro aventureiro que tentou desbancar Surtur e não teve tanta sorte.\n");
                pausar();
                limpar();
                jogador->frascoscura += 5;
                jogador->vida = jogador->vida_maxima;
                jogador->fase++;
                salvar(jogador);
                fase5(jogador);
            }
            else{
                printf("Você foi derrotado e o jogo acabou.\n");
            }
        }
        else{
            printf("Você foi derrotado e o jogo acabou.\n");
        }
    }
    else{
        printf("Você foi derrotado e o jogo acabou.\n");
    }

    return 1;
}

int fase5(jogador *jogador){
    if(jogador->vida <= 0){
        jogador->vida = jogador->vida_maxima;
    }

    inimigo dragao;
    strcpy(dragao.nome, "Rhea");
    dragao.vida = 500;
    dragao.forca = 25;
    dragao.inteligencia = 5;
    dragao.agilidade = 20;
    dragao.ataquefisico = 40;
    dragao.ataqueespecial = 50;

    inimigo surtur;
    strcpy(surtur.nome, "Surtur");
    surtur.vida = 700;
    surtur.forca = 25;
    surtur.inteligencia = 5;
    surtur.agilidade = 25;
    surtur.ataquefisico = 60;
    surtur.ataqueespecial = 60;

    printf("Depois de descansar você chega caminha um pouco e chega ao topo da montanha e logo avista Surtur levantando sua espada montado em Rhea seu colossal dragão pronto para te atacar.\n");
    
    printf("                 ==(W{==========-      /===-                        \n");
    printf("                              ||  (.--.)         /===-_---~~~~~~~~~------____  \n");
    printf("                              | \\_,|**|,__      |===-~___                _,-' `\n");
    printf("                 -==\\\\        `\\ ' `--'   ),    `//~\\\\   ~~~~`---.___.-~~      \n");
    printf("             ______-==|        /`\\_. .__/\\ \\    | |  \\\\           _-~`         \n");
    printf("       __--~~~  ,-/-==\\\\      (   | .  |~~~~|   | |   `\\        ,'              \n");
    printf("    _-~       /'    |  \\\\     )__/==0==-\\<>/   / /      \\      /               \n");
    printf("  .'        /       |   \\\\      /~\\___/~~\\/  /' /        \\   /'               \n");
    printf(" /  ____  /         |    \\`\\.__/-~~   \\  |_/'  /          \\/'                   \n");
    printf("/-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~`                    \n");
    printf("                  \\_|      /        _) | ;  ),   __--~~                         \n");
    printf("                    '~~--_/      _-~/- |/ \\   '-~ \\                             \n");
    printf("                   {\\__--_/}    / \\\\_>-|)<__\\      \\                            \n");
    printf("                   /'   (_/  _-~  | |__>--<__|      |                           \n");
    printf("                  |   _/) )-~     | |__>--<__|      |                           \n");
    printf("                  / /~ ,_/       / /__>---<__/      |                           \n");
    printf("                 o-o _//        /-~_>---<__-~      /                            \n");
    printf("                 (^(~          /~_>---<__-      _-~                             \n");
    printf("                ,/|           /__>--<__/     _-~                                \n");
    printf("             ,//('(          |__>--<__|     /                                   \n");
    printf("            ( ( '))          |__>--<__|    |                                    \n");
    printf("         `-)) )) (           |__>--<__|    |                                    \n");
    printf("        ,/,'//( (             \\__>--<__\\    \\                                   \n");
    printf("      ,( ( ((, ))              ~-__>--<_~-_  ~--____---~'                       \n");
    printf("    `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~                      \n");
    printf("  ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~                     \n");
    printf("   ;'( ')/ ,)(                              ~~~~~~~~~~                          \n");
    printf("  ' ') '( (/                                                                    \n");
    printf("    '   '  `                                                                    \n");

    printf("Começa o duelo final.\n");

    combate(jogador, &dragao);

    if(jogador->vida > 0){
        printf("Após derrotar %s, você consegue encostar no coração de Tétis por um breve momento, com isso sua vida é restaurada completamente e seu poder se nivela com o de Surtur, e a batalha começa.\n", dragao.nome);
        pausar();
        limpar();
        jogador->vida = jogador->vida_maxima;
        combate(jogador, &surtur);
        if(jogador->vida > 0){
            printf("Você derrotou Surtur!");
            printf("Com Surtur derrotado você tomou posse do coração de Tétis, sentindo em suas mãos o poder do mundo, capaz de fazer qualquer coisa que quiser. O que deseja fazer agora?\n1 - Devolver o coração.\n2 - Ficar com o coração.\n");
            int respostafinal;
            if(respostafinal == 1){
                printf("Você se mantém firme em suas convicções e vai até o interior do planeta para devolver o coração a Tétis. Agora que ela está forte e completa novamente ela restaura aquele mundo perfeito que esse planeta um dia foi.\n");
                pausar();
                limpar();
                jogador->fase++;
                salvar(jogador);
                creditos(jogador);
            }
            else{
                printf("Você fica fascinado pelo poder e mantém o coração para si. Agora você é novo Deus desse mundo, tendo a vida eterna e o controle do planeta na palma de suas mãos.\n");
                jogador->fase++;
                salvar(jogador);
                creditos(jogador);
            }
        }
        else{
            printf("Você foi derrotado e o jogo acabou.\n");
        }

    }
    else{
        printf("Você foi derrotado e o jogo acabou.\n");
    }


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
        jogador->vida += 50;
        jogador->frascoscura -= 1;
        if(jogador->vida > jogador->vida_maxima){
            jogador->vida = jogador->vida_maxima;
        }
        SLEEP(1000);
        printf("Você usou um frasco de cura!\n");
        SLEEP(1000);
        printf("Você possui %d frascos de cura restantes.\n", jogador->frascoscura);
        SLEEP(1000);
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