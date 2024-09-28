//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#include "string"

#include "layout.h"

#include <imgui.h>
#include <imgui_internal.h>

HV_NS_OPEN

static const std::string DefaultLayout = R"(
[Window][Debug##Default]
Pos = 119, 48
Size = 400, 400
Collapsed = 0


)";

void LoadLayout() {
	const char* layoutData = DefaultLayout.c_str();
	const size_t layoutDataSize = DefaultLayout.size();
	ImGui::LoadIniSettingsFromMemory(layoutData, layoutDataSize);
}

HV_NS_CLOSE