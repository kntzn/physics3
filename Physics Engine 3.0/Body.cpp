#include "Body.h"
#define pi 3.14159

Body::Body (Vectord position, PHYSENG_DATA_TYPE mass, Vectord velocity,
            size_t nPoints, darray <Vectord> &pointsArray) :
    MPoint (position, mass, velocity),
    n_points (nPoints),
    points (pointsArray)
    {
    // Calculating coordinates of mass center
    Vectord mass_center;
    for (size_t i = 0; i < n_points; i++)
        mass_center += pointsArray [i] / (PHYSENG_DATA_TYPE) n_points;

    // Moves all points by (zero_point - mass_center)
    for (size_t i = 0; i < n_points; i++)
        pointsArray [i] -= mass_center;

    // Filling points array with angles and distances
    for (size_t i = 0; i < n_points; i++)
        {
        // x coord - distance to center
        points [i].x = pointsArray [i].length ();
        // y coord - additional angle
        points [i].y = atan2 (-pointsArray [i].y, -pointsArray [i].x);

        // Calculating radius
        if (radius < points [i].x)
            radius = points [i].x;
        }

    // Calculating total inertia moment of a body
    J = 0;
    for (size_t i = 0; i < n_points; i++)
        J += points [i].x * points [i].x * (mass / n_points) / 3;

    }

Body::~Body ()
    {
    }

void Body::applyForce (int point, Vectord Force)
    {
    // Applying force directly to mass center:
    MPoint::addForce (Force);

    if (0 <= point && point < (int) n_points)
        {
        // That part of the force that is able to rotate the body is equal to
        // the scalar product of the force vector by the unit vector of angle
        // (which is perpendicular to the radius vector from the point 
        // to which the force is applied to the center of mass of the body) 
        double activeForce = Force*Vectord (pi / 2 + angleState.angle + points [point].y);

        // Angular velocity increases proprtional to Torque 
        angleState.aAngular += (activeForce * points [point].x) / J;
        }
    }
void Body::applyAccel (int point, Vectord Accel)
    {
    // Applying force directly to mass center:
    MPoint::accelerate (Accel);

    if (0 <= point && point < (int) n_points)
        {
        double activeAccel = Accel*Vectord (pi / 2 + angleState.angle + points [point].y);

        // Angular velocity increases proprtional to Torque 
        angleState.aAngular += (activeAccel * points [point].x);
        }
    }

void Body::integrateEUL (double dt)
    {
    MPoint::integrateEUL (dt);
    
    // Angular part
    angleState.omega += angleState.aAngular * dt;
    angleState.angle += angleState.omega * dt;

    angleState.aAngular = Vectord (0, 0);
    }

Vectord Body::getPointPos (int point)
    {
    if (0 <= point && point < (int) n_points)
        {
        // returns mass center + offset to point
        return state.r + Vectord (points [point].y + angleState.angle) *
                         points [point].x;
        }

    // In case of incorrect point id function returns mass center coordinates
    return state.r;
    }

double Body::getRadius ()
    {
    return radius;
    }

size_t Body::nPoints ()
    {
    return n_points;
    }

double Body::getKinEnergy ()
    {
    //                (   Er  ) =
    //  J * (               w^2                 ) / 2
    PHYSENG_DATA_TYPE rotationE =
        J * (angleState.omega * angleState.omega) / 2.0;

    return MPoint::getKinEnergy () + rotationE;
    }
