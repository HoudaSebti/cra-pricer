#pragma once

#include<definitions.h>


template <typename Underlying_type>
class Path{
    public:
        Path(ql::Date const& startDate, ql::Date const& endDate, ql::Calendar const& calendar);
        ~Path();
        double computeCashFlow(
            ql::Rate const& payoff,
            Underlying_type const& rangeMax,
            Underlying_type const& rangeMin
        );
        void addElement(Underlying_type const& element);
        Underlying_type getElement(int const& position);
        int getSize();
    private:
        double computeFixedLeg(ql::Rate const& fixedRate, double const& fixedIncrementInYears);
        double computeVariableLeg();  

        std::vector<Underlying_type> elements;
};

#include <path_impl.ipp>