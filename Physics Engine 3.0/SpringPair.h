#pragma once
#include "Pair.h"
#include "Spring.h"

class SpringPair : public Spring, public Pair
    {
    private:
        int point_left, point_right;
    public:
        SpringPair (darray <Body*> all_objects, PHYSENG_DATA_TYPE hardness,
                    size_t idxLeft, size_t idxRight,
                    int pointIdxLeft/* = -1*/, int pointIdxRight/* = -1*/);
        ~SpringPair ();

        void update (darray <Body*> all_objects, PHYSENG_DATA_TYPE dt);

        PHYSENG_DATA_TYPE getPotEnergy ();
    };