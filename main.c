#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    // Características básicas
    char nome[50];
    char nascimento[20];
    char email[50];
    char telefone[30];

    // Afinidades obrigatórias a pedido do sauer
    char time[30];
    char equipe[30];
    char profissao[30];
    char cidade[30];

    // Afinidades adicionais
    char comida[30];
    char esporte[30];
    char gosto_musical[30];
    char signo[30];
    char filme[30];
    char hobbie[30];
    char videogame[30];
}user_t;

int cadastro(){
    user_t usuario;

    puts("informacoes basicas");
    puts("---------------------------------");

    puts("insira o nome do usuario (minimo de 3 digitos)");
    fgets(usuario.nome, 50, stdin);
    if(strlen(usuario.nome) < 3) return 1;

    usuario.nome[strcspn(usuario.nome, "\n")] = '\0';

    puts("insira a data de nascimento do usuario neste formato: (DD/MM/AAAA). eh obrigatorio as barras");
    fgets(usuario.nascimento, 20, stdin);

    usuario.nascimento[strcspn(usuario.nascimento, "\n")] = '\0';

    if(strlen(usuario.nascimento) != 10) return 1;

    else if(usuario.nascimento[0] > 51 || usuario.nascimento[1] < 48 || usuario.nascimento[1] > 57 || usuario.nascimento[1] < 48 || usuario.nascimento[2] != 47) return 1;

    else if(usuario.nascimento[3] > 49 || usuario.nascimento[3] < 48 || usuario.nascimento[4] > 57 || usuario.nascimento[4] < 48 || usuario.nascimento[5] != 47) return 1;

    else if(usuario.nascimento[6] > 50 || usuario.nascimento[6] < 48 || (usuario.nascimento[7] != 57 && usuario.nascimento[7] != 48) || usuario.nascimento[8] > 57 || usuario.nascimento[8] < 48 || usuario.nascimento[9] > 57 || usuario.nascimento[9] < 48) return 1;

    puts("insira o email do usuario");
    fgets(usuario.email, 50, stdin);

    usuario.email[strcspn(usuario.email, "\n")] = '\0';
    printf("%s\n", usuario.email);
    
    puts("insira o numero de telefone do usuario. insira neste formato:(ddd) xxxxx-xxxx");
    fgets(usuario.telefone, 30, stdin);
    usuario.telefone[strcspn(usuario.telefone, "\n")] = '\0';

    puts("agora as afinidades");
    puts("caso nao tenha nenhuma, apenas coloque 'nao'");
    puts("----------------------------------------");

    puts("insira o time que o usuario torce");
    fgets(usuario.time, 30, stdin);
    usuario.time[strcspn(usuario.time, "\n")] = '\0';

    puts("insira a equipe de gincana do usuario");
    fgets(usuario.equipe, 30, stdin);
    usuario.equipe[strcspn(usuario.equipe, "\n")] = '\0';

    puts("insira a profissao do usuario");
    fgets(usuario.profissao, 30, stdin);
    usuario.profissao[strcspn(usuario.profissao, "\n")] = '\0';

    puts("insira a cidade do usuario");
    fgets(usuario.cidade, 30, stdin);
    usuario.cidade[strcspn(usuario.cidade, "\n")] = '\0';

    puts("insira a comida favorita do usuario");
    fgets(usuario.comida, 30, stdin);
    usuario.comida[strcspn(usuario.comida, "\n")] = '\0';

    puts("insira o esporte favorito do usuario");
    fgets(usuario.esporte, 30, stdin);
    usuario.esporte[strcspn(usuario.esporte, "\n")] = '\0';

    puts("insira o gosto musical do usuario");
    fgets(usuario.gosto_musical, 30, stdin);
    usuario.gosto_musical[strcspn(usuario.gosto_musical, "\n")] = '\0';

    puts("insira o signo do usuario");
    fgets(usuario.signo, 30, stdin);
    usuario.signo[strcspn(usuario.signo, "\n")] = '\0';

    puts("insira o filme favorito do usuario");
    fgets(usuario.filme, 30, stdin);
    usuario.filme[strcspn(usuario.filme, "\n")] = '\0';

    puts("insira o hobbie do usuario");
    fgets(usuario.hobbie, 30, stdin);
    usuario.hobbie[strcspn(usuario.hobbie, "\n")] = '\0';

    puts("insira o videogame favorito do usuario");
    fgets(usuario.videogame, 30, stdin);
    usuario.videogame[strcspn(usuario.videogame, "\n")] = '\0';

    puts("---------------------------------");
    printf("%s\n", usuario.nome);
    printf("%s\n", usuario.nascimento);
    printf("%s\n", usuario.email);
    printf("%s\n", usuario.telefone);
    printf("%s\n", usuario.time);
    printf("%s\n", usuario.equipe);
    printf("%s\n", usuario.profissao);
    printf("%s\n", usuario.cidade);
    printf("%s\n", usuario.comida);
    printf("%s\n", usuario.esporte);
    printf("%s\n", usuario.gosto_musical);
    printf("%s\n", usuario.signo);
    printf("%s\n", usuario.filme);
    printf("%s\n", usuario.hobbie);
    printf("%s\n", usuario.videogame);

    return 0;
}

int main(){

    int escolha = 0;

    while(1){

        puts("ola, o que voce deseja fazer?");
        puts("digite apenas o numero no console para escolher");
        puts("---------------------------------------");
        puts("1- cadastrar um usuário");
        puts("2- pesquisar usuarios pelos elementos que compõem a tabela de afinidades (verifique se a tabela existe antes de executar esta funcao)");
        puts("3- gerar uma tabela de afinidades entre os individuos cadastrados");
        puts("4- pesquisar afinidade entre dois individuos");
        puts("0- fechar o programa");
        scanf("%d", &escolha);
        getchar();

        if(escolha == 1){
            int res = cadastro();

            if(res == 1) puts("deu problema");
            else puts("tudo certo");
        }

        return 0;
    }
}