cmake_minimum_required(VERSION 3.14)

project(RevelationPluginSample)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(jsoncpp CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED 
			dllmain.cpp

			RevelationPluginSampleInterface.cpp
			RevelationPluginSampleInterface.h
)

if(MSVC)
set_property(TARGET ${PROJECT_NAME} PROPERTY FOLDER Revelation)
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "$<1:${REVELATION_OUTPUT_DIR}/Debug/extensions/${PROJECT_NAME}>"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "$<1:${REVELATION_OUTPUT_DIR}/Release/extensions/${PROJECT_NAME}>"
    RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "$<1:${REVELATION_OUTPUT_DIR}/RelWithDebInfo/extensions/${PROJECT_NAME}>"
    LIBRARY_OUTPUT_DIRECTORY_DEBUG "$<1:${REVELATION_OUTPUT_DIR}/Debug/extensions/${PROJECT_NAME}>"
    LIBRARY_OUTPUT_DIRECTORY_RELEASE "$<1:${REVELATION_OUTPUT_DIR}/Release/extensions/${PROJECT_NAME}>"
    LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO "$<1:${REVELATION_OUTPUT_DIR}/RelWithDebInfo/extensions/${PROJECT_NAME}>"
    ARCHIVE_OUTPUT_DIRECTORY_DEBUG "$<1:${REVELATION_OUTPUT_DIR}/Debug/extensions/${PROJECT_NAME}>"
    ARCHIVE_OUTPUT_DIRECTORY_RELEASE "$<1:${REVELATION_OUTPUT_DIR}/Release/extensions/${PROJECT_NAME}>"
    ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO "$<1:${REVELATION_OUTPUT_DIR}/RelWithDebInfo/extensions/${PROJECT_NAME}>"
)
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /Od")
endif()

target_link_libraries(${PROJECT_NAME} Qt6::Widgets)
target_link_libraries(${PROJECT_NAME} FluUtils)
target_link_libraries(${PROJECT_NAME} FluControls)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../Include)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../FluentUI/FluControls)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../FluentUI/FluUtils)
