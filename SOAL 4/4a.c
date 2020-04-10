#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>

int A[4][2] = {{1,3},{5,7},{10,6},{7,8}};
int B[2][5] = {{9,10,11,12,13},{14,1,6,4,18}};
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
    int counter=0;  
    key_t key = 1234;
    int *value;
    int shmid = shmget(key, sizeof(int)*4*5, IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

    pthread_t nay[20]; //baris A x kolom B , menampung jumlah thread
    for (i=0; i<4; i++)
    {
        for (j=0; j<5; j++)
        {
            struct yay *data = (struct yay*) malloc(sizeof(struct yay));
            data->i = i;
            data->j = j;

            pthread_create(&nay[counter],NULL,runner,data); //create thread passing it data as a parameter
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
            value[i*5 + j] = C[i][j];
            printf ("%d\t", value[i*5 + j]);
        }
        printf("\n");
    }

    sleep(20);
    shmdt(value);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
