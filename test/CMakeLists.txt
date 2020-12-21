# target_include_directories(${PROJECT_SOURCE_DIR}/build/lib)
include_directories(${PROJECT_SOURCE_DIR}/config
                    ${PROJECT_SOURCE_DIR}/lib/jsoncpp/include)
file(GLOB SOURCES "*.cpp")

# target_link_libraries(config)
add_executable(test_json test_json.cpp)
add_executable(test_config test_config.cpp)
add_executable(test_config_json test_config_json.cpp)
#target_link_libraries(test_json ${JSONCPP_LIBRARIES})
#target_link_libraries(test_config config)
target_link_libraries(test_config PUBLIC config ${PROJECT_SOURCE_DIR}/build/lib/libjsoncpp.so)
target_link_libraries(test_json PUBLIC config ${PROJECT_SOURCE_DIR}/build/lib/libjsoncpp.so)
target_link_libraries(test_config_json PUBLIC config ${PROJECT_SOURCE_DIR}/build/lib/libjsoncpp.so)
