cmake_minimum_required(VERSION 3.11)
project(bulletoid)

enable_language(CXX)
add_compile_options(-Wall -Werror)

set(SFML_DIR SFML/lib/cmake/SFML)
set(APP_SOURCES Game/main.cpp Game/Game.cpp Game/Platform.cpp Game/AliveObjects/Entity.cpp
        Engine/CheckKey.cpp Engine/Collision.cpp Engine/Timer.cpp)

if(TIDY)
        set(CMAKE_CXX_CLANG_TIDY
                clang-tidy;
                --format-style=file;
                --header-filter=.*;
			)
        message(STATUS "clang-tidy ON")
endif()

if(FORMAT)
        file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.hpp)
        add_custom_target(
                format
                COMMAND clang-format
    	        -style=file
                -i
                ${ALL_SOURCE_FILES}
		)
        message(STATUS "clang-format ON")
endif()

add_executable(game ${APP_SOURCES})

find_package(SFML 2.5 COMPONENTS graphics REQUIRED window system network audio REQUIRED)
target_link_libraries(game sfml-graphics sfml-window sfml-system sfml-network sfml-audio)

add_custom_target(run COMMENT "Running the game" COMMAND ./game)
add_dependencies(run game)