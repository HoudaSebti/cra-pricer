#include <dummy_model.h>

DummyModel::DummyModel(){};
DummyModel::~DummyModel(){};
double DummyModel::simulateValue(int daysFromStartDate) const{
        return 0.0;
}

Path<double> DummyModel::generatePath(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar
) const{
    Path<double> path(
        startDate,
        endDate,
        calendar
    );
    for(auto t = 0; t < path.getSize(); ++t)
        path.addElement(DummyModel::simulateValue(t));
    return path;
}
void DummyModel::calibrate(std::vector<std::istream> const& data){

    }
