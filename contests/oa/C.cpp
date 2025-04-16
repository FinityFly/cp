// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(string &S)
{
    int cntX = 0, cntO = 0;
    int maxX = 0, maxO = 0;
    for (char c : S)
    {
        if (c == 'O')
        {
            maxX = max(maxX, cntX);
            cntX = 0;
            cntO++;
        }
        else
        {
            maxO = max(maxO, cntO);
            cntO = 0;
            cntX++;
        }
    }
    if ((maxX >= 3 && maxO >= 3) || (maxX < 3 && maxO < 3))
    {
        return "tie";
    }
    else if (maxX >= 3 && maxO < 3)
    {
        return "X";
    }
    else
    {
        return "O";
    }
}
