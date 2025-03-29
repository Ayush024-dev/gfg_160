// Here simple approach is to just move forward in the array till you find a zero okay. Then...find the first nonzero element in the right of that zero and swap with it.
// if you do not find any, that means your array is now arranged as per the need. Also besides reinitiallizing j again and again when you find a zero, only initialize it
// once when you find your first ever zero, then later on let it move forward, because we don't want it to scan same elements again and again right? This is lower the complexity to o(n)


//What does j tells us? the first non zero element in the right of curr zero right? So what it means that every element to the left of j and right of curr zero is zero.
// So if we know that, we also know we won't find any non zero number in this area. Hence we must allow j to continue rather than re initializing it. Hope this makes sense.

//Here is the code: -
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        
        int n=arr.size();
        
        int j;
        int zero=0;
        
        for(int i=0; i<n; i++){
            
            if(arr[i]==0){
                zero++;
                
                if(zero==1) j=i+1;
                
                while(j<n && arr[j]==0) j++;
                
                if(j==n) break;
                
                swap(arr[i], arr[j]);
                
                
            }
        }
    }
};
