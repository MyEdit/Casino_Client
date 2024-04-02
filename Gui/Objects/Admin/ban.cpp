#include "ban.h"


Ban::Ban(int id, QString fullName)
{
    this->id = id;
    this->fullName = fullName;
}


Ban::Ban(int id, QString fullName, QString reason)
{
    this->id = id;
    this->fullName = fullName;
    this->reason = reason;
}

int Ban::getID()
{
    return this->id;
}

QString Ban::getFullName()
{
    return this->fullName;
}

QString Ban::getReason()
{
    return this->reason;
}

void Ban::setReason(QString reason)
{
    this->reason = reason;
}

bool Ban::inputDataIsValid()
{
    if (id == 0)
        return false;

    for (QString value : {fullName, reason})
    {
        if (value.isEmpty())
            return false;
    }

    return true;
}
