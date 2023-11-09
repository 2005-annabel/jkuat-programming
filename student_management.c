#include <stdio.h>

/* Structure to store student details*/
struct Student {
	char reg_no[20];
	char firstname[30];
	char lastname[30];
	float intro_to_programming;
	float networking;
	float accounting;
};

/* Function to add a new student*/
void add_student(struct Student *students, int num_students) {
	printf("Enter student details:\n");
	printf("Reg No: ");
	scanf("%s", students[num_students].reg_no);
	printf("First name: ");
	scanf("%s", students[num_students].firstname);
	printf("Last name: ");
	scanf("%s", students[num_students].lastname);
	printf("Intro to Programming: ");
	scanf("%f", &students[num_students].intro_to_programming);
	printf("Networking: ");
	scanf("%f", &students[num_students].networking);
	printf("Accounting: ");
	scanf("%f", &students[num_students].accounting);
}

/* Function to display student details*/
void display_student_details(struct Student *student) {
	printf("Student details:\n");
	printf("Reg No: %s\n", student->reg_no);
	printf("First name: %s\n", student->firstname);
	printf("Last name: %s\n", student->lastname);
	printf("Intro to Programming: %f\n", student->intro_to_programming);
	printf("Networking: %f\n", student->networking);
	printf("Accounting: %f\n", student->accounting);
}

/* Function to calculate student's average marks*/
float calculate_average_marks(struct Student *student) {
	float average = (student->intro_to_programming + student->networking + student->accounting) / 3;
	return average;
}

/* Function to find the student with the highest average marks*/
struct Student *find_student_with_highest_average_marks(struct Student *students, int num_students) {
	struct Student *highest_average_student = NULL;
	float highest_average = 0.0;
	for (int i = 0; i < num_students; i++) {
		float average_marks = calculate_average_marks(&students[i]);
		if (average_marks > highest_average) {
			highest_average = average_marks;
			highest_average_student = &students[i];
		}
	}
	return highest_average_student;
}

int main() {
	/* Create an array to store student details*/
	struct Student students[100];

	/* Get the number of students*/
	int num_students;
	printf("Enter the number of students: ");
	scanf("%d", &num_students);

	/* Add student details*/
	for (int i = 0; i < num_students; i++) {
		add_student(students, i);
	}

	/* Display student details*/
	for (int i = 0; i < num_students; i++) {
		display_student_details(&students[i]);
	}

	/* Find the student with the highest average marks*/
	struct Student *highest_average_student = find_student_with_highest_average_marks(students, num_students);

	/* Display the student with the highest average marks*/
	printf("Student with the highest average marks:\n");
	display_student_details(highest_average_student);

	return 0;
}
