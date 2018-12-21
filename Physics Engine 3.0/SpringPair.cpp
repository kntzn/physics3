#include "SpringPair.h"

SpringPair::SpringPair (darray <Body*> all_objects, PHYSENG_DATA_TYPE hardness,
                        size_t idxLeft, size_t idxRight,
                        int pointIdxLeft, int pointIdxRight) :
            
            Spring (all_objects [idxLeft]->getPointPos (pointIdxLeft),
                    all_objects [idxRight]->getPointPos (pointIdxRight),
                    hardness),
            Pair (idxLeft, idxRight),
            point_left (pointIdxLeft),
            point_right (pointIdxRight)
    {
    }


SpringPair::~SpringPair ()
    {
    }

void SpringPair::update (darray<Body*> all_objects, PHYSENG_DATA_TYPE dt)
    {
    Spring::update (all_objects [id_left]->getPointPos (point_left),
                    all_objects [id_right]->getPointPos (point_right));

    all_objects [id_left]->addForce (Spring::getForceBegin ());
    all_objects [id_right]->addForce (Spring::getForceEnd ());
    }

PHYSENG_DATA_TYPE SpringPair::getPotEnergy ()
    {
    return Spring::getPotEnergy ();
    }
