// https://binarysearch.com/room/levenshtein-distance-DkAYbqVGNJ

int partition(int s, int e, vector<int> &nums){
    int pivot = nums[e];
    int j = s;
    int i;
    for(i=s;i<e;i++){
        if(nums[i]<pivot){
            swap(nums[i],nums[j]);
            j++;
        }
    }
    swap(nums[j],nums[e]);
    return j;
}
int solve(vector<int>& nums, int k) {
    int lo=0,hi=nums.size()-1;
    int ans=-1;
    while(lo<=hi){
        int p = partition(lo,hi,nums);
        if(p==k) {
            ans = nums[p];
            break;
        }
        else if(p>k){
            hi = p-1;
        }else if(p<k){
            lo = p+1;
        } 
    }
    return ans;
}
