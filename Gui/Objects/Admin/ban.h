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
    Ban(int id, const QString& fullName);
    Ban(int id, const QString& fullName, const QString& reason);

    int getID();
    const QString& getFullName();
    const QString& getReason();

    void setReason(const QString& reason);

    bool inputDataIsValid() const;
};

#endif // BAN_H
