//Here the main approach is to calculate the min diff between any two elements. Matlab logic kuch esa hi use ho rha hai. Samjho, if I want min diff, muze greatest wale ko reduce krna hoga and smallest ko increase.
//Whenever I need the min difference between any two character, what do I do? I sort the array and then take difference of elements in each idx pair and compare it with the so far min diff. Bs ab yhi krna hai, bs 
//pair ke right idx ki value ko decrease krna hai aur use mini se compare krna hai, taki us operation ke baad mere pass min value rhe for that case. Similary left wale ke k add krke max se compare karo. Fir kya diff 
//lo and ans se compare karo. 
//Yad rkna, min distance nikalna hai, iska matlab har ek pair ko check krna hai. Ese nhi ko last - first kr rhe, usse max aayega, min nhi. Now see the code
class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        
        int n=arr.size();
        
        sort(arr.begin(), arr.end());
        
        int r=arr[n-1]-arr[0];
        
        
        
        for(int i=1; i<n; i++){
            if(arr[i]<k) continue;
            
            int maxi=max(arr[i-1]+k, arr[n-1]-k);
            int mini=min(arr[i]-k, arr[0]+k);
            
            r=min(r, (maxi-mini));
        }
        
        return r;
    }
};
