#include <pthread.h>
#include <stdio.h>

void *printmsg(void *arg) {
    printf("%s\n", (char*)arg);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;
    const char* msg1 = "Child thread 1";
    const char* msg2 = "Child thread 2";
    const char* msg3 = "Child thread 3";

    if(pthread_create(&thread1, NULL, printmsg, (void*)msg1)!=0) {
        printf("Can't create thread\n");
    }
    if(pthread_create(&thread2, NULL, printmsg, (void*)msg2)!=0) {
        printf("Can't create thread\n");
    }

    if(pthread_create(&thread3, NULL, printmsg, (void*)msg3)!=0) {
        printf("Can't create thread\n");
    }

    //pthread_join(thread1, NULL);
    //pthread_join(thread2, NULL);
    //pthread_join(thread3, NULL);

    printf("Parent thread\n");


    pthread_exit(NULL);
}