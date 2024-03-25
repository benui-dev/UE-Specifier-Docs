#include "CustomThunkExample.h"

DEFINE_FUNCTION(UCustomThunkExample::execSum)
{
	// This from Eren: 
	// https://gist.github.com/intaxwashere/e9b1f798427686b46beab2521d7efbcf

	// this macro expands to:
	// float A;																
	// Stack.StepCompiledIn<FFloatProperty>(&A);
	PARAM_PASSED_BY_VAL(A, FFloatProperty, float);

	// this macro expands to:
	// float B;																
	// Stack.StepCompiledIn<FFloatProperty>(&B);
	PARAM_PASSED_BY_VAL(B, FFloatProperty, float);
    
	// sometimes, depending on your parameter type, you might need to call something else than PARAM_PASSED_BY_VAL
	// see Script.h and .gen.cpp files for further details.
    
	// increment instruction pointer unless it's null.
	// this is required to mark we finished traversing parameters through stack.
	P_FINISH;

	P_NATIVE_BEGIN; // this macro lets profiler/insights know we're now evaluating a native logic, so it wont be displayed as Blueprint time.

	const float Result = A + B;
	// we know our return type is float, and RESULT_PARAM is a void* that points to the return parameter of this function in the "parms memory"
	// it's size is same as float too, because thats how BPVM works, so we want to re-interpret it as float and set our result variable to it.
	*reinterpret_cast<float*>(RESULT_PARAM) = Result;

	P_NATIVE_END; // let profiler know native logic has ended.
}