#include <callable_range_accrual.h>


std::vector<ql::Date> generateTenor(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int increment
){
    std::vector<ql::Date> tenor = {{startDate}};
    tenor.reserve(daysBetween(startDate, endDate) / (increment * 30) + 2);
    while(tenor.back() <= endDate)
    {
        auto date = calendar.advance(tenor.back(), increment, ql::Months);
        if(calendar.isBusinessDay(date))
            tenor.push_back(date);
        else
            tenor.push_back(calendar.advance(date, -1, ql::Days));
    }       
    return tenor;
}


CallableRangeAccrual::CallableRangeAccrual(){}
CallableRangeAccrual::CallableRangeAccrual(CallableRangeAccrual const& other)
    : payoff (other.payoff),
      maxRate(other.maxRate),
      minRate(other.minRate),
      fixedLegTenor(other.fixedLegTenor),
      varLegTenor  (other.varLegTenor)
{}
CallableRangeAccrual::CallableRangeAccrual(CallableRangeAccrual && other)
    : payoff(std::move(other.payoff)),
      maxRate(std::move(other.maxRate)),
      minRate(std::move(other.minRate)),
      fixedLegTenor(std::move(other.fixedLegTenor)),
      varLegTenor(std::move(other.varLegTenor))
{}
CallableRangeAccrual::CallableRangeAccrual(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar,
    int fixedIncrement,
    int varIncrement,
    ql::Rate const& payoff_,
    ql::Rate const& maxRate_,
    ql::Rate const& minRate_
)
    : payoff(payoff_),
      maxRate(maxRate_),
      minRate(minRate_),
      fixedLegTenor(
          generateTenor(
              startDate,
              endDate,
              calendar,
              fixedIncrement
          )
      ),
      varLegTenor(
          generateTenor(
              startDate,
              endDate,
              calendar,
              varIncrement
          )
      )
      
{}
CallableRangeAccrual::~CallableRangeAccrual(){}


std::ostream &operator<<(std::ostream &oStream, CallableRangeAccrual const& cra){
    oStream << 
    "Callable range accrual contract info:\n" <<
    "start date: "             << cra.fixedLegTenor.front() << '\n' <<
    "end date: "               << cra.fixedLegTenor.back()  << '\n' <<

    "max rate of the range : " << cra.maxRate << '\n' <<
    "min rate of the range : " << cra.minRate << '\n' <<
    "payoff: "                 << cra.payoff  << '\n' <<

    "fixed increment: "    << daysBetween(cra.fixedLegTenor.front(), cra.fixedLegTenor[1]) << "days" << '\n' <<
    "variable increment: " << daysBetween(cra.varLegTenor.front()  , cra.varLegTenor[1]  )  << "days";

    return oStream;
}
