#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"


// Return an array with all the conection with the point ask
char ***current_point(struct programe_t *programe, char letter)
{
    char ***current_point = malloc(sizeof(char *) * (100) + 1);
    int j = 0;
    int k = 0;

    for (int i = 0; programe->data[i] != NULL; i++)
    {
        if (programe->data[i][0][0] == letter)
        {
            current_point[k] = malloc(sizeof(char *) * 6);
            for (j = 0; programe->data[k][j] != NULL; j++)
            {
                current_point[k][j] = malloc(sizeof(char) * 100);
                strcpy(current_point[k][j], programe->data[i][j]);
            }
            current_point[k][j + 1] = NULL;
            k++;
        }
    }
    return current_point;
}

//Put the cost in the dist array
void is_number(struct programe_t *programe, char point, char cost)
{
    for (int i = 0; programe->dist[i] != NULL; i++)
    {
        if (programe->dist[i][0] == point)
        {
            // DEBUG print for the cost point and cost previous cost
            // printf("++>%c cost = %c point = %c\n", programe->dist[i][1], cost, point);
            if (programe->dist[i][1] > cost)
            {
                programe->dist[i][1] = cost;
                return;
            }
            programe->dist[i][1] = cost;
        }
    }
}

// Function for change the current point to the next point
void changecurentpoint(struct programe_t *programe)
{
    int tempo = programe->curent_data[0][2][0];
    int index = 0;
    int step = 0;
    int step2 = 0;

    for (int i = 0; programe->curent_data[i] != NULL; i++)
    {
        if (programe->curent_data[i][2][0] < tempo)
        {
            tempo = programe->curent_data[i][2][0];
            index = i;
        }
    }
    programe->curentLetter = programe->curent_data[index][1][0];
    programe->curentCost += atoi(programe->curent_data[index][2]);

    // DEBUG for print curent cost and letter
    printf("Choosing %c ", programe->curentLetter);
    printf("for an actual coast of %d\n",  programe->curentCost);
}

// Function for set the dist array
void set_distArray(struct programe_t *programe)
{
    programe->dist = malloc(sizeof(char *) * 100);
    char letter = 'A';
    int i = 0;
    for (i = 0; i < programe->nbPoints; i++)
    {
        programe->dist[i] = malloc(sizeof(char) * 4);
        programe->dist[i][0] = letter;
        letter++;
    }
    programe->dist[i] = NULL;
}