# CMakeList.txt : projet CMake pour CMakeProject, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

# Activez Rechargement à chaud pour les compilateurs MSVC si cela est pris en charge.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project("CMakeProject")

find_package(fmt REQUIRED)
find_package(SFML 3 REQUIRED COMPONENTS Graphics Window Audio System)

add_subdirectory(bliblioitek)

set(CPM_DOWNLOAD_VERSION 0.38.8)
include(CPM.cmake)

CPMAddPackage(
	NAME Catch2
	GITHUB_REPOSITORY CatchOrg/Catch2
	VERSION 3.6.0
	OPTIONS "CATCH_BUILD_TESTING OFF"
)

enable_testing()

# Ajoutez une source à l'exécutable de ce projet.
add_executable (CMakeProject "src/CMakeProject.cpp" "include/CMakeProject.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(CMakeProject PRIVATE bliblioitek fmt::fmt SFML::Graphics SFML::Window SFML::Audio SFML::System)
target_link_libraries(CMakeProject PRIVATE Catch2::Catch2WithMain)

include(${Catch2_SOURCE_DIR}/extras/Catch.cmake)
catch_discover_tests(CMakeProject)
# TODO: Ajoutez des tests et installez des cibles si nécessaire.
