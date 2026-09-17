#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

/* Display all lines in the document */
void displayLines(char **lines, int lineCount)
{
    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (int i = 0; i < lineCount; i++)
    {
        printf("%d: %s\n", i + 1, lines[i]);
    }

    printf("--------------------\n");
}

/* Insert a new line at the given position */
void insertLine(char **lines, int *lineCount, int position, char *text)
{
    if (*lineCount >= MAX_LINES)
    {
        printf("Document is full.\n");
        return;
    }

    if (position < 1 || position > *lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift existing lines downward */
    for (int i = *lineCount; i >= position; i--)
    {
        strcpy(lines[i], lines[i - 1]);
    }

    strcpy(lines[position - 1], text);

    (*lineCount)++;

    printf("Line inserted successfully.\n");
}

/* Delete a line */
void deleteLine(char **lines, int *lineCount, int position)
{
    if (*lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (position < 1 || position > *lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines upward */
    for (int i = position - 1; i < *lineCount - 1; i++)
    {
        strcpy(lines[i], lines[i + 1]);
    }

    (*lineCount)--;

    printf("Line deleted successfully.\n");
}

/* Edit/replace an existing line */
void editLine(char **lines, int lineCount, int position, char *text)
{
    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    if (position < 1 || position > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    strcpy(lines[position - 1], text);

    printf("Line edited successfully.\n");
}

/* Search for text in the document */
void searchText(char **lines, int lineCount, char *search)
{
    int found = 0;

    if (lineCount == 0)
    {
        printf("Document is empty.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found at line %d: %s\n", i + 1, lines[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}

/* Save document to a file */
void saveFile(char **lines, int lineCount, char *filename)
{
    FILE *file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file for saving.\n");
        return;
    }

    for (int i = 0; i < lineCount; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("Document saved successfully to %s\n", filename);
}

/* Load document from a file */
void loadFile(char **lines, int *lineCount, char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file for loading.\n");
        return;
    }

    *lineCount = 0;

    while (*lineCount < MAX_LINES &&
           fgets(lines[*lineCount], MAX_LENGTH, file) != NULL)
    {
        lines[*lineCount][strcspn(lines[*lineCount], "\n")] = '\0';

        (*lineCount)++;
    }

    fclose(file);

    printf("Document loaded successfully from %s\n", filename);
}

/* Display help information */
void showHelp()
{
    printf("\n========== HELP ==========\n");
    printf("1. Display Document\n");
    printf("   Shows all lines currently in the document.\n\n");

    printf("2. Insert Line\n");
    printf("   Inserts a new line at the selected position.\n\n");

    printf("3. Delete Line\n");
    printf("   Deletes the selected line.\n\n");

    printf("4. Edit Line\n");
    printf("   Replaces the text of an existing line.\n\n");

    printf("5. Search Text\n");
    printf("   Searches for text inside the document.\n\n");

    printf("6. Save Document\n");
    printf("   Saves the current document to a text file.\n\n");

    printf("7. Load Document\n");
    printf("   Loads a document from a text file.\n\n");

    printf("8. Help\n");
    printf("   Displays this help information.\n\n");

    printf("9. Exit\n");
    printf("   Exits the line editor.\n");
    printf("==========================\n");
}

int main()
{
    char **lines;
    int lineCount = 0;
    int choice;
    int position;
    char text[MAX_LENGTH];
    char filename[100];

    /* Allocate memory for line pointers */
    lines = malloc(MAX_LINES * sizeof(char *));

    if (lines == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Allocate memory for each line */
    for (int i = 0; i < MAX_LINES; i++)
    {
        lines[i] = malloc(MAX_LENGTH * sizeof(char));

        if (lines[i] == NULL)
        {
            printf("Memory allocation failed.\n");

            /* Free already allocated memory */
            for (int j = 0; j < i; j++)
            {
                free(lines[j]);
            }

            free(lines);
            return 1;
        }
    }

    /* Main editor loop */
    while (1)
    {
        printf("\n==============================\n");
        printf("       SIMPLE LINE EDITOR\n");
        printf("==============================\n");
        printf("1. Display Document\n");
        printf("2. Insert Line\n");
        printf("3. Delete Line\n");
        printf("4. Edit Line\n");
        printf("5. Search Text\n");
        printf("6. Save Document\n");
        printf("7. Load Document\n");
        printf("8. Help\n");
        printf("9. Exit\n");
        printf("==============================\n");

        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input. Please enter a number.\n");

            while (getchar() != '\n')
            {
                /* Clear invalid input */
            }

            continue;
        }

        getchar();

        switch (choice)
        {
            case 1:
                displayLines(lines, lineCount);
                break;

            case 2:
                printf("Enter line number to insert at: ");

                if (scanf("%d", &position) != 1)
                {
                    printf("Invalid input.\n");

                    while (getchar() != '\n')
                    {
                        /* Clear input */
                    }

                    break;
                }

                getchar();

                printf("Enter text: ");
                fgets(text, MAX_LENGTH, stdin);

                text[strcspn(text, "\n")] = '\0';

                insertLine(lines, &lineCount, position, text);
                break;

            case 3:
                printf("Enter line number to delete: ");

                if (scanf("%d", &position) != 1)
                {
                    printf("Invalid input.\n");

                    while (getchar() != '\n')
                    {
                        /* Clear input */
                    }

                    break;
                }

                getchar();

                deleteLine(lines, &lineCount, position);
                break;

            case 4:
                printf("Enter line number to edit: ");

                if (scanf("%d", &position) != 1)
                {
                    printf("Invalid input.\n");

                    while (getchar() != '\n')
                    {
                        /* Clear input */
                    }

                    break;
                }

                getchar();

                printf("Enter new text: ");
                fgets(text, MAX_LENGTH, stdin);

                text[strcspn(text, "\n")] = '\0';

                editLine(lines, lineCount, position, text);
                break;

            case 5:
                printf("Enter text to search: ");
                fgets(text, MAX_LENGTH, stdin);

                text[strcspn(text, "\n")] = '\0';

                searchText(lines, lineCount, text);
                break;

            case 6:
                printf("Enter filename to save: ");
                fgets(filename, sizeof(filename), stdin);

                filename[strcspn(filename, "\n")] = '\0';

                saveFile(lines, lineCount, filename);
                break;

            case 7:
                printf("Enter filename to load: ");
                fgets(filename, sizeof(filename), stdin);

                filename[strcspn(filename, "\n")] = '\0';

                loadFile(lines, &lineCount, filename);
                break;

            case 8:
                showHelp();
                break;

            case 9:
                printf("Exiting Simple Line Editor...\n");

                /* Free memory */
                for (int i = 0; i < MAX_LINES; i++)
                {
                    free(lines[i]);
                }

                free(lines);

                return 0;

            default:
                printf("Invalid choice. Please select 1-9.\n");
        }
    }

    return 0;
}