#ifndef URLCARD_H
#define URLCARD_H

#include "Games/BlackDjack/card.h"
#include <QMap>
#include <QString>

class UrlCard
{
public:
    static QMap<Card, QString> _urlCard;

public:
    UrlCard();
    static QString getUrlCard(Card card);
    static void initializeUrlCard();
};

#endif // URLCARD_H
