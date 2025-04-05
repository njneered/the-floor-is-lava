# Install script for directory: C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/NaviGatorGame")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2024.1.4/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/libtinyxml2.dll.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_runtime" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/libtinyxml2.dll")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libtinyxml2.dll" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libtinyxml2.dll")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "C:/Program Files/JetBrains/CLion 2024.1.4/bin/mingw/bin/strip.exe" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/libtinyxml2.dll")
    endif()
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2-shared-targets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2-shared-targets.cmake"
         "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/CMakeFiles/Export/a801c02ec1fcb42ccc21a747b2503e91/tinyxml2-shared-targets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2-shared-targets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2/tinyxml2-shared-targets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/CMakeFiles/Export/a801c02ec1fcb42ccc21a747b2503e91/tinyxml2-shared-targets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/CMakeFiles/Export/a801c02ec1fcb42ccc21a747b2503e91/tinyxml2-shared-targets-debug.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/tinyxml2" TYPE FILE FILES
    "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-src/cmake/tinyxml2-config.cmake"
    "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/tinyxml2-config-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-src/tinyxml2.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "tinyxml2_development" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "C:/Users/Nj/CLionProjects/the-floor-is-lava/cmake-build-debug/_deps/tinyxml2-build/tinyxml2.pc")
endif()

