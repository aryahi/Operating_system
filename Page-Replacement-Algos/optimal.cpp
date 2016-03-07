#include<bits/stdc++.h>
using namespace std;

int main()
{
   fstream f1;
   f1.open("/home/himani/Operating_System/in");
   int n, number, flt = 0, sze = 0;
   f1 >> n >> number;
   char arr[number+1];
   f1 >> arr;
   char wind[n+1]; int cnt[n+1];
   memset( cnt, 0, sizeof(cnt) );
   sze = 0;
   for( int i = 0; i < number; i++ )
   {
      int flag = 0;
      for( int j = 0; j < sze; j++ )
      {
         if( wind[j] == arr[i] )
         {
            flag = 1;
            break;
         }
      }
      if( flag == 0 )
      {
        if( sze < n )
        {
           wind[sze++] = arr[i];
           flt++;
        }
        else if( sze == n )
        {
           int ele = cnt[0], idx = 0;
           for( int j = 1; j < sze; j++ )
           {
              if( cnt[j] > ele )
              {
                 ele = cnt[j];
                 idx = j;
              }
           }
           wind[idx] = arr[i];
           flt++;
        }
      }
      for( int k = 0; k < sze; k++ )
      {
         int flg = 0;
         cout << wind[k] << " ";
         for( int j = i+2; j < number; j++ )
         {
             if( arr[j] == wind[k] )
             {
                cnt[k] = j;
                flg = 1;
                break;
             }
         }
         if( flg == 0 ){
            cnt[k] = 100001;
         }
      }
      cout << endl;
   }
   cout << flt << endl;
   return 0;
}
