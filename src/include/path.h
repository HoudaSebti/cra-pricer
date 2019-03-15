#pragma once

#include<definitions.h>


template <typename Underlying_type>
class Path{
    public:
        Path(ql::Date startDate, ql::Date endDate, ql::Calendar calendar);
        ~Path();
        double computeCashFlow(
            ql::Rate payoff,
            Underlying_type rangeMax,
            Underlying_type rangeMin
        );
        void addElement(Underlying_type element);
        Underlying_type getElement(int position);
        int getSize();
    private:
        double computeFixedLeg(ql::Rate fixedRate, double fixedIncrementInYears);
        double computeVariableLeg();  

        std::vector<Underlying_type> elements;
};

#include <path_impl.ipp>