#include <iostream>
#include <stdlib.h> //exit
#include <unistd.h> //fork()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()

using std::cout;

int main()
{
  pid_t pid1, pid2, cpid;
  int i, j, a, status;
  a = 0;
  pid1 = fork();
  if (pid1 < 0)
  {
    cout<<"First Fork Failed\n";
    exit(-1);
  }//end if
  else if(pid1 == 0)
  {
    for(i = 0 ; i<10 ; i++)
    {
      a++;
      cout<<"Chiled1: a = " <<a<< "\n";
      sleep(1);
    }//end for
  }//end else if
  else
  {
    pid2 = fork();
    if(pid2 < 0)
    {
      cout<<"Secound Fork Failed\n";
      exit(-1);
    }//end if
    else if(pid2 == 0)
    {
      for(j = 0 ; j<10 ; j++)
      {
        a++;
        cout<<"Chiled2: a = " <<a<< "\n";
        sleep(1);
      }//end for
     }//end else if
     else
     {
      cpid = wait($status);
      cout<<"Process trmiinate \n";
      exit(0);
     }//end else
    }//end else
}
