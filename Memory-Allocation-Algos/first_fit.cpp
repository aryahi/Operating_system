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
   cout<<"FIRST-FIT"<<endl;
   for(i = 0; i < n2; i++)
   {
	  flag = 0;
	  for(j = 0; j < n1; j++)
	  {
		 if(p[i] < arr[j])
		 {
			flag = 1;
		    arr[j] = arr[j] - p[i];
			break;
		 }
	  }
      if(flag == 0)
	     cout<<"Cant accomadate process:"<<i+1<<"  ";
   }
   for(i = 0; i < n1; i++)
	  cout<<arr[i]<<"  ";
   cout<<endl;
   return 0; 
}
