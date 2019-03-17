#pragma once

#include<definitions.h>
#include <fstream>

template <typename Underlying_type>
class Path{
    public:
        Path<Underlying_type>(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar
        );
        Path<Underlying_type>(Path const& other);
        Path<Underlying_type>(Path && other);
        ~Path<Underlying_type>();
        std::vector<double> computeCashFlow(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Rate const& riskFreeRate,
            ql::Rate const& fixedRate,
            ql::Rate const& payout,
            Underlying_type const& rangeMax,
            Underlying_type const& rangeMin
            //std::vector<ql::Date> const& fixedLegTenor,
            //std::vector<ql::Date> const& varLegTenor,
            //std::vector<ql::Date> const& callTenor
        );
        void addElement(Underlying_type const& element);
        Underlying_type getElement(int const& position);
        int getSize();
        std::basic_ofstream<char, std::char_traits<char>> saveToCsv(std::string pathName) const;
    private:
        double computeFixedLeg(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Rate const& fixedRate,
            double const& fixedIncrementInYears
        );
        double computeVariableLeg(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Rate const& payoff,
            double const& variableIncrementInYears
        );  

        std::vector<Underlying_type> elements;
};

#include <path_impl.ipp>