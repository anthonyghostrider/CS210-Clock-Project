# CS210-Clock-Project
Class projects I worked on
Reflection Questions


What did you do particularly well?

Formatted the user interface to display both clocks side by side cleanly using C++ standard formatting (std::setfill, std::setw).

Structured the menu control loop logically to handle user inputs smoothly without crash risks or visual misalignments.



Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?


Modularity & OOP: Refactoring the time-tracking and display functions into a dedicated Clock class to improve encapsulation and data security.

Input Validation: Strengthening input handling using robust checks to prevent invalid selections or unexpected non-integer inputs from causing infinite loops.

Concurrency: Implementing system time syncing and multithreading so the clocks update automatically second-by-second in real time, reducing manual user updates.



Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?


Managing edge cases during time rollovers—such as when adding seconds causes minutes to increment past 59 and hours past 23—required careful arithmetic logic.

Overcame this by breaking down the time conversion logic into modular conditional statements in Visual Studio and step-debugging variable values.

Added official C++ reference documentation (cppreference) and standard IDE debugging tools directly into my troubleshooting workflow.



What skills from this project will be particularly transferable to other projects or course work?


Core procedural logic and algorithm design for modular data handling.

Clean visual formatting techniques using standard library stream operations.

Effective use of Integrated Development Environments (IDEs) like Visual Studio for building, running, and debugging complex C++ projects.



How did you make this program maintainable, readable, and adaptable?


Applied consistent C++ naming conventions for functions and variables.

Integrated structured inline comments and function header blocks explaining code functionality.

Separated UI formatting logic from mathematical calculation loops, making future feature expansions straightforward to implement without breaking existing features.
