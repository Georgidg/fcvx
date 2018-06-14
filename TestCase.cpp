#include "TestCase.hpp"

TestCase::TestCase(const string str, ostream &outF) : str(str), outF(outF)
{
    Test1 = 0;
    Test2 = 0;
    counterTests = 0;
}
void TestCase::print()
{
    outF << str << ": " << Test2 << " failed, " << Test1 << " passed, " << counterTests << " total." << endl
      << "---" << endl;
}
