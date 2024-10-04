#!/bin/bash

valgrind --quiet --leak-check=full --show-leak-kinds=all ./push_swap "$@"
echo "Last status: $?"
echo "Moves: $(./push_swap "$@" | wc -l)"
echo "Checker: $(./push_swap "$@" | ./checker_linux "$@")"
