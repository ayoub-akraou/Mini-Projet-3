#include <stdio.h>
#include <math.h>

struct Tache {
    int identifiant;
    char titre[100];
    char description[200];
    char deadline[100];
    char statut[100];
};

struct Tache taches[200];
int n;

void ajouter_tache() {
    struct Tache tache;
    tache.identifiant = n;
    printf("Saisir le titre: \n");
    getchar();
    scanf("%[^\n]s", &tache.titre);
    printf("Saisir la description: \n");
    getchar();
    scanf("%[^\n]s", &tache.deadline);
    printf("Saisir le deadline: \n");
    getchar();
    scanf("%[^\n]s", &tache.deadline);
    printf("Saisir le statut: \n");
    getchar();
    scanf("%[^\n]s", &tache.statut);
}

void ajouter_n_taches() {
    int n;
    printf("Saisir le nombre des taches: \n");
    scanf("%d", &n);
    int i = 1;
    while(i <= n) {
        printf("=> Tache %d: \n", i);
        ajouter_tache();
        i++;
    }
}

void afficher() {
    int choix;
    printf("Saisir votre choix:\n");
    printf("   [1] affichage simple.\n");
    printf("   [2] affichage asc.\n");
    printf("   [3] affichage desc.\n");
    scanf("%d", &choix);
    printf("=> choix: %d\n", choix);

    switch (choix)
    {
    case 1: 
    
    ;
        break;
    
    default:
        break;
    }
}

void afficher_menu() {
    int choix;
    printf("****  Veuiller saisir votre choix  ****\n");
    printf("[1] Ajouter une nouvelle tâche.\n");
    printf("[2] Ajouter plusieurs nouvelles tâches.\n");
    printf("[3] Afficher la liste de toutes les tâches.\n");
    printf("=> Modifier une tâche\n");
        printf("   [4.1] Modifier la description d'une tâche.\n");
        printf("   [4.2] Modifier le statut d’une tâche.\n");
        printf("   [4.3] Modifier le deadline d’une tâche.\n");
    printf("[5] Supprimer une tâche par identifiant.\n");
    printf("=> Rechercher les Tâches\n");
        printf("   [6.1] Rechercher une tâche par son Identifiant.\n");
        printf("   [6.2] Rechercher une tâche par son Titre\n");
    printf("=> Afficher les statistiques\n");
    printf("   [7.1] Afficher le nombre total des tâches.\n");
    printf("   [7.2] Afficher le nombre de tâches complètes et incomplètes.\n");
    printf("   [7.3] Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");

    scanf("%i", &choix);
    printf("choix: %i\n\n", choix);

    switch (choix)
    {
    case 1: ajouter_tache();
        break;
    case 2: ajouter_n_taches();
        break;
    case 3:  afficher();
        break;
    // case 4:  modifier();
        // break;
    // case 5:  supprimer();
        // break;
    // case 6:  rechercher();
        // break;
    // case 7:  afficher_les_statistiques();
        // break;
    
    default:
        printf("Saisir un choix valide: entre 1 et 7\n");
        break;
    }

    afficher_menu();
}

int main()
{
   afficher_menu();
}

