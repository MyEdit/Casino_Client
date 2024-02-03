#ifndef MESSAGE_H
#define MESSAGE_H

#include <qdebug.h>
#include <qstring.h>

class Message
{
public:
    template <typename T>
    static void logInfo(const T& value)
    {
        qDebug() << "[INFO]" << value;
    }

    template <typename T>
    static void logWarn(const T& value)
    {
        qDebug() << "[WARN]" << value;
    }

    template <typename T>
    static void logError(const T& value)
    {
        qDebug() << "[ERROR]" << value;
    }
};

#endif // MESSAGE_H
