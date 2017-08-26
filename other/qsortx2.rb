arr = [-3, -1, 0, 1, 6]

def qsortX2(arr, multiply = false)
  mid = arr[(arr.size/2).to_i]
  mid = mid*mid if multiply
  left_arr = []
  mid_arr = []
  right_arr = []
  arr.select{|el|
    el = el*el if multiply
    left_arr << el if el < mid
    mid_arr << el if el == mid
    right_arr << el if el > mid
  }

  left_arr = qsortX2(left_arr) if left_arr.size > 1
  right_arr = qsortX2(right_arr) if right_arr.size > 1
  result = left_arr + mid_arr + right_arr
end

puts "#{qsortX2(arr, true)}"