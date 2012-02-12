
project(screensaver)

cmake_minimum_required(VERSION 2.6)

find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)
FIND_PACKAGE( Boost 1.40 COMPONENTS system REQUIRED )

add_subdirectory(headers)
add_subdirectory(sources)
add_subdirectory(resources)

include_directories(
  ${QT_INCLUDES}
  ${KDE4_INCLUDES}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${screensaver_SOURCE_DIR}
  ${Boost_INCLUDE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}/gen
)

AUX_SOURCE_DIRECTORY( ${screensaver_SOURCE_DIR}/sources screensaver_SRCS)

qt4_automoc(${screensaver_SRCS})
kde4_add_ui_files( screensaver_SRCS ${screensaver_SOURCE_DIR}/resources/setup_dialog.ui )
add_executable(screensaver ${screensaver_SRCS})
target_link_libraries(
  screensaver
  ${QT_QTCORE_LIBRARY}
  ${QT_QTOPENGL_LIBRARY}
  ${KDE4_KDEUI_LIBS}
  ${KDE4_KPARTS_LIBS}
  libkscreensaver.so
  libglut.so
  libGL.so
  ${Boost_LIBRARIES}
  libGLU.so
)
