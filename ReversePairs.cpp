class Solution {

private:
    void Merge(vector<int> &arr, int start, int mid, int end){
        int left = start;
        int right = mid + 1;

        vector<int> temp;
        while(left <= mid && right <= end){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }
            else{
                temp.push_back(arr[right++]);
            }
        }
        while(left <= mid){
            temp.push_back(arr[left++]);
        }
        while(right <= end){
            temp.push_back(arr[right++]);
        }
        for(auto it : temp){
            arr[start++] = it;
        }
    }

    int ReversePairsCount(vector<int>& arr, int start, int mid, int end){
        int left = start;
        int right = mid + 1;
        int cnt = 0;

        while(left <= mid && right <= end){
            if(arr[left] > (long long)2 * arr[right]){
                cnt += mid - left + 1;
                right++;
            } 
            else{
                left++;
            }
        }
        return cnt;
    }

    int MergeSort(vector<int> &arr, int start, int end){
        int cnt = 0;
        if(start >= end) return cnt;
        int mid = (start + end) / 2;

        cnt += MergeSort(arr, start, mid);
        cnt += MergeSort(arr, mid + 1, end);
        cnt += ReversePairsCount(arr, start, mid, end);
        Merge(arr, start, mid, end);
        return cnt;
    }

public:
    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        return MergeSort(nums, 0, size - 1);
    }
};
