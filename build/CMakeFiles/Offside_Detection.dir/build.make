# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build

# Include any dependencies generated for this target.
include CMakeFiles/Offside_Detection.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Offside_Detection.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Offside_Detection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Offside_Detection.dir/flags.make

CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o: CMakeFiles/Offside_Detection.dir/flags.make
CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o: ../Src/edgeDetection.cpp
CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o: CMakeFiles/Offside_Detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o -MF CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o.d -o CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o -c /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/edgeDetection.cpp

CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/edgeDetection.cpp > CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.i

CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/edgeDetection.cpp -o CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.s

CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o: CMakeFiles/Offside_Detection.dir/flags.make
CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o: ../Src/offside.cpp
CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o: CMakeFiles/Offside_Detection.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o -MF CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o.d -o CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o -c /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/offside.cpp

CMakeFiles/Offside_Detection.dir/Src/offside.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Offside_Detection.dir/Src/offside.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/offside.cpp > CMakeFiles/Offside_Detection.dir/Src/offside.cpp.i

CMakeFiles/Offside_Detection.dir/Src/offside.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Offside_Detection.dir/Src/offside.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/Src/offside.cpp -o CMakeFiles/Offside_Detection.dir/Src/offside.cpp.s

# Object files for target Offside_Detection
Offside_Detection_OBJECTS = \
"CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o" \
"CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o"

# External object files for target Offside_Detection
Offside_Detection_EXTERNAL_OBJECTS =

Offside_Detection: CMakeFiles/Offside_Detection.dir/Src/edgeDetection.cpp.o
Offside_Detection: CMakeFiles/Offside_Detection.dir/Src/offside.cpp.o
Offside_Detection: CMakeFiles/Offside_Detection.dir/build.make
Offside_Detection: /usr/local/lib/libopencv_gapi.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_stitching.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_aruco.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_barcode.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_bgsegm.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_bioinspired.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_ccalib.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_dnn_objdetect.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_dnn_superres.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_dpm.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_face.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_freetype.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_fuzzy.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_hfs.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_img_hash.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_intensity_transform.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_line_descriptor.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_mcc.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_quality.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_rapid.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_reg.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_rgbd.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_saliency.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_stereo.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_structured_light.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_superres.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_surface_matching.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_tracking.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_videostab.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_wechat_qrcode.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_xfeatures2d.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_xobjdetect.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_xphoto.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_shape.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_highgui.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_datasets.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_plot.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_text.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_ml.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_phase_unwrapping.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_optflow.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_ximgproc.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_video.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_videoio.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_imgcodecs.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_objdetect.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_calib3d.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_dnn.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_features2d.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_flann.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_photo.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_imgproc.so.4.7.0
Offside_Detection: /usr/local/lib/libopencv_core.so.4.7.0
Offside_Detection: CMakeFiles/Offside_Detection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Offside_Detection"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Offside_Detection.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Offside_Detection.dir/build: Offside_Detection
.PHONY : CMakeFiles/Offside_Detection.dir/build

CMakeFiles/Offside_Detection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Offside_Detection.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Offside_Detection.dir/clean

CMakeFiles/Offside_Detection.dir/depend:
	cd /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5 /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5 /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build /home/parsa/Documents/Unipd/2ndSem-30/3-ComputerVision-21-June/LAB5/build/CMakeFiles/Offside_Detection.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Offside_Detection.dir/depend

