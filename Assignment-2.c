#include <stdio.h>

void input(int rows, int cols, int sparse[10][10]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &sparse[i][j]);
        }
    }
}

void display(int rows, int cols, int matrix[10][10]) {
    printf("Matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void compact(int rows, int cols, int sparse[10][10], int cmatrix[10][10]) {
    int k = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (sparse[i][j] != 0) {
                cmatrix[k][0] = i;
                cmatrix[k][1] = j;
                cmatrix[k][2] = sparse[i][j];
                k++;
            }
        }
    }

    cmatrix[0][0] = rows;
    cmatrix[0][1] = cols;
    cmatrix[0][2] = k - 1;
}


void simple_t(int cmatrix[10][10], int transpose[10][10]) {
    int numValues = cmatrix[0][2];
    int numCols = cmatrix[0][1];
    
    
    transpose[0][0] = cmatrix[0][1]; 
    transpose[0][1] = cmatrix[0][0]; 
    transpose[0][2] = numValues;    
    
    int k = 1;
    
    for (int col = 0; col < numCols; col++) {
        for (int i = 1; i <= numValues; i++) {
            if (cmatrix[i][1] == col) {
                transpose[k][0] = cmatrix[i][1]; 
                transpose[k][1] = cmatrix[i][0]; 
                transpose[k][2] = cmatrix[i][2]; 
                k++;
            }
        }
    }
}
void fast_t(int cmatrix[10][10], int transpose[10][10]) {
    int numRows = cmatrix[0][0];
    int numCols = cmatrix[0][1];
    int numValues = cmatrix[0][2];

    transpose[0][0] = numCols;
    transpose[0][1] = numRows;
    transpose[0][2] = numValues;

    int term_count[10] = {0};   
    int starting_pos[10] = {0}; 

    
    for (int i = 1; i <= numValues; i++) {
        term_count[cmatrix[i][1]]++;
    }

    
    starting_pos[0] = 1;
    for (int i = 1; i < numCols; i++) {
        starting_pos[i] = starting_pos[i - 1] + term_count[i - 1];
    }

  
    for (int i = 1; i <= numValues; i++) {
        int col_index = cmatrix[i][1];
        int target_pos = starting_pos[col_index];

        transpose[target_pos][0] = cmatrix[i][1]; 
        transpose[target_pos][1] = cmatrix[i][0]; 
        transpose[target_pos][2] = cmatrix[i][2]; 

        starting_pos[col_index]++; 
    }
}
int main() {
    int rows, cols;
    int sparse[10][10];
    int cmatrix[10][10];
    int transpose[10][10];

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("\nInput Sparse Matrix:\n");
    input(rows, cols, sparse);

    printf("\nOriginal Matrix:\n");
    display(rows, cols, sparse);

    compact(rows, cols, sparse, cmatrix);

    printf("\nCompact Matrix:\n");
    display(cmatrix[0][2] + 1, 3, cmatrix);
    
   
    simple_t(cmatrix, transpose);
    
    printf("\nTransposed Compact Matrix:\n");
    display(transpose[0][2] + 1, 3, transpose);

    return 0;
}
