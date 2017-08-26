# https://leetcode.com/problems/single-number/

# Given an array of integers, every element appears twice except for one. Find that single one.

# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

def single_number(nums)
  result = 0
  nums.each do |n|
    result ^= n
  end
  return result
end