#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"
static PyMethodDef module_methods[] = {
    {"nod", (PyCFunction)CPyPy_nod, METH_FASTCALL | METH_KEYWORDS, NULL /* docstring */},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "euc_module",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_euc_module(void)
{
    PyObject* modname = NULL;
    if (CPyModule_euc_module_internal) {
        Py_INCREF(CPyModule_euc_module_internal);
        return CPyModule_euc_module_internal;
    }
    CPyModule_euc_module_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_euc_module_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_euc_module_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_euc_module_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_euc_module_internal;
    fail:
    Py_CLEAR(CPyModule_euc_module_internal);
    Py_CLEAR(modname);
    return NULL;
}

PyObject *CPyDef_nod(PyObject *cpy_r_a, PyObject *cpy_r_b) {
    PyObject *cpy_r_r0;
    int32_t cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    int32_t cpy_r_r5;
    char cpy_r_r6;
    char cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
CPyL0: ;
    goto CPyL13;
CPyL1: ;
    cpy_r_r0 = PyObject_RichCompare(cpy_r_a, cpy_r_b, 3);
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("euc_module.py", "nod", 2, CPyStatic_globals);
        goto CPyL14;
    }
CPyL2: ;
    cpy_r_r1 = PyObject_IsTrue(cpy_r_r0);
    CPy_DECREF(cpy_r_r0);
    cpy_r_r2 = cpy_r_r1 >= 0;
    if (unlikely(!cpy_r_r2)) {
        CPy_AddTraceback("euc_module.py", "nod", 2, CPyStatic_globals);
        goto CPyL14;
    }
CPyL3: ;
    cpy_r_r3 = cpy_r_r1;
    if (!cpy_r_r3) goto CPyL15;
CPyL4: ;
    cpy_r_r4 = PyObject_RichCompare(cpy_r_a, cpy_r_b, 4);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("euc_module.py", "nod", 3, CPyStatic_globals);
        goto CPyL14;
    }
CPyL5: ;
    cpy_r_r5 = PyObject_IsTrue(cpy_r_r4);
    CPy_DECREF(cpy_r_r4);
    cpy_r_r6 = cpy_r_r5 >= 0;
    if (unlikely(!cpy_r_r6)) {
        CPy_AddTraceback("euc_module.py", "nod", 3, CPyStatic_globals);
        goto CPyL14;
    }
CPyL6: ;
    cpy_r_r7 = cpy_r_r5;
    if (!cpy_r_r7) goto CPyL9;
CPyL7: ;
    cpy_r_r8 = PyNumber_InPlaceSubtract(cpy_r_a, cpy_r_b);
    CPy_DECREF(cpy_r_a);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("euc_module.py", "nod", 4, CPyStatic_globals);
        goto CPyL16;
    }
CPyL8: ;
    cpy_r_a = cpy_r_r8;
    goto CPyL1;
CPyL9: ;
    cpy_r_r9 = PyNumber_InPlaceSubtract(cpy_r_b, cpy_r_a);
    CPy_DECREF(cpy_r_b);
    if (unlikely(cpy_r_r9 == NULL)) {
        CPy_AddTraceback("euc_module.py", "nod", 6, CPyStatic_globals);
        goto CPyL17;
    }
CPyL10: ;
    cpy_r_b = cpy_r_r9;
    goto CPyL1;
CPyL11: ;
    return cpy_r_a;
CPyL12: ;
    cpy_r_r10 = NULL;
    return cpy_r_r10;
CPyL13: ;
    CPy_INCREF(cpy_r_a);
    CPy_INCREF(cpy_r_b);
    goto CPyL1;
CPyL14: ;
    CPy_DecRef(cpy_r_a);
    CPy_DecRef(cpy_r_b);
    goto CPyL12;
CPyL15: ;
    CPy_DECREF(cpy_r_b);
    goto CPyL11;
CPyL16: ;
    CPy_DecRef(cpy_r_b);
    goto CPyL12;
CPyL17: ;
    CPy_DecRef(cpy_r_a);
    goto CPyL12;
}

PyObject *CPyPy_nod(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    static const char * const kwlist[] = {"a", "b", 0};
    static CPyArg_Parser parser = {"OO:nod", kwlist, 0};
    PyObject *obj_a;
    PyObject *obj_b;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_a, &obj_b)) {
        return NULL;
    }
    PyObject *arg_a = obj_a;
    PyObject *arg_b = obj_b;
    PyObject *retval = CPyDef_nod(arg_a, arg_b);
    return retval;
fail: ;
    CPy_AddTraceback("euc_module.py", "nod", 1, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    char cpy_r_r16;
CPyL0: ;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
CPyL1: ;
    cpy_r_r3 = CPyStatics[3]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("euc_module.py", "<module>", -1, CPyStatic_globals);
        goto CPyL8;
    }
CPyL2: ;
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatic_globals;
    cpy_r_r6 = CPyStatics[4]; /* '__name__' */
    cpy_r_r7 = CPyDict_GetItem(cpy_r_r5, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("euc_module.py", "<module>", 9, CPyStatic_globals);
        goto CPyL8;
    }
CPyL4: ;
    if (likely(PyUnicode_Check(cpy_r_r7)))
        cpy_r_r8 = cpy_r_r7;
    else {
        CPy_TypeError("str", cpy_r_r7); cpy_r_r8 = NULL;
    }
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("euc_module.py", "<module>", 9, CPyStatic_globals);
        goto CPyL8;
    }
CPyL5: ;
    cpy_r_r9 = CPyStatics[5]; /* 'was imported' */
    cpy_r_r10 = CPyModule_builtins;
    cpy_r_r11 = CPyStatics[6]; /* 'print' */
    cpy_r_r12 = CPyObject_GetAttr(cpy_r_r10, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("euc_module.py", "<module>", 9, CPyStatic_globals);
        goto CPyL9;
    }
CPyL6: ;
    PyObject *cpy_r_r13[2] = {cpy_r_r8, cpy_r_r9};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = _PyObject_Vectorcall(cpy_r_r12, cpy_r_r14, 2, 0);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("euc_module.py", "<module>", 9, CPyStatic_globals);
        goto CPyL9;
    } else
        goto CPyL10;
CPyL7: ;
    CPy_DECREF(cpy_r_r8);
    return 1;
CPyL8: ;
    cpy_r_r16 = 2;
    return cpy_r_r16;
CPyL9: ;
    CPy_DecRef(cpy_r_r8);
    goto CPyL8;
CPyL10: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL7;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_euc_module = Py_None;
    CPyModule_builtins = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[7];
const char * const CPyLit_Str[] = {
    "\004\bbuiltins\b__name__\fwas imported\005print",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {0};
CPyModule *CPyModule_euc_module_internal = NULL;
CPyModule *CPyModule_euc_module;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins_internal = NULL;
CPyModule *CPyModule_builtins;
PyObject *CPyDef_nod(PyObject *cpy_r_a, PyObject *cpy_r_b);
PyObject *CPyPy_nod(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
