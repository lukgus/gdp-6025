#pragma once

#ifdef BLACKBOXTESTLIBRARY_EXPORTS
#define BLACKBOXTEST_API __declspec(dllexport)
#else
#define BLACKBOXTEST_API __declspec(dllimport)
#endif


// Use extern "C" so C++ compiler does not mess with
// the headers we defined
extern "C"
{
	BLACKBOXTEST_API int Fibonacci(int v);
}
