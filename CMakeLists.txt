add_library(pico_sht45 INTERFACE)

target_sources(pico_sht45 INTERFACE
  ${CMAKE_CURRENT_LIST_DIR}/src/pico_sht45.cpp
)

target_include_directories(pico_sht45 INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src ${CMAKE_CURRENT_LIST_DIR}/include)

# Pull in pico libraries that we need
target_link_libraries(pico_sht45 INTERFACE pico_stdlib hardware_i2c)
