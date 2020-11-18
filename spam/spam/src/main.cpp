#include "include.h"

typedef unsigned int Color32;

inline Color32 Color32Reverse(Color32 x)
{

	return
		// Source is in format: 0xAARRGGBB
		((x & 0xFF000000) >> 24) |	//______AA
		((x & 0x00FF0000) >> 8) |	//____RR__
		((x & 0x0000FF00) << 8) |	//__GG____
		((x & 0x000000FF) << 24);	//BB______
		// Return value is in format:  0xBBGGRRAA
}

PyObject* some_function(PyObject* self, PyObject* args)
{
	__int64 input_value;
	if (!PyArg_ParseTuple(args, "L", &input_value))
	{
		goto error;
	}
	return PyLong_FromLongLong(input_value + 1);
error:
	return 0;
}

PyObject* bgr2rgb(PyObject* self, PyObject args)
{

	Color32 bgr;
	if (!PyArg_ParseTuple(args, "L", &bgr))
	{
		goto error;
	}
	
	return;

error:
	return 0;
}

PyMethodDef SpamMethods[]=
{
	{"add_one", (PyCFunction)some_function, METH_VARARGS, 0},
	{0,0,0,0}
};

static struct PyModuleDef spammodule = {
	PyModuleDef_HEAD_INIT,
	"spam",   /* name of module */
	"My Wonderful Module", /* module documentation, may be NULL */
	-1,       /* size of per-interpreter state of the module,
			  or -1 if the module keeps state in global variables. */
	SpamMethods
};



PyMODINIT_FUNC
PyInit_spam(void)
{
	return PyModule_Create(&spammodule);
}
