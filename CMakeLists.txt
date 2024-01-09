cmake_minimum_required(VERSION 3.27)
project(Forest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(Forest src/main.cpp
        src/App.cpp
        src/App.h
        src/includes.h
        src/trees/AVLTree/AVLNode.cpp
        src/trees/AVLTree/AVLNode.h
        src/trees/RBTree/RBNode.cpp
        src/trees/RBTree/RBNode.h
        src/trees/Treap/TreapNode.cpp
        src/trees/Treap/TreapNode.h
        src/trees/SplayTree/SplayNode.cpp
        src/trees/SplayTree/SplayNode.h)
target_link_libraries(Forest
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

