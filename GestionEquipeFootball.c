#include <stdio.h>
#include <stdbool.h>

int main(){

    int choix;
    do
    {  
        printf("\n================ Application de gestion d’une Équipe de Football ================\n");
        printf("\n--------------------------------- Menu principale --------------------------------\n");
        printf("\n1 - Ajouter un joueur \n");
        printf("2 - Afficher la liste de tous les joueurs\n");
        printf("3 - Modifier un joueur\n");
        printf("4 - Supprimer un joueur\n");
        printf("5 - Rechercher un joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("\n---------------------------- Saisissez votre choix  -------------------------------\n");
        scanf("%d",&choix);
        getchar();

        int choixMenu;
        bool isChoice;
        switch(choix){

            case 1:
                do{
                    printf("-------------- Ajouter des joueurs -------------------\n");
                    printf("1 - Ajouter un nouveau joueur\n");
                    printf("2 - Ajouter plusieurs joueurs en une seule opération\n");
                    printf("------------- Saisissez votre choix ------------------\n");
                    scanf("%d",&choixMenu);
                    getchar();
                    if(choixMenu == 1){

                        isChoice = true;
                    }else if (choixMenu == 2){

                        isChoice = true;
                    }else{
                        printf("Choix invalide, veuillez réessayer !!\n");
                        scanf("%d",&choixMenu);
                        getchar();
                        isChoice = false;
                    }
                }while (isChoice);
                break;

            case 2:
                do{
                    printf("-------- Affichage du liste de tous les joueurs ----------\n");
                    printf("1 - Trier par nom en ordre alphabétique\n");
                    printf("2 - Trier par âge\n");
                    printf("3 - Afficher les joueurs par poste\n");
                    printf("--------- Saisissez votre choix ---------------\n");
                    scanf("%d",&choixMenu);
                    getchar();

                    if(choixMenu == 1){

                        isChoice = true;
                    }else if (choixMenu == 2){

                        isChoice = true;
                    }else if (choixMenu == 3){

                        isChoice = true;
                    }else{
                        printf("Choix invalide, veuillez réessayer !!\n");
                        scanf("%d",&choixMenu);
                        getchar();
                        isChoice = false;
                    }
                }while (isChoice); 
                break;

            case 3:
                do{
                    printf("---------------- Modification -----------------\n");
                    printf("1 - Modifier le poste d’un joueur\n");
                    printf("2 - Modifier l’âge d’un joueur\n");
                    printf("3 - Modifier le nombre de buts marqués par un joueur\n");
                    printf("--------- Saisissez votre choix ---------------\n");
                    scanf("%d",&choixMenu);
                    getchar();

                    if(choixMenu == 1){

                        isChoice = true;
                    }else if (choixMenu == 2){

                        isChoice = true;
                    }else if (choixMenu == 3){

                        isChoice = true;
                    }else{
                        printf("Choix invalide, veuillez réessayer !!\n");
                        scanf("%d",&choixMenu);
                        getchar();
                        isChoice = false;
                    }
                }while (isChoice); 
                break;
            case 4:
                break;
            case 5:
                do{
                    printf("----------- Rechercher un joueur -----------------\n");
                    printf("1 - Rechercher un joueur par Identifiant\n");
                    printf("2 - Rechercher un joueur par Nom\n");
                    printf("--------- Saisissez votre choix ---------------\n");
                    scanf("%d",&choixMenu);
                    getchar();
                    if(choixMenu == 1){

                        isChoice = true;
                    }else if (choixMenu == 2){

                        isChoice = true;
                    }else{
                        printf("Choix invalide, veuillez réessayer !!\n");
                        scanf("%d",&choixMenu);
                        getchar();
                        isChoice = false;
                    }
                }while (isChoice);
                break;
            case 6:
                do{
                    printf("-------------------- Statistiques ----------------------\n");
                    printf("1 - Afficher le nombre total de joueurs dans l’équipe\n");
                    printf("2 - Afficher l’âge moyen des joueurs\n");
                    printf("3 - Afficher les joueurs ayant marqué plus de X buts (X introduit par vous)\n");
                    printf("4 - Afficher le meilleur buteur (joueur avec le maximum de buts)\n");
                    printf("5 - Afficher le joueur le plus jeune et le plus âgé\n");
                    printf("------------- Saisissez votre choix --------------------\n");
                    scanf("%d",&choixMenu);
                    getchar();
                    switch(choixMenu){
                        case 1 :
                            isChoice = true;
                            break;
                        case 2 :
                            isChoice = true;
                            break;
                        case 3 :
                            isChoice = true;
                            break;
                        case 4 :
                            isChoice = true;
                            break;
                        case 5 :
                            isChoice = true;
                            break; 
                        default :
                            printf("Choix invalide, veuillez réessayer !!\n");
                            scanf("%d",&choixMenu);
                            getchar();
                            break;                  
                    }
                }while (isChoice);
                break;
            case 7:
                printf("Merci d'avoir utilisé l'application. À bientôt !\n");
                break;
            default : 
                printf("Choix invalide, veuillez réessayer !!");
                scanf("%d",&choix);
                getchar();
                break;                            
        }

    } while (choix != 7);
    
    return 0;
}