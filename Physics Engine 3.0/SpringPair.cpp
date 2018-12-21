#include "SpringPair.h"

SpringPair::SpringPair (darray <Body*> all_objects, PHYSENG_DATA_TYPE hardness,
                        size_t idxLeft, size_t idxRight,
                        int pointIdxLeft = -1, int pointIdxRight = -1) :
            
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
