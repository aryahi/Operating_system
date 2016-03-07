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

   cout<<"NEXT-FIT"<<endl;
   int o = 0, tk, flag ;
   for(i = 0; i < n2; i++)
   {  
      tk = i; flag = 0; int flag2 = 0;
	  for(j = o; j <= n1; j++)
	  {
		 if((tk == 0) && (flag != 1))
		 {
		    if(p[i] < arr[j])
			{
			   arr[j] = arr[j] - p[i];
			   o = j+1;
			   flag = 1;
			}
		 }
		 if((tk != 0) && (flag != 1) && (j != n1))
		 {
			if(p[i] < arr[j])
			{
			   arr[j] = arr[j] - p[i];
			   o = j+1;
			   flag = 1;
			}
		 }
		 if((j == n1) && (flag != 1))
		 {
			for(k = 0; k < n1; k++)
			{
			   if(arr[k] - p[i] >= 0)
			   {
				  flag2 = 1;
			   }
			}
			if(flag2 == 1)
			{
			   o = 0;
			   j = -1;
			}
			else
		    {
			   cout<<p[i]<<" size process can't be accomodated"<<endl;
			}
		 }
   	  }   
   }
   for(i = 0; i < n1; i++)
	  cout<<arr[i]<<"  ";
   cout<<endl;
   return 0; 
}
