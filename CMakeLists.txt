cmake_minimum_required(VERSION 3.1)
project(fixme)

set(CMAKE_CXX_STANDARD 14)

# Find Boost
find_package(Boost REQUIRED program_options system)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${CMAKE_SOURCE_DIR}/include)

set(fixme_SRC
	fixme/connection.cpp
	fixme/fields.cpp
	fixme/fixme.cpp
	fixme/market.cpp
	fixme/options.cpp
	fixme/parser.cpp
	fixme/server.cpp
)

add_executable(fixme ${fixme_SRC})

target_link_libraries(fixme
	pthread
	${Boost_PROGRAM_OPTIONS_LIBRARY}
	${Boost_SYSTEM_LIBRARY}
)
