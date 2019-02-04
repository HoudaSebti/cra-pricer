# DOCOPT_FOUND
# DOCOPT_INCLUDE_DIR
# DOCOPT_LIBRARY

find_path(
    DOCOPT_INCLUDE_DIR
    NAMES docopt/docopt.hpp
    HINTS /usr/include /usr/local/include /opt/local/include
)
find_library(
    DOCOPT_LIBRARY
    NAMES docopt libdocopt
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(docopt DEFAULT_MSG DOCOPT_LIBRARY DOCOPT_INCLUDE_DIR)

mark_as_advanced(
    DOCOPT_INCLUDE_DIR
    DOCOPT_LIBRARY
)

