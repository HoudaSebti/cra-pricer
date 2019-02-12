set(Callable_range_accrual_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/callable_range_accrual.cpp"
)

set(Longstaff_schwartz_algorithm_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/longstaff_schwartz.cpp"
)

#callable range accrual
add_library(callable_range_accrual ${Callable_range_accrual_SRC})
target_link_libraries(callable_range_accrual ${LIBS})

#longstaff schwartz algorithm
add_library(longstaff_schwartz_algorithm ${Longstaff_schwartz_algorithm_SRC})
target_link_libraries(longstaff_schwartz_algorithm ${LIBS})