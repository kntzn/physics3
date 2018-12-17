#pragma once
#include "Vector.h"

typedef Vector2 <PHYSENG_DATA_TYPE> Vectord;



class Spring
    {
    private:
        Vectord right, left, force;
        
        double hardness;
        double init_dist, curr_dist, delta_dist,
               max_dist,  min_dist;
    public:
        Spring (Vectord pos0, Vectord pos1, double k);
        ~Spring ();

        // TODO:
        
        //Vectord getForceRight ();
        //Vectord getForceLeft ();

        void update (Vectord begin, Vectord end);
        
        //double getPotEnergy ();
    };

