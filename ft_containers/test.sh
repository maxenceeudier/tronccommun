#!/bin/bash

mkdir -p test_vector
c++ -Wall -Wextra -Werror -std=c++98 test/test_vector.o -o test_vector/vectorFt;
c++ -Wall -Wextra -Werror -std=c++98 test/test_vector_std.o -o test_vector/vectorStd;
./test_vector/vectorFt > test_vector/vector_ft;
./test_vector/vectorStd > test_vector/vector_std;
diff test_vector/vector_ft test_vector/vector_std > test_vector/diff;

mkdir -p test_map
c++ -Wall -Wextra -Werror -std=c++98 test/test_map.o -o test_map/mapFt;
c++ -Wall -Wextra -Werror -std=c++98 test/test_map_std.o -o test_map/mapStd;
./test_map/mapFt > test_map/map_ft;
./test_map/mapStd > test_map/map_std;
diff test_map/map_ft test_map/map_std > test_map/diff;

mkdir -p test_utils
c++ -Wall -Wextra -Werror -std=c++98 test/test_utils.o -o test_utils/utilsFt && \
c++ -Wall -Wextra -Werror -std=c++11 test/test_utils_std.o -o test_utils/utilsStd;
./test_utils/utilsStd > test_utils/utils_std;
./test_utils/utilsFt > test_utils/utils_ft;
diff test_utils/utils_std test_utils/utils_ft > test_utils/diff;

mkdir -p test_RBT;
c++ -Wall -Wextra -Werror -std=c++98 test/test_RBT.o -o test_RBT/RBTFt;
./test_RBT/RBTFt > test_RBT/RBTFt_rslt;

mkdir -p test_stack
c++ -Wall -Wextra -Werror -std=c++98 test/test_stack.o -o test_stack/stackFt && \
c++ -Wall -Wextra -Werror -std=c++98 test/test_stack_std.o -o test_stack/stackStd;
./test_stack/stackFt > test_stack/stack_ft;
./test_stack/stackStd > test_stack/stack_std;
diff test_stack/stack_ft test_stack/stack_std > test_stack/diff