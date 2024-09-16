// Importing the thread library
#include "pthread.h"

#include "stdio.h"


#include "unistd.h"

#include "string.h"

#define THREAD_COUNT 8

 int tickets[THREAD_COUNT];
 int choosing[THREAD_COUNT];

 int resource;

void lock(int thread)
{

// Before getting the ticket number
//"choosing" variable is set to be true
    choosing[thread] = 1;


    int max_ticket = 0;

// Finding Maximum ticket value among current threads
    for (int i = 0; i < THREAD_COUNT; ++i) {

        int ticket = tickets[i];
        max_ticket = ticket > max_ticket ? ticket : max_ticket;
    }

// Allotting a new ticket value as MAXIMUM + 1
    tickets[thread] = max_ticket + 1;

    //;
    choosing[thread] = 0;
    //;

// The ENTRY Section starts from here
    for (int other = 0; other < THREAD_COUNT; ++other) {

// Applying the bakery algorithm conditions
        while (choosing[other]) {
        }

      //  ;

        while (tickets[other] != 0 && (tickets[other]
                                       < tickets[thread]
                                       || (tickets[other]
                                           == tickets[thread]
                                           && other < thread))) {
        }
    }
}

// EXIT Section
void unlock(int thread)
{

    //;
    tickets[thread] = 0;
}

// The CRITICAL Section
void use_resource(int thread)
{
    resource = thread;
    printf("%d using resource...\n", thread);

    //;
    sleep(2);
    resource = 0;
}

// A simplified function to show the implementation
void* thread_body(void* arg)
{

    long thread = (long)arg;
    lock(thread);
    use_resource(thread);
    unlock(thread);
    return NULL;
}

int main(int argc, char** argv)
{

    memset((void*)tickets, 0, sizeof(tickets));
    memset((void*)choosing, 0, sizeof(choosing));
    resource = 0;

// Declaring the thread variables
    pthread_t threads[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; ++i) {


        pthread_create(&threads[i], NULL, &thread_body, (void*)((long)i));
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {

        pthread_join(threads[i], NULL);
    }

    return 0;
} 
