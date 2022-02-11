find_program(PYTHON_EXECUTABLE python)

if(NOT PYTHON_EXECUTABLE)
	message(FATAL_ERROR "python not found. Required by generator.")
endif()

set(GENERATOR generate_test_cases.py)

function(add_generated_stuff SCRIPT_DIR TARGET TEST_FILES_DIR OUTPUT_DIR)
	set_property(DIRECTORY APPEND PROPERTY CMAKE_CONFIGURE_DEPENDS ${OUTPUTFILE})
	set(GENERATOR_PATH ${PYTHON_EXECUTABLE} ${SCRIPT_DIR}/${GENERATOR})

	message("OUTPUT_DIR: ${OUTPUT_DIR}")
	execute_process(
			COMMAND ${GENERATOR_PATH} --print-dependencies ./ ./
			OUTPUT_VARIABLE DEPENDENCIES
			RESULT_VARIABLE RETURN_VALUE
	)

	if (NOT RETURN_VALUE EQUAL 0)
		message(FATAL_ERROR "Failed to get dependencies for ${OUTPUTFILE}")
	endif()

	message("DEPENDENCIES ${DEPENDENCIES}")
	message("COMMAND ${GENERATOR_PATH} ${TEST_FILES_DIR} ${OUTPUT_DIR}")

	add_custom_command(
			COMMAND ${GENERATOR_PATH} ${TEST_FILES_DIR} ${OUTPUT_DIR}
			OUTPUT ${DEPENDENCIES}
			DEPENDS ${GENERATOR} ${TEST_FILES_DIR}
			COMMENT "Generating ${DEPENDENCIES} from ${TEST_FILES_DIR}"
	)
	add_library(${TARGET} SHARED ${DEPENDENCIES})
	target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
endfunction()