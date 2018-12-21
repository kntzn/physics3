#pragma once
#include "Vector.h"

// Spring class
// This is default spring with basic methods
// and acts like a mathematical one
// i.e. there is no restrictions on
// it's deformation
class Spring
    {
    private:
        Vectord right, left, force;
        
        double hardness;
        double init_dist, curr_dist, delta_dist,
               max_dist,  min_dist;
    public:
        // Constructor and destructor
        Spring (Vectord pos0, Vectord pos1, PHYSENG_DATA_TYPE k);
        ~Spring ();

        // Force at spring's ends getters
        Vectord getForceBegin ();
        Vectord getForceEnd ();
        
        // Main update function
        void update (Vectord begin, Vectord end);
        
        // Returns potential energy of the spring
        PHYSENG_DATA_TYPE getPotEnergy ();
    };

