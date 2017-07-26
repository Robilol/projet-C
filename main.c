#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char client_ids[1024][4];

char* getfield(char* line, int num)
{
    char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

void read_csv(char *filename, int value) {
    char end[50] = ".csv";
    char path[50] = "../Bank/";
    strcat(path, filename);
    strcat(path, end);
    FILE *fstream = fopen(path,"r");

    if(fstream == NULL)
    {
        printf("\n file opening failed ");
    }

    int i = 0;
    char line[1024];
    while (fgets(line, 1024, fstream))
    {
        char* tmp = strdup(line);
//        printf("%s\n", getfield(tmp, value));

        printf("%s", line);

        i++;
        free(tmp);
    }

    fclose(fstream);
}

void write_csv(char *filename, int value, char *textToWrite) {
    FILE *fstream;
    char end[50] = ".csv";
    char path[50] = "../Bank/";
    strcat(path, filename);
    strcat(path, end);

    switch (value) {
        case 0:
            fstream = fopen(path,"a");
            break;
        case 1:
            fstream = fopen(path,"w");
            break;
        default:
            break;
    }

    if(fstream == NULL)
    {
        printf("\n file opening failed ");
    }

    fprintf(fstream, textToWrite);

    fclose(fstream);
}

//COMPTE
void comptes_listing(){
    char buffer[1024] ;
    char *record,*line;
    int i=0,j=0;
    int mat[100][100];
    FILE *fstream = fopen("../Bank/Accounts.csv","r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
        return;
    }
    printf(" ID Compte - ID client - Solde - Taux \n");
    printf(" - ");
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        record = strtok(line,";");
        while(record != NULL)
        {
            printf("%s - ",record) ;
            mat[i][j++] = atoi(record) ;
            record = strtok(NULL,";");
        }
        ++i ;
    }
    printf("\n");
    fclose(fstream);
}

void compte_new() {
    /* Génère un ID numérique de 4 chiffres : */
    int id = rand()%(9999-1000)+1;

    int id_proprietaire;
    int solde;
    int taux;

    char string[100];

    printf("ID proprietaire : ");
    scanf("%d", &id_proprietaire);

    printf("Solde : ");
    scanf("%d", &solde);

    printf("Taux : ");
    scanf("%d", &taux);

    sprintf(string, "%d;%d;%d;%d;\n", id, id_proprietaire, solde, taux);

    write_csv("Accounts", 0, string);
}

void compte_show_solde() {

}

void compte_close() {

}

// CLIENT

void clients_listing(){
    char buffer[1024] ;
    char *record,*line;
    int i=0,j=0;
    int mat[100][100];
    FILE *fstream = fopen("../Bank/Clients.csv","r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
        return;
    }
    printf(" ID - Nom - Prenom - Role - Tel \n");
    printf(" - ");
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        record = strtok(line,";");
        while(record != NULL)
        {
            printf("%s - ",record) ;
            mat[i][j++] = atoi(record) ;
            record = strtok(NULL,";");
        }
        ++i ;
    }
    printf("\n");
    fclose(fstream);
}

int * get_clients_id(){
    char buffer[1024] ;
    char *record,*line;
    int i=0;
    static int r[1024];
    FILE *fstream = fopen("../Bank/Clients.csv", "r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
        return -1;
    }
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        record = strtok(line,";");
        r[i] = atoi(record) ;
        ++i ;
    }
    fclose(fstream);
    return r;
}

void client_add() {
    /* Génère un ID numérique de 4 chiffres : */
    int id = rand()%(9999-1000)+1;

    char nom[50];
    char prenom[50];
    char role[50];
    char tel[50];

    char string[100];

    printf("Nom : ");
    scanf("%s", nom);

    printf("Prenom : ");
    scanf("%s", prenom);

    printf("Role : ");
    scanf("%s", role);

    printf("Tel : ");
    scanf("%s", tel);

    sprintf(string, "\n%d;%s;%s;%s;%s;", id, nom, prenom, role, tel);

    write_csv("Clients", 0, string);
}


void client_edit(int id) {

}

void client_delete() {

}

void client_search() {

}

void choose_client(int value) {
    char *res[1024];
    printf("Liste des clients : \n");
    read_csv("Clients", 2);

    printf("\n\n");
    int id;
    /* Modifier un client : */
    if (value == 1) {
        printf("\nTaper l'ID du client à modifier : ");
        scanf("%d", &id);
        client_edit(id);
    }
    /* Créer un compte : */
    else if (value == 2) {
        compte_new();
    }

}

//OPERATION
void operation_depot() {

}

void operation_retrait() {

}

void operation_virement() {

}

//HISTORIQUE
void historique_show() {

}

int menu_client() {
    int select;

    printf("~~~~~~~ MENU CLIENT ~~~~~~~\n");

    printf("1 - Listing des clients\n");
    printf("2 - Ajouter un client\n");
    printf("3 - Modifier un client\n");
    printf("4 - Supprimer un client\n");
    printf("5 - Rechercher un client\n");
    printf("0 - Retour\n");

    scanf("%d", &select);
    return select;
}

int menu_compte() {
    int select;

    printf("~~~~~~~ MENU COMPTE ~~~~~~~\n");
    printf("1 - Listing comptes\n");
    printf("2 - Nouveau compte\n");
    printf("3 - Consultation solde\n");
    printf("4 - Fermer un compte\n");
    printf("0 - Retour\n");

    scanf("%d", &select);
    return select;
}

int menu_operation() {
    int select;

    printf("~~~~~~~ MENU OPERATION ~~~~~~~\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Retour\n");

    scanf("%d", &select);
    return select;
}

int menu_admin() {
    int select;

    printf("~~~~~~~ MENU ADMINISTRATION ~~~~~~~\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Retour\n");

    scanf("%d", &select);
    return select;
}

int show_menu() {
    int select;

    printf("~~~~~~~ MENU ~~~~~~~\n");
    printf("1 - Gestion des clients\n");
    printf("2 - Gestion des comptes\n");
    printf("3 - Gestion des operations\n");
    printf("4 - Historique\n");
    printf("5 - Administration\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int main()
{
    int *p;
    int i;

    p = get_clients_id();
    size_t taille = strlen(p);

    for ( i = 0; i < taille; i++ ) {
        printf( "*(p + %d) : %d\n", i, *(p + i));
    }

    int running = 1;
    srand(time(NULL));

    while (running) {
        switch (show_menu()) {
            case 1:
                switch (menu_client()) {
                    case 1:
                        clients_listing();
                        break;
                    case 2:
                        client_add();
                        break;
                    case 3:
                        choose_client(1);
                        break;
                    case 4:
                        client_delete();
                        break;
                    case 5:
                        client_search();
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                switch (menu_compte()) {
                    case 1:
                        comptes_listing();
                        break;
                    case 2:
                        choose_client(2);
                        break;
                    case 3:
                        compte_show_solde();
                        break;
                    case 4:
                        compte_close();
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 3:
                switch (menu_operation()) {
                    case 1:
                        operation_depot();
                        break;
                    case 2:
                        operation_retrait();
                        break;
                    case 3:
                        operation_virement();
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 4:
                historique_show();
                break;
            case 5:
                switch (menu_admin()) {
                    case 1:
                        operation_depot();
                        break;
                    case 2:
                        operation_retrait();
                        break;
                    case 3:
                        operation_virement();
                        break;
                    case 0:
                        break;
                    default:
                        break;
                }
                break;
            case 0:
                running = 0;
//                exit(0);
                break;
            default:
//                exit(0);
                break;
        }
    }

    return 0 ;
}