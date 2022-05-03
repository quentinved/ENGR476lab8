#include <stdio.h>
#include <unistd.h>
#include "struct.h"

char ***open_file(char *filename, struct programe_t *programe)
{
    FILE *fp;
    char buffer[1024];
    int j = 0;
    int k = 0;
    char firstline[100];

    char ***data = malloc(sizeof(char *) * (100) + 1);

    for (int i = 0; i < 100; i++)
        data[i] = malloc(sizeof(char *) * 6);

    fp = fopen(filename, "r");
    fgets(firstline, 100, fp);
    programe->firstLetter = firstline[0];
    programe->lastLetter = firstline[2];
    programe->nbPoints = firstline[4] - '0';
    for (int i = 0; fscanf(fp, "%s", buffer) == 1; i++)
    {
        if (j == 3)
        {
            data[k][j + 1] = NULL;
            j = 0;
            k++;
        }
        data[k][j] = malloc(sizeof(char) * 100);
        strcpy(data[k][j], buffer);
        j++;
    }
    data[k + 1] = NULL;
    fclose(fp);

    // DEBUG for print data read in the file
    // for (int x = 0; data[x] != NULL; x++)
    // {
    //     for (int y = 0; data[x][y] != NULL; y++)
    //         printf("%s ", data[x][y]);
    //     printf("\n");
    // }
    return data;
}
