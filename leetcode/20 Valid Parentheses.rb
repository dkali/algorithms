# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

# @param {String} s
# @return {Boolean}
def is_valid(str)
  brakets = {'{' => '}', '(' => ')', '[' => ']'}
  stack = []
  str.each_char do |char|
    stack << char if brakets.keys.include?(char)
    if brakets.values.include?(char)
      br = stack.pop
      return false if (brakets[br] != char)
    end
  end

  return false if not stack.empty?
  return true
end