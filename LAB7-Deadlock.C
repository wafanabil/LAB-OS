#include <iostream>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <pthread.h>

using std::cout;
using std::dec;
using std::endl;

pthread_mutex_t Chopstick_mutex [5] = {PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER, 
                                       PTHREAD_MUTEX_INITIALIZER, PTHREAD_MUTEX_INITIALIZER};

void* doit(void*);

int main()
{
  pthread_t Lawyer[5];
  int i;
  cout<<dec;
  
  for(i==0 ; i<5 ; i++)
    pthread_create(&Lawyer[i], NULL, doit, (void *)(int)i);
  
  for(i=0 ; i<5 ; i++)
    pthread_join(Lawyer[i], NULL);
  
  for(i=0 ; i<5 ; i++)
    pthread_mutex_destroy(&Chopstick_mutex[i]);
  
  exit(0);
}

void *doit(void *vptr)
{
  pthread_mutex_lock(&Chopstick_mutex[(int)vptr]);
  pthread_mutex_lock(&Chopstick_mutex[((int)vptr+1)%5]);
  
  cout<<"Lawyer " <<(int)vptr <<" got chopstick number ";
  cout<<(int)vptr <<endl;
  
  sleep(1);
  
  cout<<"Lawyer " <<(int)vptr <<" got chopstick number ";
  cout<<((int)vptr+1)%5 <<endl;
  
  sleep(2);
  
  pthread_mutex_unlock(&Chopstick_mutex[(int)vptr]);
  pthread_mutex_unlock(&Chopstick_mutex[((int)vptr+1)%5]);
  
  return(NULL);
}
