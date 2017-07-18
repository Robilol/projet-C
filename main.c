#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
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