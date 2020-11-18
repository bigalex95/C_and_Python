#include <stdio.h>
#include <Python.h>
#include "demolib.h"

// wrapper function for cfactorial_sum
static PyObject *DemoLib_cFactorialSum(PyObject *self, PyObject *args) {
	char *char_nums;
	if (!PyArg_ParseTuple(args, "s", &char_nums)) {
		return NULL;
	}

	unsigned long fact_sum;
	fact_sum = cfactorial_sum(char_nums);

	return Py_BuildValue("i", fact_sum);
}

// wrapper function for ifactorial_sum
static PyObject *DemoLib_iFactorialSum(PyObject *self, PyObject *args) {
	PyObject *lst;
	if (!PyArg_ParseTuple(args, "O", &lst)) {
		return NULL;
	}

	int n = PyObject_Length(lst);
	if (n < 0) {
		return NULL;
	}

	//long nums[n];
	long *nums;
	nums = (long)malloc((n)*sizeof(long));
	for (int i = 0; i < n; i++) {
		PyLongObject *item = PyList_GetItem(lst, i);
		long num = PyLong_AsLong(item);
		nums[i] = num;
	}

	unsigned long fact_sum;
	fact_sum = ifactorial_sum(nums, n);

	return Py_BuildValue("i", fact_sum);
}

// module's function table
static PyMethodDef DemoLib_FunctionsTable[] = {
	{
		"sfactorial_sum", // name exposed to Python
		DemoLib_cFactorialSum, // C wrapper function
		METH_VARARGS, // received variable args (but really just 1)
		"Calculates factorial sum from digits in string of numbers" // documentation
	},{
		"ifactorial_sum", // name exposed to Python
		DemoLib_iFactorialSum, // C wrapper function
		METH_VARARGS, // received variable args (but really just 1)
		"Calculates factorial sum from list of ints" // documentation
	},{
		NULL, NULL, 0, NULL
	}
};

// modules definition
static struct PyModuleDef DemoLib_Module = {
	PyModuleDef_HEAD_INIT,
	"demo",     // name of module exposed to Python
	"Demo Python wrapper for custom C extension library.", // module documentation
	-1,
	DemoLib_FunctionsTable
};

PyMODINIT_FUNC PyInit_demo(void) {
	return PyModule_Create(&DemoLib_Module);
}