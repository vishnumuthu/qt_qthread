#include "thread_call.h"

thread_call::thread_call(QObject *parent)
    : QObject{parent}
{
    QThread cpuInfo; //get CPU info
    thread_count = cpuInfo.idealThreadCount();

    for(int i = 0; i < thread_count; i++)
    {
        Thread_object*create_process = new Thread_object; // Thread as QVector
        obj.append(create_process);

        connect(create_process, &Thread_object::send_finished,this, &thread_call::read_processed);
    }
}

void thread_call::split_thread()
{
    int index_start = 0, index_end = 99;

    int avg_count = (index_end - index_start) / thread_count;

    std::cout << "Avg: " << avg_count << std::endl;

    for(int i = 0; i < thread_count; i++)
    {
        if(i == 0) // Start
        {
            obj.at(i)->get_limit(index_start, avg_count);
            obj.at(i)->start();
        }

        else if(i == thread_count - 1) // End
        {
            obj.at(i)->get_limit((avg_count * i) + 1, index_end);
            obj.at(i)->start();
        }

        else // Middle
        {
            obj.at(i)->get_limit((avg_count * i) + 1, avg_count * (i + 1));
            obj.at(i)->start();
        }
    }
}

void thread_call::read_processed(int data)
{
    qDebug() << data;
}
