# Algorithms
set(ALGORITHMS_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/longstaff_schwartz.cpp"
)

add_library(algorithms ${ALGORITHMS_SRC})
target_link_libraries(algorithms ${LIBS})

# Calibrator
set(MODELS_CREATOR_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/models_creator.cpp"
    "${cra_pricer_SOURCE_DIR}/src/lib/utilities.cpp"
)

add_library(models_creator ${MODELS_CREATOR_SRC})
target_link_libraries(models_creator ${LIBS})
