#include "Spring.h"

Spring::Spring (Vectord pos0, Vectord pos1, PHYSENG_DATA_TYPE k) :
    right (pos0),
    left (pos1),
    hardness (k)
    {
    init_dist = curr_dist = max_dist = min_dist = (pos0 - pos1).length ();
    delta_dist = 0;
    }

Spring::~Spring ()
    {
    }

Vectord Spring::getForceBegin ()
    {
    return force;
    }
Vectord Spring::getForceEnd ()
    {
    return -force;
    }

void Spring::update (Vectord begin, Vectord end)
    {
    Vectord deltaPos = end - begin;
    curr_dist = deltaPos.length ();

    //(  dx  ) = (   x   ) - (   x0  )
    delta_dist = curr_dist - init_dist;
    
    //(F) = (            dx              ) * (   k   )
    force = (deltaPos.dir () * delta_dist) * hardness;

    // Min/Max distance stats:
    if (max_dist < curr_dist)
        max_dist = curr_dist;
    if (min_dist > curr_dist)
        min_dist = curr_dist;
    }

PHYSENG_DATA_TYPE Spring::getPotEnergy ()
    {
    // E = (   k  ) * (         dx^2        ) / 2
    return hardness * delta_dist * delta_dist / 2.0;
    }
