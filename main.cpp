#include <QCoreApplication>
#include <QThread>
#include <iostream>

#include "thread_object.h"
#include "thread_call.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QThread cpuInfo; //get CPU info
    // std::cout << cpuInfo.idealThreadCount() << std::endl;

    // int index_start = 0, index_end = 99;
    // int count_thread = cpuInfo.idealThreadCount();

    // Thread_object *obj = new Thread_object[count_thread]; // Thread as Array

    // int avg_count = (index_end - index_start) / count_thread;

    // std::cout << "Avg: " << avg_count << std::endl;

    // for(int i = 0; i < count_thread; i++)
    // {
    //     if(i == 0) // Start
    //     {
    //         obj[i].get_limit(index_start, avg_count);
    //         obj[i].start();
    //     }

    //     else if(i == count_thread - 1) // End
    //     {
    //         obj[i].get_limit((avg_count * i) + 1, index_end);
    //         obj[i].start();
    //     }

    //     else // Middle
    //     {
    //         obj[i].get_limit((avg_count * i) + 1, avg_count * (i + 1));
    //         obj[i].start();
    //     }
    // }

    thread_call call;
    call.split_thread();

    return a.exec();
}
