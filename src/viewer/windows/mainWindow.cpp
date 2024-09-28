//
//  Create by AhrenLi (https://github.com/AhrenLi) on $YEAR$/$MONTH$/$DAY$.
//

#include "mainWindow.h"
#include "../utils/logger.h"

#include <imgui.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <stdlib.h> 

HV_NS_OPEN

MainWindow::MainWindow() {

}

MainWindow::~MainWindow() {
}

void MainWindow::Update() {
	_DrawMenuBar();
	_DrawAboutDialog();

}

void MainWindow::_DrawMenuBar() {
	if (ImGui::BeginMainMenuBar()) {
		// File
		if (ImGui::BeginMenu("File")) {
			ImGui::MenuItem("Open");

			ImGui::EndMenu();
		}
		// About
		if (ImGui::BeginMenu("Help")) {
			if (ImGui::MenuItem("About")) {
				mShowAbout = true;
			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
}

void MainWindow::_DrawAboutDialog() {
	if (mShowAbout) {
		ImGui::OpenPopup("About Dialog");
		mShowAbout = false;
	}

	if (ImGui::BeginPopup("About Dialog", ImGuiWindowFlags_AlwaysAutoResize)) {

		LOG_INFO("Show About Dialog");

		ImGui::Text("Copyright©2024 AhrenLi");
		ImGui::Text("Github:");
		ImGui::SameLine();

		static const char* url = "https://github.com/AhrenLi/HydraViewer";
		if (ImGui::Selectable(url, false)) {
#ifdef WIN32
			ShellExecute(0, 0, url, 0, 0, SW_SHOW);
#else
			std::string command = "xdg-open " + std::string(url);
			system(command.c_str());
#endif
		}

		ImGui::Separator();

		if (ImGui::Button("Sure")) {
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
	}

}


HV_NS_CLOSE