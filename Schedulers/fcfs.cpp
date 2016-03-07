
// First Come First Serve


# include <iostream>
# include <fstream>
# include <iomanip>
using namespace std;

struct process
{
   char name;
   int at, st;
   float wta,  wt, ta;
   int time1;
}p[100];


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

int main()
{
   int i, sum_st = 0;
   char c;
   float avg_wt; 
   int time;
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
cout<<"n = "<<n<<endl;
cout<<"sum_st = "<<sum_st<<endl;
   enqueue(0); 

   p[0].time1 = 0;

   out<<setw(5)<<"Time"<<"    "<<setw(5)<<"Name"<<"    "<<setw(5)<<"ta"<<"    "<<setw(5)<<"wta"<<"    "<<setw(5)<<"wt"<<"    "<<setw(5)<<endl;

   out<<setw(5)<<"0"<<"    "<<setw(5)<<"-"<<"    "<<setw(5)<<"-"<<"    "<<setw(5)<<"-"<<"    "<<setw(5)<<"-"<<"    "<<setw(5)<<endl;

   for(time = p[0].at; time < sum_st; )       
   {   
	  i = dequeue();

	  p[i+1].time1 = p[i].st + p[i].time1;
	  p[i].wt = p[i].time1 - p[i].at;
	  p[i].ta = p[i].wt + p[i].st;
	  p[i].wta = (p[i].ta/p[i].st); 
      
	  out << setw(5) << p[i+1].time1 <<"    "<< setw(5) << i+1 <<"    "<< setw(5) << p[i].ta <<"    "<< setw(5) << p[i].wta <<"    "<< setw(5) << p[i].wt <<"    "<< setw(5) <<endl; 

      //out<<i+1<<" "<<p[i+1].time1<<endl; 

	  time += p[i].st;
	  enqueue(i+1);  
   }
   return 0;	
}
