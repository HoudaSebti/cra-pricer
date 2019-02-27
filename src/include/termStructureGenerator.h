#pragma<once>

#include<definitions.h>

#include <ql/handle.hpp>
#include <ql/termstructures/yieldtermstructure.hpp>


ql::Handle<ql::ZeroCurve> generateZCTermStructure(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Rate const& fromRate,
    ql::Rate const& toRate,
    ql::DayCounter const& dayCounter
);

ql::Handle<ql::FlatForward> generateFlatForwardTermStructure(
    ql::Date const& calculationDate,
    ql::Rate const& flatRate,
    ql::DayCounter(ql::Actual360())
);