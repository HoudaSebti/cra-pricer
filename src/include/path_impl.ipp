#pragma once


template <typename Underlying_type>
Path<Underlying_type>::Path(ql::Date startDate, ql::Date endDate, ql::Calendar calendar){
    elements.reserve(calendar.businessDaysBetween(startDate, endDate));
}

template <typename Underlying_type>
Path<Underlying_type>::~Path(){};

template <typename Underlying_type>
double Path<Underlying_type>::computeCashFlow(
    ql::Rate payoff,
    Underlying_type rangeMax,
    Underlying_type rangeMin
){
    return 0.0;
}

template <typename Underlying_type>
void Path<Underlying_type>::addElement(Underlying_type element){
    elements.push_back(element);
}

template <typename Underlying_type>
Underlying_type Path<Underlying_type>::getElement(int position){
    return elements[position];
}

template <typename Underlying_type>
int Path<Underlying_type>::getSize(){
    return elements.size();
}
