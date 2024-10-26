/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    var n = k % nums.length;
    
    let ans = Array(nums.length).fill(0);
    // console.log(ans);
    var size = nums.length;
    for (let i = 0; i < nums.length; i++) {
        var index = i-n;
        if(index<0){
            index = index+nums.length;
        }
        ans[index] = nums[i];
        
    }
    console.log(ans);
    for (let index = 0; index < nums.length; index++) {
        nums[index] = ans[index];
        
    }

    
};

let nums = [1,2,3,4,5,6,7]
let k = 3+8

rotate(nums,k);
// console.log(tmp);