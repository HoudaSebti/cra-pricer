# QUANTLIB_FOUND
# QUANTLIB_INCLUDE_DIR
# QUANTLIB_LIBRARY

find_path(QUANTLIB_INCLUDE_DIR
    NAMES ql/version.hpp
    HINTS /usr/include /usr/local/include /opt/local/include
)
find_library(QUANTLIB_LIBRARY
    NAMES QuantLib libQuantLib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(QUANTLIB DEFAULT_MSG QUANTLIB_LIBRARY QUANTLIB_INCLUDE_DIR)

mark_as_advanced(
    QUANTLIB_INCLUDE_DIR
    QUANTLIB_LIBRARY
)
