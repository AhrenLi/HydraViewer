//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#pragma once

#define HV_MAJOR_VERSION 0
#define HV_MINOR_VERSION 1
#define HV_PATCH_VERSION 0

#define HV_VERSION 10

#define HV_USE_NAMESPACE 1

#if HV_USE_NAMESPACE

#define HV_NS HV

namespace HV_NS {
}

#define HV_NS_OPEN namespace HV_NS {
#define HV_NS_CLOSE }
#define HV_NS_USING using namespace HV_NS;

#endif // HV_USE_NAMESPACE