// https://leetcode.com/problems/check-if-it-is-a-straight-line/description/

// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Example 1:
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

// Example 2:
// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false

public class Solution {
    public bool CheckStraightLine(int[][] coordinates) {
        if (coordinates.Length == 2)
            return true;

        // the formula to calcute the slope of two points is
        // m = (y2-y1) / (x2-x1)

        // now for three points we can compare their slopes,i.e
        // if
        // slope(coordinate 1 and 2) == slope(coordinate 2 and 3)
        // they form a straight line

        // now x1 can be equal to x2
        // then we will have divide by zero exception.
        // to avoid that we will modify the formula
        // ((y2 - y1) * (x3 - x2)) == ((y3 - y2) * (x2 - x1))

        // simple, no need to take care of the exception now

        int x1 = coordinates[0][0];
        int x2 = coordinates[1][0];
        int y1 = coordinates[0][1];
        int y2 = coordinates[1][1];

        for (int ind = 2; ind < coordinates.Length; ind++) {
            if ((y2 - y1) * (coordinates[ind][0] - x2) != ((coordinates[ind][1] - y2) * (x2 - x1)))
                return false;
        }
        return true;
    }
}