#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

using namespace std;

int main()
{
    atomic<int> count = 0;
    const int ITERATIONS = 1e6;
    mutex mtx;
    auto lambda = [&]() {
        for (int i = 0; i < ITERATIONS; i++)
        {
            mtx.lock();
            // critical section, only one thread can access
            ++count;
            mtx.unlock();
        }
    };

    thread t1(lambda);
    thread t2(lambda);

    t1.join();
    t2.join();
    cout << count << endl;
    return 0;
}