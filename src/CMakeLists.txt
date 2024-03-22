enable_language(ASM)

set(SWITCH_SOURCES switch.cpp x86_64/context.S)

add_library(switch_context STATIC ${SWITCH_SOURCES})
target_include_directories(switch_context PUBLIC ${CMAKE_CURRENT_LIST_DIR})