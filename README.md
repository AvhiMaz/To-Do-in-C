# To-Do Manager

## Overview
This simple command-line To-Do Manager written in C allows users to create, manage, and save their tasks with additional notes.

## Features
- **Task Creation**: Users can add tasks to their to-do list.
- **Note Addition**: The program enables users to add notes to each task.
- **Automatic Notes File Creation**: A `notes.txt` file is automatically generated to save all added notes.
- **Task Management**: Basic functionalities to view, edit, and delete tasks.

## Getting Started
1. **Compile**: Compile the `todo.c` file using a C compiler.
    ```bash
    gcc main.c -o main
    ```
2. **Run**: Execute the compiled program.
    ```bash
    ./main
    ```
   
## Usage
- **Add a Task**: Enter the task details when prompted.
- **Add Notes**: After adding a task, you'll be prompted to add notes. These notes will be saved in `notes.txt`.
- **View Tasks**: Option to view all tasks with their corresponding notes.
- **Edit or Delete Tasks**: Functionality available to modify or remove tasks.
- **Exit**: Close the program.

## File Structure
- `main.c`: Contains the C code for the To-Do Manager.
- `notes.txt`: Automatically created to store added notes.

## Contributing
Feel free to fork this repository and contribute to its development. Any improvements or bug fixes are welcome.
