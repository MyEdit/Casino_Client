#ifndef BAN_H
#define BAN_H

#include <QString>

class Ban
{
    int id;
    QString fullName;
    QString reason;

public:
    Ban() {};
    Ban(int id, QString fullName);
    Ban(int id, QString fullName, QString reason);

    int getID();
    QString getFullName();
    QString getReason();

    void setReason(QString reason);

    bool inputDataIsValid();
};

#endif // BAN_H
