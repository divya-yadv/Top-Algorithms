void quickSort(int arr[], int low, int high)
    {
        if(low<high)
        {
          // we will put the pivot at the correct position and return its position (here pivot will be arr[high])
            int pivot = partition(arr,low,high);
          // then both array because pivot is already at the place its supposed to be
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
      // in hoare we take last element as pivot
       int p = arr[high];
       int i = low-1;// we are trying to find the last smaller element index before pivot, so that we can return index+1 which is pivot index ;
       int j = low;
      for( j=low;j<high;j++)
      {
          if(arr[j] < p) // putting all smaller elements before pivot
          {
              i++; // increase index for smaller element
              swap(arr[i],arr[j]); // swap smaller element
          }
      }
      swap(arr[high],arr[i+1]); // put pivot at its correct position
      return (i+1); // return correct position
      
    }
