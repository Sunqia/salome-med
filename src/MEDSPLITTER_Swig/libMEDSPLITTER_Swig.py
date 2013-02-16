# This file was automatically generated by SWIG (http://www.swig.org).
# Version 1.3.40
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.
# This file is compatible with both classic and new-style classes.

from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_libMEDSPLITTER_Swig', [dirname(__file__)])
        except ImportError:
            import _libMEDSPLITTER_Swig
            return _libMEDSPLITTER_Swig
        if fp is not None:
            try:
                _mod = imp.load_module('_libMEDSPLITTER_Swig', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _libMEDSPLITTER_Swig = swig_import_helper()
    del swig_import_helper
else:
    import _libMEDSPLITTER_Swig
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


METIS = _libMEDSPLITTER_Swig.METIS
SCOTCH = _libMEDSPLITTER_Swig.SCOTCH
MedAscii = _libMEDSPLITTER_Swig.MedAscii
MedXML = _libMEDSPLITTER_Swig.MedXML
Undefined = _libMEDSPLITTER_Swig.Undefined
class Graph(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Graph, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Graph, name)
    __repr__ = _swig_repr
    METIS = _libMEDSPLITTER_Swig.Graph_METIS
    SCOTCH = _libMEDSPLITTER_Swig.Graph_SCOTCH
    def __init__(self): 
        this = _libMEDSPLITTER_Swig.new_Graph()
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _libMEDSPLITTER_Swig.delete_Graph
    __del__ = lambda self : None;
Graph_swigregister = _libMEDSPLITTER_Swig.Graph_swigregister
Graph_swigregister(Graph)

class MESHCollection(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, MESHCollection, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, MESHCollection, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _libMEDSPLITTER_Swig.new_MESHCollection(*args)
        try: self.this.append(this)
        except: self.this = this
    def createPartition(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_createPartition(self, *args)
    def setDriverType(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_setDriverType(self, *args)
    def setSubdomainBoundaryCreates(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_setSubdomainBoundaryCreates(self, *args)
    def write(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_write(self, *args)
    def castAllFields(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_castAllFields(self, *args)
    def castFamilies(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_castFamilies(self, *args)
    def castField(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_castField(self, *args)
    def setIndivisibleGroup(self, *args): return _libMEDSPLITTER_Swig.MESHCollection_setIndivisibleGroup(self, *args)
    __swig_destroy__ = _libMEDSPLITTER_Swig.delete_MESHCollection
    __del__ = lambda self : None;
MESHCollection_swigregister = _libMEDSPLITTER_Swig.MESHCollection_swigregister
MESHCollection_swigregister(MESHCollection)


