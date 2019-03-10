#pragma<once>

#include<definitions.h>
#include<models_creator.h>

template <typename Underlying_type>
 std::vector<Underlying_type> generatePath(ql::Date startDate, ql::Date endDate, ql::Calendar calendar);
