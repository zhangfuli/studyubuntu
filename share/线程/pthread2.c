#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int count=0;
void *thread_function(void *arg);

char message1[] = "I'm thread1";
char message2[] = "I'm thread2";
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
    printf("count is %d\n",count);
    exit(EXIT_FAILURE);
}

void *thread_function(void *arg)
{
	while(1)
	{
    	printf("thread_function is running. Argument was %s\n", (char *)arg);
    	count++; 
    	sleep(1);
	}
    	pthread_exit(NULL);
}

