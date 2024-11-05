/*
 * Copyright (C) 2006-2018 Istituto Italiano di Tecnologia (IIT)
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms of the
 * BSD-3-Clause license. See the accompanying LICENSE file for details.
 */

#include <sharedlibpp/version.h>

int sharedlibpp::getVersionMajor()
{
    return SHLIBPP_VERSION_MAJOR;
}

int sharedlibpp::getVersionMinor()
{
    return SHLIBPP_VERSION_MINOR;
}

int sharedlibpp::getVersionPatch()
{
    return SHLIBPP_VERSION_PATCH;
}

std::string sharedlibpp::getVersion()
{
    return SHLIBPP_VERSION;
}
