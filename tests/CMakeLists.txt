
add_executable(eng_tests ${TEST_SOURCES})

# Assets
#======================================================================
# add_custom_command(TARGET eng_tests POST_BUILD
#         COMMAND ${CMAKE_COMMAND} -E copy_directory
#         ${PROJECT_SOURCE_DIR}/assets $<TARGET_FILE_DIR:clarkwaylife>/assets)

#
# Includes
#=====================================================================
include_directories(
    ${PROJECT_SOURCE_DIR}/tests/include
)

# Linking
#==========================================================================

target_link_libraries(eng_tests
        wizengine
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBS}
        ${Boost_LIBRARIES}
        )
