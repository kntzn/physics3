#pragma once

class Pair
    {
    protected:
        int id_left = -1, id_right = -1;
        Pair (size_t left, size_t right)
            {
            id_left = left;
            id_right = right;
            }

    public:
        virtual void update (std::vector <Body*> all_objects, double dt) = 0;

        virtual double getPotEnergy () = 0;