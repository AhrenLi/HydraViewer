#include <iostream>

#include "viewer/hv.h"
#include "viewer/utils/logger.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <GLFW/glfw3.h>

HV_NS_USING

#define WINDOW_TITLE "Hydra Viewer"
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

static void glfw_error_callback(int error, const char* description)
{
	LOG_ERROR("GLFW Error {}:{}", error, description);
}

GLFWwindow* InitGLFWindow(const char* title) {
	glfwSetErrorCallback(glfw_error_callback);

	if (!glfwInit()) {
		LOG_ERROR("GLFW init failed!");
		return nullptr;
	}

	// Decide GL+GLSL versions
#if defined(__APPLE__)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);             // 3.2+ only
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // Required on Mac
#else
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // 3.0+ only
#endif

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, title, nullptr, nullptr);
	if (window == nullptr) {
		LOG_ERROR("Create GLFW window failed!");
		glfwTerminate();
		return nullptr;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync


	return window;
}

void TerminateGLFW(GLFWwindow* window)
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool InitImGui(GLFWwindow* window) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	//ImGui::StyleColorsLight();

#if defined(__APPLE__)
	const char* glsl_version = "#version 150";
#else
	const char* glsl_version = "#version 130";
#endif
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui_ImplGlfw_InitForOpenGL(window, true);

	// layout

	return true;
}

void TerminateImGui() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

int main() {
	// initialize logger
	Logger logger;

	// init glfw window
	auto* window = InitGLFWindow(WINDOW_TITLE);

	// init imgui 
	if (!window || !InitImGui(window)) return 1;

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();

		// render content

		ImGui::Render();

		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	}

	// Cleanup
	TerminateImGui();
	TerminateGLFW(window);

	return 0;
}