#include <stdio.h>
#include <string.h>

#define NOT_VISITED 0
#define VISITED 1

/* Reads the image from the open file fp into the two-dimensional array arr 
 * num_rows and num_cols specify the dimensions of arr
 */
void read_image(int num_rows, int num_cols, int arr[num_rows][num_cols], FILE *fp) {
    for (int i = 0; i < num_rows; i ++)
    {
        for (int j = 0; j < num_cols; j ++) 
        {
            fscanf(fp, "%d", &arr[i][j]);
        } 
    }   
}

/* Print to standard output the contents of the array arr */
void print_image(int num_rows, int num_cols, int arr[num_rows][num_cols]) {
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++) 
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/* Helper function for marking visited cells */
void checkCell(int i, int j, int num_rows, int num_cols, int arr[num_rows][num_cols], int visited[num_rows][num_cols]) {
    if (i < 0 || i >= num_rows) {
        return;
    }
    if (j < 0 || j >= num_cols) {
        return;
    }
    if (arr[i][j] == 0) {
        return;
    }
    if (visited[i][j] == VISITED) {
        return;
    }
    visited[i][j] = VISITED;

    checkCell(i - 1, j, num_rows, num_cols, arr, visited);
    checkCell(i + 1, j, num_rows, num_cols, arr, visited);
    checkCell(i, j - 1, num_rows, num_cols, arr, visited);
    checkCell(i, j + 1, num_rows, num_cols, arr, visited);

}
/* Count the number of cells in arr */
int count_cells(int num_rows, int num_cols, int arr[num_rows][num_cols]) {
    int visited [num_rows][num_cols];
    int count = 0;

    memset(visited, NOT_VISITED, num_rows * num_cols * sizeof(int));

    for (int i = 0; i < num_rows; i ++) {
        for (int j = 0; j < num_cols; j++) {
            if (arr[i][j] == 255 && visited[i][j] == NOT_VISITED) {
                checkCell(i, j, num_rows, num_cols, arr, visited);
                count ++;
            }
        }
    }
    return count;
}