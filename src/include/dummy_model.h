#pragma once

#include <definitions.h>
#include <models.h>

class DummyModel : Models<double>{
    public:
        DummyModel();
        ~DummyModel();
        double simulateValue(int daysFromStartDate) const override;
        Path<double> generatePath(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar
        ) const override;
    private:
        
        void calibrate(std::vector<std::istream> const& data) override;
};