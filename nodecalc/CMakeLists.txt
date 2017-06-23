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



set(src_lua
    ../external/lua/src/lapi.c
    ../external/lua/src/lauxlib.c
    ../external/lua/src/lbaselib.c
    ../external/lua/src/lbitlib.c
    ../external/lua/src/lcode.c
    ../external/lua/src/lcorolib.c
    ../external/lua/src/lctype.c
    ../external/lua/src/ldblib.c
    ../external/lua/src/ldebug.c
    ../external/lua/src/ldo.c
    ../external/lua/src/ldump.c
    ../external/lua/src/lfunc.c
    ../external/lua/src/lgc.c
    ../external/lua/src/linit.c
    ../external/lua/src/liolib.c
    ../external/lua/src/llex.c
    ../external/lua/src/lmathlib.c
    ../external/lua/src/lmem.c
    ../external/lua/src/loadlib.c
    ../external/lua/src/lobject.c
    ../external/lua/src/lopcodes.c
    ../external/lua/src/loslib.c
    ../external/lua/src/lparser.c
    ../external/lua/src/lstate.c
    ../external/lua/src/lstring.c
    ../external/lua/src/lstrlib.c
    ../external/lua/src/ltable.c
    ../external/lua/src/ltablib.c
    ../external/lua/src/ltm.c
    ../external/lua/src/lundump.c
    ../external/lua/src/lutf8lib.c
    ../external/lua/src/lvm.c
    ../external/lua/src/lzio.c
    )
source_group("lua" FILES ${src_lua})
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/external/lua/src/)
include_directories(SYSTEM ${CMAKE_SOURCE_DIR}/external/sol2/)
set(src ${src} ${src_lua})


find_package(Protobuf REQUIRED)
include_directories(SYSTEM ${PROTOBUF_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS ${CMAKE_SOURCE_DIR}/nodecalc.proto)
set(generated_proto ${PROTO_SRCS} ${PROTO_HDRS})
source_group("generated" FILES ${generated_proto})
set(src ${src} ${generated_proto})



add_executable(nodecalc WIN32 MACOSX_BUNDLE ${src})





find_package(wxWidgets COMPONENTS core base gl)
include("${wxWidgets_USE_FILE}" )
target_link_libraries(nodecalc ${wxWidgets_LIBRARIES})


target_link_libraries(nodecalc ${PROTOBUF_LIBRARIES})
