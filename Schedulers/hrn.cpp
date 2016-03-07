
// Highest Response Ratio Next


# include <iostream>
# include <fstream>
# include <iomanip>

using namespace std;

struct process
{
   char name;
   float at, st;
   float wta,  wt, ta;
   int time1;
   int complete;
}p[100];

float min23;

int q[100];  
int front = -1, rear =- 1;

void enqueue(int x)
{
   if(rear == 100)
	  cout<<"Queue Overflow";

   q[++rear] = x;

   if(front == -1)
	  front = 0;
}

int dequeue()
{
   if(front == -1)
	  cout<<"Queue Underflow";

   int temp = q[front];

   if(front == rear)
	  front = rear = -1;
   else
	  front++;
  
   return temp;
}

int main()
{
   int i, sum_st = 0;int j, k, min2;
   char c;
   float avg_wt; 
   float time;
   fstream in, out;
   in.open("/home/himani/OperatingSystem/input.txt");
   out.open("/home/himani/OperatingSystem/output.txt");

   int n;

   while(!in.eof())
   {
      in>>n;
      for(i = 0; i < n; i++)
  	     in>>p[i].at;
   	  for(i = 0; i < n; i++)
	     in>>p[i].st;
   }
   for(i = 0, c = 'A'; i < n; i++, c++)
   {
      p[i].name = c;
      sum_st += p[i].st;
   }
   for(i = 0; i < n; i++)
   {
	  cout<<p[i].name<<"   "<<p[i].at<<"   "<<p[i].st<<endl;
   }

   for(i = 0; i < n+1; i++)
	  enqueue(i);

   for(i = 0; i < n; i++)
	  p[q[i]].complete = 0;

 
   for(time = p[0].at; time < sum_st;)
   { 
 	  int min ;
	  min23 = -1;
      
      for(j = front; j < rear; j++ )
      {
	     if((p[q[j]].at == 0) && (p[q[j]].complete == 0))
	     {
	        min = j; 
	     }
	     if( (p[q[j]].complete == 0) && (p[q[j]].at != 0)&&  (p[j].at <= time) )
	     {
    	    if( (((time-p[j].at)/p[j].st)+1) >= min23)
		    {
	 	 	   min = j;
	 		   min23 = ((time-p[j].at)/p[j].st)+1;
       		}
  		 }
	  }
	  p[0].time1 = 0;
	     
	  p[q[min]].complete = -1;

	  time += p[min].st; 

	  out<<time<<" "<<min+1<<endl;
   }
   return 0;	
}
