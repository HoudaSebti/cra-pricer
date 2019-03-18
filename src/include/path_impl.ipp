#pragma once


template <typename Underlying_type>
Path<Underlying_type>::Path(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Calendar const& calendar){
        elements.reserve(calendar.businessDaysBetween(startDate, endDate));
}

template<typename Underlying_type>
Path<Underlying_type>::Path(Path const& other):
    elements(other.elements)
{}

template<typename Underlying_type>
Path<Underlying_type>::Path(Path && other):
    elements(std::move(other.elements))
{}

template <typename Underlying_type>
Path<Underlying_type>::~Path(){};

template <typename Underlying_type>
double Path<Underlying_type>::computeCashFlow(
    ql::Date const& startDate,
    ql::Date const& endDate,
    ql::Rate const& riskFreeRate,
    ql::Rate const& fixedRate,
    ql::Rate const& payout,
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

template <typename Underlying_type>
bool Path<Underlying_type>::empty() const{
    return elements.empty();
}

template<typename TT>
void saveToCsv(std::string const& pathName, std::vector<Path<TT>> const& paths){
    std::vector<std::vector<TT>> pathsElements(paths.size());
    std::transform(
        paths.begin(),
        paths.end(),
        pathsElements.begin(),
        [](Path<TT> const& path){
            return path.elements;
        }
    );

    CSV_Handler(pathName).write(pathsElements);
}
