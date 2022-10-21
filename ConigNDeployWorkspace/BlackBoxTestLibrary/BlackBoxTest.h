#pragma once

#ifdef BLACKBOXTESTLIBRARY_EXPORTS
#define BLACKBOXTEST_API __declspec(dllexport)
#else
#define BLACKBOXTEST_API __declspec(dllimport)
#endif


class Vec {
public:
	int a;
};

// Use extern "C" so C++ compiler does not mess with
// the headers we defined
extern "C"
{
	class BLACKBOXTEST_API MathLibrary
	{
	public:
		MathLibrary(int type)
			: m_Type(type) {
		}
		int Fibonacci(int v);

		bool operator==(const MathLibrary& other) {
			return m_Type == other.m_Type;
		}
	//private:
		int m_Type;
	};
}
