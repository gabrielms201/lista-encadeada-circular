project ("Circular Linked List")


file(GLOB SOURCES
	*.cpp
	*.h)
add_executable(${PROJECT_NAME}
		${SOURCES})
