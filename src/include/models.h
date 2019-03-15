#pragma once

#include<definitions.h>
#include <path.h>


template <typename UnderlyingType>
class Models{
    public:
        Models(){};
        ~Models(){};

    protected:
        virtual UnderlyingType simulateValue(int daysFromStart) const {};
        virtual Path<UnderlyingType> generatePath(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar
        ) const {};
        virtual void calibrate(std::vector<std::istream> const& data){};
};
