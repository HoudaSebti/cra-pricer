#pragma once

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(){}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(CallableRangeAccrual const& other)
    : payoff (other.payoff),
    fixedRate(other.fixedRate),
    notional(other.notional),
    rangeMax(other.rangeMax),
    rangeMin(other.rangeMin),
    fixedLegTenor(other.fixedLegTenor),
    varLegTenor(other.varLegTenor),
    callTenor(other.callTenor)
{}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(CallableRangeAccrual && other)
    : payoff(std::move(other.payoff)),
    fixedRate(std::move(other.fixedRate)),
    notional(std::move(other.notional)),
    rangeMax(std::move(other.rangeMax)),
    rangeMin(std::move(other.rangeMin)),
    fixedLegTenor(std::move(other.fixedLegTenor)),
    varLegTenor(std::move(other.varLegTenor)),
    callTenor(std::move(other.callTenor))
{}

template <typename Underlying_type>
CallableRangeAccrual<Underlying_type>::CallableRangeAccrual(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int fixedIncrement,
    int varIncrement,
    int callIncrement,
    ql::Rate const& payoff_,
    ql::Rate const& fixedRate_,
    double const& notional_,
    Underlying_type const& rangeMax_,
    Underlying_type const& rangeMin_
)
    : payoff(payoff_),
    fixedRate(fixedRate_),
    notional(notional_),
    rangeMax(rangeMax_),
    rangeMin(rangeMin_)
{
    /*
        Must check before initializing!
    */
    checkLimitDates(startDate, true, calendar);
    checkLimitDates(endDate  , false, calendar);
    fixedLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        fixedIncrement
    );
    varLegTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        varIncrement
    );
    callTenor = generateTenor(
        startDate,
        endDate,
        calendar,
        callIncrement
    );
}

template <typename Underlying_type>   
CallableRangeAccrual<Underlying_type>::~CallableRangeAccrual(){}

template <typename Underlying_type>   
double CallableRangeAccrual<Underlying_type>::computeExerciseValue(
    Path<Underlying_type> const& path,
    ql::Date const& startDate,
    ql::Date const& endDate,
    double const& discountRate
){
    
}

template <typename Underlying_type> 
double CallableRangeAccrual<Underlying_type>::computeFixedLeg(
    ql::Date const& startDate,
    ql::Date const& endDate,
    double const& discountRate
){
    if(endDate < fixedLegTenor[1])
        return 0.0;
    else{
        double fixedCoupon = 0.0;
        double fixedIncrement = daysBetween(fixedLegTenor[0], fixedLegTenor[1]) / 365.0;
        for(int i = 1; i < fixedLegTenor.size(); ++i){
            auto fixedDate = fixedLegTenor[i];
            if(fixedDate >= startDate && fixedDate <= endDate)
                fixedCoupon += fixedRate * notional * fixedIncrement * exp(discountRate * daysBetween(fixedDate, endDate) / 365.0);
        }
        return fixedCoupon;
    }
}

template <typename Underlying_type> 
double CallableRangeAccrual<Underlying_type>::computeVariableLeg(
    Path<Underlying_type> const& path,
    ql::Calendar const& calendar,
    ql::Date const& startDate,
    ql::Date const& endDate,
    double const& discountRate
){
    int startIndex = calendar.businessDaysBetween(varLegTenor[0], startDate);
    int endIndex   = calendar.businessDaysBetween(varLegTenor[0], endDate);

    std::cout << "start index is: " << startIndex << std::endl;
    std::cout << "end index is: " << endIndex     << std::endl;

    int periodBusinessDays = calendar.businessDaysBetween(startDate, endDate);
    int variableDelta = ql::daysBetween(varLegTenor[0], varLegTenor[1]) / 365.0;

    std::vector<double> inRangeRatios;
    std::transform(
        varLegTenor.begin() + 1,
        varLegTenor.end(),
        std::back_inserter(inRangeRatios),
        [](ql::Date varLegDate) -> double {
            double inRangeRatio = 0;
            double discountFactor = 
                (varLegDate > endDate) ? 1.0 : exp(discountRate * daysBetween(varLegDate, endDate));
            for(int j = startIndex; j <= endIndex; ++i){
                if(path[i] >= rangeMin && path[i] <= rangeMax)
                    inRangeRatio += (1.0 / periodBusinessDays);     
            }
            
            return 
                payoff *
                inRangeRatio *
                discountFactor *
                variableDelta;
        }
    );
    return std::accumulate(inRangeRatios.begin(), inRangeRatios.end(), 0.0);
}

template <typename TT>
std::ostream& operator<<(std::ostream& oStream, CallableRangeAccrual<TT> const& cra){
    oStream << 
    "Callable range accrual contract info:" << std::endl <<

    "start date: "             << cra.fixedLegTenor.front() << std::endl <<
    "end date: "               << cra.fixedLegTenor.back()  << std::endl <<

    "max range of the range : " << cra.rangeMax << std::endl <<
    "min range of the range : " << cra.rangeMin << std::endl <<

    "payoff: "                 << cra.payoff     << std::endl <<
    "fixed rate: "             << cra.fixedRate  << std::endl <<
    "cra.fixedLegTenor[1]= "   << cra.fixedLegTenor[1] << std::endl <<
    "cra.varLegTenor  [1]= "   << cra.varLegTenor  [1] << std::endl <<

    "size of fixed tenor: "    << cra.fixedLegTenor.size() << std::endl <<
    "size of variable tenor: " << cra.varLegTenor.size();
    return oStream;
}

