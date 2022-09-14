#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int VetG[1000];

// Criando vetor randomizado
void vetor(){
    
    printf("\t\t\t------------------------ Vetor Randomizado ---------------------------\n\n");
    srand(time(NULL));
    for(int i=0; i<200; i++){
        VetG[i]=rand() % 1000;
        printf("[%.3d]",VetG[i]);
    }
}

// Select Sort
void S_Sort(int *vetor){
    clock_t ini = clock();
    int aux,menor;

    for(int i=0; i<200-1;i++){
        menor = i;
        for(int j=i+1; j<200; j++){
            if(vetor[menor]>vetor[j]){
                menor = j;
            } 
        }
        if(i!=menor){
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }        
    }
    printf("\n\n\t        --------------------------- Vetor Ordenado ---------------------------\n\n");
    for(int i = 0; i < 200; i++){
        printf("[%.3d]",vetor[i]);
    }
    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// INSERT SORT

void I_Sort(int *vetor){
    clock_t ini = clock();
    int troca,j;

    printf("\n\n\t\t\t--------------------------- Vetor Ordenado ---------------------------\n\n");
    for (int i=1; i < 20; i++) // i começa na posição 1 do vetor e vai até a ultima posição;
    {
        j = i; // j recebe a posição que está passando no "for";

        while (vetor[j] < vetor[j-1]) // Enquanto o valor que está passando na posição "j" for menor que a posição "j" menos 1, ocorre a troca;
        { // Ocorre a troca;
            troca      = vetor[j];
            vetor[j]   = vetor[j-1];
            vetor[j-1] = troca;
            j--; // j decrementa 1;

            if (j == 0) // Quando "j" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }
    }
    for (int i = 0; i < 20; i++){
            printf("[%.3d]",vetor[i]);
    }
    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// Merge SORT
void M_Sort(int *vetor){
    clock_t ini = clock();

    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// HEAP SORT
void H_Sort(int *vetor){
    clock_t ini = clock();

    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
}

// QUICK SORT
void Q_Sort(int *vetor){
    clock_t ini = clock();

    printf("\nExecutou em %f segundos\n", ((double)clock() - ini) / CLOCKS_PER_SEC);
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

        vetor();

        switch(item){
            case 1:
                S_Sort(&VetG);
            break;
            case 2:
                I_Sort(&VetG);
            break;
            case 3:
                vetor();
                M_Sort(&VetG);
            break;
            case 4:
                vetor();
                H_Sort(&VetG);
            break;
            case 5:
                vetor();
                Q_Sort(&VetG);
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