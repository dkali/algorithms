// https://leetcode.com/problems/text-justification/description/
// Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left justified and no extra space is inserted between words.

// For example,
// words: ["This", "is", "an", "example", "of", "text", "justification."]
// L: 16.

// Return the formatted lines as:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]
// Note: Each word is guaranteed not to exceed L in length.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int startCursor = 0, endCursor = 0, lineLength = 0;
        
        for (int pos = 0; pos < words.size(); pos++) {
            if (lineLength + words[pos].size() <= maxWidth) {
                endCursor++;
                lineLength += words[pos].size() + 1;
            }
            else {
                int wordsCount = endCursor - startCursor;
                int spaceNedeed = maxWidth - (lineLength - wordsCount);
                int gaps = wordsCount - 1;
                vector<int> spaces;
                // calculate spaces
                if (spaceNedeed != 0) {
                    if (gaps == 0) {
                        spaces.push_back(spaceNedeed);
                    }
                    else if (spaceNedeed % gaps == 0) {
                        int tmp = spaceNedeed / gaps;
                        for (int i = 0; i < gaps; i++)
                            spaces.push_back(tmp);
                    }
                    else {
                        spaces.resize(gaps, 0);
                        int tmp = 0;
                        while (spaceNedeed-- > 0) {
                            if (tmp >= gaps)
                                tmp = 0;
                            spaces[tmp++]++;
                        }
                    }
                }
                
                //build line
                string line = "";
                for (int i = startCursor; i < endCursor; i++) {
                    line += words[i];
                    if (spaces.size() > i - startCursor)
                        line += string(spaces[i - startCursor], ' ');
                }
                result.push_back(line);
                
                startCursor = endCursor;
                lineLength = 0;
                endCursor++;
                lineLength += words[pos].size() + 1;
            }
        }
        
        //append last line, left justified
        string line = "";
        while (startCursor < endCursor) {
            if (!line.empty())
                line += ' ';
            line += words[startCursor++];
        }
        while (line.size() < maxWidth)
            line += ' ';
        result.push_back(line);
        
        return result;
    }
};