#include <iostream>
#include <pthread.h> 
#include <unistd.h> 

using std::cout;
using std::dec;
using std::endl;

#define NLOOP 10 //constant value
int counter = 0;
void* doit(void*);
int main()
{
  pthread_t tidA, tidB;  
  pthread_create(&tidA, NULL, doit, NULL);
  pthread_create(&tidB, NULL, doit, NULL);
  pthread_join(tidA, NULL);
  pthread_join(tidB, NULL);
  exit(0);
}

void* doit(void* vprt)
{
  int i, val;
  for(i = 0 ; i < NLOOP ; i++)
  {
    val = counter;
    cout<<"Thread = " <<pthread_self();
    cout<<"Counter = " <<dec <<counter <<endl;
    sleep(2);
    counter = val + 1;
  }
  return(NULL);
}
