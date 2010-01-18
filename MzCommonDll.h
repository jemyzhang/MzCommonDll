#pragma once
// include the MZFC library header file
#include <mzfc_inc.h>
//#include <afxwin.h>

#ifdef COMMON_EXPORTS
	#ifdef MZFC_STATIC
		#define COMMON_API  
	#else
		#define COMMON_API __declspec(dllexport)
	#endif
#else
	#ifdef MZFC_STATIC
		#define COMMON_API  
	#else
		#define COMMON_API __declspec(dllimport)
	#endif
#endif

