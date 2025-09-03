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

    if(strlen(usuario.nascimento) != 10) return 2;

    else if(usuario.nascimento[0] > 51 || usuario.nascimento[1] < 48 || usuario.nascimento[1] > 57 || usuario.nascimento[1] < 48 || usuario.nascimento[2] != 47) return 2;

    else if(usuario.nascimento[3] > 49 || usuario.nascimento[3] < 48 || usuario.nascimento[4] > 57 || usuario.nascimento[4] < 48 || usuario.nascimento[5] != 47) return 2;

    else if(usuario.nascimento[6] > 50 || usuario.nascimento[6] < 48 || (usuario.nascimento[7] != 57 && usuario.nascimento[7] != 48) || usuario.nascimento[8] > 57 || usuario.nascimento[8] < 48 || usuario.nascimento[9] > 57 || usuario.nascimento[9] < 48) return 2;

    puts("insira o email do usuario");
    fgets(usuario.email, 50, stdin);

    usuario.email[strcspn(usuario.email, "\n")] = '\0';

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

    FILE *data_file = fopen("../data/data.txt", "a+");

    if(data_file == NULL){

        return 3;
    }

    size_t tamanho = 0;
    fseek(data_file, 0, SEEK_END);
    tamanho = ftell(data_file);

    if(tamanho < 150){
        freopen("data/data.txt", "w", data_file);
        char cabecalho[256] = "nome,data,email,telefone,time,equipe,proficao,cidade,comida favorita,esporte favorito,gosto musical,signo,filme favorito,hobbie,videogame favorito\n";
        fputs(cabecalho, data_file);
        freopen("../data/data.txt", "a", data_file);
    }

    fputs(usuario.nome, data_file); fputc(',', data_file);
    fputs(usuario.nascimento, data_file); fputc(',', data_file);
    fputs(usuario.email, data_file); fputc(',', data_file);
    fputs(usuario.telefone, data_file); fputc(',', data_file);
    fputs(usuario.time, data_file); fputc(',', data_file);
    fputs(usuario.equipe, data_file); fputc(',', data_file);
    fputs(usuario.profissao, data_file); fputc(',', data_file);
    fputs(usuario.cidade, data_file); fputc(',', data_file);
    fputs(usuario.comida, data_file); fputc(',', data_file);
    fputs(usuario.esporte, data_file); fputc(',', data_file);
    fputs(usuario.gosto_musical, data_file); fputc(',', data_file);
    fputs(usuario.signo, data_file); fputc(',', data_file);
    fputs(usuario.filme, data_file); fputc(',', data_file);
    fputs(usuario.hobbie, data_file); fputc(',', data_file);
    fputs(usuario.videogame, data_file); fputc('\n', data_file);

    fclose(data_file);


    return 0;
}

int pesquisar_usuarios(){

    //char [30]
}

int gerar_relatorio(){

    char nome[50];
    char categoria[30];
    char item[30];

    FILE *cabecalho = fopen("data/data.txt", "r");
    FILE *f = fopen("data/relatorio.txt", "w");

    int cabecalho_vir = 0;

    int cabecalho_vir2 = 0;

    int cabecalho_loop = 3;

    int k = 0;

    int repetida = 0;

    
    char checar_fim;

    char buffer[512];

    char buffer2[512];

    fgets(buffer, sizeof(buffer), cabecalho);

    while(checar_fim != '\n'){

        char palavras_repetidas[25][30];

        if(strchr(buffer + k, ',') != NULL){
            strcpy(categoria, "");
            cabecalho_vir++;
            k = strchr(buffer + k, ',');
            k++;
            int i = 0;
            while(1){

                if(*(buffer + k + i) == ',' || *(buffer + k + i) == '\n') break;
                categoria[i] = *(buffer + k + i);
                i++;
            }
            categoria[i + 1] = '\0';
        }

        while(cabecalho_vir > cabecalho_loop){
            int i = 0;
            char temp;
            int cabecalho_vir2 = 0;
            fgets(buffer2, sizeof(buffer2), cabecalho);

            if(strchr(buffer2 + i, ',') != NULL){
                strcpy(nome, "");
                cabecalho_vir2++;
                i = strchr(buffer2 + i, ',');
                i++;
                int j = 0;

                while(1){

                    if(*(buffer2 + i + j) == ',' || *(buffer2 + i + j) == '\n') break;
                    nome[i] = *(buffer + i + j);
                    j++;
                }
                nome[j + 1] = '\0';

            }
            while(cabecalho_vir2 < cabecalho_loop){
                
                if(strchr(buffer2 + i, ',') != NULL){
                    strcpy(item, "");
                    cabecalho_vir2++;
                    i = strchr(buffer2 + i, ',');
                    i++;
                    int j = 0;
                    if(cabecalho_vir2 == cabecalho_vir){
                        while(1){

                            if(*(buffer2 + i + j) == ',' || *(buffer2 + i + j) == '\n') break;
                            item[i] = *(buffer + i + j);
                            j++;
                        }
                        item[j + 1] = '\0';                        
                    }

                    int x = 0;

                    for(int z = 0; z < sizeof(palavras_repetidas); z++){
                        if(strcmp(palavras_repetidas[z], item) == 0) x = 1;
                    }

                    if(x = 0){
                        strcpy(palavras_repetidas[repetida], item);
                        repetida++;
                    }
                }

            }


        }
    }

}

int pesquisar_afinidade(){

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

            if(res == 1) fprintf(stderr,"nome \n");
            else if(res == 2) fprintf(stderr, "formato de data invalido\n");
            else if(res == 3) fprintf(stderr, "nao foi possivel abrir o arquivo\n");
            else puts("tudo certo");
        }

        return 0;
    }
}
