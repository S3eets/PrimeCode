
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector <int> vPrime;

int GetOddNumber(int Indix)
{
	return (2 * Indix) - 1;
}
bool IsPrime(int Number, int &Prime)
{
    if (Number < 2)
    { 
        Prime = Number;
        return false;
    }

    if (Number == 2)
    {
        Prime = Number;
        return true;
    }

    if (Number % 2 == 0)
    { 
        return false;
    }

    for (int i = 3; i * i <= Number; i += 2)
    {
        if (Number % i == 0)
            return false;
    }

    Prime = Number;
    return true;
}
bool IsPrime(int Number)
{
    int DummyNumber = 0;
    return IsPrime(Number, DummyNumber);
}

int GetNearestPrime(int Number)
{
    for (int d = 0; d <= Number; d++)
    {
        int Prime = 0;
        if (Number - d >= 2 && IsPrime(Number - d, Prime)) return Number - d;
        if (IsPrime(Number + d, Prime))                    return Number + d;
    }
    return -1;
}
bool IsNonNagative(int Number)
{
    return (Number >= 0);
}
const char* PrintOperator(int Number)
{
    return IsNonNagative(Number) ? "+" : "-";
}
int GetDiffNumberBetweenOddAndPrime(int Odd, int Prime)
{
    return Prime - Odd;
}
int GetNextPrimeAfter(int Number)
{
    int temp = 0;
    for (int d = Number + 1; ; d++)
        if (IsPrime(d, temp)) return d;
}


void PrintOddNumbers(int NumberOfOddWantPrinted)
{
    int LastUsedPrime = 0;

    for (int i = 1; i <= NumberOfOddWantPrinted; i++)
    {
        int OddNumber = GetOddNumber(i);
        int Prime = 0;
        int Diff = 0;

        Prime = GetNearestPrime(OddNumber);

        if (Prime <= LastUsedPrime)
            Prime = GetNextPrimeAfter(LastUsedPrime);

        LastUsedPrime = Prime;
        Diff = GetDiffNumberBetweenOddAndPrime(OddNumber, Prime);

        if (Diff == 0)
        {
            //printf("%d: %-6d %-3s %-5d = %d\n", i, OddNumber, "+-", 0, OddNumber);
        }
        else
            //printf("%d: %-6d %-3s %-5d = %d\n", i, OddNumber, PrintOperator(Diff), abs(Diff), Prime);

        vPrime.push_back(Prime);
    }
}

string GetStringIsPrime(int Number)
{
    return IsPrime(Number) ? "Prime" : "NotPrime";
}

int main()
{
    int End = 1000;
	PrintOddNumbers(End);

    for (int i = 1; i <= vPrime.size() - 1; i++)
    {
        cout << i << ": " << vPrime[i] << " -> " << GetStringIsPrime(vPrime[i]) << endl;
        //cout << vPrime[i] - i << endl; i see 
    }

	return 0;
}