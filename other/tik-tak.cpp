// Tik Tak multithreading

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable tik_cv, tak_cv;

void printTik(int sec){
    int repeats = 10;
    while (repeats-- > 0){
        unique_lock<mutex> lck(mtx);
        tik_cv.wait(lck);
        printf("tik\n");

        this_thread::sleep_for (chrono::seconds(sec));
        tak_cv.notify_one();
    }
}

void printTak(int sec) {
    int repeats = 10;
    while (repeats-- > 0){
        unique_lock<mutex> lck(mtx);
        tak_cv.wait(lck);
        printf("tak\n");

        this_thread::sleep_for (chrono::seconds(sec));
        tik_cv.notify_one();
    }
}

int main(){
    thread first(printTik, 1);
    thread second(printTak, 2);

    this_thread::sleep_for (chrono::seconds(1));
    tik_cv.notify_one();

    first.join();
    second.join();
    return 0;
}