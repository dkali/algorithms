// https://leetcode.com/problems/decode-the-slanted-ciphertext/

public class Solution
{
    public string DecodeCiphertext(string encodedText, int rows)
    {
        StringBuilder decodedSB = new StringBuilder("", encodedText.Length);
        int columns = encodedText.Length / rows;
        char[][] data = new char[rows][];

        //fill in data
        int index = 0;
        for (int row = 0; row < rows; row++)
        {
            data[row] = new char[columns];
            for (int col = 0; col < columns; col++)
            {
                data[row][col] = encodedText[index++];
            }
        }

        //restore original text;
        int offset = 0;

        while (true)
        {
            if (offset >= columns)
                break;

            for (int rowInd = 0; rowInd < rows; rowInd++ )
            {
                int curColInd = rowInd + offset;
                if (curColInd >= columns)
                    break;
                
                decodedSB.Append(data[rowInd][curColInd]);
            }

            offset += 1;
        }

        string decoded = decodedSB.ToString();
        char[] charsToTrim = { ' ' };
        return decoded.TrimEnd(charsToTrim);
    }
}