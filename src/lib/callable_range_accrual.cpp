#include <callable_range_accrual.h>

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

CallableRangeAccrual::CallableRangeAccrual()
{}
CallableRangeAccrual::~CallableRangeAccrual()
{}

std::vector<ql::Date> CallableRangeAccrual::generateTenor(
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
