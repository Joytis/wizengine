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
        ${SDL2_LIBRARIES}
        -L${SDL2_IMAGE_LIBRARY_DIR} -lSDL2_image
        ${Boost_LIBRARIES}
   	)
