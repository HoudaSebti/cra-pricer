#pragma<once>

#include<definitions.h>
#include<models.h>

template <typename Underlying_type>
std::vector<Underlying_type> generatePath(ql::Date startDate, ql::Date endDate, ql::Calendar calendar);
template <typename Underlying_type>
class Path{
    public:
        double computeCashFlow(
            ql::Date startDate,
            ql::Date endDate,
            ql::Rate payoff,
            Underlying_type rangeMax,
            Underlying_type rangeMin
        );
    private:
        double computeFixedLeg(ql::Rate fixedRate, double fixedIncrementInYears);
    
};

