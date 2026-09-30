# Simple Line Editor

A simple command-line line editor written in C.

The program allows users to create and modify a text document line by line. It supports inserting, deleting, editing, displaying, searching, saving, and loading lines.

## Team Members

* Member 1: [PRAYAG KISHORE]
* Member 2: [R.JAYA PRANAY RAJU]
* Member 3: [MD ANIS]

## Features

The Simple Line Editor provides the following features:

1. **Display Document**

   * Displays all lines currently stored in the document.
   * Each line is shown with its line number.

2. **Insert Line**

   * Inserts a new line at a specified position.
   * Supports insertion at the beginning, middle, and end of the document.
   * Validates the requested line number.

3. **Delete Line**

   * Deletes a line using its line number.
   * Automatically shifts the remaining lines upward.
   * Handles empty documents and invalid line numbers.

4. **Edit Line**

   * Replaces the text of an existing line.
   * Validates the selected line number.

5. **Search Text**

   * Searches for text within all document lines.
   * Displays the line numbers where the text is found.

6. **Save Document**

   * Saves the current document to a text file.

7. **Load Document**

   * Loads lines from a previously saved text file.

8. **Help**

   * Displays information about the available editor commands.

9. **Exit**

   * Safely exits the program and releases allocated memory.

## Data Structure

The program uses an **array of strings implemented using dynamic memory allocation**.

The main structure is:

```c
char **lines;
```

Each element of `lines` points to a character array containing one line of the document.

The program uses:

```text
MAX_LINES  = 100
MAX_LENGTH = 200
```

Therefore, the editor can store up to 100 lines, with each line containing up to 199 characters plus the null terminator.

### Why this data structure?

An array of strings is simple and suitable for a small line editor.

It provides:

* Easy access using line numbers
* Simple display operations
* Straightforward insertion and deletion
* Easy file saving and loading
* Simple memory management

## Main Functions

### `displayLines()`

Displays all lines currently stored in the document.

### `insertLine()`

Inserts a new line at the requested position and shifts existing lines downward.

### `deleteLine()`

Deletes a selected line and shifts the remaining lines upward.

### `editLine()`

Replaces the contents of an existing line.

### `searchText()`

Searches all document lines for a specified piece of text.

### `saveFile()`

Writes the document contents to a text file.

### `loadFile()`

Reads a text file and loads its contents into the document.

### `showHelp()`

Displays instructions for using the editor.

## Input Validation

The program handles several invalid-input cases, including:

* Invalid menu choices
* Invalid line numbers
* Attempting to delete from an empty document
* Attempting to insert when the document is full
* Invalid file operations
* Invalid numeric input

## Compilation

Make sure GCC is installed.

Open a terminal in the project folder and run:

```bash
gcc line_editor.c -o line_editor
```

## Running the Program

On Windows PowerShell:

```powershell
.\line_editor
```

On Linux/macOS:

```bash
./line_editor
```

## Menu

When the program starts, the following menu is displayed:

```text
==============================
       SIMPLE LINE EDITOR
==============================
1. Display Document
2. Insert Line
3. Delete Line
4. Edit Line
5. Search Text
6. Save Document
7. Load Document
8. Help
9. Exit
==============================
Enter your choice:
```

## Example

The user can insert two lines:

```text
Enter your choice: 2
Enter line number to insert at: 1
Enter text: Hello World
Line inserted successfully.

Enter your choice: 2
Enter line number to insert at: 2
Enter text: This is a simple line editor.
Line inserted successfully.
```

Displaying the document:

```text
Enter your choice: 1

----- DOCUMENT -----
1: Hello World
2: This is a simple line editor.
--------------------
```

The user can then edit, search, delete, save, or load the document.

## File Handling

The editor can save the document to a text file such as:

```text
document.txt
```

Each document line is stored as a separate line in the file.

The saved file can later be loaded using the **Load Document** option.

## Memory Management

The program dynamically allocates memory for:

* The array of line pointers
* Each individual line

Before exiting, all allocated memory is released using `free()`.

This prevents memory from remaining allocated after the program terminates.

## Project Structure

```text
Line-Editor/
│
├── line_editor.c
├── README.md
├── HELP.md
└── document.txt
```

`document.txt` is created when the user saves a document and does not need to be included in the repository unless required.

## Limitations

* Maximum number of lines: 100
* Maximum characters per line: 199
* The editor works through a command-line interface.
* Search is performed using substring matching.

## Conclusion

The Simple Line Editor demonstrates basic text-editor functionality using C, dynamic memory allocation, arrays of strings, string manipulation, file handling, input validation, and modular functions.
