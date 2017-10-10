
declare_PID_Component(
    HEADER_LIB 
    NAME pygen
    DIRECTORY pygen_converters
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

if (BUILD_AND_RUN_TESTS)
    declare_PID_Component(
        SHARED_LIB
        NAME TestFunctions
        DIRECTORY test_lib
        CXX_STANDARD 14
    )

    declare_PID_Component_Dependency(
        COMPONENT TestFunctions
        EXPORT NATIVE pygen
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
endif()
