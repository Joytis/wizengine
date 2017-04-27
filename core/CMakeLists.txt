#
# Library Sources

# Executable
#======================================================================
add_library(wizengine SHARED ${CORE_SOURCES} ${CORE_HEADERS})

#
# Includes
#=====================================================================
include_directories(
    ${PROJECT_SOURCE_DIR}/core/include
)

target_link_libraries(
        ${SFML_LIBRARIES} 
        ${Boost_LIBRARIES}
   	)
