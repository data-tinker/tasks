#!/usr/bin/env python3

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []

        nums.sort()

        for first_idx in range(len(nums)):
            if first_idx > 0 and nums[first_idx] == nums[first_idx - 1]:
                continue

            second_idx = first_idx + 1
            third_idx = len(nums) - 1

            required_sum  = 0 - nums[first_idx];

            while second_idx < third_idx:
                current_sum = nums[second_idx] + nums[third_idx]

                if current_sum < required_sum:
                    second_idx += 1
                elif current_sum > required_sum:
                    third_idx -= 1
                else:
                    result.append([nums[first_idx], nums[second_idx], nums[third_idx]])
                    second_idx += 1
                    while second_idx < third_idx and nums[second_idx] == nums[second_idx - 1]:
                        second_idx += 1

        return result

def main():
    nums = [-1, 0, 1, 2, -1, -4]

    print(Solution().threeSum(nums))

if __name__ == "__main__":
    main()

