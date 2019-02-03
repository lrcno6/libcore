#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include<cstdlib>
namespace lib{
	inline char randc(){
		return rand()%26+'A';
	}
}
#endif