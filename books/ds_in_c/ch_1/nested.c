#include <stdio.h>

#define FN_LN_BUFF 31 // First name and last name buffer
#define MID_NAME_BUFF 2 // Buffer for characters in middle name

typedef struct {
    char first_n[FN_LN_BUFF];
    char mid[MID_NAME_BUFF];
    char last_n[FN_LN_BUFF];
} Name;

typedef struct {
    int year;
    int month;
    int day;
} Age;

typedef struct {
    Name f_name;
    char gender;
    Age dob;
} Student;

Student get_student(Student st)
{
    printf("Please provide your name: ");
    scanf("%s", st.f_name.first_n);

    //TODO: Find a way to provide no middle name such that it can be left empty
    printf("Please provide your middle name: ");
    scanf("%s", st.f_name.mid);

    printf("Please provide your last name: ");
    scanf("%s", st.f_name.last_n);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &st.gender);

    printf("Enter your age:\n");
    printf("Year: ");
    scanf("%d", &st.dob.year);
    printf("Month: ");
    scanf("%d", &st.dob.month);
    printf("Day: ");
    scanf("%d", &st.dob.day);

    return st;
}

void print_st(Student st)
{
    //TODO: Decide if middle name is provided and needs to be printed
    printf("Name: %s %s %s\n", st.f_name.first_n, st.f_name.mid, st.f_name.last_n);
    printf("Gender: %c\n", st.gender);
    printf("Date of birth: %d/%d/%d\n", st.dob.year, st.dob.month, st.dob.day);
}

int main(void)
{
    Student st = get_student(st);
    print_st(st);
}