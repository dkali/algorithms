// Given a calendar of workdays (W) and holidays (H), plus available PTO days,
// find the length of the longest possible vacation.
// for WHHWWHHW pto = 2, result is 6.
// for WHHWWWHHWHHWHHH pto = 2, result is 9.

string calendar = "WHHWWWHHWHHWHHH";
int pto = 2;

int maxLength = 0;
List<int> vacationLengths = new List<int>();
List<int> ptos = new List<int>();

foreach (char day in calendar)
{
    // start potential vacation
    vacationLengths.Add(0);
    ptos.Add(pto);

    switch (day)
    {
        case 'W':
            // waste the pto day
            for (int ind = 0; ind < ptos.Count; ind++)
            {
                if (ptos[ind] > 0)
                {
                    vacationLengths[ind]++;
                }
                if (ptos[ind] >= 0)
                {
                    ptos[ind]--;
                }
            }
            break;

        case 'H':
            // prolonge the existing vacations
            for (int ind = 0; ind < vacationLengths.Count; ind++)
            {
                vacationLengths[ind]++;
            }
            break;
    }

    // check the max length and invalidate the lists
    List<int> indToRemove = new List<int>();
    for (int ind = 0; ind < vacationLengths.Count; ind++)
    {
        if (ptos[ind] >= 0 && vacationLengths[ind] > maxLength)
        {
            maxLength = vacationLengths[ind];
        }
        if (ptos[ind] < 0)
        {
            indToRemove.Add(ind);
        }
    }
    for (int ind = indToRemove.Count - 1; ind >= 0; ind--)
    {
        vacationLengths.RemoveAt(ind);
        ptos.RemoveAt(ind);
    }
}

Console.WriteLine($"maxLength = {maxLength}");
