#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int count=0;
pthread_mutex_t count_lock = PTHREAD_MUTEX_INITIALIZER;
void *thread_function(void *arg);

char *message1="I'm thread 1";
char *message2="I'm thread 2";
int main()
{
    int res;
    pthread_t a_thread;
    pthread_t b_thread;
    void *thread_result;
   
    res = pthread_create(&a_thread, NULL, thread_function, 
                                                  (void *)message1);
    if (res !=0)
    {
       perror("Thread creation failed");
       exit(EXIT_FAILURE);
    }
    res = pthread_create(&b_thread, NULL, thread_function, 
                                                  (void *)message2);
    if (res !=0)
    {
       perror("Thread creation failed");
       exit(EXIT_FAILURE);
    }

    printf("Waiting for thread to finish...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res !=0)
    {
       perror("Thread join failed");
       exit(EXIT_FAILURE);
    }
     
    printf("Waiting for thread to finish...\n");
    res = pthread_join(b_thread, &thread_result);
    if (res !=0)
    {
       perror("Thread join failed");
       exit(EXIT_FAILURE);
    }
    
    printf("Thread joined\n");
    exit(EXIT_FAILURE);
}

void *thread_function(void *arg)
{
    printf("thread_function is running. Argument was %s\n", (char *)arg);
    pthread_mutex_lock(&count_lock); 
    count++;
    sleep(1);
    printf("count is %d\n",count);
    pthread_mutex_unlock(&count_lock); 
    pthread_exit(NULL);
}

