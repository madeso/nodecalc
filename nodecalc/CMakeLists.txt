set(src main.cc)
source_group("" FILES ${src})

find_package(wxWidgets COMPONENTS core base gl)
include( "${wxWidgets_USE_FILE}" )
add_executable(nodecalc WIN32 MACOSX_BUNDLE ${src})
target_link_libraries(nodecalc
                      ${wxWidgets_LIBRARIES}
                      )

