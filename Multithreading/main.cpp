#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <iomanip>
#include <future>

using namespace std;

double calculatePi(int terms)
{
    if (terms < 1)
    {
        throw runtime_error("Terms cannot be less than 1");
    }
    double sum = 0.0;
    for (int i = 0; i < terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0 / (i * 2 + 1);
        sum += sign * term;
    }
    return sum * 4;
}

int main()
{
    promise<double> promise;
    auto do_calculation = [&](int terms) {
        try
        {
            auto result = calculatePi(terms);
            promise.set_value(result);
        }
        catch (const exception &e)
        {
            promise.set_exception(current_exception());
        }
    };
    thread t1(do_calculation, 0);
    future<double> future = promise.get_future();

    try
    {
        cout << setprecision(15) << future.get() << endl;
    }
    catch (const std::exception &e)
    {
        cout << e.what() << '\n';
    }

    t1.join();
    return 0;
}