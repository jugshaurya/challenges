class Solution {
public:

    int helper(vector<int>& arr,int key, int start, int end){
        if(start>end){
            return -1;
        }
        int mid = (start+end)/2;
        if(arr[mid] == key){
            return mid;
        }
        //mid lies in--left part
        if(arr[mid] >= arr[start]){
            if(arr[start]<=key && arr[mid]>=key){
                return helper(arr,key,start,mid-1);
            }else{
                return helper(arr,key,mid+1,end);
            }
        }
        //mid lies in--right part
        if(arr[mid]<=key && arr[end]>=key){
            return helper(arr,key,mid+1,end);
        }else{
            return helper(arr,key,start,mid-1);
        }
    }


    int search(vector<int>& nums, int target) {
        return helper(nums, target, 0, nums.size()-1);
    }


};


// 
//     int search(vector<int>& nums, int target) {
//     int left = 0;
//     int right = nums.size() -1;
//     while(left <=right){
//         int mid = left + (right-left)/2;
//         if(nums[mid]==target){
//             return mid;
//         }

//         // top half
//         if(nums[mid] >= nums[left] and nums[mid] >= nums[right]){
//             // left part is sorted (left...mid)
//             if(target >= nums[left] and target <= nums[mid]){
//                 right = mid - 1;
//             }else{
//                 // right part is unsorted(mid+1...right)
//                 left = mid + 1;
//             }
//         }

//         // bottom half
//         if(nums[mid] <= nums[left] and nums[mid] <= nums[right]){
//             // right part is sorted (mid...right)
//             if(target >= nums[mid] and target <= nums[right]){
//                 left = mid + 1;
//             }else{
//                 // left part is unsorted(left...mid)
//                 right = mid - 1;
//             }
//         }
//     }

//     return -1;
// }