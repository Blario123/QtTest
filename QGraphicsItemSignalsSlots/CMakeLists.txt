cmake_minimum_required(VERSION 3.20)
project(QtQGraphicsItemSignalsSlots)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH  ~/Qt/6.2.1/gcc_64/)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(HSOURCE CarPanel.h main.h)
set(CPPSOURCE main.cpp CarPanel.cpp)

add_executable(QtQGraphicsItemSignalsSlots ${HSOURCE} ${CPPSOURCE})
target_link_libraries(QtQGraphicsItemSignalsSlots
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

