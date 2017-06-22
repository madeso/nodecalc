set(main_src main.cc proto.h proto.cc)
source_group("" FILES ${main_src})
set(src ${main_src})





set(pbjson_src
    ${CMAKE_SOURCE_DIR}/external/pbjson/src/pbjson.cpp
    ${CMAKE_SOURCE_DIR}/external/pbjson/src/pbjson.hpp
    ${CMAKE_SOURCE_DIR}/external/pbjson/src/bin2ascii.h
    )
source_group("pbjson" FILES ${pbjson_src})
include_directories(${CMAKE_SOURCE_DIR}/external/pbjson/src/)
set(src ${src} ${pbjson_src})



find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${CMAKE_SOURCE_DIR}/nodecalc.proto)
set(generated_proto ${PROTO_SRCS} ${PROTO_HDRS})
source_group("generated" FILES ${generated_proto})
set(src ${src} ${generated_proto})



add_executable(nodecalc WIN32 MACOSX_BUNDLE ${src})





find_package(wxWidgets COMPONENTS core base gl)
include( "${wxWidgets_USE_FILE}" )
target_link_libraries(nodecalc ${wxWidgets_LIBRARIES})


target_link_libraries(nodecalc ${PROTOBUF_LIBRARIES})
