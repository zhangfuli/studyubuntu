#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
sem_t sem;
void *thread_function(void *arg);
void sendsem(){    
    sem_post(&sem);
}   
char message[] = "Hello World";

int main(){    
   int res;    
   pthread_t a_thread;    
   void *thread_result;    
   sem_init(&sem ,0,0);    
   signal(SIGINT,sendsem);       
   res = pthread_create(&a_thread, NULL, 
            thread_function, (void *)message);   
 if (res !=0)    {       
      perror("Thread creation failed");       
      exit(EXIT_FAILURE);    }    
 printf("Waiting for SEM from SIGNAL...\n");    
 res = pthread_join(a_thread, &thread_result);    
 if (res !=0)
{       
    perror("Thread join failed");       
    exit(EXIT_FAILURE);    }    
    printf("Thread joined\n");    
    exit(EXIT_FAILURE);
}
void *thread_function(void *arg)
{ sem_wait(&sem);    
  printf("thread_function is running. Argument was %s\n", (char *)arg);    
  sleep(1);    
  pthread_exit(NULL);
}

