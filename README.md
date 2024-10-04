# Sorting-Algorithm
In this project, I'll be sorting data on a stack using a limited set of instructions. My goal is to use the fewest number of actions possible. To succeed, I'll need to manipulate various types of algorithms and carefully choose the most appropriate solution from many options to achieve optimized data sorting.

![viualizer](https://github.com/buggcatcher/Sorting-Algorithm/blob/main/visualizer.gif)


    #!/bin/bash
    valgrind --quiet --leak-check=full --show-leak-kinds=all ./push_swap "$@"
    echo "Last status: $?"
    echo "Moves: $(./push_swap "$@" | wc -l)"
    echo "Checker: $(./push_swap "$@" | ./checker_linux "$@")"

