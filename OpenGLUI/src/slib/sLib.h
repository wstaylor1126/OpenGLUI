//#define _SLIB_NO_DEBUG_

#if !defined(_SLIB_H_)
#define _SLIB_H_

#if !defined(_SLIB_NO_DEBUG_)
#define _SLIB_LOG_DEBUG_ERR_
#define _SLIB_SIGNATURE_SCAN_DEBUG_PAGE_INFO_
#endif

#if defined(_WIN32)
#include <windows.h>
#endif

#include <cstdlib>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


#include "Log.h"
#include "Mem.h"

#endif 