#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int langs_check(char langs[]) {
	int L = 0, R = 0, F = 0, S = 0, E = 0;
	for (int i = 0; langs[i] != '\0'; i++) {
		if (langs[i] == 'L')
			L++;
		else if (langs[i] == 'E')
			E++;
		else if (langs[i] == 'R')
			R++;
		else if (langs[i] == 'S')
			S++;
		else if (langs[i] == 'F')
			F++;
	}
	if ( (L>1) || (E>1) || (F>1) || (S>1) || (R>1) )
		return 1;
	else
		return 0;
}

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
			
			if(1){ // *** first filter, conditions on the student
				// printf went down :)
				int anotherDemo = 0; // for counting courses/grades
				char courses_langs[405] = ")";
				int languages_check = langs_check(s.languages); // Useless?

				for (int i = 0; i < s.load; ++i){ // process each course taken by the student
					if( (strstr(courses_langs, s.courses[i]) != NULL) || languages_check ){ // *** second filter, conditions on the course/grade
						++anotherDemo; // counting courses   |||||||||  (strstr(courses_langs, s.courses[i]) != NULL) || 
						// printf("Course: %s Grade: %d\n", s.courses[i], s.grades[i]);
						// printf("Languages: %s\n\n", s.languages);
					}
					strcat(courses_langs, s.courses[i]);
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