#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PRINT_OPTION "-p"

void read_image(int num_rows, int num_cols,
                int arr[num_rows][num_cols], FILE *fp);

void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]);

int count_cells(int num_rows, int num_cols, int arr[num_rows][num_cols]);

int main(int argc, char **argv)
{
   if (argc == 1 || argc > 3 || (argc == 3 && strcmp(argv[2], PRINT_OPTION) != 0)) {
        fprintf(stderr, "Usage: count_cells <imagefile.txt> [-p]\n");
        return 1;
    }
    char * filename = argv[1];
    bool need_print_image = argc == 3;
    FILE * fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot find the file with name = %s\n", filename);
        return 2;
    }
    int num_rows, num_cols;
    fscanf(fp, "%d %d", &num_rows, &num_cols);

    int arr[num_rows][num_cols];
    read_image(num_rows, num_cols, arr, fp);
    
    int cell_count = count_cells(num_rows, num_cols, arr);
    printf("Number of Cells is %d\n", cell_count);
    
    if (need_print_image) {
        print_image(num_rows, num_cols, arr);
    }

    return 0;
}