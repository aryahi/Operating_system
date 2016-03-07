
#include<fstream>
#include<iostream>
#include<stdio.h>
using namespace std;

int queue[100001], front, rear, arr[100001], serv[100001], exit[100001];

void enqueue( int a )
{
   if( front == -1  && rear == -1 )
   {
      front = 0;
      rear = 0;
      queue[rear] = a;
   }
   else
   {
      queue[++rear] = a;
   }
}

int dequeue()
{
   if( front == -1 && rear == -1 )
      return -1;
   else if( front == rear )
   {
      int x = queue[front];
      front = -1;
      rear = -1;
      return x;
   }
   else
   {
      int idx = front;
      for( int i = front; i <= rear; i++ )
      {
         if( serv[queue[i]] < serv[queue[idx]] )
         {
            idx = i;
         }
      }
      int val = queue[idx];
      for( int i = idx; i < rear; i++ )
      {
         queue[i] = queue[i+1];
      }
      rear--;
      return val;
   }
}

int main()
{
   front = -1;
   rear = -1;
   int n;
   fstream o1, in1;
   o1.open("/home/himani/OS/opt.in"); 
   in1.open("/home/himani/OS/inp");
   while( !in1.eof() )
   {
      in1 >> n;
      for( int i = 0; i < n; i++ )
         in1 >> arr[i];
      for( int i = 0; i < n; i++ )
         in1 >> serv[i];
   }
  // cin >> n;
  // for( int i = 0; i < n; i++ )
  // {
  //    cin >> arr[i];
  // }
  // for( int i = 0; i < n; i++ )
  // {
  //    cin >> serv[i];
  // }
   for( int t = 0; t < 50; t++ )
   {
      for( int i = 0; i < n; i++ )
      {
         if( t == arr[i] )
         {
            enqueue( i );
         }
      }
         int k = dequeue();
         if( k != -1 )
         {
            serv[k]--; 
            if( serv[k] == 0 )
            {
               exit[k] = t+1;
            }
            else
            {
               enqueue( k );
            }           
         }
      
   }
   for( int i = 0; i < n; i++ )
   {
        o1 << i << " " << exit[i] << endl;
 //     cout << i << " " << arr[i] << " " << exit[i] << endl;
   }
   return 0;
}
