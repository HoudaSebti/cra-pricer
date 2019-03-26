# Algorithms
set(ALGORITHMS_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/longstaff_schwartz.cpp"
)

add_library(algorithms ${ALGORITHMS_SRC})
target_link_libraries(algorithms ${LIBS})

# Models
set(MODELS_CREATOR_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/rate_models.cpp"
    "${cra_pricer_SOURCE_DIR}/src/lib/black_scholes.cpp"
    "${cra_pricer_SOURCE_DIR}/src/lib/dummy_model.cpp"
    "${cra_pricer_SOURCE_DIR}/src/lib/utilities.cpp"
)

add_library(models_creator ${MODELS_CREATOR_SRC})
target_link_libraries(models_creator ${LIBS})

# csv handler
set(CSV_HANDLER_SRC
    "${cra_pricer_SOURCE_DIR}/src/lib/csv_handler.cpp"
)

add_library(csv_handler ${CSV_HANDLER_SRC})
target_link_libraries(csv_handler ${LIBS})
