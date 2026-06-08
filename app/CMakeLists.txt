# add exacutable to you app
add_executable(ANNFromScratch main.cpp)

# Add library to you executable 
target_link_libraries(ANNFromScratch PRIVATE Qt6::Widgets
    Qt6::Quick 
    ANNUi 
    ANNCore)


if(WIN32)
     get_target_property(_qmake_executable Qt6::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    if(WINDEPLOYQT_EXECUTABLE)
        # Run windeployqt  
        add_custom_command(TARGET ANNFromScratch POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-translations --no-opengl-sw --compiler-runtime "$<TARGET_FILE:ANNFromScratch>"
            COMMENT "Running windeployqt to copy Qt DLLs into the build directory..."
        )
    else()
        message(WARNING "windeployqt not found. You may need to copy DLLs manually.")
    endif()
endif()