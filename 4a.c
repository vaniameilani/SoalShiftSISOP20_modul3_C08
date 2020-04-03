#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int A[4][2] = {{1,2},{3,4},{5,6},{7,8}};
int B[2][5] = {{9,10,11,12,13},{14,15,16,17,18}};
int C[4][5];

// structer for passing data to threads
struct yay
{
    int i; 
    int j;
};

void *runner(void *ptr) //threads
{
    // casting parameter to struct yay pointer
    struct yay *data=ptr;
    int i, sum=0;

    for (i=0; i<2; i++)
    {
        sum += A[data->i][i] * B[i][data->j];
    }
    C[data->i][data->j] = sum;
    pthread_exit(0);
}

int main (int argc, char **argv)
{
    int i, j;
    int counter=0;  //counter of thread

    pthread_t nay[20]; //baris A x kolom B
    for (i=0; i<4; i++)
    {
        for (j=0; j<5; j++)
        {
            struct yay *data = (struct yay*) malloc(sizeof(struct yay));
            data->i = i;
            data->j = j;

            pthread_create(&nay[counter],NULL,runner,data); //create thread passing it data as a parameter
            pthread_join(nay[counter],NULL);
            counter++;
        }
    }

    // waiting for threads to complete
    for (i=0; i<20; i++)
    {
        pthread_join(nay[i], NULL);
    }
    for (i=0; i<4; i++)
    {
        for (j=0; j<5; j++)
        {
            printf ("%d\t", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}