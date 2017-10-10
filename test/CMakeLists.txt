
declare_PID_Component(
    SHARED_LIB
    NAME TestFunctions
    DIRECTORY converter_test
    CXX_STANDARD 14
)

declare_PID_Component_Dependency(
    COMPONENT TestFunctions
    EXPORT NATIVE numpy-eigen-converter
    PACKAGE numpy-eigen-converter
)

declare_PID_Component_Dependency(
    COMPONENT TestFunctions
    EXPORT EXTERNAL eigen
)

get_PID_Platform_Info(PYTHON PY_VERSION)

if(PY_VERSION VERSION_LESS 3.0)
    #using python2 to manage python wrappers
    declare_PID_Component_Dependency(
        COMPONENT TestFunctions
        EXTERNAL boost-python 
        PACKAGE boost
    )
else()
    #using python3 to manage python wrappers
    declare_PID_Component_Dependency(
        COMPONENT TestFunctions
        EXTERNAL boost-python3 
        PACKAGE boost
    )
endif()

run_PID_Test(NAME test-python-check-converters PYTHON ARGUMENTS converter_test/pyTests.py)

