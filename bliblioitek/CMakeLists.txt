add_library(bliblioitek "../bliblioitek/Source.cpp" "PasSoure.cpp")

target_include_directories(bliblioitek PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(bliblioitek PROPERTIES UNITY_BUILD ON)

set(UNITY_BUILD_BATCH_SIZE 2)
