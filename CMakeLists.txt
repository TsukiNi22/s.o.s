cmake_minimum_required(VERSION 3.20)
set(TARGET sos)
project(${TARGET} VERSION 1.0 LANGUAGES CXX)

# =========================
# Compilateur & Standard
# =========================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # Moderne compilation -fPIE

# =========================
# Requirement
# =========================
find_package(PkgConfig REQUIRED)
find_program(CCACHE_PROGRAM ccache) # Used for cache during compilation
if (CCACHE_PROGRAM)
    set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif()

# =========================
# Warnings
# =========================
add_compile_options(
    -W
    -Wall
    -Wextra
    -Wpedantic
    -Wunused-parameter
    -Wshadow
    -Wuninitialized
)

# =========================
# Sources
# =========================
set(SRC
    # Optimized
    src/sos/optimized/embed_optimized.cpp
    src/sos/optimized/extract_optimized.cpp

    # Simplifed
    src/sos/simplified/embed_simplified.cpp
    src/sos/simplified/extract_simplified.cpp
)
add_library(${TARGET} STATIC ${SRC})
#add_library(${TARGET} SHARED ${SRC})

# =========================
# Dependencies
# =========================
target_include_directories(${TARGET} PUBLIC include)

# =========================
# Modes
# =========================
target_compile_options(${TARGET} PRIVATE
    $<$<CONFIG:Debug>:-g -ggdb3>
    $<$<CONFIG:Optimized>:-O3 -ffast-math -flto -funroll-loops -fvectorize -fslp-vectorize -march=native -fno-plt -pipe -DNDEBUG>
)

# =========================
# Installation
# =========================
include(GNUInstallDirs) # load variable used for installation

# library
install(TARGETS ${TARGET}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# header
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# =========================
# Utils
# =========================
add_custom_target(get_unregistered_files
    COMMAND bash ${CMAKE_SOURCE_DIR}/cmake/script/check_files.sh unregistered ${SRC}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
