#ifndef MESSAGE_H
#define MESSAGE_H

#include <qdebug.h>
#include <qstring.h>
#include <QThread>

class Message
{
public:
    template <typename T>
    static void logInfo(const T& value)
    {
        qDebug() << "THREAD:" << QThread::currentThreadId() << "[INFO]" << value;
    }

    template <typename T>
    static void logWarn(const T& value)
    {
        qDebug() << "THREAD:" << QThread::currentThreadId() << "[WARN]" << value;
    }

    template <typename T>
    static void logError(const T& value)
    {
        qDebug() << "THREAD:" << QThread::currentThreadId() << "[ERROR]" << value;
    }
};

#endif // MESSAGE_H
