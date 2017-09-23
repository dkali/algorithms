t1, t2, n = 0, 0, 0
ARGF.each {|line| t1, t2, n = line.split(" ")}
t1 = t1.to_i
t2 = t2.to_i
for i in 2..n.to_i-1
    t1, t2 = t2, t1 + t2 * t2
end
puts t2