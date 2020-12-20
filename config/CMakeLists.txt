include_directories(${PROJECT_SOURCE_DIR}/config)

file(GLOB SOURCES "*.cpp")
add_library(config SHARED ${SOURCES})
install(TARGETS config DESTINATION bin)
