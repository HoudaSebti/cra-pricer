#pragma once

#include<definitions.h>


typename <typedef UnderlyingType>
class Models_creator{
    public:
        Models_creator(){};
        ~Models_creator();

    protected:
        virtual UnderlyingType computeValue(ql::Date date);
        virtual void calibrate(std::vector<std::istream> const& data);
};
