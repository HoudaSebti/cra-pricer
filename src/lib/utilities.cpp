#include<utilities.h>


ql::Handle<ql::ZeroCurve> generateZeroCurveTermStructure(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Rate const& fromRate,
    ql::Rate const& toRate,
    ql::DayCounter const& dayCounter
){

    return ql::Handle<ql::ZeroCurve>(
        boost::shared_ptr<ql::ZeroCurve>(
            new ql::ZeroCurve(
                std::vector<ql::Date>{{startDate, endDate}},
                std::vector<ql::Rate>{{fromRate, toRate}},
                dayCounter
            )
        )
    );
}

ql::Handle<ql::FlatForward> generateFlatForwardTermStructure(
    ql::Date const& calculationDate,
    ql::Rate const& flatRate,
    ql::DayCounter const& dayCounter
){
    return ql::Handle<ql::FlatForward>(
        boost::shared_ptr<ql::FlatForward>(
            new ql::FlatForward(
                calculationDate,
                ql::Handle<ql::Quote>(
                    boost::shared_ptr<ql::Quote>(
                        new ql::SimpleQuote(flatRate)
                    )
                ),
                dayCounter
            )
        )
    );
}