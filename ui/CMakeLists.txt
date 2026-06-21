qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_add_qml_module(ANNUi
    STATIC
    URI ANNUi
    VERSION 1.0
    RESOURCE_PREFIX /qt/qml
    OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ANNUi
    QML_FILES 
        qml/components/Presentor.qml
)

 target_sources(ANNUi PRIVATE 
    components/graph/Ploter.cpp
    components/graph/Ploter.hpp
    windows/mainWindow.hpp
   windows/mainWindow.cpp
)

target_include_directories(ANNUi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ANNUi PRIVATE Qt6::Widgets Qt6::Quick Qt6::Qml Qt6::QuickWidgets ANNCore)