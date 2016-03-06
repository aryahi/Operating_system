# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

//	Zombie and no zombie process

int main( int argc, char *argv[])
{
  int pid, s;
  pid = fork();
  if(pid == 0)
  {
    sleep(40);
		printf("\nI am the child(%d) of %s(%d)\n",getpid(),argv[0],getppid());	
		printf("\nMy work is done, I am terminating\n");
  }
  else if(pid > 0)
  {
		sleep(80);  //Comment out this line to create a zombie process
		int i = wait(&s);
		//sleep(50);
		printf("\nI was the parent process(%d) of process(%d) and Status: %d\n",getpid(),i,WEXITSTATUS(s));
		//sleep(20);
  }
  else
  {
		printf("\nError!! Can't create a process\n");
  }
  //return 257; 	
	exit(11);
   
}
