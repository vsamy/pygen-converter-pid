
declare_PID_Component(
    HEADER_LIB 
    NAME pygen
    DIRECTORY pygen_converter
    CXX_STANDARD 11
)

declare_PID_Component_Dependency(
    COMPONENT pygen
    EXPORT EXTERNAL eigen 
    PACKAGE eigen
)

get_PID_Platform_Info(PYTHON PY_VERSION)

if(PY_VERSION VERSION_LESS 3.0)
    #using python2 to manage python wrappers
    declare_PID_Component_Dependency(
        COMPONENT pygen
        EXTERNAL boost-python 
        PACKAGE boost
    )
else()
    #using python3 to manage python wrappers
    declare_PID_Component_Dependency(
        COMPONENT pygen
        EXTERNAL boost-python3 
        PACKAGE boost
    )
endif()