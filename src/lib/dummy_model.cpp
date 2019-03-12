#include <dummy_model.h>

DummyModel::DummyModel(){};
DummyModel::~DummyModel(){};
double DummyModel::simulateValue(int daysFromStartDate) const{
        return 0.0;
    }
void DummyModel::calibrate(std::vector<std::istream> const& data){

    }
