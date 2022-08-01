void selectionSort(int arr[], int n)
{
   for(int i=0;i<n-1;i++)
   {
      int ans = i;
     // get minimum
      for(int j=i+1;j<n;j++)
      {
          if(arr[j] < arr[ans])
          {
             ans = j;
          }
      }
       if(ans != i) swap(arr[i],arr[ans]);
   }
}
