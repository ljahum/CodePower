nums = [5,14,13,8,12]
# nums = [5,14,13,8]
ans = 0
if len(nums) &1 == 0:
    # print(nums)
    for i in range(len(nums)//2):
        tmp =  int(str(nums[i]) + str(nums[-i-1]))
        ans+=tmp
else:
    for i in range(len(nums)//2):
        tmp =  int(str(nums[i]) + str(nums[-i-1]))
        # print(tmp)
        ans+=tmp

    ans+=nums[len(nums)//2]
print(ans)