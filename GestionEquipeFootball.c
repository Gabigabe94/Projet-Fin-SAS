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
    char poste[10]; //  (gardien, défenseur, milieu, attaquant)
    int age;
    int buts;
    // char dateInscription[11];
    char statut[11]; //  "titulaire" ou "remplaçant"

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
        return taille;
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
        printf("Entrez l'âge du joueur :\n");
        scanf("%d", &tabJr[taille].age);
        getchar();
        printf("Entrez nombre de buts marqués par le joueur :\n");
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

// Bonus start d'équipe
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
    printf("Statut : %s\n", jr.statut);
    if (jr.buts >= 10)
    {
        printf("***** Ce joueur est un STAR de l'équipe *****\n");
    }
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
            if (strcasecmp(tabJr[i].nom, tabJr[j].nom) > 0)
            {
                jou = tabJr[i];
                tabJr[i] = tabJr[j];
                tabJr[j] = jou;
            }
        }
    }
    afficherListeJrs(tabJr, taille);
}

void grouperParPoste(Joueur tabJr[], int taille)
{
    printf("====== Liste des joueurs par poste ======\n");

    printf("\n--- Gardiens ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (strcasecmp(tabJr[i].poste, "Gardien") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Défenseurs ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (strcasecmp(tabJr[i].poste, "Défenseur") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Milieux ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (strcasecmp(tabJr[i].poste, "Milieu") == 0)
        {
            afficherJr(tabJr[i]);
        }
    }

    printf("\n--- Attaquants ---\n");
    for (int i = 0; i < taille; i++)
    {
        if (strcasecmp(tabJr[i].poste, "Attaquant") == 0)
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
        printf("Joueur avec ID %d non trouvé.\n", id);
    }
    else
    {
        for (int i = posJoueur; i < taille - 1; i++)
        {
            tabJr[i] = tabJr[i + 1];
        }
        printf("Le joueur à bien été supprimer !!\n");
        return taille - 1;
    }
    return taille;
}

int rechercherParNom(Joueur tabJr[], int taille, char nom[])
{
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

// Bonus : Rechercher par critère spécifique (par poste, par tranche d’âge)
void rechercherParCritere(Joueur liste[], int nb)
{
    int choix;
    bool c;
    printf("1 - Rechercher par poste\n");
    printf("2 - Rechercher par tranche d'âge\n");
    printf("0 - Quitter \n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    getchar();

    do
    {
        if (choix == 1)
        {
            char poste[20];
            char chPoste;
            bool isChoice;
            do
            {
                printf("Choisissez le poste :[G] gardien, [D] défenseur, [M] milieu, [A] attaquant\n ");
                scanf("%c", &chPoste);
                getchar();
                chPoste = tolower(chPoste);

                switch (chPoste)
                {
                case 'g':
                    strcpy(poste, "gardien");
                    isChoice = false;
                    break;
                case 'd':
                    strcpy(poste, "défenseur");
                    isChoice = false;
                    break;
                case 'm':
                    strcpy(poste, "milieu");
                    isChoice = false;
                    break;
                case 'a':
                    strcpy(poste, "attaquant");
                    isChoice = false;
                    break;
                default:
                    printf("Choix invalide, veulliez résseyez !!\n");
                    isChoice = true;
                    break;
                }

            } while (isChoice);

            for (int i = 0; i < nb; i++)
            {
                if (strcasecmp(liste[i].poste, poste) == 0)
                    afficherJr(liste[i]);
            }
            c = false;
        }
        else if (choix == 2)
        {
            int min, max;
            printf("Entrez l'âge minimum : ");
            scanf("%d", &min);
            printf("Entrez l'âge maximum : ");
            scanf("%d", &max);
            getchar();

            for (int i = 0; i < nb; i++)
            {
                if (liste[i].age >= min && liste[i].age <= max)
                    afficherJr(liste[i]);
            }
            c = false;
        }else if (choix == 3)
        {
            c = false;
        }
        else
        {
            printf("Choix invalide !\n");
            c = true;
        }
    } while (c);
}

void modifierPoste(Joueur listeJr[], int n)
{

    int id, p;
    char choi;
    bool isChoice;

    printf("Entrez l'identifiant du joueur :\n");
    scanf("%d", &id);
    getchar();
    p = rechercherParId(listeJr, n, id);
    if (p == -1)
    {
        printf("Joueur avec ID %d non trouvé.\n", id);
    }
    else
    {
        do
        {

            printf("Choisissez le nouveau poste [G]: Gardien, [D]: Défenseur, [M]: Milieu, [A]: Attaquant\n");
            scanf("%c", &choi);
            getchar();
            choi = tolower(choi);

            switch (choi)
            {
            case 'g':
                strcpy(listeJr[p].poste, "Gardien");
                afficherJr(listeJr[p]);
                printf("============== Modification de poste éffectué ================");
                isChoice = false;
                break;
            case 'd':
                strcpy(listeJr[p].poste, "Défenseur");
                afficherJr(listeJr[p]);
                printf("============== Modification de poste éffectué ================");
                isChoice = false;
                break;
            case 'm':
                strcpy(listeJr[p].poste, "Milieu");
                afficherJr(listeJr[p]);
                printf("============== Modification de poste éffectué ================");
                isChoice = false;
                break;
            case 'a':
                strcpy(listeJr[p].poste, "Attaquant");
                afficherJr(listeJr[p]);
                printf("============== Modification de poste éffectué ================");
                isChoice = false;
                break;

            default:
                printf("Choix invalide, veuillez réessayer !!\n");
                isChoice = true;
                break;
            }
        } while (isChoice);
    }
}

// Bonus : affecter un joueur à une position spécifique dans l’équipe (par exemple : titulaire ou remplaçant.
void affecterStatut(Joueur liste[], int nb)
{
    int id, pos;
    printf("Entrez l'ID du joueur à modifier : ");
    scanf("%d", &id);
    getchar();
    pos = rechercherParId(liste, nb, id);
    if (pos == -1)
    {
        printf("Joueur avec ID %d non trouvé.\n", id);
    }
    else
    {
        bool isNotValide;
        do
        {
            printf("1 - Titulaire\n2 - Remplaçant\nVotre choix : ");
            int choix;
            scanf("%d", &choix);
            getchar();

            if (choix == 1)
            {
                strcpy(liste[pos].statut, "Titulaire");
                isNotValide = false;
            }
            else if (choix == 2)
            {
                strcpy(liste[pos].statut, "Remplaçant");
                isNotValide = false;
            }
            else
            {
                printf("Choix invalide, veulliez résseyez \n");
                isNotValide = true;
            }
        } while (isNotValide);
        printf("Statut mis à jour.\n");
    }
}

void modifierAge(Joueur liste[], int taille)
{

    int id, p, age;
    printf("Entrez l'identifiant du joueur :\n");
    scanf("%d", &id);
    getchar();
    p = rechercherParId(liste, taille, id);
    if (p == -1)
    {
        printf("Joueur avec ID %d non trouvé.\n", id);
    }
    else
    {
        printf("Entrez l'age du joueur :\n");
        scanf("%d", &age);
        getchar();
        liste[p].age = age;
        afficherJr(liste[p]);
        printf("================ Modification de l'age éffectué ==============");
    }
}

void modifierNbButs(Joueur liste[], int taille)
{

    int id, p, nbuts;
    printf("Entrez l'identifiant du joueur :\n");
    scanf("%d", &id);
    getchar();
    p = rechercherParId(liste, taille, id);
    if (p == -1)
    {
        printf("Joueur avec ID %d non trouvé.\n", id);
    }
    else
    {
        printf("Entrez le nombre buts du joueur :\n");
        scanf("%d", &nbuts);
        getchar();
        liste[p].buts = nbuts;
        afficherJr(liste[p]);
        printf("================ Modification du nombre de buts éffectué ==============");
    }
}

float moyenAge(Joueur liste[], int n)
{
    float somme = 0;
    for (size_t i = 0; i < n; i++)
    {
        somme += liste[i].age;
    }
    return somme / n;
}

void listeJrMarquePlusXButs(Joueur lis[], int t)
{

    int nombreB;
    printf("Entrez nombre de buts :");
    scanf("%d", &nombreB);
    getchar();
    for (int i = 0; i < t; i++)
    {
        if (lis[i].buts > nombreB)
            afficherJr(lis[i]);
    }
}

void meilleurButeur(Joueur listeJr[], int n)
{
    int max = listeJr[0].buts;
    for (int i = 1; i < n; i++)
    {
        if (listeJr[i].buts > max)
            max = listeJr[i].buts;
    }
    for (int i = 0; i < n; i++)
    {
        if (listeJr[i].buts == max)
            afficherJr(listeJr[i]);
    }
}

void joueurPlAgePlJeune(Joueur liste[], int nb)
{

    int plusAge = liste[0].age, jeune = liste[0].age;
    for (int i = 1; i < nb; i++)
    {
        if (liste[i].age > plusAge)
        {
            plusAge = liste[i].age;
        }
        if (liste[i].age < jeune)
        {
            jeune = liste[i].age;
        }
    }
    for (int i = 0; i < nb; i++)
    {
        if (liste[i].age == plusAge)
        {
            printf("Le joueur le plus âgé dans l'équipe est :\n");
            afficherJr(liste[i]);
        }
        if (liste[i].age == jeune)
        {
            printf("Le joueur le plus jeune dans l'équipe est :\n");
            afficherJr(liste[i]);
        }
    }
}

int main()
{
    Joueur listeJoueurs[MAX_JOUEURS] = {
        {1, "Benzema", "Karim", 9, "attaquant", 36, 15, "titulaire"},
        {2, "Courtois", "Thibaut", 1, "gardien", 32, 0, "titulaire"},
        {3, "Varane", "Raphael", 4, "défenseur", 31, 2, "titulaire"},
        {4, "Modric", "Luka", 10, "milieu", 38, 5, "titulaire"},
        {5, "Vinicius", "Junior", 7, "attaquant", 25, 12, "titulaire"},
        {6, "Camavinga", "Eduardo", 12, "milieu", 22, 3, "remplaçant"},
        {7, "Nacho", "Fernandez", 6, "défenseur", 34, 1, "remplaçant"},
        {8, "Rodrygo", "Goes", 11, "attaquant", 24, 8, "titulaire"}};
    int nbJoueurs = 8;

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
        printf("0 - Quitter\n");
        printf("------------------------------------------------------------------------------------\n");
        printf("Saisissez votre choix : ");
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
                printf("0 - Quitter\n");
                printf("------------------------------------------------------\n");
                printf("Saisissez votre choix : ");
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
                else if (choixMenu == 0)
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
                printf("0 - Quitter\n");
                printf("Saisissez votre choix : ");
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
                    grouperParPoste(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 0)
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

        case 3:
            do
            {
                printf("---------------- Modification -----------------\n");
                printf("1 - Modifier le poste d’un joueur\n");
                printf("2 - Modifier l’âge d’un joueur\n");
                printf("3 - Modifier le nombre de buts marqués par un joueur\n");
                printf("4 - Affecter un joueur à une position spécifique dans l’équipe\n");
                printf("0 - Quitter\n");
                printf("------------------------------------------------\n");
                printf("Saisissez votre choix : ");
                scanf("%d", &choixMenu);
                getchar();

                if (choixMenu == 1)
                {
                    modifierPoste(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {
                    modifierAge(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 3)
                {
                    modifierNbButs(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 4)
                {
                    affecterStatut(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 0)
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
            printf("Entrez l'identifiant du joueur à supprimer : ");
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
                printf("3 - Rechercher par critère spécifique\n");
                printf("0 - Quitter\n");
                printf("--------------------------------------------------\n");
                printf("Saisissez votre choix : ");
                scanf("%d", &choixMenu);
                getchar();
                if (choixMenu == 1)
                {
                    printf("Entrez l'identifiant du joueur à rechercher : ");
                    scanf("%d", &idJr);
                    getchar();
                    posJr = rechercherParId(listeJoueurs, nbJoueurs, idJr);
                    if (posJr == -1)
                    {
                        printf("Joueur avec ID %d non trouvé.\n", idJr);
                    }
                    else
                    {
                        afficherJr(listeJoueurs[posJr]);
                    }
                    isChoice = false;
                }
                else if (choixMenu == 2)
                {
                    printf("Entrez le nom du joueur à rechercher : ");
                    fgets(nom, sizeof(nom), stdin);
                    nom[strcspn(nom, "\n")] = 0;
                    posJr = rechercherParNom(listeJoueurs, nbJoueurs, nom);
                    if (posJr == -1)
                    {
                        printf("Joueur avec NOM %s non trouvé.\n", nom);
                    }
                    else
                    {
                        afficherJr(listeJoueurs[posJr]);
                    }
                    isChoice = false;
                }
                else if (choixMenu == 3)
                {
                    rechercherParCritere(listeJoueurs, nbJoueurs);
                    isChoice = false;
                }
                else if (choixMenu == 0)
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
        case 6:
            do
            {
                printf("-------------------- Statistiques ----------------------\n");
                printf("1 - Afficher le nombre total de joueurs dans l’équipe\n");
                printf("2 - Afficher l’âge moyen des joueurs\n");
                printf("3 - Afficher les joueurs ayant marqué plus de X buts (X introduit par vous)\n");
                printf("4 - Afficher le meilleur buteur (joueur avec le maximum de buts)\n");
                printf("5 - Afficher le joueur le plus jeune et le plus âgé\n");
                printf("0 - Quitter\n");
                printf("-------------------------------------------------------\n");
                printf("Saisissez votre choix : ");
                scanf("%d", &choixMenu);
                getchar();
                switch (choixMenu)
                {
                case 1:
                    printf("Le nombre total de joueurs dans l’équipe est : %d.\n", nbJoueurs);
                    isChoice = false;
                    break;
                case 2:
                    float m = moyenAge(listeJoueurs, nbJoueurs);
                    printf("L’âge moyen des joueurs est : %.2f ans.", m);
                    isChoice = false;
                    break;
                case 3:
                    listeJrMarquePlusXButs(listeJoueurs, nbJoueurs);
                    isChoice = false;
                    break;
                case 4:
                    meilleurButeur(listeJoueurs, nbJoueurs);
                    isChoice = false;
                    break;
                case 5:
                    joueurPlAgePlJeune(listeJoueurs, nbJoueurs);
                    isChoice = false;
                    break;
                case 0:
                    isChoice = false;  
                    break; 
                default:
                    printf("Choix invalide, veuillez réessayer !!\n");
                    isChoice = true;
                    break;
                }
            } while (isChoice);
            break;
        case 0:
            printf("Merci d'avoir utilisé l'application. À bientôt !\n");
            break;
        default:
            printf("Choix invalide, veuillez réessayer !!");
            break;
        }

    } while (choix != 0);

    return 0;
}