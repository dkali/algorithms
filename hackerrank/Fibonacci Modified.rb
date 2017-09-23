# Enter your code here. Read input from STDIN. Print output to STDOUT
t1 = 0, t2 = 0, n = 0
ARGF.each {|line| t1, t2, n = line.split(" ")}
arr = [t1.to_i, t2.to_i]
for i in 2..n.to_i-1
    arr << arr[i - 2] + arr[i - 1] * arr[i - 1]
end
puts arr.last