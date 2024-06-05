# Sorting Algorithm Visualizer
This tools provides a visual representation of various sorting algorithms, allowing users to observe the inner workings and performance in real-time.

This project has been created as an initial exploration of the Simple Fast Media Library (SFML). It is intended to be easily-extendable, new algorithms can be implemented through the 4-step process included below.

## Functionality (buttons)
- Sort: Begin sorting
- (Algorithm name): Select sorting algorithm
- Shuffe: Re-shuffle values
- Exit: Quit program

## Adding a new algorithm visualization
- Add algorithm name to SortAlgorithm enumeration in Sorters/Sorter.h (i.e. "newalgorithname")
- Add function definition and implementation to Sorters/Sorter.h and Sorters/Sorter.cpp. This function should use the template form template <typename T> and include a parameter for a const std::function<void()>& drawer function (this is the call for the visualizer to draw). At this stage you need to add the point at which to highlight, draw, and turn highlighting off on the relevant location in the function.
- Add a button to select the new sorting algorithm in the UI by adding a new call to the addButton() function in the initializeButtons() function in ScreenManager/ScreenManager.cpp. Give the button a name to display for the algorithm (i.e. "New Algorithm Name")
- Add functionality to this button in the Engine/InputHandler.cpp file by adding the following call to handleLeftClick():
    if (buttonInteractedWith == "New Algorithm Name") m_sortManager->setSorter(SortAlgorithm::newalgorithname);

### Tradeoffs
There are tradeoffs to the structuring of this code:
#### Pros
Easy to extend to new algorithms with minimal modification of the original algorithm code (no need to change algorithm to make it iteration-based)
#### Cons
Because this method of visualization relies on SFML's sleep() function, it is dificult to extend this visualizer to a grid-based one with multiple algorithms running simultaneously. For this, an iteration-based visualizer is better suited.
