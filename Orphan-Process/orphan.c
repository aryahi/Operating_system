# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int main( int argc, char *argv[])
{
  int pid, i, s;
  pid = fork();
  if(pid == 0)
  {
		int ppid = getppid();
		printf("\nI am the child(%d) of %s(%d)\n",getpid(),argv[0],getppid());	
		/*
		On newer versions of Linux, the parent process of orphaned children is set to the nearest grandparent process 
		of the child that is marked as a subreaper, or process #1 if there is no grandparent subreaper process.
		Process may go to init/user
		*/
		while( getppid() != 1)
		{
			sleep(1);
      printf("parent = %d\n",getppid());
    }
	  printf("Parent(%d) process has terminated; Now SuperParent(%d) is taking care of me !! :-)",ppid,getppid());
		while(pid != 100)
		{
			if(pid%5 == 0)
				printf("I still got work to do\n");
			sleep(1);
			pid = pid + 2;
		}
  }
  else if(pid > 0)
  {
	  sleep(3);
//	i = wait(NULL);
		printf("\nI am parent process(%d) and I have a child: %d\n",getpid(),pid);
		sleep(2);
  }
  else
  {
		printf("\nError!! Can't create a process\n");
  }
    
  return 0;
}

