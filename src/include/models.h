#pragma once

#include<definitions.h>


template <typename UnderlyingType>
class Models{
    public:
        Models(){};
        ~Models(){};

    protected:
        virtual UnderlyingType simulateValue(int daysFromStart) const {};
        virtual void calibrate(std::vector<std::istream> const& data){};
};
