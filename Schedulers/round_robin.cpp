

# include <iostream>
# include <fstream>
# include <iomanip>

using namespace std;

struct process
{
   char name;
   int at,st,wt,ta,rt;
   int completed;
   float ntt;
}p[100];

//int n;

//QUEUE
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

int isInQueue(int i)
{
   int k;
   for(k = front; k <= rear; k++)
   {
	  if(q[k] == i)
	     return 1;
   }
   return 0;
}


int main()
{
   int i, j, time = 0, sum_bt = 0, tq;
   char c;
   float avgwt = 0;

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
      p[i].rt = p[i].st;
      p[i].completed = 0;
      sum_bt += p[i].st;
   }

   for(i = 0; i < n; i++)
   {
	  cout<<p[i].name<<"   "<<p[i].at<<"   "<<p[i].st<<endl;
   }

   cout<<"Enter the time quantum(time slice):";
   cin>>tq;

   //sortByArrival(n);

   enqueue(0);          // FIRST PROCESS IN THE QUEUE

   cout<<"Process execution order:"<<endl;

   for(time = p[0].at; time<sum_bt; )       
   {   
	  i = dequeue();

	  if(p[i].rt <= tq)
	  {                          
                      
	  	 time += p[i].rt;
		 p[i].rt = 0;
		 p[i].completed = 1;         
         cout<<p[i].name;
         p[i].wt = time-p[i].at - p[i].st;
         p[i].ta = time - p[i].at;      
         p[i].ntt= ((float)p[i].ta / p[i].st);
            
		 for(j = 0; j < n; j++)              
         {
            if(p[j].at <= time && p[j].completed != 1 && isInQueue(j) != 1)
            {
               enqueue(j);
            }
         }
      }
      else       
      {
    	 time += tq;
    	 p[i].rt -= tq;
    	 cout<<p[i].name;
    	 for(j = 0; j < n; j++)   
         {
            if(p[j].at <= time && p[j].completed != 1 && i != j && isInQueue(j) != 1)
            {
               enqueue(j);
          	}
         }
            enqueue(i);   
      }  
   }

   //out<<setw(5)<<"Name"<<"    "<<setw(5)<<"at"<<"    "<<setw(5)<<"st"<<"    "<<setw(5)<<"wt"<<"    "<<setw(5)<<"ta"<<"    "<<setw(5)<<"ntt"<<endl;

   for(i = 0; i < n; i++)
   {
	  avgwt += p[i].wt;
	  out<<setw(5)<<p[i].name<<"    "<<setw(5)<<p[i].at<<"    "<<setw(5)<<p[i].st<<"    "<<setw(5)<<p[i].wt<<"    "<<setw(5)<<p[i].ta<<"    "<<setw(5)<<p[i].ntt<<endl;

	  //out<<setw(5)<<i+1<<"    "<<setw(5)<<p[i].ta<<endl;
   }

   printf("\nAverage waiting time:%f\n",avgwt/n);

   return 0;	
}
