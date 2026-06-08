add_library(ANNUi STATIC 
    components/graph/Ploter.hpp
    components/graph/Ploter.cpp 
)

 
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_add_qml_module(ANNUi
    URI ANNUi
    VERSION 1.0
    RESOURCE_PREFIX /qt/qml
     OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/ANNUi
    QML_FILES 
        qml/components/Presentor.qml
)

target_include_directories(ANNUi PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(ANNUi PRIVATE Qt6::Widgets Qt6::Quick)