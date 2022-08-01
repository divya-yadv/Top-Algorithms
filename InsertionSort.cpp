void insertionSort(int arr[], int n)
    {
        for(int i=1;i<n;i++)
        {
          // if not in correct order
            if(arr[i] < arr[i-1])
            {
              // we will get its right position by swapping it with every element that is greater than this in sorted subarray
                int k = i;
                for(int j=i-1;j>=0;j--)
                {
                    if(arr[k] < arr[j])
                    {
                       swap(arr[k],arr[j]);
                        k=j;
                    }
                    else
                        break;
                }
            }
        }
    }
