#include <stdio.h>
#include <stdlib.h> // system
#include <cstring> // memset
#include <string.h> // strcmp, strncpy_s
#include <locale.h>
// fflush

struct product {
    int num;
    char color[20];
    char sex;
    short int size;
    float diameter;
    char barcode[14];
    int orderNum;
    char fullName[20];
};

void Menu(product*, int*, char*);
void Create(product*, int*);
void Display(product*, int*, char*);
void AddLine(product*, int*);
void DeleateLine(product*, int*, int*);
void Find(product*, int*);
void Sort(product*, int*);
void FSave(product*, int*, char*);
void FOpen(product*, int*, char*);

int main()
{
    product pirsis[100];
    char nameOfFile[50] = "My new table";
    int count = 0;
    Menu(pirsis, &count, nameOfFile);
    
}

void Menu(product* pirsis, int * count, char * name) {
    int command = 9;
    int line = 0;

    do {
        printf("\t%20c%c%c%c%c%c%c%c \n", 201, 205, 205, 205, 205, 205, 205, 187);
        printf("\t%20c Menu %c \n", 186, 186);
        printf("\t%20c%c%c%c%c%c%c%c \n\n", 200, 205, 205, 205, 205, 205, 205, 188);

        printf("\t1) Create new \n");
        printf("\t2) Display a table \n");
        printf("\t3) Add new line \n");
        printf("\t4) Deleate line \n");
        printf("\t5) Find by parameter \n");
        printf("\t6) Sort by parameter \n");
        printf("\t7) Save file \n");
        printf("\t8) Read file \n");
        printf("\t9) Exit \n\n");

        printf("\t>> ");
        scanf_s("%d", &command);
        getchar();

        switch (command) {
        case 1:
            system("cls");
            do {
                printf("Enter the number of elements: ");
                scanf_s("%d", count);
                if (*count < 1 || *count > 100)
                    printf("Number of elements can't be much then 100 and less then 1 \n");
            } while (*count < 1 || *count > 100);
            system("cls");

            Create(pirsis, count);
            break;
        case 2:
            system("cls");
            Display(pirsis, count, name);
            getchar();
            break;
        case 3:
            system("cls");
            AddLine(pirsis, count);
            break;
        case 4:
            system("cls");
            if (*count != 0) {
                do {
                    printf("Choose the number of line: ");
                    scanf_s("%d", &line);
                    if (line < 1 || line > 100)
                        printf("Number of elements can't be much then 100 and less then 1 \n");
                } while (line < 1 || line > 100);
                DeleateLine(pirsis, count, &line);
            } else {
                printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
                printf("\t\t\t\tPress Enter to go to the main menu...");
                getchar();
            }
            break;
        case 5:
            system("cls");

            Find(pirsis, count);
            break;
        case 6:
            system("cls");

            Sort(pirsis, count);
            break;
        case 7:
            system("cls");
            FSave(pirsis, count, name);
            break;
        case 8:
            system("cls");
            FOpen(pirsis, count, name);
            break;
        case 9:

            break;
        default:
            printf("\t\tTry again! \n");
            printf("\t\tPress Enter to continue...");
            getchar();
            break;
        }
        system("cls");
    } while (command != 9);
}

void Create(product *pirsis, int * count) {

    for (int i = 0; i < (*count); i++) {

        pirsis[i].num = i + 1;

        printf("Enter color of %d item: ", (i + 1));
        scanf_s("%s", pirsis[i].color, 20);
        getchar();

        printf("Enter for which gender the item is (M/F): ");
        scanf_s("%c", &pirsis[i].sex, 1);
        getchar();

        do {
            printf("Enter size: ");
            scanf_s("%hd", &pirsis[i].size);
            if (pirsis[i].size < 1 || pirsis[i].size > 100)
                printf("Size can't be much then 100 and less then 1 \n");
        } while (pirsis[i].size < 1 || pirsis[i].size > 100);

        do {
            printf("Enter diameter: ");
            scanf_s("%f", &pirsis[i].diameter);
            if (pirsis[i].diameter < 0.01 || pirsis[i].diameter > 10)
                printf("Diameter can't be much then 10 and less then 0.1 \n");
        } while (pirsis[i].diameter < 0.01 || pirsis[i].diameter > 10);

        printf("Enter barcode: ");
        scanf_s("%s", pirsis[i].barcode, 14);
        getchar();

        do {
            printf("Enter number of order: ");
            scanf_s("%d", &pirsis[i].orderNum);
            if (pirsis[i].orderNum < 1 || pirsis[i].orderNum > 1000000000)
                printf("Number of order can't be much then 10^9 and less then 1 \n");
        } while (pirsis[i].orderNum < 1 || pirsis[i].orderNum > 1000000000);
        
        printf("Enter seller's full name (surname and initials together): ");
        scanf_s("%50s", pirsis[i].fullName, 50);
        getchar();

        system("cls");
    }
}
void Display(product* pirsis, int* count, char * name) {
    if (*count != 0) {
        printf("\n\t%s \n\n", name);

        printf("%c", 201);
        for (int i = 0; i < 107; i++)
            printf("%c", 205);
        printf("%c \n", 187);

        printf("%c%2c.%c %22s%c %3s%c %3s%c %5s%c %15s%c %11s%c %22s %1c\n", 186, 252, 186, "Color", 186,
            "Gender", 186, "Size", 186, "Diemeter", 186, "Barcode", 186, "Order Number", 186, "Customer", 186);

        printf("%c", 204);
        for (int i = 0; i < 107; i++)
            printf("%c", 205);
        printf("%c \n", 185);

        for (int i = 0; i < (*count); i++) {
            printf("%c%2d.%c %22s%c %6c%c %4hd%c %8.1f%c %15s%c %12d%c %22s %1c\n", 186, pirsis[i].num, 186, pirsis[i].color, 186,
                pirsis[i].sex, 186, pirsis[i].size, 186, pirsis[i].diameter, 186, pirsis[i].barcode, 186, pirsis[i].orderNum, 186, pirsis[i].fullName, 186);
            if ((i + 1) < (*count)) {
                printf("%c", 204);
                for (int i = 0; i < 107; i++)
                    printf("%c", 205);
                printf("%c \n", 185);
            }
            else {
                printf("%c", 200);
                for (int i = 0; i < 107; i++)
                    printf("%c", 205);
                printf("%c \n", 188);
            }
        }
    }
    else {
        printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
        printf("\t\t\t\tPress Enter to go to the main menu...");
    }
}

void AddLine(product* pirsis, int* count) {
    if (*count != 0) {
        pirsis[*count].num = *count + 1;

        printf("Enter color of %d item: ", *count + 1);
        scanf_s("%s", pirsis[*count].color, 20);
        getchar();

        printf("Enter for which gender the item is (M/F): ");
        scanf_s("%c", &pirsis[*count].sex, 2);
        getchar();

        printf("Enter size: ");
        scanf_s("%hd", &pirsis[*count].size);

        printf("Enter diameter: ");
        scanf_s("%f", &pirsis[*count].diameter);

        printf("Enter barcode: ");
        scanf_s("%s", pirsis[*count].barcode, 14);
        getchar();

        printf("Enter number of order: ");
        scanf_s("%d", &pirsis[*count].orderNum);

        printf("Enter seller's full name (surname and initials together): ");
        scanf_s("%50s", pirsis[*count].fullName, 50);

        *count += 1;
    }
    else {
        printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
        printf("\t\t\t\tPress Enter to go to the main menu...");
    }
    getchar();
    system("cls");
}

void DeleateLine(product* pirsis, int* count, int* line) {
    *line -= 1;
    //Clean All
    pirsis[*line].num = 0;
    memset(pirsis[*line].color, 0, sizeof(pirsis[*line].color));
    memset(pirsis[*line].barcode, 0, sizeof(pirsis[*line].barcode));
    pirsis[*line].diameter = 0;
    memset(pirsis[*line].fullName, 0, sizeof(pirsis[*line].fullName));
    pirsis[*line].orderNum = 0;
    pirsis[*line].sex = 'n';
    pirsis[*line].size = 0;

    //Sort
    for (int i = *line + 1; i < (*count); i++) {
        pirsis[i - 1].num = pirsis[i].num - 1;
        for (int j = 0; j < sizeof(pirsis[i].color); j++) {
            pirsis[i - 1].color[j] = pirsis[i].color[j];
        }
        for (int j = 0; j < sizeof(pirsis[i].barcode); j++) {
            pirsis[i - 1].barcode[j] = pirsis[i].barcode[j];
        }
        pirsis[i - 1].diameter = pirsis[i].diameter;
        for (int j = 0; j < sizeof(pirsis[i].fullName); j++) {
            pirsis[i - 1].fullName[j] = pirsis[i].fullName[j];
        }
        pirsis[i - 1].orderNum = pirsis[i].orderNum;
        pirsis[i - 1].sex = pirsis[i].sex;
        pirsis[i - 1].size = pirsis[i].size;
    }

    *count -= 1;
    getchar();
}

void Find(product* pirsis, int* count) {
    int object = 0;

    if (*count != 0) {
        printf("Choose the column: \n\n");
        printf("\t1) Color\t  5) Barcode\n");
        printf("\t2) Gender\t  6) Order Number\n");
        printf("\t3) Size\t\t  7) Customer\n");
        printf("\t4) Diemeter\t  8) Exit   \n\n");

        printf("\t>> ");
        scanf_s("%d", &object);
        getchar();
        system("cls");

        product temp[100];
        int num = 0;

        switch (object) {
        case 1:
            char color[20];

            printf("Enter the color name: \n");
            printf(">> ");
            scanf_s("%s", color, 20);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (strcmp(pirsis[i].color, color)) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Color";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This color does not exist");
            }
            getchar();
            break;
        case 2:
            char sex;

            printf("Enter the gender: \n");
            printf(">> ");
            scanf_s("%c", &sex, 1);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (pirsis[i].sex != sex) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Gender";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This gender does not exist");
            }
            getchar();
            break;
        case 3:
            short int size;

            printf("Enter the size: \n");
            printf(">> ");
            scanf_s("%hd", &size);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (pirsis[i].size != size) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Size";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This size does not exist");
            }
            getchar();
            break;
        case 4:
            float diameter;

            printf("Enter the diameter: \n");
            printf(">> ");
            scanf_s("%f", &diameter);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (pirsis[i].diameter != diameter) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Diameter";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This diameter does not exist");
            }
            getchar();
            break;
        case 5:
            char barcode[14];

            printf("Enter the barcode number: \n");
            printf(">> ");
            scanf_s("%s", &barcode, 14);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (strcmp(pirsis[i].barcode, barcode)) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Barcode number";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This barcode number does not exist");
            }
            getchar();
            break;
        case 6:
            int orderNum;

            printf("Enter the number of order: \n");
            printf(">> ");
            scanf_s("%d", &orderNum);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (pirsis[i].orderNum != orderNum) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, pirsis[i].fullName, 20);
                    temp[num].orderNum = orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by number of Order";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This number of order does not exist");
            }
            getchar();
            break;
        case 7:
            char fullName[20];

            printf("Enter the customer: \n");
            printf(">> ");
            scanf_s("%s", &fullName, 20);
            printf("\n\n");
            for (int i = 0; i < *count; i++) {
                short int exist = 1;
                if (strcmp(pirsis[i].fullName, fullName)) {
                    exist = 0;
                    continue;
                }
                if (exist == 1) {
                    strncpy_s(temp[num].color, pirsis[i].color, 20);
                    temp[num].num = pirsis[i].num;
                    strncpy_s(temp[num].barcode, pirsis[i].barcode, 20);
                    temp[num].diameter = pirsis[i].diameter;
                    strncpy_s(temp[num].fullName, fullName, 20);
                    temp[num].orderNum = pirsis[i].orderNum;
                    temp[num].sex = pirsis[i].sex;
                    temp[num].size = pirsis[i].size;

                    num++;
                }
            }
            if (num > 0) {
                char name[50] = "Find by Customer";
                Display(temp, &num, name);
                printf("\t\tPress Enter to continue...");
            }
            else {
                printf("This customer does not exist");
            }
            getchar();
            break;
        case 8:
            printf("\t\tPress Enter to continue...");
            break;
        default:
            printf("\t\tTry again! \n");
            printf("\t\tPress Enter to continue...");
            getchar();
            break;
        }
    }
    else {
    printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
    printf("\t\t\t\tPress Enter to go to the main menu...");
    }
    getchar();
}

void Sort(product* pirsis, int* count) {
    int object = 0;

    if (*count != 0) {
        printf("Choose the column: \n\n");
        printf("\t1) Color\t  5) Barcode\n");
        printf("\t2) Gender\t  6) Order Number\n");
        printf("\t3) Size\t\t  7) Customer\n");
        printf("\t4) Diemeter\t  8) Exit   \n\n");

        printf("\t>> ");
        scanf_s("%d", &object);
        getchar();
        system("cls");

        switch (object) {
        case 1:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (strcmp(pirsis[i].color, pirsis[j].color) > 0) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 2:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (pirsis[i].sex > pirsis[j].sex) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 3:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (pirsis[i].size > pirsis[j].size) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 4:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (pirsis[i].diameter > pirsis[j].diameter) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 5:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (strcmp(pirsis[i].barcode, pirsis[j].barcode) > 0) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 6:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (pirsis[i].orderNum > pirsis[j].orderNum) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 7:
            for (int i = 0; i < *count - 1; i++) {
                for (int j = i + 1; j < *count; j++) {
                    if (strcmp(pirsis[i].fullName, pirsis[j].fullName) > 0) {
                        product tmp = pirsis[j - 1];
                        pirsis[j - 1] = pirsis[j];
                        pirsis[j] = tmp;
                        int num = pirsis[j - 1].num;
                        pirsis[j - 1].num = pirsis[j].num;
                        pirsis[j].num = num;
                    }
                }
            }
            printf("\n\t\t\t\t Sorting is Done! Check on the display mode.");
            break;
        case 8:
            printf("\t\tPress Enter to continue...");
            break;
        default:
            printf("\t\tTry again! \n");
            printf("\t\tPress Enter to continue...");
            getchar();
            break;
        }
    }
    else {
        printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
        printf("\t\t\t\tPress Enter to go to the main menu...");
    }
    getchar();
}

void FSave(product* pirsis, int* count, char* name) {
    if (*count != 0) {
        printf("Enter a new name for the saved file (no more then 50 symbols!):\n");
        printf(">> ");
        scanf_s("%s", name, 50);
        getchar();

        FILE* file;
        fopen_s(&file, name, "w");
        for (int i = 0; i < *count; i++) {
            fprintf(file, "%s\n", pirsis[i].color);
            fprintf(file, "%c\n", pirsis[i].sex);
            fprintf(file, "%hd\n", pirsis[i].size);
            fprintf(file, "%f\n", pirsis[i].diameter);
            fprintf(file, "%s\n", pirsis[i].barcode);
            fprintf(file, "%d\n", pirsis[i].orderNum);
            fprintf(file, "%s\n", pirsis[i].fullName);
        }
        fclose(file);

        system("cls");
        printf("\n\t\t\t\tThe operation was completed successfully!");
    } else {
    printf("\n\t\tThere is no data in the table! Open the file or create a new document. \n\a");
    printf("\t\t\t\tPress Enter to go to the main menu...");
    }
    getchar();
}

void FOpen(product* pirsis, int* count, char* name) {

    printf("Enter a new name of opened file (with .txt extension):\n");
    printf(">> ");
    scanf_s("%s", name, 50);
    getchar();

    *count = -1;

    FILE* file;
    fopen_s(&file, name, "r");
    if (file == NULL)
    {
        printf("\n\t\t\t\tSuch file does not exist!\n");
        printf("\t\t\t\tPress Enter to go to the main menu...");
    }
    else {
        int i = 0;
        while(!feof(file)){
            pirsis[i].num = *count + 2;
            fscanf_s(file, "%s", &pirsis[i].color, 20);
            fscanf_s(file, "%s", &pirsis[i].sex, 6);
            fscanf_s(file, "%hd", &pirsis[i].size);
            fscanf_s(file, "%f", &pirsis[i].diameter);
            fscanf_s(file, "%s", &pirsis[i].barcode, 15);
            fscanf_s(file, "%d", &pirsis[i].orderNum);
            fscanf_s(file, "%s", &pirsis[i].fullName, 22);
            i++;
            *count += 1;
        }

        printf("\n\t\t\t\tFile opened successfully! \n");
        printf("\t\t\t\tPress Enter to go to the main menu...");
        fclose(file);
    }

    getchar();
    system("cls");
}