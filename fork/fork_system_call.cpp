/* fork() implements parallel processing */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>

int main( int argc, char *argv[])
{
  int pid;
  pid = fork();
  if(pid == 0)
  {
	  printf("\nI am a child(%d) of %s(%d)\n",getpid(),argv[0],getppid());
  }
  else if(pid > 0)
  {
	  printf("\nI am a parent process(%d) and I have a child(%d)\n",getpid(),pid);
  }
  else
  {
	  printf("\nError!! Can't create a process\n");
  }
  printf("\nHi\n");
  return 0;
}
