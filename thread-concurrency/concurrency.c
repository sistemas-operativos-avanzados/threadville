/*
File name: concurrency.c 
Description: Created to handle threads concurrency
Author: Oscar Rodríguez Arroyo

References
    http://www.thegeekstuff.com/2012/04/create-threads-in-linux/?utm_source=feedburner
    http://stackoverflow.com/questions/7978152/concurrency-in-threads


Compilation
    gcc -pthread -o concurrency concurrency.c

*/
#include <pthread.h>
#include <stdio.h>


void * func ( void * arg) 
{ 
    printf("printing from thread %d\n",(int) arg); 
    return NULL;
}

int main(void) 
{ 
    pthread_t threads[5];
    int i;

    /*
    Se crean las estructuras que los threads van a ejecutar

    func debe ser cambiado por la función a ejecutar

    (void*) i) debe ser cambiado por la estructura u objeto
    */

    for(i = 0; i<5; i++){
        pthread_create(&threads[i], NULL, func, (void*) i);
    }

    printf("Threads Created\n");
    
    for(i = 0; i < 5; i++){
        pthread_join(&threads[i], NULL);
        printf("printing from joined thread %d\n",i); 
    }

 return 0;
}