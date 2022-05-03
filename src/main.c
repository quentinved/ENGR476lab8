#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "readfile.h"
#include "dijkstra.h"


// Main function
int main()
{
    struct programe_t prog;

    prog.data = open_file("map.txt", &prog);
    prog.curentLetter = prog.firstLetter;
    prog.curentCost = 0;

    set_distArray(&prog);
    for (int i = 0; prog.curentLetter != prog.lastLetter; i++)
    {
        prog.curent_data = current_point(&prog, prog.curentLetter);
        for (int v = 0; prog.curent_data[v] != NULL; v++)
            is_number(&prog, prog.curent_data[v][1][0], prog.curent_data[v][2][0]);
        // DEBUG print all the dist step
        // for (int j = 0; prog.dist[j] != NULL; j++) {
        //     printf("%s \n", prog.dist[j]);
        // }
        changecurentpoint(&prog);
    }
    return 0;
}