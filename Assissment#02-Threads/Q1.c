//Write a program using Threads to perform a Matrix addition. You have to create
//threads equal to the number of rows in Matrix, each thread should perform single
//element addition of two matrices in parallel.



#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

#define N 3 		//number of rows of matrix A
#define M 3 		//number of columns of matrix A and rows of matrix B
#define L 3 		//number of columns of matrix B
#define NTHREADS N 	//number of threads



//create matrices
int matrixA[N][M]; // matrix A
int matrixB[M][L]; // matrix B
int matrixC[N][L]; // matrix C (= A+B)

//create N threads
pthread_t threads[NTHREADS];

//struct to hold i value
typedef struct {
    int num;
} i_holder;

// function to add matrices 
void *multiply_matrices(void *arg) {
    // get x passed during thread creation
    i_holder *x = (i_holder *) arg;
    for (int i = 0; i < M; i++) { // rows
        for (int j = 0; j < L; j++) { // columns
            //adding 
            matrixC[(x)->num][j] = matrixA[(x)->num][i] + matrixB[i][j];
        }
    }
    //return null pointer
    return NULL;
}

// main function
int main() {
    
    // fill matrix A with random integer values
    printf("******\n");
    printf("*** Matrix A ***\n");
    printf("******\n");
    for (int i = 0; i < N; i++) { // each row
        for (int j = 0; j < M; j++) { // each column
            matrixA[i][j] = 10; // get a random value and store at i,j in matrix
            printf("%d\t", matrixA[i][j]); // print the value at i, j
        }
        printf("\n");
    }
    printf("******\n\n");

    // fill matrix B with random integer values
    printf("******\n");
    printf("*** Matrix B ***\n");
    printf("******\n");
    for (int i = 0; i < M; i++) { // each row
        for (int j = 0; j < L; j++) { // each column
            matrixB[i][j] = 10; // get a random value and store at i,j in matrix
            printf("%d\t", matrixB[i][j]); // print the value at i, j
        }
        printf("\n");
    }
    printf("******\n\n");

    // now make threads
    for (int i = 0; i < NTHREADS; i++) {
        // for each ith thread
        i_holder *x;
        // allocate memory
        x = malloc(sizeof(i_holder));
        (*x).num = i; // store i value for passing to function
        // create ith thread
        pthread_create(&threads[i], NULL, multiply_matrices, (void *) x);
    }

    // join all threads and wait for the threads to finish task
    for (int i = 0; i < NTHREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    //display the result matrix C
    printf("******\n");
    printf("*** Matrix C ***\n");
    printf("******\n");
    for (int i = 0; i < N; i++) { // each row
        for (int j = 0; j < L; j++) // each column
            printf("%d\t\t", matrixC[i][j]); // print the (i, j)th element
        printf("\n");
    }

    return 0;
}
