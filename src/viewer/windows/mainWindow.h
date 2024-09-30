//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#pragma once

#include <string>

#include "../hv.h"

HV_NS_OPEN

class MainWindow {

public:

	MainWindow();

	~MainWindow();

	void Update();

private:

	void _DrawMenuBar();
	void _DrawLoadUsdFile();
	void _DrawAboutDialog();

	void _LoadUsdStage(const std::string& filePath);

	bool mShowAbout{ false };
};

HV_NS_CLOSE