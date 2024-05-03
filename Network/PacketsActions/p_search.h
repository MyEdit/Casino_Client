#ifndef P_SEARCH_H
#define P_SEARCH_H

#include "Network/networkclient.h"

class P_Search
{
public:
    static QPair<ModelTypes, QString> getResultSearchFromServer();
};

#endif // P_SEARCH_H
