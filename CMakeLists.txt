cmake_minimum_required(VERSION 3.5)

project(TF VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        Store/main.cpp
        Store/mainwindow.cpp
        Store/mainwindow.h
        Store/mainwindow.ui
        Store/JanelaComanda.cpp
        Store/JanelaComanda.h
        Store/JanelaComanda.ui
        Store/janelapagamento.cpp
        Store/janelapagamento.h
        Store/janelapagamento.ui
        Store/adcionarprodutojanela.cpp
        Store/adcionarprodutojanela.h
        Store/adcionarprodutojanela.ui
        Store/verifica.cpp
        Store/verifica.h
        Store/verifica.ui
        src/Atendente.cpp
        src/Caixa.cpp
        src/Comanda.cpp
        src/Estoque.cpp
        src/Funcionario.cpp
        src/Gerente.cpp
        src/Produto.cpp
        include/Atendente.hpp
        include/Caixa.hpp
        include/Comanda.hpp
        include/Estoque.hpp
        include/Funcionario.hpp
        include/Gerente.hpp
        include/Produto.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TF
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TF APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TF SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TF
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(TF PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(TF PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS TF
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(TF)
endif()
