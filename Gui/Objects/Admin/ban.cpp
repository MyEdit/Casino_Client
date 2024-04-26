#include "ban.h"


Ban::Ban(int id, const QString& fullName)
{
    this->id = id;
    this->fullName = fullName;
}


Ban::Ban(int id, const QString& fullName, const QString& reason)
{
    this->id = id;
    this->fullName = fullName;
    this->reason = reason;
}

int Ban::getID()
{
    return this->id;
}

const QString& Ban::getFullName()
{
    return this->fullName;
}

const QString& Ban::getReason()
{
    return this->reason;
}

void Ban::setReason(const QString& reason)
{
    this->reason = reason;
}

bool Ban::inputDataIsValid() const
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
