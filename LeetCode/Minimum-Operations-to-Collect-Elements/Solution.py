    }

    for(int i = nums.Count-1;i>=0;i--)
    {
        operation++;
        if(nums[i]>k)
        {
            continue;
        }
  
        if(!ones.Contains(nums[i]))
        {
            ones.Add(nums[i]);
            sum+= nums[i];
        }
        if(sum==sumk)
        {
            return operation;
        }
    }
    return 0;
    
}