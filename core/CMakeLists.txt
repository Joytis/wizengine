#
# Includes
#=====================================================================
include_directories(
    ${PROJECT_SOURCE_DIR}/core/include
)

# Executable
#======================================================================
add_library(wizengine SHARED ${CORE_SOURCES})
# target_link_libraries(
# 		wizengine
#         ${SFML_LIBRARIES} 
#         ${Boost_LIBRARIES}
#    	)
