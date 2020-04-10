#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>
#include<sys/ipc.h>

#define MAX 500

int C[4][5];

struct yay {
    int n;
};

void *runner (void *ptr) {

    struct yay* data;
    data = (struct yay*) ptr;

    int n = data->n;
    
    n = ((n * (n + 1)) / 2);
    printf("%d\t", n);

}

int main (int argc, char **argv) 
{
    int *value;
    key_t key = 1234;
    int shmid = shmget(key, sizeof(int)*4*5, IPC_CREAT | 0666);
    value = (int *)shmat(shmid, NULL, 0);

    printf("MATRIKS PERKALIAN\n");

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 5; j++){
            printf("%d\t", value[i*5 + j]);
            C[i][j] = value[i*5 + j];
        }
        printf("\n");
    }

    printf("\nMATRIKS PENAMBAHAN\n");

    pthread_t nay[20];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++){

            struct yay* data = (struct yay*)malloc(sizeof(struct yay));
            data->n = C[i][j];

            pthread_create(&(nay[i * 5 + j]), NULL, runner, data);
            pthread_join(nay[i * 5 + j], NULL);
        }
        printf("\n");
    }

    shmdt(value);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}