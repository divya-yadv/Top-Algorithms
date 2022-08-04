// for N/2
// if an element is in majority despite cancelling out with different elements, its count will still be more than zero
int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int k=0;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] == nums[k])
                count++;
            else
            {
               count--;
                if(count == 0)
                {
                    count++;
                    k = i;
                }
            }
            if(count > n/2)
                return nums[k];
        }
        return nums[k];
    }
// for N/3
vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int first = -1, second = -1, count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == first)
            {
                count1++;
            }
            else if(nums[i] == second)
            {
                count2++;
            }
            else 
            {
              // check and assign as a new element
                if(count1 == 0)
                {
                    count1 = 1;
                    first = nums[i];
                }
                else if(count2 == 0)
                {
                    count2 = 1;
                    second = nums[i];
                }
              // decrease probability for both being a majority element
                else
                {
                    count1--;
                    count2--;
                }
            }
        }
  // check if they are majority elements or not, by counting
        count1=0,count2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i] == first)
            {
                count1++;
            }
            else if(nums[i] ==  second)
            {
                count2++;
            }
        }
        if(count1 >( n/3))
        {
            ans.push_back(first);
        }
        if(count2 > (n/3))
        {
            ans.push_back(second);
        }
        return ans;
    }
