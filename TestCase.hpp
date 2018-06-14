#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TestCase
{
  private:
    string str;
    int Test1;
    int Test2;
    int counterTests;
    ostream &outF;
	
  public:
    void print();
    TestCase(const string str, ostream &outF);
    template <typename T>
    TestCase check_equal(T a, T b)
    {
        counterTests++;
        if (!(a == b))
        {
            Test2++;
            outF << str << ": Failure in test #" << counterTests << ": "
              << a << " should equal " << b << "!" << endl;
        }
        else
            Test1++;
        return *this;
    }
    template <typename T1, typename T2, typename T3>
    TestCase check_function(T1(f), T2 a, T3 b)
    {
        counterTests++;
        if (!(f(a) == b))
        {
            Test2++;
            outF << str << ": Failure in test #" << counterTests << ": Function should return " << b << " but returned " << f(a) << "!" << endl;
        }
        else
            Test1++;
        return *this;
    }

    template <typename T>
    TestCase check_output(T a, string givenStr)
    {
        counterTests++;
        ostringstream OS_STR;
        OS_STR << a;
        string tests = OS_STR.str();
        if (tests != givenStr)
        {
            Test2++;
            outF << str << ": Failure in test #" << counterTests << ": string value should be "
              << givenStr << " but is " << a << endl;
        }
        else
            Test1++;
        return *this;
    }
  
template <typename T>
    TestCase check_different(T a, T b)
    {
        counterTests++;
        if (!(a != b))
        {
            Test2++;
            outF << str << ": Failure in test #" << counterTests << ": "
              << a << " should different " << b << "!" << endl;
        }
        else
            Test1++;
        return *this;
    }
};
