void merge(int arr[], int l, int m, int r)
    {
        int left = m-l+1;
        int right = r-m;
        int leftarr[left];
        int rightarr[right];
        for(int i=0;i<left;i++)
        {
            leftarr[i] = arr[l+i];
        }
        for(int i=0;i<right;i++)
        {
            rightarr[i] = arr[m+1+i];
        }
        int i=0;
        int j=0;
        int k=l;
        while((i<left) && (j < right))
        {
           if(leftarr[i] <= rightarr[j])
           {
               arr[k++] = leftarr[i++];
           }
           else
           {
               arr[k++] = rightarr[j++];
           }
        }
        while(i < left)
        {
            arr[k++] = leftarr[i++];
        }
        
        while(j < right)
        {
            arr[k++] = rightarr[j++];
        }
        delete []leftarr;
        delete []rightarr;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l<r)
        {
            int mid = l + (r-l)/2;
            mergeSort(arr,l,mid);
            mergeSort(arr,mid+1,r);
            merge(arr,l,mid,r);
        }
        return;
       
    }
