# Callable range accrual
set(CRA_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/callable_range_accrual.cpp"
)

add_library(cra ${CRA_SRC})
target_link_libraries(cra ${LIBS})

#Algorithms
set(ALGORITHMS_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/longstaff_schwartz.cpp"
)

add_library(algorithms ${ALGORITHMS_SRC})
target_link_libraries(algorithms ${LIBS})

set(CALIBRATOR_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/calibrator.cpp"
    "${cra_pricer_SOURCE_DIR}/src/lib/utilities.cpp"
)

add_library(calibrator ${CALIBRATOR_SRC})
target_link_libraries(calibrator ${LIBS})
