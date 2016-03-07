 
# include <iostream>
# include <string>
using namespace std;

int main()
{
   int n, i, count = 0, p, alloc, available, j;
   cout<<"Enter total numbers to put in cache : ";
   cin>>n;
   int arr[n];
   cout<<"Enter sequence : "<<endl;
   for(i = 0; i < n; i++)
	  cin>>arr[i];
   int frame[n];

   cout<<"Enter alloc value : ";
   cin>>alloc;
   
   for(i = 0; i < alloc; i++)
	  frame[i] = -1;
   j = 0;
   for(i = 0; i < n; i++)
   {
	  cout<<arr[i]<<"\t\t";
	  available = 0;
	  for(p = 0; p < alloc; p++)
	  {
	     if(frame[p] == arr[i]) 
		    available = 1;
		 if(available == 1)
			break;
	  }
	  
	  if(available == 0)
	  {
		 frame[j] = arr[i];
		 j = (j+1)%alloc;
		 count++;
		 for(p = 0; p < alloc; p++)
		    cout<<frame[p]<<"\t";
	  }
	  cout<<endl;
   }
   cout<<"Page Fault : "<<count<<endl;
   return 0;
}


