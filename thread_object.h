#ifndef THREAD_OBJECT_H
#define THREAD_OBJECT_H

#include <QObject>
#include <QThread>

class Thread_object : public QThread
{
    Q_OBJECT
public:
    explicit Thread_object(QObject *parent = nullptr);

    void get_limit(int start, int end);

    void run();
private:
    int mStart, mEnd;
};

#endif // THREAD_OBJECT_H
