//First calculate the maxi using kadane algo and then if the max sum is in circular array, then that circular array would start from an element and then would continue
// till any element b4 the starting element. like - > [10, -3, -4, 7, 6, 5, -4, -1] if the max sum circular array starts from 7, so it will take all the elements, starting
// from 7 till end + some elements from first index to some idx b4 7. Like in this case the max sum circular array is [7, 6, 5, -4, -1,(from 7 till last)| (from first idx onwards)10]. 
// So we calculate max subarray sum from idx=0 till curridx and also the sum of elements from curridx till last idx. We store these values for each element and then 
// compare there sum with already computed maxi from kadane algorithm okay. 
//Now here is the code...

class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        
        int n=arr.size();
        
        int maxi=INT_MIN, sum=0;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            
            maxi=max(maxi, sum);
            
            if(sum<0) sum=0;
        }
        
        
        vector<pair<int,int>> max_sum(n,{0,0});
        
        int lmax=arr[0];
        
        int lsum=arr[0];
        
        
        
        for(int i=1; i<n; i++){
            lmax=max(lmax, lsum);
            lsum+=arr[i];
            
            
            max_sum[i].first=lmax;
        }
        
        int rsum=0;
        
        for(int i=n-1; i>=0; i--){
            rsum+=arr[i];
            
            max_sum[i].second=rsum;
            
            maxi=max(maxi, max_sum[i].first+max_sum[i].second);
        }
        
        return maxi;
    }
};
