#include <stdio.h>
#include <math.h>

struct Tache
{
    int identifiant;
    char titre[100];
    char description[200];
    char deadline[100];
    char statut[100];
};

struct Tache taches[200];
int size = 0;

void echanger(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void trie_par_selection(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (min_idx != i)
            echanger(&arr[min_idx], &arr[i]);
    }
}

void ajouter_tache()
{
    struct Tache tache;
    tache.identifiant = size;
    puts("Saisir le titre:");
    scanf("%[^\n]", tache.titre);
    getchar();
    puts("Saisir la description:");
    scanf("%[^\n]", tache.description);
    getchar();
    puts("Saisir le deadline:");
    scanf("%[^\n]", tache.deadline);
    getchar();
    puts("Saisir le statut:");
    scanf("%[^\n]", tache.statut);
    getchar();
    taches[size] = tache;
    size++;

    puts(taches[0].titre);
}

void ajouter_n_taches()
{
    int n;
    printf("Saisir le nombre des taches: \n");
    scanf("%d", &n);
    getchar();
    int i = 1;
    while (i <= n)
    {
        printf("=> Tache %d: \n", i);
        ajouter_tache();
        i++;
    }
}

void afficher()
{
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
        for (int i = 0; i < size; i++)
        {
            printf("Tache %i:\n", i + 1);
            printf("titre: %s\n", taches[i].titre);
            printf("description: %s\n", taches[i].description);
            printf("deadline: %s\n", taches[i].deadline);
            printf("statut: %s\n", taches[i].statut);
        }
        break;

    default:
        break;
    }
}

int obtenir_indice(struct Tache[], int taille, id) {
    for(int i = 0; i < taille; i++) {
        if(taches[i].identifiant == id) return i;
        return -1;
    }
}

void modifier()
{
    int choix, id;

    printf("Veuiller saisir l'identifiant de la tache\n");
    scanf("%i", &id);
    printf("Saisir votre choix:\n");
    printf("   [1] Modifier la description d une tâche.\n");
    printf("   [2] Modifier le statut d une tâche.\n");
    printf("   [3] Modifier le deadline d une tâche.\n");
    scanf("%i", &choix);
    printf("%d \n%d", choix, id);
    
    
    printf("saisir la nouvelle value:")
    switch(choix) {
        case 1:
            scanf("%[^\n]", taches[id].description);
        break;
        case 2:
            scanf("%[^\n]", taches[id].statut);
        break;
        case 3:
        break;
    }
}

void afficher_menu()
{
    int choix;
    printf("****  Veuiller saisir votre choix  ****\n");
    printf("[1] Ajouter une nouvelle tâche.\n");
    printf("[2] Ajouter plusieurs nouvelles tâches.\n");
    printf("[3] Afficher la liste de toutes les tâches.\n");
    printf("[4] Modifier une tâche\n");
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
    getchar();

    switch (choix)
    {
    case 1:
        ajouter_tache();
        break;
    case 2:
        ajouter_n_taches();
        break;
    case 3:
        afficher();
        break;
    case 4:
        modifier();
        break;
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
