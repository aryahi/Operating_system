# include <stdio.h>

int main()
{
   fork();
   fork();
   fork();
   
   return 0;
   //Total 8 processes created 
   //Processes are created in the order of 2 raise to power n
   //n = Number of fork() used
}
