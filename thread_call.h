#ifndef THREAD_CALL_H
#define THREAD_CALL_H

#include <QObject>

#include "thread_object.h"
#include <QDebug>

class thread_call : public QObject
{
    Q_OBJECT
public:
    explicit thread_call(QObject *parent = nullptr);

    QVector<Thread_object *> obj;

    void split_thread();

public slots:
    void read_processed(int data);

signals:

private:
    int thread_count;
};

#endif // THREAD_CALL_H
