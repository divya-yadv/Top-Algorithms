public:
    int parent(i)
    {
        // because child= 2*parent+1;
        // parenet = child-1/2;
        return (i-1)/2;
    }
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
       int maxvalue = i;
       int l = 2*i+1;
       int r = 2*i+2;
       if(l<n && arr[l] > arr[maxvalue])
       {
           maxvalue = l;
       }
       if(r<n && arr[r] > arr[maxvalue])
       {
           maxvalue = r;
       }
       // swaped parent with children
       if(maxvalue != i)
       {
           swap(arr[i],arr[maxvalue]);
           // again heapify the affected subtree (children should be heapified)
           heapify(arr,n,maxvalue);
       }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        for(int i=parent(n-1);i>=0;i--)
        {
            heapify(arr,n,i);
        }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        // build a maxheap
       // here we have a tree but we need to modify our array
      //4 5 3 10 1 - before building maxheap
      // 10 5 3 4 1 - after building
      // here we are only sure about 0th index that this is greatest element so we store it at last index remove from heap tree and start process for one lesser size
        buildHeap(arr,n);
       // now swap the last index value with its root value and heapify one by one by reducing size 
        for(int i=n-1;i>=1;i--)
        {
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
