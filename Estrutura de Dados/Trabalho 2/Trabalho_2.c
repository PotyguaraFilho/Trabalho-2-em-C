#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 20

int VetG[MAX];

// Criando vetor randomizado
void vetor(){
    
    printf("\t\t\t------------------------ Vetor Randomizado ---------------------------\n\n");
    srand(time(NULL));
    for(int i=0; i<MAX; i++){
        VetG[i]=rand() % 1000;
        printf("[%.3d]",VetG[i]);
    }
}

void mostrarVetor(){
    for(int i = 0; i < MAX; i++){
        printf("[%.3d]",VetG[i]);
    }
}

// Select Sort
void S_Sort(){
    clock_t ini = clock();
    int aux,menor;

    for(int i=0; i<MAX-1;i++){
        menor = i;
        for(int j=i+1; j<MAX; j++){
            if(VetG[menor]>VetG[j]){
                menor = j;
            } 
        }
        if(i!=menor){
            aux = VetG[i];
            VetG[i] = VetG[menor];
            VetG[menor] = aux;
        }        
    }
    printf("\n\n\t\t        --------------------------- Vetor Ordenado ---------------------------\n\n");
    mostrarVetor();
    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// INSERT SORT

void I_Sort(){
    clock_t ini = clock();
    int troca,j;

    printf("\n\n\t\t\t--------------------------- Vetor Ordenado ---------------------------\n\n");
    for (int i=1; i < MAX; i++) // i começa na posição 1 do vetor e vai até a ultima posição;
    {
        j = i; // j recebe a posição que está passando no "for";

        while (VetG[j] < VetG[j-1]) // Enquanto o valor que está passando na posição "j" for menor que a posição "j" menos 1, ocorre a troca;
        { // Ocorre a troca;
            troca      = VetG[j];
            VetG[j]   = VetG[j-1];
            VetG[j-1] = troca;
            j--; // j decrementa 1;

            if (j == 0) // Quando "j" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }
    }
    for (int i = 0; i < MAX; i++){
            printf("[%.3d]",VetG[i]);
    }
    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// Merge SORT
/*
  Dado um vetor de inteiros v e um inteiro n >= 0, ordena o vetor v[0..n-1] em ordem crescente.
*/
void mergesort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}

/*
  Dado um vetor de inteiros v e dois inteiros i e f, ordena o vetor v[i..f] em ordem crescente.
  O vetor c é utilizado internamente durante a ordenação.
*/
void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, c, i, m);
  sort(v, c, m + 1, f);

  /* Se v[m] <= v[m + 1], então v[i..f] já está ordenado. */
  if (v[m] <= v[m + 1]) return;

  merge(v, c, i, m, f);
}


/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, em ordem crescente, no vetor em v[i..f].
*/
void merge(int *v, int *c, int i, int m, int f) {
  int z,
      iv = i, ic = m + 1;

  for (z = i; z <= f; z++) c[z] = v[z];

  z = i;

  while (iv <= m && ic <= f) {
    /* Invariante: v[i..z] possui os valores de v[iv..m] e v[ic..f] em ordem crescente. */

    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }

  while (iv <= m) v[z++] = c[iv++];

  while (ic <= f) v[z++] = c[ic++];
}

// HEAP SORT

void H_Sort() {
    clock_t ini = clock();
    int n = MAX;
    int stop = 0;
    int i = MAX / 2, pai, filho, t;
    while(stop==0) {
        if (i > 0) {
            i--;
            t = VetG[i];
        } else {
            n--;
            if (n <= 0) return;
            t = VetG[n];
            VetG[n] = VetG[0];
        }
        pai = i;
        filho = i * 2 + 1;
        while (filho < n) {
            if ((filho + 1 < n)  &&  (VetG[filho + 1] > VetG[filho]))
                filho++;
            if (VetG[filho] > t) {
                VetG[pai] = VetG[filho];
                pai = filho;
                filho = pai * 2 + 1;
            } else {
                break;
            }
        }
        VetG[pai] = t;
    }
    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}


// QUICK SORT

void Q_Sort(int esquerda, int direita){
    // Variávies auxiliares
    /**
     * i = lado esquerdo variável
     * j = lado direito variável
     * x = valor do meio do vetor
    */
    int i, j, x, y;
     
    i = esquerda;
    j = direita;
    x = VetG[(esquerda + direita) / 2];

    // Enquanto a posição do lado esquerdo variável for menor ou igual a posição do lado direito variável
    while(i <= j) {
        /**
         * Enquanto o valor do vetor principal de posição flutuante esquerda > pivo
         * for menor que o valor do pivo (meio)
         * AND
         * Posição variável da esquerda for menor que o MAX do vetor
         * Pule para a próxima posição (Lado esquerdo flutuante)
        */
        while(VetG[i] < x && i < direita) {
            i++;
        }
        /**
         * Enquanto o valor do vetor principal de posição flutuante direita > pivo
         * for menor que o valor do pivo (meio)
         * AND
         * Posição flutuante da direita for menor que o MINIMO do vetor
         * Pule para a próxima posição (Lado direito flutuante)
        */
        while(VetG[j] > x && j > esquerda) {
            j--;
        }

        /**
         * Quando passar dos dois WHILES acima, ele entra na verificação se a posição flutuante
         * esquerda é menor ou igual a posição flutuante direita
         * primeiramente usa a variável auxiliar Y para receber o valor do vetor com a posição
         * flutuante esquerda.
         * Logo após é substituido o valor pelo valor do vetor de posição flutuante direita
         * onde após verificações dos WHILES é identificado que é menor que o de posição
         * flutuante esquerda, e então substitui o valor do vetor em posição flutuante direita
         * pelo valor armazenado na var auxiliar Y
         * Pula as posições para continuar no WHILE se necessário.
        */
        if(i <= j) {
            y = VetG[i];
            VetG[i] = VetG[j];
            VetG[j] = y;
            i++;
            j--;
        }
    }


    /**
     * Aplica-se o conceito de função recursiva, para que o mesmo algoritmo possa executar 
     * diversas vezes até atender a ordenação total do mesmo.
    */
    if(j > esquerda) {
        Q_Sort(esquerda, j);
    }
    if(i < direita) {
        Q_Sort(i, direita);
    }
}


//  Função principal
int main(){

    // Criação de variáveis, controle de menu e lopping
    int item, loop = 0, loopin = 1;
    char resp;

    //Esse {Do While} será usado para chamar o menu novamente.
    do{
        //{System("cls")} é usado para limpar a operação anterior toda vez que chamar o menu.
        system("cls");

        printf("\n\n||====================================||\n");
        printf("||       TRABALHO -|- GERHARD         ||\n");
        printf("||====================================||\n");
        printf("||====================================||\n");
        printf("|| [ 1 ] ----->  Select Sort  <------ ||\n");
        printf("|| [ 2 ] ----->  Insert Sort  <------ ||\n");
        printf("|| [ 3 ] ----->  Merge Sort   <------ ||\n");
        printf("|| [ 4 ] ----->  Heap  Sort   <------ ||\n");
        printf("|| [ 5 ] ----->  Quick  Sort  <------ ||\n");
        printf("|| [ 6 ] ----->     SAIR      <------ ||\n");
        printf("||====================================||\n\n");
        printf("Item escolhido: ");
        scanf("%d",&item);  
        clock_t ini;
        vetor();

        switch(item){
            case 1:
                S_Sort();
            break;
            case 2:
                I_Sort();
            break;
            case 3:
                M_Sort();
            break;
            case 4:
                H_Sort();
                printf("\n\n\t\t\t--------------------------- Vetor Ordenado ---------------------------\n\n");
                mostrarVetor();
            break;
            case 5:
                ini = clock();
                Q_Sort(0, MAX);
                
                printf("\n\n\t\t\t--------------------------- Vetor Ordenado ---------------------------\n\n");
                mostrarVetor();
                printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
            break;
            case 6:
                printf("Ok,saindo...\n\n");
            break;
            default:
                printf("\nEscolha um item acima numerados de 1 à 5 !\n");
            break;
        }
        //Esse {Do While} será usado para quando o usuário responder com letra diferente de S e N.
        do{
            printf("\nDeseja escolher outro item? [S]-Sim [N]-Nao \n");
            scanf(" %c",&resp);
            if(resp == 'S' || resp == 's'){
                loop = 1;
                loopin = 1;
            }else if(resp == 'N' || resp == 'n'){
                loop = 0;
                loopin = 1;
            }else{
                printf("Precisa escolher entre S ou N !\n");
                loopin = 2;
            }
        }while(loopin == 2);

         
    }while(loop == 1); 
    

    return 0;
}
