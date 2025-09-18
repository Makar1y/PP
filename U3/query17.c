#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
	char name[30];
	char surname[30];
	int course;					// year of study
	double average; 			// average grade
	
	int load; 					// number of courses
	char courses[10][30]; 		// course names
	int grades[10]; 			// course grades	
	
	char languages[100];		// spoken languages
	
} Student;


int main(int argc, char *argv[]) {
	FILE *db = NULL;
	// open database file for reading, provide a parameter or use default "db.bin"
	if (argc > 1)
		db = fopen(argv[1], "rb");
	else
		db = fopen("db.bin", "rb");
		
	if (db){							
		Student students[1000];			// all the data goes here
		int size = 0;					// how many students in database
		
		// reading data from file
		fread(&size, sizeof(int), 1, db);
		
		for (int i = 0; i < size; i++){			
			fread(&students[i], sizeof(Student), 1, db);			
		}	
		printf("%d records loaded successfully\n", size);
		
		// MODIFY CODE BELOW
		
		int counterDemo = 0; // for counting students

		for (int i = 0; i < size; ++i){ // process all the student records in database
			Student s = students[i]; // store data for each student in s
			
			if(s.load){ // *** first filter, conditions on the student
				// printf went down :)
				int anotherDemo = 0; // for counting courses/grades
				char courses_for_count[1000] = "";
				char course_grade[50] = "";
				char for_num[5] = "";

				strcpy(courses_for_count, "");
				strcpy(course_grade, "");
				strcpy(for_num, "");

				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					strcpy(course_grade, s.courses[i]);
					sprintf(for_num, "%d", s.grades[i]);
					strcat(course_grade, for_num);
					if( (strstr(courses_for_count, course_grade) == NULL) && (strstr(courses_for_count, s.courses[i]) != NULL) ){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses
						// printf("Course: %s Grade: %d\n", s.courses[i], s.grades[i]);
						// printf("Languages: %s\n\n", s.languages);
					}
					strcat(courses_for_count, course_grade);
					// printf("\n\n%s %s\n\n", course_grade, s.courses[i]);
				}
				// printf("Languages: %s\n\n", s.languages);
						
				if (anotherDemo) {// *** third filter, various other conditions		
					printf("\n%s %s Course: %d Average: %f Load: %d", s.name, s.surname, s.course, s.average, s.load); // print student data	
					++counterDemo; // counting students
            	}
			}
		}
		printf("\n\nFilter applied, %d students found\n", counterDemo); // how many passed the filters
		fclose(db);	
	} else {
		printf("File db.bin not found, check current folder\n");
	}
	
	return 0;
}