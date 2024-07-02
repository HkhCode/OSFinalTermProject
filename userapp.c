// user/hello.c
#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
    int x = 0;

    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < 10; k++) {
                x += 1;
            }
        }
    }

    printf(1, "The value of x is: %d\n", x);
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