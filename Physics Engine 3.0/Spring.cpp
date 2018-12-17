#include "Spring.h"



Spring::Spring (Vectord pos0, Vectord pos1, double k) :
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
