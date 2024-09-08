#include "thread_object.h"
#include <QDebug>

Thread_object::Thread_object(QObject *parent)
    : QThread{parent}
{
}

void Thread_object::get_limit(int start, int end)
{
    mStart = start;
    mEnd = end;
}

void Thread_object::run()
{
    for(int i = mStart; i <= mEnd; i++)
        qDebug()  << i ;
}
