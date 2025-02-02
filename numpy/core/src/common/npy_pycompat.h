#ifndef _NPY_PYCOMPAT_H_
#define _NPY_PYCOMPAT_H_

#include "numpy/npy_3kcompat.h"


/*
 * In Python 3.10a7 (or b1), python started using the identity for the hash
 * when a value is NaN.  See https://bugs.python.org/issue43475
 */
#if PY_VERSION_HEX > 0x030a00a6
#define Npy_HashDouble _Py_HashDouble
#else
static NPY_INLINE
#if PY_VERSION_HEX < 0x03020000
long
#else
Py_hash_t
#endif
Npy_HashDouble(PyObject *NPY_UNUSED(identity), double val)
{
    return _Py_HashDouble(val);
}
#endif


#endif /* _NPY_COMPAT_H_ */
