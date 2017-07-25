#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* getfield(char* line, int num)
{
    const char* tok;
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

    char line[1024];
    while (fgets(line, 1024, fstream))
    {
        char* tmp = strdup(line);
        printf("%s\n", getfield(tmp, value));
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


// CLIENT
void client_add() {
    char id[50];
    char nom[50];
    char prenom[50];
    char role[50];
    char tel[50];

    char string[100];

    printf("Id : ");
    scanf("%s", id);

    printf("Nom : ");
    scanf("%s", nom);

    printf("Prenom : ");
    scanf("%s", prenom);

    printf("Role : ");
    scanf("%s", role);

    printf("Tel : ");
    scanf("%s", tel);

    sprintf(string, "%s;%s;%s;%s;%s;", id, nom, prenom, role, tel);

    printf("\nstring: %s", string);

    write_csv("Account", 0, string);
}

void client_edit() {

}

void client_delete() {

}

void client_search() {

}

//COMPTE
void compte_new() {

}

void compte_show_solde() {

}

void compte_close() {

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
    printf("1 - Ajouter un client\n");
    printf("2 - Modifier un client\n");
    printf("3 - Supprimer un client\n");
    printf("4 - Rechercher un client\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int menu_compte() {
    int select;

    printf("~~~~~~~ MENU COMPTE ~~~~~~~\n");
    printf("1 - Nouveau compte\n");
    printf("2 - Consultation solde\n");
    printf("3 - Fermer un compte\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int menu_operation() {
    int select;

    printf("~~~~~~~ MENU OPERATION ~~~~~~~\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int menu_admin() {
    int select;

    printf("~~~~~~~ MENU ADMINISTRATION ~~~~~~~\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Quitter\n");

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
    int running = 1;

    while (running) {
        switch (show_menu()) {
            case 1:
                switch (menu_client()) {
                    case 1:
                        client_add();
                        break;
                    case 2:
                        client_edit();
                        break;
                    case 3:
                        client_delete();
                        break;
                    case 4:
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
                        compte_new();
                        break;
                    case 2:
                        compte_show_solde();
                        break;
                    case 3:
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
                        running = 0;
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