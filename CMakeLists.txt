cmake_minimum_required(VERSION 3.12)
project(tasks)

set(CMAKE_CXX_STANDARD 14)

add_executable(tasks
        leetcode/binary_tree_inorder_traversal.cpp
        leetcode/binary_tree_level_order_traversal.cpp
        leetcode/coin_change.cpp
        leetcode/delete_node_in_linked_list.cpp
        leetcode/evaluate_reverse_polish_notation.cpp
        leetcode/find_redundant_connection.cpp
        leetcode/first_unique_character_in_string.cpp
        leetcode/fizz_buzz.cpp
        leetcode/generate_parentheses.cpp
        leetcode/invert_binary_tree.cpp
        leetcode/longest_increasing_subsequence.cpp
        leetcode/max_depth_binary_tree.cpp
        leetcode/merge_k_sorted_lists.cpp
        leetcode/merge_sorted_array.cpp
        leetcode/move_zeroes.cpp
        leetcode/number_of_islands.cpp
        leetcode/permutations.cpp
        leetcode/pow.cpp
        leetcode/randomized_set.cpp
        leetcode/remove_nth_node_from_list_end.cpp
        leetcode/reverse_integer.cpp
        leetcode/reverse_linked_list.cpp
        leetcode/reverse_string.cpp
        leetcode/reverse_words.cpp
        leetcode/rotate_array.cpp
        leetcode/search_in_rotated_sorted_array.cpp
        leetcode/simplify_path.cpp
        leetcode/single_number.cpp
        leetcode/sum_of_two.cpp
        leetcode/top_frequent_elements.cpp
        leetcode/trapping_rain_water.cpp
        leetcode/unique_paths.cpp
        leetcode/valid_parentheses.cpp
        leetcode/validate_bst.cpp
        misc/beautiful_strings.cpp
        misc/binary_tree_count.cpp
        misc/bit_convert.cpp
        misc/bracket_sequence.cpp
        misc/edit_distance.cpp
        misc/game_of_life.cpp
        misc/gauss.cpp
        misc/get_divisors.cpp
        misc/is_palindrome.cpp
        misc/is_tree_bst.cpp
        misc/lis.cpp
        misc/local_min_array.cpp
        misc/lru.cpp
        misc/majority_elment.cpp
        misc/move_spaces_to_end.cpp
        misc/pair_sum_close_to_number.cpp
        misc/pair_sum_equal_to_number.cpp
        misc/polynom.cpp
        misc/reverse_linked_list.cpp
        misc/reverse_words_in_string.cpp
        misc/right_bracket_sequence.cpp
        misc/rle.cpp
        misc/set_range_sum.cpp
        misc/stack_with_min.cpp
        misc/string_generator.cpp
        misc/subarray_predefined_sum.cpp
        misc/topsort.cpp
        misc/union_intersection_lists.cpp)

add_library(linked_list cracking_interview/linked_lists/linked_list.h)

SET_TARGET_PROPERTIES(linked_list PROPERTIES LINKER_LANGUAGE CXX)

add_executable(unique_characters cracking_interview/arrays_and_strings/unique_characters.cpp)
add_executable(rotate_matrix cracking_interview/arrays_and_strings/rotate_matrix.cpp)
add_executable(reverse cracking_interview/arrays_and_strings/reverse.cpp)
add_executable(fill_with_zeroes cracking_interview/arrays_and_strings/fill_with_zeroes.cpp)
add_executable(replace cracking_interview/arrays_and_strings/replace.cpp)
add_executable(remove_duplicates cracking_interview/arrays_and_strings/remove_duplicate_chars.cpp)
add_executable(anagram cracking_interview/arrays_and_strings/anagram.cpp)
add_executable(string_rotation cracking_interview/arrays_and_strings/string_rotation.cpp)
add_executable(remove_duplicate_nodes cracking_interview/linked_lists/remove_duplicate_nodes.cpp)
add_executable(find_nth_to_last cracking_interview/linked_lists/find_nth_to_last.cpp)
add_executable(delete_node cracking_interview/linked_lists/delete_node.cpp)
add_executable(sum_lists cracking_interview/linked_lists/sum_lists.cpp)
add_executable(find_cycle cracking_interview/linked_lists/find_cycle.cpp)