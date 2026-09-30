# Simple Line Editor - Help

## Introduction

The Simple Line Editor is a command-line text editor written in C.

It allows the user to create and modify a document one line at a time.

## Starting the Program

Compile the program using GCC:

```bash
gcc line_editor.c -o line_editor
```

Run the program on Windows:

```powershell
.\line_editor
```

Run on Linux/macOS:

```bash
./line_editor
```

## Main Menu

The editor provides the following options:

```text
1. Display Document
2. Insert Line
3. Delete Line
4. Edit Line
5. Search Text
6. Save Document
7. Load Document
8. Help
9. Exit
```

---

## 1. Display Document

Select:

```text
1
```

This displays all lines currently stored in the document with their line numbers.

Example:

```text
----- DOCUMENT -----
1: Hello World
2: This is my second line.
--------------------
```

If there are no lines:

```text
Document is empty.
```

---

## 2. Insert Line

Select:

```text
2
```

The editor asks for:

1. The line number where the new line should be inserted.
2. The text of the new line.

Example:

```text
Enter line number to insert at: 2
Enter text: This is a new line.
```

The new line is inserted at position 2, and existing lines are shifted downward.

A line can be inserted:

* At the beginning
* In the middle
* At the end

The valid insertion positions are from `1` to `lineCount + 1`.

---

## 3. Delete Line

Select:

```text
3
```

Enter the line number to delete.

Example:

```text
Enter line number to delete: 2
```

The selected line is removed, and the lines after it are shifted upward.

If the document is empty:

```text
Document is empty.
```

If the line number is invalid:

```text
Invalid line number.
```

---

## 4. Edit Line

Select:

```text
4
```

Enter the line number and the new text.

Example:

```text
Enter line number to edit: 1
Enter new text: Updated first line.
```

The existing line is replaced with the new text.

---

## 5. Search Text

Select:

```text
5
```

Enter the text you want to search for.

Example:

```text
Enter text to search: Hello
```

If the text is found, the editor displays the matching line number and line.

Example:

```text
Found at line 1: Hello World
```

If the text is not found:

```text
Text not found.
```

The search uses substring matching.

---

## 6. Save Document

Select:

```text
6
```

Enter a filename.

Example:

```text
Enter filename to save: document.txt
```

The current document is saved to the specified text file.

Example message:

```text
Document saved successfully to document.txt
```

Each document line is stored as a separate line in the file.

---

## 7. Load Document

Select:

```text
7
```

Enter the name of an existing text file.

Example:

```text
Enter filename to load: document.txt
```

The contents of the file are loaded into the editor.

Example message:

```text
Document loaded successfully from document.txt
```

Loading a file replaces the current document contents.

---

## 8. Help

Select:

```text
8
```

This displays information about all available editor commands.

---

## 9. Exit

Select:

```text
9
```

The editor exits and releases the dynamically allocated memory.

Example:

```text
Exiting Simple Line Editor...
```

---

## Limits

The editor has the following limits:

```text
Maximum lines: 100
Maximum characters per line: 199
```

The program reserves 200 characters for each line, including the string terminator.

---

## Error Handling

The editor handles common errors such as:

* Invalid menu choices
* Invalid line numbers
* Deleting from an empty document
* Inserting when the document is full
* Invalid numeric input
* File opening errors

---

## Data Storage

The document is stored using an array of strings with dynamic memory allocation.

The main structure is:

```c
char **lines;
```

Each element stores one document line.

---

## Quick Example

A typical session can be:

```text
2
1
Hello World

2
2
This is a line editor.

1

4
1
Welcome to the Simple Line Editor.

5
Editor

6
document.txt

9
```

This demonstrates inserting, displaying, editing, searching, saving, and exiting.

---

## Notes

* Line numbers start from `1`.
* To insert at the end, use `lineCount + 1`.
* To delete or edit a line, the line number must already exist.
* Save the document before exiting if you want to keep your changes.
* Loading a file replaces the current document.

## Support

For information about the project structure, compilation, features, and implementation, see `README.md`.
