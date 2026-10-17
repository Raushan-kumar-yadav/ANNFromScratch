qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

qt_add_executable(neurolens_viewer
    main.cpp
    windows/mainWindow.cpp
    windows/mainWindow.hpp
    panels/scatter/Ploter.cpp
    panels/scatter/Ploter.hpp
)

qt_add_qml_module(neurolens_viewer
    URI NeuroLens.Viewer
    VERSION 1.0
    RESOURCE_PREFIX /qt/qml
    QML_FILES
        qml/panels/Presentor.qml
)

# headers are included relative to viewer/, e.g. "panels/scatter/Ploter.hpp"
target_include_directories(neurolens_viewer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(neurolens_viewer PRIVATE
    Qt6::Widgets
    Qt6::Quick
    Qt6::Qml
    Qt6::QuickWidgets
    neurolens_core
)

# Windows: copy the Qt DLLs next to the exe so it runs without Qt on PATH
if(WIN32)
    get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET neurolens_viewer POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-translations --no-opengl-sw --compiler-runtime
                    --qmldir "${CMAKE_CURRENT_SOURCE_DIR}/qml" "$<TARGET_FILE:neurolens_viewer>"
            COMMENT "Running windeployqt to copy Qt DLLs..."
        )
    endif()
endif()
