#include <stdio.h>
#include <stdbool.h>

int main(){

    int choix;
    do
    {  
        printf("\n================ Application de gestion d’une Équipe de Football ================\n");
        printf("1 - Ajouter un joueur \n");
        printf("2 - Afficher la liste de tous les joueurs\n");
        printf("3 - Modifier un joueur\n");
        printf("4 - Supprimer un joueur\n");
        printf("5 - Rechercher un joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("\n========================= Saisissez votre choix  ===============================\n");
        scanf("%d",&choix);
        getchar();

        switch(choix){

            int choixMenu;
            bool isChoice = false;

            case 1:
                do{
                    printf("----------- Ajouter des joueurs -----------------\n");
                    printf("1 - Ajouter un nouveau joueur\n");
                    printf("2 - Ajouter plusieurs joueurs en une seule opération\n");
                    printf("--------- Saisissez votre choix ---------------\n");
                    choixMenu = scanf("%d",&choixMenu);
                    getchar();
                    if(choixMenu == 1){

                    }else if (choixMenu == 2){

                    }else{
                        printf("Choisi un choix valide !!\n");
                    }
                    }while (isChoice);
                     break;

            case 2:
                do{
                    printf("-------- Affichage du liste de tous les joueurs -----------------\n");
                    printf("1 - Trier par nom en ordre alphabétique\n");
                    printf("2 - Trier par âge\n");
                    printf("3 - Afficher les joueurs par poste\n");
                    printf("--------- Saisissez votre choix ---------------\n");
                    scanf("%d",&choixMenu);
                    getchar();
                    

                }while (choixMenu != 3);
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Merci d'avoir utilisé l'application. À bientôt !\n");
                break;
            default : 
                printf("Choix invalide, veuillez réessayer !!");
                break;                            
        }

    } while (choix != 7);
    
    return 0;
}