file(GLOB_RECURSE TEST_SRC 
        "${cra_pricer_SOURCE_DIR}/src/tests/*.cpp"
    )
    
add_executable(tests ${TEST_SRC})
target_link_libraries(tests Catch2 algorithms models_creator csv_handler)
