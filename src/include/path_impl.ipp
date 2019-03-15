#pragma once


template <typename Underlying_type>
Path<Underlying_type>::Path(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar){
        elements(calendar.businessDaysBetween(startDate, endDate));
}

template <typename Underlying_type>
Path<Underlying_type>::~Path(){};

template <typename Underlying_type>
double Path<Underlying_type>::computeCashFlow(
    ql::Rate const& payoff,
    Underlying_type const& rangeMax,
    Underlying_type const& rangeMin
){
    return 0.0;
}

template <typename Underlying_type>
void Path<Underlying_type>::addElement(Underlying_type const& element){
    elements.push_back(element);
}

template <typename Underlying_type>
Underlying_type Path<Underlying_type>::getElement(int const& position){
    return elements[position];
}

template <typename Underlying_type>
int Path<Underlying_type>::getSize(){
    return elements.size();
}
