#include <stdio.h>
#include <math.h>
#include <string.h>

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
            printf("---------------------\n");
            printf("Tache %i:\n", i + 1);
            printf("titre: %s\n", taches[i].titre);
            printf("description: %s\n", taches[i].description);
            printf("deadline: %s\n", taches[i].deadline);
            printf("statut: %s\n", taches[i].statut);
            printf("---------------------\n");
        }
        break;

    default:
        break;
    }
}

int rechercher_par_id(int id)
{
    for (int i = 0; i < size; i++)
    {
        if (taches[i].identifiant == id)
            return i;
    }
    printf("aucun element trouve\n");
    return -1;
}

int rechercher_par_titre(char titre[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(taches[i].titre, titre) == 0)
            return i;
    }
    printf("aucun element trouve\n");
    return -1;
}

void modifier()
{
    int choix, id, indice_tache;

    printf("Veuiller saisir l'identifiant de la tache\n");
    scanf("%i", &id);
    printf("Saisir votre choix:\n");
    printf("   [1] Modifier la description d une tâche.\n");
    printf("   [2] Modifier le statut d une tâche.\n");
    printf("   [3] Modifier le deadline d une tâche.\n");
    scanf("%i", &choix);
    printf("choix: %d\nidentifiant: %d\n", choix, id);
    indice_tache = rechercher_par_id(id);
    printf("indice de tache: %d\n", indice_tache);

    printf("saisir la nouvelle value:\n");
    switch (choix)
    {
    case 1:
        getchar();
        scanf("%[^\n]", taches[indice_tache].description);
        getchar();
        break;
    case 2:
        getchar();
        scanf("%[^\n]", taches[indice_tache].statut);
        break;
    case 3:
        getchar();
        scanf("%[^\n]", taches[indice_tache].deadline);
        break;
    }
}

void supprimer()
{
    int id;
    printf("Veuiller saisir l'identifiant de la tache\n");
    scanf("%i", &id);
    int indice_tache = rechercher_par_id(id);
    if (indice_tache != -1)
    {

        for (int i = indice_tache; i < size - 1; i++)
        {
            taches[i] = taches[i + 1];
        }
    }
    size--;
}

void rechercher()
{
    int choix, indice;
    printf("veuiller saisir votre choix:\n");
    printf("   [1] Rechercher une tâche par son Identifiant.\n");
    printf("   [2] Rechercher une tâche par son Titre\n");
    scanf("%d", choix);
    if (choix == 1)
        indice = rechercher_par_id();
    if (choix == 2)
        indice = rechercher_par_titre();
    if (indice != -1)
    {
        printf("---------------------\n");
        printf("titre: %s\n", taches[indice].titre);
        printf("description: %s\n", taches[indice].description);
        printf("deadline: %s\n", taches[indice].deadline);
        printf("statut: %s\n", taches[indice].statut);
        printf("---------------------\n");
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
    printf("[6] Rechercher les Tâches\n");
    printf("=> Afficher les statistiques\n");
    printf("   [7.1] Afficher le nombre total des tâches.\n");
    printf("   [7.2] Afficher le nombre de tâches complètes et incomplètes.\n");
    printf("   [7.3] Afficher le nombre de jours restants jusqu'au délai de chaque tâche.\n");

    scanf("%i", &choix);
    getchar();
    printf("choix: %i\n\n", choix);

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
    case 5:
        supprimer();
        break;
    case 6:
        rechercher();
        break;
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
