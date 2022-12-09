#include <iostream>
#include <string>
#include <array>
using namespace std;

#include <stl/Vector.h>
using namespace yazi::stl;

#include <sys/time.h>


int main()
{
    Vector<int> a;
    return 0;

    /*
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int start_sec = tv.tv_sec;
    int start_usec = tv.tv_usec;

    const int max = 100000;
    Array<bool> a(max);

    gettimeofday(&tv, NULL);
    int end_sec = tv.tv_sec;
    int end_usec = tv.tv_usec;
    double time_diff = (end_sec - start_sec) * 1000000 + (end_usec - start_usec);
    std::cout << time_diff / 1000 / max << "ms" << std::endl;
    return 0;
    */
}
