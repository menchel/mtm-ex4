#ifndef GREMLIN_H
#define GREMLIN_H
#include "BattleCard.h"
class Gremlin: public BattleCard
{
    static const int DEFAULT_FORCE=5;
    static const int DEFAULT_LOOT=2;
    static const int DEFAULT_DAMAGE=10;

public:

    //constructor
    Gremlin();

    //destructor
    virtual ~Gremlin()=default;
};
#endif // GREMLIN_H
