#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <zconf.h>

using namespace std;
sem_t access_seats=0;
//sem_t barberready=0;
sem_t customer_ready=0;
int waiting;
int seats;
void setSeats(int number)
{
    seats=number;
}
void *barber( void *args)
{
    while( true)
    {
        sem_wait(&customer_ready);
        cout<<"customer is ready";
        sem_wait(&access_seats);
        cout<<"mutex given barber";
        cout<<"Barber is cutting hair" << waiting;
        waiting--;
        sem_post(&access_seats);
        sleep(3);
    }


}

void *customer( void *args) {
    while(true)
    {
        sem_wait(&access_seats);
        if (waiting < seats) {
            waiting++;
            cout<<waiting;
            cout<<"its customer";
            sem_post(&access_seats);
            cout<<"Customer changing ready ";
            sem_post(&customer_ready);
            cout<< "customer changing barber"<<endl;
        } else {
            sem_post(&access_seats);
        }
    }
}
int main() {
    cout << "How many seats do you want in waiting area";
    int num;
    cin >> num;
    setSeats(num);
    sem_init(&access_seats,0,1);
    sem_init(&customer_ready,0,0);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,customer,NULL);
    pthread_create(&t2,NULL,barber,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}