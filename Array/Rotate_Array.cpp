//Here we need to find by how many positions do we need to rotate the array? Right now we are given d, that means we are taking first d elements and placing it at the last
// of the array. There are easier way to do it by taking some space, like using another array or map to store elements in their new position. But we need to do it in place.
// So how to do it? It's all about observation in such questions. Let's see this example: arr[] = [1, 2, 3, 4, 5], d = 2. Here we need the place first 2 elements at the last
// so the answer must be [3,4,5,1,2] okay. We archived this moving elements in certain fashion. 
// So if we observe carefully: The answer looks similar to the reverse of the input array,(last elements at first and first elements at last). So let's try reversing-
// [5,4,3,2,1]. Okay looks similar, but still the elements aren't in the correct position. So let's compare the elements of the ans and reverse array. 
// If we see the first 3 elements (without considering the order) of both the arrays are same set of numbers. Similarly the last 2 numbers are also same set of numbers.
// But the difference is their order and if observed carefully, the first 3 elements of the reversed array are in reversed order of that of ans array and same can be seen 
// with the last two elements. So what if we reverse these two sets as well? So by reversing the first 3 elements of the reversed arr=[3,4,5,2,1] (See now even the order is same for the first
// 3 elements) and then if I reverse the last two elements as well->[3,4,5,1,2] exactly equal to our ans.
//So what did we observe? To get the ans, we need to perform a series of 3 reverse 1.> full reverse 2.> reverse of only first n-d elements 3.> reverse of last d elements

// Also d can be greated than n so to get d in range d%=n; 

// Also in reverse fun the right limit is excluded.

// Now the code: -
class Solution {
  public:

    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        
        k%=n;
        reverse(arr.begin(),arr.end());
        
        reverse(arr.begin(), arr.begin()+(n-k));
        
        reverse(arr.begin()+(n-k), arr.end());
    }
};
