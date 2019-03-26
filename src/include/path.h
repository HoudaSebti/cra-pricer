#pragma once

#include<definitions.h>
#include<csv_handler.h>

#include <fstream>


template <typename Underlying_type>
class Path{
    public:
        Path<Underlying_type>(
            ql::Date const& startDate,
            ql::Date const& endDate,
            ql::Calendar const& calendar
        );
        Path<Underlying_type>(Path const& other);
        Path<Underlying_type>(Path && other);
        ~Path<Underlying_type>();
        void addElement(Underlying_type const& element);
        Underlying_type getElement(int const& position);
        int getSize();
        bool empty() const;
        template<typename TT>
        friend void saveToCsv(std::string const& pathName, std::vector<Path<TT>> const& paths);
    private:

        std::vector<Underlying_type> elements;
};

#include <path_impl.ipp>