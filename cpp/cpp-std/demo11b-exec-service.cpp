/*
EXECUTOR SERVICES AND THREAD POOLS

Executor services in C++ std threading are not supported by default.
So, I use mylib::ExecService for this demonstration.
*/


#include <iostream>
#include <chrono>
#include "mylib-execservice.hpp"
using namespace std;



int main() {
    constexpr int NUM_THREADS = 2;
    constexpr int NUM_TASKS = 5;

    auto execService = mylib::ExecService(NUM_THREADS);

    for (int i = 0; i < NUM_TASKS; ++i) {
        execService.submit([=] {
            char id = 'A' + i;
            cout << "Task " << id << " is starting" << endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            cout << "Task " << id << " is completed" << endl;
        });
    }

    cout << "All tasks are submitted" << endl;

    execService.waitTaskDone();
    cout << "All tasks are completed" << endl;

    execService.shutdown();

    return 0;
}
