#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CLIENT
void client_add() {

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

    printf("¤~~~~~~~¤ MENU CLIENT ¤~~~~~~~¤\n");
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

    printf("¤~~~~~~~¤ MENU COMPTE ¤~~~~~~~¤\n");
    printf("1 - Nouveau compte\n");
    printf("2 - Consultation solde\n");
    printf("3 - Fermer un compte\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int menu_operation() {
    int select;

    printf("¤~~~~~~~¤ MENU OPERATION ¤~~~~~~~¤\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int menu_admin() {
    int select;

    printf("¤~~~~~~~¤ MENU ADMINISTRATION ¤~~~~~~~¤\n");
    printf("1 - Depot\n");
    printf("2 - Retrait\n");
    printf("3 - Virement\n");
    printf("0 - Quitter\n");

    scanf("%d", &select);
    return select;
}

int show_menu() {
    int select;

    printf("¤~~~~~~~¤ MENU ¤~~~~~~~¤\n");
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
                        client_search();
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
                        break;
                    default:
                        break;
                }
                break;
            case 0:
                exit(0);
                break;
            default:
                exit(0);
                break;
        }
    }

    char buffer[1024] ;
    char *record,*line;
    int i=0,j=0;
    char* accountArray[20][10];
    FILE *fstream = fopen("../Bank/Account.csv","r");
    if(fstream == NULL)
    {
        printf("\n file opening failed ");
        return -1 ;
    }
    while((line=fgets(buffer,sizeof(buffer),fstream))!=NULL)
    {
        j = 0;
        record = strtok(line,";");
        while(record != NULL)
        {
            accountArray[i][j] = record ;
            record = strtok(NULL,";");
            j++;
        }
        i++ ;
    }
    fclose(fstream);

    return 0 ;
}