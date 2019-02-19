
if(NOT TARGET Catch)
    include(ExternalProject)
    if(IS_TRAVIS_BUILD)     # on travis, use git for fetching instead of wget
        set(GB_FETCH_EXTERNAL_CATCH
            GIT_REPOSITORY https://github.com/catchorg/Catch2
            GIT_TAG dbbab8727c342733f75045483048cdcb52421e32)
    elseif(WIN32)
        set(GB_FETCH_EXTERNAL_CATCH
            URL https://github.com/catchorg/Catch2/archive/v2.6.1.zip
        )
    else()
        set(GB_FETCH_EXTERNAL_CATCH
            URL https://github.com/catchorg/Catch2/archive/v2.6.1.tar.gz
        )
    endif()
    ExternalProject_Add(libcatch
        PREFIX ${CMAKE_BINARY_DIR}/external/Catch
        ${GB_FETCH_EXTERNAL_CATCH}
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/external/Catch/src/libcatch/single_include/catch2
                                                           ${CMAKE_BINARY_DIR}/external/Catch/include/catch2
    )
    add_library(Catch2 INTERFACE)
    add_dependencies(Catch2 libcatch)
    target_include_directories(Catch2 INTERFACE ${CMAKE_BINARY_DIR}/external/Catch/include)
endif()
