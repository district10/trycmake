#include <iostream>
#include <cstdlib>
#include <boost/timer.hpp>

using namespace std;
using namespace boost;

int main(int argc, char** argv)
{
    timer t;
    cout << "max timespan: "
        << t.elapsed_max() / 3600 << "h" << endl;
    cout << "min timespan: "
        << t.elapsed_min() << "s" << endl;
    cout << "now times elapsed: "
        << t.elapsed() << "s" << endl;
    
    getchar();
    return EXIT_SUCCESS;
}