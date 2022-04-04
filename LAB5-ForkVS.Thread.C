#include <iostream>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h> 
#include <pthread.h>

using std::cout;
using std::endl;

int counter = 0;
void* doit(void*);

int main()
{
  pthread_t tid;
  pid_t pid, cpid;
  int status;
  pthread_create(&tid, NULL, doit, NULL);
  sleep(2);
  pid = fork();
  if(pid < 0)
     {
       cout<<"First Fork Failed\n";
       exit(-1);
     }//end if
  else if(pid == 0)
     {
       sleep(2);
       counter++;
       cout<<"Child Counter = " <<counter <<endl;
     }//end else if
  else
     cpid = wait(&status);
     pthread_join(tid, NULL);
     exit(0);
}
     
void* doit(void* vprt)
{
  sleep(1)
  cout<<"Thread First Counter = " <<++counter <<endle;
  sleep(5)
  cout<<"Thread First Counter = " <<++counter <<endle;
  return NULL;
}
