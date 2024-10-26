/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var smallestRangeII = function(nums, k) {
    var min_ = Math.min(...nums);
    var max_ = Math.max(...nums);
    // console.log(min_);
    // console.log(max_);
    var ans = Math.abs(max_ - min_-2*k);
    return ans;
};

const nums1  = [1,3,6];
const k = 3;

console.log(smallestRangeII(nums1,k)); 