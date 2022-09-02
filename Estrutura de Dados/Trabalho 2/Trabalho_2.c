#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Quick(){

}

int main(){

    int item, loop = 0, loopin = 1;
    char resp;

    //Esse {Do While} será usado para chamar o menu novamente.
    do{
        printf("\n\n|====================================|\n");
        printf("|       TRABALHO -|- GERHARD         |\n");
        printf("|====================================|\n");
        printf("|====================================|\n");
        printf("| [ 1 ] ----->  Select Sort  <------ |\n");
        printf("| [ 2 ] ----->  Insert Sort  <------ |\n");
        printf("| [ 3 ] ----->  Merge Sort   <------ |\n");
        printf("| [ 4 ] ----->  Heap  Sort   <------ |\n");
        printf("| [ 5 ] ----->  Quick  Sort  <------ |\n");
        printf("| [ 6 ] ----->     SAIR      <------ |\n");
        printf("|====================================|\n\n");
        printf("Item escolhido: ");
        scanf("%d",&item);

        switch(item){
            case 1:
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            default:
                printf("\nEscolha um item acima numerados de 1 à 5 !\n");
            break;
        }
        //Esse {Do While} será usado para quando o usuário responder com letra diferente de S e N.
        do{
            printf("Deseja escolher outro item? [S]-Sim [N]-Nao \n");
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