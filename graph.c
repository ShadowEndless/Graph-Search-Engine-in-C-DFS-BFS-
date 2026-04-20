#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <malloc.h>

int V;
int charsize = 34;

/*decidi eu mesmo implementar o tipo boleano apenas para tentar algo diferente*/
typedef int bool;
#define true 1
#define false 0

void inicializar_digrafo(int V, int mAdj[V][V]);
void inicializar_grafo(int V,int mAdj[V][V]);
void imprimir(int V, int mAdj[V][V]);

void dfs(int V, int mAdj[V][V], int source, int destination);
int dfs_recursion_helper(int V, int mAdj[V][V], int source, int destination, bool visited[]);

/*implementação de uma fila para o algoritmo BFS, e a implementação do algoritmo de BFS*/
typedef struct {
    int capacidade;     /*capacidade de itens na fila*/
    int *dados;         /*dados armazenados*/
    int primeiro;       /*pos primeiro*/
    int ultimo;         /*pos ultimo*/
    int nItems;         /*numero atual de itens atual na fila*/ 
}Fila;

void criarFila(Fila *f, int c);
void inserirFila(Fila *f, int v);
int removerFila(Fila *f);
int vaziaFila(Fila *f);
int cheiaFila(Fila *f);
void esvaziarFila(Fila *f);
int bfs_search(int V,int mAdj[V][V],int origem, int destino);

void main(void){
    setlocale(LC_ALL,"Portuguese");

    /*logica para o usuario decidir qual algoritmo usar*/
    int dfs_ou_bfs;
    printf("Qual algoritmo deseja usar como base fazer para este exercicio:\n");
    printf("0) usar dfs (entre com 0)\n");
    printf("1) usar bfs (entre com 1)\n");
    scanf("%d", &dfs_ou_bfs);

    /*logica para entrada do usuario*/
    int automatico_ou_personalizado;
    printf("\nO que deseja fazer:\n");
    printf("0) Criar automaticamente o grafo do exercicio e realizar todos testes de caminhos(entre com 0)\n");
    printf("1) Entrar com um grafo personalizado(entre com 1)\n");
    scanf("%d", &automatico_ou_personalizado);

    if(automatico_ou_personalizado<=0){

        /*opção de criar o grafo do exercicio automaticamente: 
        * 1. criar um grafo de 7 V
        * 2. entrar com as arestas
        * 3. testar os caminhos
        * 4. perguntar se deseja testar mais caminhos ou sair colocando -1 duas vezes
        * */

        int V = 7;
        int mAdj[V][V];
        int i,j;

        for(i=0;i<V;i++)
            for(j=0;j<V;j++) mAdj[i][j] = 0;

        charsize = V*8+2;

        int digrafo_ou_grafo;
        printf("\nDeseja criar um dígrafo ou grafo?\n");
        printf("0) Para criar um dígrafo(caminhos orientados) digite 0:\n ");
        printf("1) Para criar um grafo(caminhos não orientados) digite 1:\n ");
        scanf("%d", &digrafo_ou_grafo);

        if(digrafo_ou_grafo <= 0){
            /*inicializar_digrafo(V, mAdj);*/

            /*parte superior*/
            printf("\nCriando digrafo...\n");
            mAdj[0][1] = 1;
            mAdj[1][2] = 1;
            mAdj[2][6] = 1;

            /*parte inferior*/
            mAdj[0][3] = 1; 
            mAdj[3][4] = 1; 
            mAdj[4][5] = 1; 

        }else if(digrafo_ou_grafo >= 1){
            /*inicializar_grafo(V,mAdj);*/

            /*parte superior*/
            printf("\nCriando grafo...\n");
            mAdj[0][1] = 1;
            mAdj[1][0] = 1;

            mAdj[1][2] = 1;
            mAdj[2][1] = 1;

            mAdj[2][6] = 1;
            mAdj[6][2] = 1;

            /*parte inferior*/
            mAdj[0][3] = 1; 
            mAdj[3][0] = 1;

            mAdj[3][4] = 1; 
            mAdj[4][3] = 1;

            mAdj[4][5] = 1; 
            mAdj[5][4] = 1;
        }

        imprimir(V, mAdj);

        /*testar caminhos*/
        if(dfs_ou_bfs <= 0){

            printf("\n-------------------------teste usando DFS---------------------------\n");

            printf("\nteste 1\n");
            dfs(V,mAdj,0,1);

            printf("\nteste 2\n");
            dfs(V,mAdj,0,2);

            printf("\nteste 3\n");
            dfs(V,mAdj,0,3);

            printf("\nteste 4\n");
            dfs(V,mAdj,0,5);

            printf("\nteste 5\n");
            dfs(V,mAdj,1,3);

            printf("\nteste 6\n");
            dfs(V,mAdj,2,5);

            printf("\nteste 7\n");
            dfs(V,mAdj,4,2);

        }else if(dfs_ou_bfs >= 1){

            printf("\n-------------------------teste usando BFS---------------------------\n");

            printf("\nteste 1\n");
            bfs_search(V,mAdj,0,1);

            printf("\nteste 2\n");
            bfs_search(V,mAdj,0,2);

            printf("\nteste 3\n");
            bfs_search(V,mAdj,0,3);

            printf("\nteste 4\n");
            bfs_search(V,mAdj,0,5);

            printf("\nteste 5\n");
            bfs_search(V,mAdj,1,3);

            printf("\nteste 6\n");
            bfs_search(V,mAdj,2,5);

            printf("\nteste 7\n");
            bfs_search(V,mAdj,4,2);

            printf("\n");
        }

        return;
    }

    /*opção de construir do zero um grafo personalizado:
     * 1. criando e alocando os vertices
     * 2. decidindo se tem arestas orientadas ou não
     * 3. escolhendo arestas e imprimindo grafo
     * 4. por ultimo testando caminhos*/

    while(1==1){
        int temp;
        printf("Entre com a quantidade de vertices do grafo: ");
        scanf("%d",&temp);

        if(temp <= 0){
            printf("Erro entre com outro valor! O numero de vertices deve ser um numero positivo que maior que 1\n");
        }else{
            V = temp;
            break;
        }
    }

    /*Alocando grafo na memoria.*/
    int mAdj[V][V];

    charsize = V*8+2;

    int digrafo_ou_grafo;
    printf("\nDeseja criar um dígrafo ou grafo?\n");
    printf("Para criar um dígrafo(caminhos orientados) digite 0, ou grafo(caminhos não orientados) digite 1: ");
    scanf("%d", &digrafo_ou_grafo);

    printf("\nEntre com as arestas, partindo de 1 até %d\n",V);

    if(digrafo_ou_grafo <= 0){
        inicializar_digrafo(V, mAdj);
    }else if(digrafo_ou_grafo >= 1){
        inicializar_grafo(V, mAdj);
    }

    /*imprimindo grafo*/
    imprimir(V, mAdj);

    printf("\nEntrando na fase de teste de caminhos...\n");

    if(dfs_ou_bfs<=0)
        printf("\n-------------------------teste usando DFS---------------------------\n");
    else if(dfs_ou_bfs >= 1)
        printf("\n-------------------------teste usando BFS---------------------------\n");

    while(1==1){
        int origem,destino;

        printf("Entre com a origem(ou, valor menor ou igual a zero para sair): ");
        scanf("%d",&origem);

        printf("Entre com o destino(ou, valor menor ou igual a zero para sair): ");
        scanf("%d",&destino);

        if(origem<=0 || destino<=0){
            printf("Encerrando programa...");
            break;
        }else if(origem>V || destino>V)
            printf("\nErro entre com outro valor! O numero do vertice está acima do intervalo permitido\n");
        else if(origem == destino)
            printf("\nErro entre com outro valor! Pois esse espaço está reservado para bicoloração\n");
        else{
            if(dfs_ou_bfs <= 0)
                dfs(V,mAdj,origem-1,destino-1);
            else if(dfs_ou_bfs >= 1)
                bfs_search(V,mAdj,origem-1,destino-1);
        }
    }
}

void inicializar_digrafo(int V, int mAdj[V][V]){
    int i,j;

    for(i = 0; i<V;i++)
        for(j=0;j<V;j++) mAdj[i][j]=0;

    while(1==1){
        int origem,destino;

        printf("Entre com a origem(ou, valor menor ou igual a zero para continuar): ");
        scanf("%d", &origem);

        printf("Entre com o destino(ou, valor menor ou igual a zero para continuar): ");
        scanf("%d", &destino);

        if(origem<=0 || destino<=0) {
            printf("\nSaindo do loop...\n");
            break;

        }else if(origem == destino)
            printf("Erro entre com outro valor! Origem e Destino iguais não são permitidos, pois esse espaço está reservado para bicoloração.\n");
        else if(origem > V || destino > V)
            printf("Erro entre com outro valor! Não é possivel criar uma aresta com um Vertice que está fora do intervalo estabelecido.\n");
        else {
            mAdj[origem-1][destino-1] = 1;
        }
    }
}

void inicializar_grafo(int V, int mAdj[V][V]){
    int i,j;

    for(i = 0; i<V;i++)
        for(j=0;j<V;j++) mAdj[i][j]=0;

    while(1==1){
        int origem,destino;

        printf("Entre com a origem(ou, valor menor ou igual a zero para continuar): ");
        scanf("%d", &origem);

        printf("Entre com o destino(ou, valor menor ou igual a zero para continuar): ");
        scanf("%d", &destino);

        if(origem<= 0 || destino<= 0) {
            printf("\nSaindo do loop...\n");
            break;
        }else if(origem == destino)
            printf("\nErro entre com outro valor! Origem e Destino iguais não são permitidos, pois esse espaço está reservado para bicoloração.\n");
        else if(origem > V || destino > V)
            printf("\nErro entre com outro valor! Não é possivel criar uma aresta com um Vertice que está fora do intervalo estabelecido.\n");
        else {
            mAdj[origem-1][destino-1] = 1;
            mAdj[destino-1][origem-1] = 1;
        }
    }
}

void imprimir(int V, int mAdj[V][V]){
    int i,j;

    printf("\nImprimindo visualização em forma de matriz...\n");

    for(i=0;i<charsize;i++) printf("=");

    printf("\nMATRIZ| ");

    /*printf("\n\t");*/

    for (i=0; i<V; i++) printf("%d\t",i+1);

    printf("\n");

    for (i=0; i<charsize; i++) printf("-");

    printf("\n");

    for(i=0;i < V;i++){
        printf("%d | ",i+1);
        for(j=0;j< V;j++){
            printf("%d\t",mAdj[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<charsize;i++) printf("=");

    printf("\n");
}

/* usando memoria dinamicamente alocada, com risco de estourar a pilha.
 * neste caso ultilizando o proprio call stack do C,
 * apenas por conveniencia, e porque nesse caso de uso se encaixa perfeitamente
 * uma vez que se trata de um grafo pequeno e que não ira crescer dinamicamente.
 * isso não possa simplesmente alocar uma pilha na heap e resolver de maneira iterativa.
 * curiosamente nesse caso provavelmente a solução recursiva deve ser mais rapida por 
 * estar alocada de maneira adjacente na memoria.
 * */

void dfs(int V, int mAdj[V][V], int origem, int destino){
    bool visitado[V];
    int k;

    for(k=0;k<V;k++) visitado[k] = false;

    printf("caminho de %d pra %d\n",origem+1,destino+1);

    int result = dfs_recursion_helper(V, mAdj, origem, destino, visitado);

    if(result==1) printf("Encontrado!!!\n");
    else if(result==-1) printf("Não Encontrado!!!\n");
    else printf("Erro! valor inesperado!");
}

int dfs_recursion_helper(int V, int mAdj[V][V], int origem, int destino, bool visitado[]){
    if(visitado[origem] == true){
        return -1;
    }else{
        visitado[origem] = true;
        printf("%d visitado -> ",origem+1);
    }

    int i;

    for(i = 0; i<V; i++){
        if(mAdj[origem][i] == 1){
            if(mAdj[origem][destino] == 1){
                return 1;
            }
            int result = dfs_recursion_helper(V, mAdj,i, destino, visitado);
            if(result == 1) return 1;
        }
    }

    return -1;
}

/*implementação da fila que foi aprendida em aula*/

void criarFila(Fila *f, int c){
    f->capacidade = c;
    f->dados = (int *) malloc(sizeof(int));
    f->primeiro = 0;
    f->ultimo = -1;
    f->nItems = 0;
}

void inserirFila(Fila *f, int v){
    if(f->ultimo == f->capacidade) f->ultimo = -1;
    f->ultimo++;
    f->dados[f->ultimo] = v;
    f->nItems++;
}

int removerFila(Fila *f){
    int temp = f->dados[f->primeiro++];

    /*valor do primeiro e guarda em temp.*/
    /*incrementa o valor do primeiro depois de executar a linha.*/

    if(f->primeiro == f->capacidade) f->primeiro = 0;

    f->nItems--;
    return temp;
}

int vaziaFila(Fila *f){
    return(f->nItems == 0);
}

int cheiaFila(Fila *f){
    return(f->nItems == f->capacidade);
}

void mostrarFila(Fila *f){
    int cont,i;

    for(cont = 0, i = f->primeiro; cont <f->nItems; cont++){
        printf("%d\t|", f->dados[i++]);
        if(i == f->capacidade) i = 0;
    }

    printf("\n\n");
}

void esvaziarFila(Fila *f){
    while(f->nItems>=0){
        removerFila(f);
    }
}

/* Pelo menos essa indiscutivelmente faz o uso de memoria dinamica,
 * ao realizar buscas*/

int bfs_search(int V,int mAdj[V][V],int origem, int destino){
    Fila f1;
    bool visitado[V];
    int i;

    for(i=0; i<V; i++)
        visitado[i] = false;

    criarFila(&f1,V);
    inserirFila(&f1,origem);
    visitado[origem] = true;

    printf("caminho de %d pra %d\n",origem+1,destino+1);

    while(f1.nItems >= 0){
        if(vaziaFila(&f1)) break;
        else origem = removerFila(&f1);

        printf("%d visitado -> ", origem+1);

        for(i=0; i<V; i++){
            if(mAdj[origem][i] == 1 && visitado[i] == false){
                if(mAdj[origem][destino] == 1){
                    printf("Encontrado!!!\n");
                    esvaziarFila(&f1);
                    return 1;
                }

                inserirFila(&f1, i); 
                visitado[i] = true;
            }
        }
    }

    printf("Não encontrado\n");
    esvaziarFila(&f1);
    return -1;
}