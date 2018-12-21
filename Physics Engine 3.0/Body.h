#pragma once
#include "MPoint.h"
#include "darray.h"

struct AngleState
    {
    double angle;
    double omega;
    double aAngular;
    };

class Body : public MPoint
    {
    protected:
        // Vectors that contain points' 
        //distance from mass center (x) and 
        //additional angle of rotation (y)
        darray <Vectord> points;
        
        // Number of points
        size_t n_points;

        // Angle of the body
        AngleState angleState;
        // Inertia moment
        double J;

        // Maximum distance from mass center (farthest point)
        double radius;

    public:
        Body (Vectord position, PHYSENG_DATA_TYPE mass, Vectord velocity,
              size_t nPoints, darray <Vectord> &pointsArray);
        ~Body ();

        void applyForce (int point, Vectord Force);
        void applyAccel (int point, Vectord Accel);

        //void applyForceToVirtual (Vectord virtualPoint, Vectord Force, double dt);
        //void accelerateVirtual (Vectord virtualPoint, Vectord Accel, double dt);

        void integrateEUL (double dt);

        Vectord getPointPos (int point);
        double getRadius ();
        size_t nPoints ();
        double getKinEnergy ();
    };

