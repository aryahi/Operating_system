# include <iostream>
using namespace std;

int main()
{
   int n1, n2, i, j, k;
   cout<<"Enter number of memory partitions and number of processes"<<endl;
   cin>>n1>>n2;

   int arr[n1], p[n2];
   
   cout<<"Enter memory size"<<endl;
   for(i = 0; i < n1; i++)
   {
	  cin>>arr[i];
   }
   cout<<"Enter process size"<<endl;
   for(i = 0; i < n2; i++)
   {
	  cin>>p[i];
   }
   int flag;
   cout<<"WORST-FIT"<<endl;
   for(i = 0; i < n2; i++)
   {
	  flag = 0;
	  int max, l, m = 0, n;
	  for(j = 0; j < n1; j++)
	  {
		 if(p[i] < arr[j])
		 {
			max = arr[j] - p[i];
			if(max > m)
			{
			   l = j;
			   n = i;
			   m = max;
			   flag = 1;
			}
					 
	     }
   	  }
	  if(flag == 1)
	     arr[l] = arr[l] - p[n];
	  else 
		 cout<<"Cant accomodate process: "<<i+1<<endl;
   }
   for(i = 0; i < n1; i++)
	  cout<<arr[i]<<"  ";
   cout<<endl;
   return 0; 
}
