/***
 * Copyright (C) Microsoft. All rights reserved.
 * Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * win32_encryption_tests.cpp
 *
 * Tests for win32_encryption class.
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ****/

#include "stdafx.h"

using namespace utility;

namespace tests
{
namespace functional
{
namespace utils_tests
{
#if defined(_WIN32) && _WIN32_WINNT >= _WIN32_WINNT_VISTA && !defined(__cplusplus_winrt)
SUITE(win32_encryption)
{
    TEST(win32_encryption_random_string)
    {
        auto rndStr = std::wstring(L"random string");
        web::details::win32_encryption enc(rndStr);

        VERIFY_ARE_EQUAL(*enc.decrypt(), rndStr);
    }

    TEST(win32_encryption_empty_string)
    {
        auto emptyStr = std::wstring(L"");
        web::details::win32_encryption enc(emptyStr);
        #ifdef _UTF16_STRINGS
        VERIFY_ARE_EQUAL(*enc.decrypt(), emptyStr);
        #else 
        VERIFY_ARE_EQUAL(*enc.decrypt(), emptyStr);
        #endif

    }

} // SUITE(win32_encryption)

#endif // defined(_WIN32) && _WIN32_WINNT >= _WIN32_WINNT_VISTA && !defined(__cplusplus_winrt)

} // namespace utils_tests
} // namespace functional
} // namespace tests
