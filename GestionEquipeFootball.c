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
    char statut[11]; // indique si le joueur est "titulaire" ou "remplaçant"

} Joueur;

int ajouterjr(Joueur j, Joueur tabJr[], int taille)
{
    tabJr[taille].id = j.id;
    strcpy(tabJr[taille].nom, j.nom);
    strcpy(tabJr[taille].prenom, j.prenom);
    tabJr[taille].numeroMaillot = j.numeroMaillot;
    tabJr[taille].age = j.age;
    strcpy(tabJr[taille].poste, j.poste);
    tabJr[taille].buts = j.buts;
    strcpy(tabJr[taille].statut, j.statut);
    return taille + 1;
}

int ajouterJr(Joueur tabJr[], int taille)
{
    if (taille >= MAX_JOUEURS)
    {
        printf("La liste des joueurs est remplie. \n");
    }
    else
    {
        printf("Saisissez les informations du joueur\n");
        tabJr[taille].id = taille + 1;
        printf("Entrez le nom du joueur :\n");
        fgets(tabJr[taille].nom, sizeof(tabJr[taille].nom), stdin);
        tabJr[taille].nom[strcspn(tabJr[taille].nom, "\n")] = 0;
        printf("Entrez le prénom du joueur :\n");
        fgets(tabJr[taille].prenom, sizeof(tabJr[taille].prenom), stdin);
        tabJr[taille].prenom[strcspn(tabJr[taille].prenom, "\n")] = 0;
        printf("Entrez le numéro de maillot du joueur :\n");
        scanf("%d", &tabJr[taille].numeroMaillot);
        getchar();
        char choi;
        bool isChoice = false;
        do
        {
            printf("Choisissez le poste du joueur [G]: Gardien, [D]: Défenseur, [M]: Milieu, [A]: Attaquant\n");
            scanf("%c", &choi);
            getchar();
            choi = tolower(choi);

            switch (choi)
            {
            case 'g':
                strcpy(tabJr[taille].poste, "Gardien");
                isChoice = false;
                break;
            case 'd':
                strcpy(tabJr[taille].poste, "Défenseur");
                isChoice = false;
                break;
            case 'm':
                strcpy(tabJr[taille].poste, "Milieu");
                isChoice = false;
                break;
            case 'a':
                strcpy(tabJr[taille].poste, "Attaquant");
                isChoice = false;
                break;

            default:
                printf("Choix invalide, veuillez réessayer !!\n");
                isChoice = true;
                break;
            }
        } while (isChoice);
        printf("Entez l'âge du joueur :\n");
        scanf("%d", &tabJr[taille].age);
        getchar();
        printf("Entez nombre de buts marqués par le joueur :\n");
        scanf("%d", &tabJr[taille].buts);
        getchar();
        do
        {
            printf("Choisissez le statut du joueur [T]: Titulaire, [R]: Remplaçant\n");
            scanf("%c", &choi);
            getchar();
            choi = tolower(choi);
            switch (choi)
            {
            case 't':
                strcpy(tabJr[taille].statut, "Titulaire");
                isChoice = false;
                break;
            case 'r':
                strcpy(tabJr[taille].statut, "Remplaçant");
                isChoice = false;
                break;
            default:
                printf("Choix invalide, veuillez réessayer !!\n");
                isChoice = true;
                break;
            }
        } while (isChoice);
        printf("========== Le joueur a bien été ajouté ============\n");
        return taille + 1;
    }
}

int ajouterPlusJrs(Joueur tabJr[], int taille)
{
    int nb;
    printf("Donnez le nombre de joueurs que vous voulez ajouter :\n");
    scanf("%d", &nb);
    getchar();
    for (int i = 0; i < nb; i++)
    {
        taille = ajouterJr(tabJr, taille);
    }
    printf("======= Vous avez ajouté tous les joueurs demandés ========\n");
    return taille;
}

void afficherJr(Joueur jr)
{
    printf("--------------------------------------------------\n");
    printf("\nId : %d\n", jr.id);
    printf("Nom : %s\n", jr.nom);
    printf("Prenom : %s\n", jr.prenom);
    printf("Numéro de maillot : %d\n", jr.numeroMaillot);
    printf("Poste : %s\n", jr.poste);
    printf("Age : %d\n", jr.age);
    printf("Buts : %d\n", jr.buts);
    printf("Statu : %s\n", jr.statut);
    printf("\n--------------------------------------------------\n");
}

void afficherListeJrs(Joueur tabJr[], int taille)
{
    for (int i = 0; i < taille; i++)
    {
        afficherJr(tabJr[i]);
    }
}

void trieParAge(Joueur tabJr[], int taille)
{
    Joueur jou;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (tabJr[i].age < tabJr[j].age)
            {
                jou = tabJr[i];
                tabJr[i] = tabJr[j];
                tabJr[j] = jou;
            }
        }
    }
    afficherListeJrs(tabJr, taille);
}

void trieParNom(Joueur tabJr[], int taille)
{
    Joueur jou;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = i + 1; j < taille; j++)
        {
            if (_stricmp(tabJr[i].nom, tabJr[j].nom) > 0)
            {
                jou = tabJr[i];
                tabJr[i] = tabJr[j];
                tabJr[j] = jou;
            }
        }
    }
    afficherListeJrs(tabJr, taille);
}

void trieParPoste(Joueur tabJr[], int taille)
{
    printf("====== Liste des joueurs par poste ======\n");

    printf("\n--- Gardiens ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (_stricmp(tabJr[i].poste, "Gardien") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Défenseurs ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (_stricmp(tabJr[i].poste, "Défenseur") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Milieux ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (_stricmp(tabJr[i].poste, "Milieu") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Attaquants ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (_stricmp(tabJr[i].poste, "Attaquant") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }
}

int rechercherParId(Joueur tabJr[], int taille, int id)
{

    for (int i = 0; i < taille; i++)
    {
        if (tabJr[i].id == id)
        {
            return i;
            break;
        }
    }
    return -1;
}

int supprimerJoueur(Joueur tabJr[], int taille, int id)
{

    int posJoueur = rechercherParId(tabJr, taille, id);
    if (posJoueur == -1)
    {
        printf("Le joueur n'existe pas !!\n");
    }
    else
    {
        for (int i = posJoueur; i < taille; i++)
        {
            tabJr[i] = tabJr[i + 1];
        }
        printf("Le joueur à bien été supprimer !!\n");
        return taille - 1;
    }
    return taille;
}

int rechercherParNom(Joueur tabJr[], int taille, char nom[]){

    for (int i = 0; i < taille; i++)
    {
        if (_stricmp(tabJr[i].nom, nom) == 0)
        {
            return i;
            break;
        }
    }
    return -1;
}
int main()
{
    Joueur listeJoueurs[MAX_JOUEURS];
    int nbJoueurs = 0;

    Joueur j1 = {1, "Badr", "Ahmmed", 3, "défenseur", 28, 5, "titulaire"};
    nbJoueurs = ajouterjr(j1, listeJoueurs, nbJoueurs);
    Joueur j2 = {2, "alaoui", "Ali", 10, "milieu", 22, 5, "remplaçant"};
    nbJoueurs = ajouterjr(j2, listeJoueurs, nbJoueurs);
    Joueur j3 = {3, "Gabi", "mhammed", 3, "défenseur", 30, 5, "titulaire"};
    nbJoueurs = ajouterjr(j3, listeJoueurs, nbJoueurs);
    Joueur j4 = {4, "ziar", "yahya", 4, "gardien", 18, 5, "titulaire"};
    nbJoueurs = ajouterjr(j4, listeJoueurs, nbJoueurs);
    Joueur j5 = {5, "yasin", "youssef", 3, "attaquant", 29, 5, "remplaçant"};
    nbJoueurs = ajouterjr(j5, listeJoueurs, nbJoueurs);

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

        int choixMenu, idJr, posJr;
        bool isChoice;
        char nom[30];

        switch (choix)
        {

        case 1:
            do
            {
                printf("------------------------------------------------------\n");
                printf("1 - Ajouter un nouveau joueur\n");
                printf("2 - Ajouter plusieurs joueurs en une seule opération\n");
                printf("------------- Saisissez votre choix ------------------\n");
                scanf("%d", &choixMenu);
                getchar();
                if (choixMenu == 1)
                {
                    nbJoueurs = ajouterJr(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {
                    nbJoueurs = ajouterPlusJrs(listeJoueurs, nbJoueurs);
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
                    trieParNom(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {
                    trieParAge(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 3)
                {
                    trieParPoste(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = true;
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

                    isChoice = false;
                }
                else if (choixMenu == 2)
                {

                    isChoice = false;
                }
                else if (choixMenu == 3)
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

        case 4:
            printf("Entrez l'identifiant du joueur à supprimer :\n");
            scanf("%d", &idJr);
            getchar();
            nbJoueurs = supprimerJoueur(listeJoueurs, nbJoueurs, idJr);
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
                    printf("Entrez l'identifiant du joueur à modifier :\n");
                    scanf("%d", &idJr);
                    getchar();
                    posJr = rechercherParId(listeJoueurs, nbJoueurs, idJr);
                    if(posJr == -1){
                        printf("Le joueur n'existe pas !!\n");
                    }else{
                        afficherJr(listeJoueurs[posJr]);
                    }
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {
                    printf("Entrez le nom du joueur à modifier :\n");
                    fgets(nom, sizeof(nom), stdin);
                    nom[strcspn(nom,"\n")] = 0;
                    posJr = rechercherParNom(listeJoueurs, nbJoueurs, nom);
                    if(posJr == -1){
                        printf("Le joueur n'existe pas !!\n");
                    }else{
                        afficherJr(listeJoueurs[posJr]);
                    }
                    isChoice = false;
                }
                else
                {
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = true;
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
                    isChoice = false;
                    break;
                case 2:
                    isChoice = false;
                    break;
                case 3:
                    isChoice = false;
                    break;
                case 4:
                    isChoice = false;
                    break;
                case 5:
                    isChoice = false;
                    break;
                default:
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = true;
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