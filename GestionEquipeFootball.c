#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_JOUEURS 30

typedef struct
{
    int id;
    char nom[30];
    char prenom[30];
    int numeroMaillot;
    char poste[10]; // permet de distinguer les rôles (gardien, défenseur, milieu, attaquant).
    int age;
    int buts;
    // char dateInscription[11];
    char status[11]; // indique si le joueur est "titulaire" ou "remplaçant"

} Joueur;

Joueur listeJoueurs[MAX_JOUEURS];
int nbJoueurs = 0;

void ajouterJoueur()
{
    if (nbJoueurs == MAX_JOUEURS)
    {
        printf("La liste du joueurs est rempliee \n");
    }
    else
    {
        printf("Saisissez les informations du joueur\n");
        listeJoueurs[nbJoueurs].id = nbJoueurs + 1;
        printf("Entrer le nom du joueur :\n");
        fgets(listeJoueurs[nbJoueurs].nom, sizeof(listeJoueurs[nbJoueurs].nom), stdin);
        printf("Entrer le prenom du joueur :\n");
        fgets(listeJoueurs[nbJoueurs].prenom, sizeof(listeJoueurs[nbJoueurs].prenom), stdin);
        printf("Entrer le numéro de maillot du joueur :\n");
        scanf("%d", &listeJoueurs[nbJoueurs].numeroMaillot);
        getchar();
        char choi;
        bool isChoice = false;
        do
        {
            printf("Choisi le poste du joueur [G]: Gardien, [D]: Défenseur, [M]: Milieu, [A]: Attaquant\n");
            scanf("%c", &choi);
            choi = tolower(choi);
            getchar();
            switch (choi)
            {
            case 'g':
                strcpy(listeJoueurs[nbJoueurs].poste, "Gardien");
                isChoice = false;
                break;
            case 'd':
                strcpy(listeJoueurs[nbJoueurs].poste, "Défenseur");
                isChoice = false;
                break;
            case 'm':
                strcpy(listeJoueurs[nbJoueurs].poste, "Milieu");
                isChoice = false;
                break;
            case 'a':
                strcpy(listeJoueurs[nbJoueurs].poste, "Attaquant");
                isChoice = false;
                break;

            default:
                printf("Choix invalide, veuillez réessayer !!\n");
                isChoice = true;
                break;
            }
        }while (isChoice);
        printf("Enter l'age du joueur\n");
        scanf("%d", &listeJoueurs[nbJoueurs].age);
        getchar();
        printf("Enter nombre de buts marqués par le joueur\n");
        scanf("%d", &listeJoueurs[nbJoueurs].buts);
        getchar();
        do
        {
            printf("Choisi le status du joueur [T]: Titulaire, [R]: Remplaçant\n");
            scanf("%c", &choi);
            getchar();
            choi = tolower(choi);
            switch (choi)
            {
            case 't':
                strcpy(listeJoueurs[nbJoueurs].status, "Titulaire");
                isChoice = false;
                break;
            case 'r':
                strcpy(listeJoueurs[nbJoueurs].status, "Remplaçant");
                isChoice = false;
                break;
            default:
                printf("Choix invalide, veuillez réessayer !!\n");
                isChoice = true;
                break;
            }
        }while(isChoice);   
        printf("========== Le joueur est bien ajouté ============\n");
        nbJoueurs++;
    }
}

int main()
{

    int choix;
    do
    {
        printf("\n================ Application de gestion d’une Équipe de Football ================\n");
        printf("\n--------------------------------- Menu principale --------------------------------\n");
        printf("1 - Ajouter un joueur \n");
        printf("2 - Afficher la liste de tous les joueurs\n");
        printf("3 - Modifier un joueur\n");
        printf("4 - Supprimer un joueur\n");
        printf("5 - Rechercher un joueur\n");
        printf("6 - Statistiques\n");
        printf("7 - Quitter\n");
        printf("---------------------------- Saisissez votre choix  -------------------------------\n");
        scanf("%d", &choix);
        getchar();

        int choixMenu;
        bool isChoice;

        switch (choix)
        {

        case 1:
            do
            {
                printf("-------------- Ajouter des joueurs -------------------\n");
                printf("1 - Ajouter un nouveau joueur\n");
                printf("2 - Ajouter plusieurs joueurs en une seule opération\n");
                printf("------------- Saisissez votre choix ------------------\n");
                scanf("%d", &choixMenu);
                getchar();
                isChoice = false;
                if (choixMenu == 1)
                {
                    ajouterJoueur();
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {

                    isChoice = false;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = true;
                }
            } while (isChoice);
            break;

        case 2:
            do
            {
                printf("-------- Affichage du liste de tous les joueurs ----------\n");
                printf("1 - Trier par nom en ordre alphabétique\n");
                printf("2 - Trier par âge\n");
                printf("3 - Afficher les joueurs par poste\n");
                printf("--------- Saisissez votre choix ---------------\n");
                scanf("%d", &choixMenu);
                getchar();

                if (choixMenu == 1)
                {

                    isChoice = true;
                }
                else if (choixMenu == 2)
                {

                    isChoice = true;
                }
                else if (choixMenu == 3)
                {

                    isChoice = true;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = false;
                }
            } while (isChoice);
            break;

        case 3:
            do
            {
                printf("---------------- Modification -----------------\n");
                printf("1 - Modifier le poste d’un joueur\n");
                printf("2 - Modifier l’âge d’un joueur\n");
                printf("3 - Modifier le nombre de buts marqués par un joueur\n");
                printf("--------- Saisissez votre choix ---------------\n");
                scanf("%d", &choixMenu);
                getchar();

                if (choixMenu == 1)
                {

                    isChoice = true;
                }
                else if (choixMenu == 2)
                {

                    isChoice = true;
                }
                else if (choixMenu == 3)
                {

                    isChoice = true;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = false;
                }
            } while (isChoice);
            break;
        case 4:
            break;
        case 5:
            do
            {
                printf("----------- Rechercher un joueur -----------------\n");
                printf("1 - Rechercher un joueur par Identifiant\n");
                printf("2 - Rechercher un joueur par Nom\n");
                printf("--------- Saisissez votre choix ---------------\n");
                scanf("%d", &choixMenu);
                getchar();
                if (choixMenu == 1)
                {

                    isChoice = true;
                }
                else if (choixMenu == 2)
                {

                    isChoice = true;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = false;
                }
            } while (isChoice);
            break;
        case 6:
            do
            {
                printf("-------------------- Statistiques ----------------------\n");
                printf("1 - Afficher le nombre total de joueurs dans l’équipe\n");
                printf("2 - Afficher l’âge moyen des joueurs\n");
                printf("3 - Afficher les joueurs ayant marqué plus de X buts (X introduit par vous)\n");
                printf("4 - Afficher le meilleur buteur (joueur avec le maximum de buts)\n");
                printf("5 - Afficher le joueur le plus jeune et le plus âgé\n");
                printf("------------- Saisissez votre choix --------------------\n");
                scanf("%d", &choixMenu);
                getchar();
                switch (choixMenu)
                {
                case 1:
                    isChoice = true;
                    break;
                case 2:
                    isChoice = true;
                    break;
                case 3:
                    isChoice = true;
                    break;
                case 4:
                    isChoice = true;
                    break;
                case 5:
                    isChoice = true;
                    break;
                default:
                    printf("Choix invalide, veuillez réessayer !!\n");
                    break;
                }
            } while (isChoice);
            break;
        case 7:
            printf("Merci d'avoir utilisé l'application. À bientôt !\n");
            break;
        default:
            printf("Choix invalide, veuillez réessayer !!");
            break;
        }

    } while (choix != 7);

    return 0;
}