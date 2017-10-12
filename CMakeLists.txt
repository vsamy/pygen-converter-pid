CMAKE_MINIMUM_REQUIRED(VERSION 3.0.2)
set(WORKSPACE_DIR ${CMAKE_SOURCE_DIR}/../.. CACHE PATH "root of the packages workspace directory")
list(APPEND CMAKE_MODULE_PATH ${WORKSPACE_DIR}/share/cmake/system) # using generic scripts/modules of the workspace
include(Package_Definition NO_POLICY_SCOPE)

PROJECT(pygen-converter)

declare_PID_Package(	
			AUTHOR 			Vincent Samy
			INSTITUTION		LIRMM
			ADDRESS 		git@github.com:vsamy/pygen-converter.git
			PUBLIC_ADDRESS 	https://github.com/vsamy/pygen-converter.git
			MAIL			vincent.samy@lirmm.fr
	 		YEAR 			2017
			LICENSE 		CeCILL-C
			DESCRIPTION 	"This is an header only library that provides list to eigen and numpy to eigen converters for boost python."
			README			readme.md
)

set_PID_Package_Version(0 3 0)

#now finding packages
declare_PID_Package_Dependency(PACKAGE eigen EXTERNAL VERSION 3.3.4)
declare_PID_Package_Dependency(PACKAGE boost EXTERNAL VERSION 1.64.0)

build_PID_Package()

