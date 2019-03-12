#pragma once

#include<definitions.h>


template <typename UnderlyingType>
class Models{
    public:
        Models(){};
        ~Models(){};

    protected:
        virtual UnderlyingType computeValue(ql::Date date) const {};
        virtual void calibrate(std::vector<std::istream> const& data){};
};
