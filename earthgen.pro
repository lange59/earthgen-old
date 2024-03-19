######################################################################
# Automatically generated by qmake (2.01a) Thu Mar 21 12:08:47 2013
######################################################################

MOC_DIR = moc

TEMPLATE = app
config += qt console
QMAKE_CXXFLAGS += -std=c++17
QT += opengl
DESTDIR = release
OBJECTS_DIR = release/.obj
TARGET = earthgen
DEPENDPATH += . \
              source \
              source/gui \
              source/hash \
              source/math \
              source/planet \
              source/render \
              source/planet/climate \
              source/planet/grid \
              source/planet/terrain \
              source/render/render_data
INCLUDEPATH += . \
               source/gui \
               source/math \
               source/planet \
               source/planet/grid \
               source/planet/terrain \
               source/planet/climate \
               source/render \
               source/hash

# Input
HEADERS += source/gui/axisBox.h \
           source/gui/climateBox.h \
           source/gui/displayBox.h \
           source/gui/mainMenu.h \
           source/gui/mainWindow.h \
           source/gui/planetHandler.h \
           source/gui/planetWidget.h \
           source/gui/terrainBox.h \
           source/gui/util.h \
           source/hash/md5.h \
           source/math/math_common.h \
           source/math/matrix2.h \
           source/math/matrix3.h \
           source/math/quaternion.h \
           source/math/vector2.h \
           source/math/vector3.h \
           source/render/color.h \
           source/render/empty_renderer.h \
           source/render/globe_renderer.h \
           source/render/hammer_projection.h \
           source/render/hammer_tile.h \
           source/render/map_renderer.h \
           source/render/planet_colors.h \
           source/render/planet_renderer.h \
           source/planet/climate/climate.h \
           source/planet/climate/climate_generation.h \
           source/planet/climate/climate_parameters.h \
           source/planet/climate/climate_structs.h \
           source/planet/climate/season.h \
           source/planet/grid/corner.h \
           source/planet/grid/create_grid.h \
           source/planet/grid/edge.h \
           source/planet/grid/grid.h \
           source/planet/grid/grid_util.h \
           source/planet/grid/tile.h \
           source/planet/terrain/terrain.h \
           source/planet/terrain/terrain_generation.h \
           source/planet/terrain/terrain_parameters.h \
           source/planet/terrain/terrain_structs.h
SOURCES += source/main.cpp \
           source/gui/axisBox.cpp \
           source/gui/climateBox.cpp \
           source/gui/displayBox.cpp \
           source/gui/mainMenu.cpp \
           source/gui/mainWindow.cpp \
           source/gui/planetHandler.cpp \
           source/gui/planetWidget.cpp \
           source/gui/terrainBox.cpp \
           source/gui/util.cpp \
           source/hash/md5.cpp \
           source/math/matrix2.cpp \
           source/math/matrix3.cpp \
           source/math/quaternion.cpp \
           source/math/vector2.cpp \
           source/math/vector3.cpp \
           source/render/color.cpp \
           source/render/globe_renderer.cpp \
           source/render/hammer_projection.cpp \
           source/render/hammer_tile.cpp \
           source/render/map_renderer.cpp \
           source/render/planet_colors.cpp \
           source/render/planet_renderer.cpp \
           source/planet/climate/climate.cpp \
           source/planet/climate/climate_generation.cpp \
           source/planet/climate/climate_structs.cpp \
           source/planet/grid/corner.cpp \
           source/planet/grid/create_grid.cpp \
           source/planet/grid/edge.cpp \
           source/planet/grid/grid.cpp \
           source/planet/grid/grid_util.cpp \
           source/planet/grid/tile.cpp \
           source/planet/terrain/terrain.cpp \
           source/planet/terrain/terrain_generation.cpp \
