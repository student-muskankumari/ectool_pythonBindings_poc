#include <Python.h>

//lets assume fan state 
static int current_speed = 35;

// current fan level
static PyObject* read_fan_level(PyObject* self, PyObject* args)
{
    return PyLong_FromLong(current_speed);
}

// Updating fan level
static PyObject* update_fan_level(PyObject* self, PyObject* args)
{
    int level;

    if (!PyArg_ParseTuple(args, "i", &level))
        return NULL;

    if (level < 0)
        level = 0;

    if (level > 100)
        level = 100;

    current_speed = level;

    Py_RETURN_NONE;
}

// Function table
static PyMethodDef CoolctlMethods[] = {
    {"read_fan_level", read_fan_level, METH_VARARGS, "Read current fan level"},
    {"update_fan_level", update_fan_level, METH_VARARGS, "Update fan level"},
    {NULL, NULL, 0, NULL}
};

//Defining Module
static struct PyModuleDef coolctlmodule = {
    PyModuleDef_HEAD_INIT,
    "coolctl",
    "Cooling control Python bindings",
    -1,
    CoolctlMethods
};

//initialization
PyMODINIT_FUNC PyInit_coolctl(void)
{
    return PyModule_Create(&coolctlmodule);
}
