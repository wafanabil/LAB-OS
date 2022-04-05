#include <iostream>
#include <pthread.h> 
#include <unistd.h> 

using std::cout;
using std::dec;
using std::endl;

#define NLOOP 10 //constant value

pthread_mutex_t Count_mutex = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
void* doit(void*);
int main()
{
  pthread_t tidA, tidB;  
  pthread_create(&tidA, NULL, doit, NULL);
  pthread_create(&tidB, NULL, doit, NULL);
  pthread_join(tidA, NULL);
  pthread_join(tidB, NULL);
  
  pthread_mutex_destroy(&Count_mutex);
  exit(0);
}

void* doit(void* vprt)
{
  int i, val;
  for(i = 0 ; i < NLOOP ; i++)
  {
    pthread_mutex_lock(&Count_mutex);
    val = counter;
    cout<<pthread_self() <<" " <<dec <<val+1 <<endl;
    sleep(1);
    counter = val + 1;
    pthread_mutex_unlock(&Count_mutex);
  }
  return(NULL);
}
  
