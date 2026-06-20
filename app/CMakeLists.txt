add_executable(ANNFromScratch main.cpp)

target_link_libraries(ANNFromScratch PRIVATE 
    Qt6::Widgets
    Qt6::Quick 
    ANNUi 
    ANNCore
)

# Windows Deployment
if(WIN32)
    get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET ANNFromScratch POST_BUILD
             COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-translations --no-opengl-sw --compiler-runtime --qmldir "${CMAKE_SOURCE_DIR}/ui/qml" "$<TARGET_FILE:ANNFromScratch>"
            COMMENT "Running windeployqt to scan QML and copy Qt DLLs..."
        )
    endif()
endif()