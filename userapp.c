// user/matrix_mul.c
#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"
#define SIZE 5

// void multiply(int a[SIZE][SIZE], int b[SIZE][SIZE], int result[SIZE][SIZE], int row)
// {
//     int x = 0;
//     for (int j = 0; j < SIZE; j++)
//     {
//         result[row][j] = 0;
//         for (int k = 0; k < SIZE; k++)
//         {
//             for (int i = 0; i < 1000; i++)
//             {
//                 for (int j = 0; j < 1000; j++)
//                 {
//                     x = 10000 * 10000;
//                 }
//                 x += 1;
//             }
//             result[row][j] += a[row][k] * b[k][j];
//         }
//     }
// }

int main(void)
{

    int sched_data = get_sched_data();
    // int a[SIZE][SIZE] = {
    //     {101, 102, 103, 114, 114},
    //     {104, 105, 106, 102, 105},
    //     {107, 108, 109, 106, 108},
    //     {104, 105, 106, 102, 105},
    //     {107, 108, 109, 106, 108}};

    // int b[SIZE][SIZE] = {
    //     {119, 118, 711, 500, 200},
    //     {116, 115, 114, 324, 455},
    //     {116, 112, 111, 123, 234},
    //     {115, 115, 114, 324, 455},
    //     {113, 112, 111, 123, 234},
    // };

    // int result[SIZE][SIZE];

    // for (int i = 0; i < SIZE; i++)
    // {
    //     if (fork() == 0)
    //     {
    //         multiply(a, b, result, i);
    //         printf(1, "Row %d computed by process %d: ", i, getpid());
    //         for (int j = 0; j < SIZE; j++)
    //         {
    //             printf(1, "%d ", result[i][j]);
    //         }
    //         printf(1, "\n");
    //         exit();
    //     }
    // }

    // for (int i = 0; i < SIZE; i++)
    // {
    //     wait();
    // }
    // printf(1, "%d\n", sched_data);
    int pid;
    int x = 0;
    for (int k = 0; k < 100000; k++)
    {
        /* code */
        pid = fork();
        if (pid == 0)
        {
            for (int i = 0; i < 2147483640; i++)
            {
                for (int j = 0; j < 2147483640; j++)
                {
                    x = 10000 * 10000;
                }
                x += 1;
            }
            exit();
        }
        
    }
    printf(1 , "%d \n", sched_data);
    sched_data +=1;
    for (int i = 0; i < 100000; i++)
    {
        wait();
    }
    exit();
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include<sys/wait.h>
// #include<semaphore.h>
// #include<sys/ipc.h>
// #include<sys/shm.h>

// #define SHM_KEY 4660

// sem_t write_sem;

// int main()
// {
//     sem_init(&write_sem,0,1);
//     int a_row,a_column,i;
//     int b_row,b_column,j;

//     printf("matrix 'a' row size:");
//     scanf("%d",&a_row);
//     printf("matrix 'a' colmn size:");
//     scanf("%d",&a_column);
//     int matrix_a[a_row][a_column];
//     printf("enter the matrix 'a':\n");
//     for(i=0;i<a_row;i++){
//         for(j=0;j<a_column;j++){
//             scanf("%d",&matrix_a[i][j]);
//         }
//     }

//     printf("matrix 'b' row size:");
//     scanf("%d",&b_row);
//     printf("matrix 'b' colmn size:");
//     scanf("%d",&b_column);
//     int matrix_b[b_row][b_column];
//     printf("enter the matrix 'b':\n");
//     for(i=0;i<b_row;i++){
//         for(j=0;j<b_column;j++){
//             scanf("%d",&matrix_b[i][j]);
//         }
//     }

//     int c_row=a_row,c_column=b_column;

//     int shmid = shmget(SHM_KEY,sizeof(int)*c_row*c_column,0644|IPC_CREAT);
//     if (shmid == -1) {
//       perror("shared memory error");
//       return 1;
//    }

//     int pid=1;
//     for(i=0;i<(c_row*c_column);i++){
//         pid=fork();
//         if(pid==0){
//             int result=0,i_p,row,column;
//             row=i/c_column;
//             column=i%c_column;
//             for(i_p=0;i_p<a_column;i_p++){
//                 result+=matrix_a[row][i_p]*matrix_b[i_p][column];
//             }
//             sem_wait(&write_sem);
//             int* matrix_c = shmat(shmid, NULL, 0);
//             if (matrix_c == (void *) -1) {
//                 perror("Shared memory attach error");
//                 sem_post(&write_sem);
//                 return 1;
//             }
//             matrix_c[i]=result;
//             if(shmdt(matrix_c)==-1) {
//                 perror("shmdt error");
//                 sem_post(&write_sem);
//                 return 1;
//             }
//             sem_post(&write_sem);
//             break;
//         }

//     }
//     if(pid!=0){
//         wait(NULL);

//         int* matrix_c = shmat(shmid, NULL, 0);
//         if (matrix_c == (void *) -1) {
//             perror("Shared memory attach error");
//             return 1;
//         }

//         for(i=0;i<c_row*c_column;i++){
//             if(i%(c_column)==0) printf("\n");
//             printf("%d ",matrix_c[i]);
//         }
//         printf("\n");
//         if(shmdt(matrix_c)==-1) {
//             perror("shmdt error");
//             return 1;
//         }
//         shmctl(shmid,0,NULL);
//         return 0;
//     }

// }