#include <stdio.h>

void accept(int a1[10][10], int r, int c);
void display(int a1[10][10], int r, int c);
void add(int a1[10][10], int a2[10][10], int r, int c);
void subtract(int a1[10][10], int a2[10][10], int r, int c);
void multiply(int a1[10][10], int a2[10][10], int r1, int c1, int c2);
void transpose(int a1[10][10],int r,int c);

int main() {
    int a1[10][10], a2[10][10];
    int r1, c1, r2, c2;
    
    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &r1, &c1);
    accept(a1, r1, c1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &r2, &c2);
    accept(a2, r2, c2);
    
    // Addition and Subtraction check
    if (r1 == r2 && c1 == c2) {        
        add(a1, a2, r1, c1);
        subtract(a1, a2, r1, c1);
    } else {
        printf("\nError: Matrices cannot be added or subtracted. Dimensions must be identical.\n");
    }
    
    // Separate Matrix Multiplication check
    if (c1 == r2) {
        multiply(a1, a2, r1, c1, c2);
    } else {
        printf("\nError: Matrices cannot be multiplied. Columns of Matrix 1 must equal Rows of Matrix 2.\n");
    }
    transpose(a1,r1,c1);
    return 0;
}

void accept(int a[10][10], int r, int c) {
    printf("Enter the elements of the matrix (%d x %d):\n", r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void transpose(int a[10][10], int r, int c) {
    int tp[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tp[j][i] = a[i][j];
        }
    }
    display(tp, c,r);
}

void add(int a1[10][10], int a2[10][10], int r, int c) {
    int sum[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            sum[i][j] = a1[i][j] + a2[i][j];
        }
    }
    printf("\nThe sum of the matrices is:\n");
    display(sum, r, c);
}

void subtract(int a1[10][10], int a2[10][10], int r, int c) {
    int diff[10][10];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            diff[i][j] = a1[i][j] - a2[i][j];
        }
    }
    printf("\nThe difference of the matrices is:\n");
    display(diff, r, c);
}



void multiply(int a1[10][10], int a2[10][10], int r1, int c1, int c2) {
    int mul[10][10];
    
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int m_sum = 0; 
            for (int k = 0; k < c1; k++) { 
                m_sum += a1[i][k] * a2[k][j];
            }
            mul[i][j] = m_sum;
        }
    }
    printf("\nThe product of the matrices is:\n");
    display(mul, r1, c2);
}
