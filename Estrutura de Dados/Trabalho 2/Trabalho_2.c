#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int VetG[1000];

void vetor(){
    srand(time(NULL));
    for(int i=0; i<1000; i++){
        VetG[i]=rand() % 1000;
        printf("VetG[%d] = %d",i,VetG[i]);
    }
}
void S_Sort(int *vetor){
    int aux,menor;

    for(int i=0; i<1000; i++){
        vetor[i]=rand() % 1000; 
    }
    for(int i=0; i<1000-1;i++){
        menor=i;
        for(int j=i+1; j<1000; j++){
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
    printf("|");
    for(int i=0; i<1000; i++){
        printf("%.3d|",vetor[i]);
    }
}
void I_Sort(int *vetor){

}
void M_Sort(int *vetor){

}
void H_Sort(int *vetor){

}
void Q_Sort(int *vetor){

}

int main(){

    int item, loop = 0, loopin = 1;
    char resp;

    //Esse {Do While} será usado para chamar o menu novamente.
    do{
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

        switch(item){
            case 1:
                S_Sort(&VetG);
            break;
            case 2:
                I_Sort(&VetG);
            break;
            case 3:
                M_Sort(&VetG);
            break;
            case 4:
                H_Sort(&VetG);
            break;
            case 5:
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

         //{System("cls")} é usado para limpar a operação anterior toda vez que chamar o menu.
        system("cls");
    }while(loop == 1); 
    

    return 0;
}