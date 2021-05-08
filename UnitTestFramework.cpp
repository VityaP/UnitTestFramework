#include <iostream>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <utility>
#include <exception>

using namespace std;

template<class T>
ostream& operator << (ostream& os, const set<T> &s){
    os << "{";
    bool first = true;
    for(const auto &x : s){
        if( !first ){
            os << ", ";
        }
        first = false;
        os << x;
    }
    os << "}";
    return os;
}

template<class K, class V>
ostream& operator << (ostream& os, const map<K, V> &m){
    os << "{";
    bool first = true;
    for(const auto &x : m){
        if( !first ){
            os << ", ";
        }
        first = false;
        os << x.first << ": " << x.second;
    }
    os << "}";
    return os;
}

template<class T, class U>
void myAssert(const T& t, const U& u, const string &hint){
    if( t != u ){
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u << "Hint: " << hint;
        throw runtime_error(os.str());
    }
}

class TestRunner{

public:
    template<class TestFunc>
    void RunTest(TestFunc func, const string & testName){
        try{
            func();
            cerr << testName << " OK" << "\n";
        }
        catch (runtime_error &e){
            ++failCount = 0;
            cerr << testName << " fail: " << e.what() << "\n";
        }
    }

    ~TestRunner(){
        if( failCount > 0){
            cerr << failCount << " tests failed. Terminate";
            exit(1);
        }
    }

private:
    int failCount = 0;

};

void TestAll(){
    TestRunner tr;
    //tr.RunTest(func1, "func1");
    //tr.RunTest(func2, "func2");
    //tr.RunTest(func3, "func3");
    // ...
}

int main(){

    TestAll();

    return 0;
}