//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#include "mainWindow.h"
#include "../utils/logger.h"

#include <imgui.h>
#include <ImGuiFileDialog.h>

#ifdef WIN32
#include <windows.h>
#endif
#include <stdlib.h> 

HV_NS_OPEN

static inline constexpr auto LoadUsdFile = "LoadUsdFile";

MainWindow::MainWindow() {

}

MainWindow::~MainWindow() {
}

void MainWindow::Update() {
	_DrawMenuBar();
	_DrawLoadUsdFile();
	_DrawAboutDialog();
}

void MainWindow::_DrawMenuBar() {
	if (ImGui::BeginMainMenuBar()) {
		// File
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("Open")) {
				IGFD::FileDialogConfig config;
				config.path = ".";
				config.countSelectionMax = 1;
				config.flags = ImGuiFileDialogFlags_Modal;
				ImGuiFileDialog::Instance()->OpenDialog(LoadUsdFile, "Choose File", ".usd,.usdc,.usda,.usdz", config);
			}
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

void MainWindow::_DrawLoadUsdFile() {
	if (ImGuiFileDialog::Instance()->Display(LoadUsdFile)) {
		if (ImGuiFileDialog::Instance()->IsOk()) {
			const auto filePath = ImGuiFileDialog::Instance()->GetFilePathName();
			_LoadUsdStage(filePath);
		}
		ImGuiFileDialog::Instance()->Close();
	}
}

void MainWindow::_DrawAboutDialog() {
	if (mShowAbout) {
		ImGui::OpenPopup("About Dialog");
		mShowAbout = false;
	}

	if (ImGui::BeginPopup("About Dialog", ImGuiWindowFlags_AlwaysAutoResize)) {
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

		ImGui::Spacing();
		ImGui::Separator();

		if (ImGui::Button("Sure")) {
			ImGui::CloseCurrentPopup();
		}

		ImGui::EndPopup();
		}
	}

void MainWindow::_LoadUsdStage(const std::string& filePath) {
	LOG_ERROR("Todo: load usd stage at {}", filePath);
}

HV_NS_CLOSE