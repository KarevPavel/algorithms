//
// Created by yacopsae on 10/03/22.
//

#include "utils.hpp"
#include "file_path_config.hpp"
#include "../sort/include/file_sort.hpp"
#include "../sort/include/shell_sort.hpp"

int main() {
  	Utils::generate_file(FILE_OUTPUT, ',' ,33);
  	std::string sort_result(SORT_RESULT);
    FileSort file_sort {
		new ShellSort(),
		sort_result
	};
    file_sort.file_sort(FILE_OUTPUT, ',', 32);
}
