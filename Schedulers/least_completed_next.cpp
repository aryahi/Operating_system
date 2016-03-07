#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int n, arr[100001], serv[100001], front, rear, queue[100001], flag[100001], i, init[100001], fin[100001];

void enqueue( int val )
{
   if( front == -1 && rear == -1 )
   {
      front = 0; 
      rear = 0;
      queue[front] = val;
   }
   else
   {
      queue[++rear] = val;
   }
}

int dequeue()
{
   if( front == -1 && rear == -1 )
      return -1; 
   else if( front == rear )
   {
      int j = queue[rear];
      front = -1;
      rear = -1;
      return j;
   }
   else
   {
      int va[100001], sol;
      int mini = 100001;
      for( i = front; i <= rear; i++ )
      {
         if( flag[queue[i]] < mini )
         {
            mini = flag[queue[i]];
         }
      }
      int calc[100001], cnt = 0;
      for( i = front; i <= rear; i++ )
      {
         if( flag[queue[i]] == mini ){ 
            va[cnt] = i;
            calc[cnt++] = queue[i];
         }
      }
      int ans = 100001;
      for( i = 0; i < cnt; i++ )
      {
         //cout << "cal " << calc[i] << endl;
         if( arr[calc[i]] < ans )
         {
            ans = calc[i];
            sol = va[i];
         }
      }
      for( i = sol; i < rear; i++ )
         queue[i] = queue[i+1];
      rear--;
      return ans;
   }
}

int main()
{
   memset( flag, 0, sizeof(flag) );
   front = -1;
   rear = -1;
   fstream o1, in1;
   o1.open("/home/himani/OS/opt.in"); 
   in1.open("/home/himani/OS/inp");
   while( !in1.eof() )
   {
      in1 >> n;
      for( i = 0; i < n; i++ )
         in1 >> arr[i];
      for( i = 0; i < n; i++ )
         in1 >> serv[i];
   }
   for( int t = 0; t < 50; t++ )
   {
      for( int j = 0; j < n; j++ )
      {
         if( arr[j] == t )
         {
            enqueue(j);
            init[j] = t;
         }
      }
      int k = dequeue();
 //     cout << "dQ " << k << endl;
      if( k != -1 )
      {
         
         flag[k]++;
        // cout << " flg " << flag[k] << endl;
         if( flag[k] < serv[k] )
         {
            enqueue(k);
         }
         else
         {
            fin[k] = t;
         }
      }
   }
   for( i = 0; i < n; i++ )
   {
      o1 << i << " " << fin[i]-init[i]+1 << endl;
   }
   return 0;
}
