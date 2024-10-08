project(imgui)

set(SRC_CPP
	"imgui/imgui.cpp"
	"imgui/imgui_demo.cpp"
	"imgui/imgui_draw.cpp"
	"imgui/imgui_tables.cpp"
	"imgui/imgui_widgets.cpp"
	"imgui/backends/imgui_impl_opengl3.cpp"
	"imgui/backends/imgui_impl_glfw.cpp"
	"imgui/misc/cpp/imgui_stdlib.cpp"
)

set(SRC_H
	"imgui/imgui_internal.h"
	"imgui/misc/cpp/imgui_stdlib.h"
)

set(PUBLIC_HEADER
	"imgui/imgui.h"
	"imgui/backends/imgui_impl_opengl3.h"
	"imgui/backends/imgui_impl_glfw.h"
)

add_library(${PROJECT_NAME} 
	${SRC_CPP} 
	${SRC_H} 
	${PUBLIC_HEADER}
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        IMGUI_IMPL_OPENGL_LOADER_GL3W=1
        # IMGUI_DISABLE_OBSOLETE_FUNCTIONS # to check for obsolete functions
        # IMGUI_USER_CONFIG="${PROJECT_SOURCE_DIR}/path/to/imconfig.h" # to use your own imconfig.h
)
target_include_directories(${PROJECT_NAME}
    PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/imgui"
        "${CMAKE_CURRENT_SOURCE_DIR}/imgui/backends"
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC
		glfw
)
set_target_properties(${PROJECT_NAME}
    PROPERTIES
        PUBLIC_HEADER "${PUBLIC_HEADERS}"
)